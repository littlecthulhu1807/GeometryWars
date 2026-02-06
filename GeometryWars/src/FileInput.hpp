#include<iostream>
#include<fstream>

struct WindowData{

	WindowData() {};

	unsigned int width;
	unsigned int height;
	unsigned int frameLimit;
};

struct FontData {

	FontData() {};

	std::string filePath;
	unsigned int size;
	unsigned int r;
	unsigned int g;
	unsigned int b;
};

struct PlayerData {

	PlayerData() {};

	float ShapeRadius;
	float CollisionRadius;
	float Speed;
	int r;
	int g;
	int b;
	int oR;
	int oG;
	int oB;
	float OutlineThickness;
	int ShapeVertices;

};

struct EnemyData {

	EnemyData() {};

	float ShapeRadius;
	float CollisionRadius;
	float Speed;
	int r;
	int g;
	int b;
	int oR;
	int oG;
	int oB;
	float OutlineThickness;
	int minVert;
	int maxVert;
	int SmallLifespan;
	int SpawnInterval;

};

struct BulletData {

	BulletData() {};

	float ShapeRadius;
	float CollisionRadius;
	float Speed;
	int r;
	int g;
	int b;
	int oR;
	int oG;
	int oB;
	float OutlineThickness;
	int ShapeVertices;
	int lifespan;

};



class ConfigReader {

public:

	WindowData windowData = WindowData();
	FontData fontData = FontData();

	ConfigReader(){};

	bool readData(const char* filename) {
		std::ifstream fin(filename);
		std::string temp;

		while (fin >> temp) {
			if (temp == "Window") {
				fin >> windowData.width >> windowData.height >> windowData.frameLimit;
				std::cout << "Window Data: " << windowData.width << ' ' << windowData.height << ' ' << windowData.frameLimit << '\n';
			}
			else if (temp == "Font") {
				fin >> fontData.filePath >> fontData.size >> fontData.r >> fontData.g >> fontData.b;
				std::cout << "Font Data: " << fontData.filePath << ' ' << fontData.size << ' ' << fontData.r << fontData.g << fontData.b << '\n';
			}
		}
		return true;
	}

};