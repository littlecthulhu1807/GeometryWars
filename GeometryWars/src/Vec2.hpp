#include<iostream>

template<typename T>
class Vec2 {
public:
	T x = 0;
	T y = 0;

	Vec2<T>() {};
	Vec2<T>(float xin, float yin) :
		x(xin),
		y(yin) {
	};

	void print() {
		std::cout << x << ' ' << y << '\n';
	}
	Vec2<T> add(const Vec2& v) {
		x = x + v.x;
		y = y + v.y;
		return *this;
	}
	Vec2<T> sub(const Vec2& v) {
		x = x - v.x;
		y = y - v.y;
		return *this;
	}
	Vec2<T> scale(float f) {
		x = x * f;
		y = y * f;
		return *this;
	}
	float lenght() {
		//TODO: calculate vector lenght
	}
	float normalize() {
		//TODO: calculate normalized Vector
	}
	//rhs -> rightHandSide (of the operator)
	bool operator == (const Vec2& rhs) const {
		if (x == rhs.x && y == rhs.y) {
			return true;
		}
		else {
			return false;
		}
	};
	Vec2<T> operator + (const Vec2<T>& rhs) {
		return Vec2(x + rhs.x, y + rhs.y);
	};
	Vec2<T> operator - (const Vec2<T>& rhs) {
		return Vec2(x - rhs.x, y - rhs.y);
	};
	Vec2<T> operator * (const float& val) {
		return Vec2(x * val, y * val);
	};
};