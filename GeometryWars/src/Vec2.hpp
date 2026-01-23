#include<iostream>
#include<math.h>

template<typename T>
class Vec2 {
public:
	//Variable Area
	T x = 0;
	T y = 0;

	//Constructor Area
	Vec2() {};
	Vec2(float xin, float yin) :
		x(xin),
		y(yin) {
	};

	//Conversion constructor
	Vec2(const sf::Vector2<T>& vec) :
		x(vec.x),
		y(vec.y) {
	};
	//Vec2(const sf::Vector2i& vec) :
	//	x(T(vec.x)),
	//	y(T(vec.y)) {
	//};

	//Aditional function
	void print() {
		std::cout << x << ' ' << y << '\n';
	}

	//Math Functions
	Vec2 add(const Vec2& v) {
		x = x + v.x;
		y = y + v.y;
		return *this;
	}
	Vec2 sub(const Vec2& v) {
		x = x - v.x;
		y = y - v.y;
		return *this;
	}
	Vec2 scale(float f) {
		x = x * f;
		y = y * f;
		return *this;
	}
	Vec2 distance(Vec2& target) {
		return Vec2(target.x - x, target.y - y);
	}
	float lenght() {
		//TODO: calculate vector lenght
		return std::sqrt(x * x + y * y);
	}
	Vec2<float> normalize() {
		//TODO: calculate normalized Vector
		return Vec2<float>((float)x / lenght(), (float)y / lenght());
	}

	//Math Operations
	//rhs -> rightHandSide (of the operator)
	bool operator == (const Vec2& rhs) const {
		if (x == rhs.x && y == rhs.y) {
			return true;
		}
		else {
			return false;
		}
	};
	Vec2 operator + (const Vec2& rhs) {
		return Vec2(x + rhs.x, y + rhs.y);
	};
	Vec2 operator - (const Vec2& rhs) {
		return Vec2(x - rhs.x, y - rhs.y);
	};
	Vec2 operator * (const float& val) {
		return Vec2(x * val, y * val);
	};
};