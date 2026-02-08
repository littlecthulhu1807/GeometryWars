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

	float shapeRadius;
	float collisionRadius;
	float speed;
	int r;
	int g;
	int b;
	int oR;
	int oG;
	int oB;
	float outlineThickness;
	int shapeVertices;

};

struct EnemyData {

	EnemyData() {};

	float shapeRadius;
	float collisionRadius;
	float speed;
	int r;
	int g;
	int b;
	int oR;
	int oG;
	int oB;
	float outlineThickness;
	int minVert;
	int maxVert;
	int smallLifespan;
	int spawnInterval;

};

struct BulletData {

	BulletData() {};

	float shapeRadius;
	float collisionRadius;
	float speed;
	int r;
	int g;
	int b;
	int oR;
	int oG;
	int oB;
	float outlineThickness;
	int shapeVertices;
	int lifespan;

};



class ConfigReader {

public:

	WindowData windowData = WindowData();
	FontData fontData = FontData();
	PlayerData playerData = PlayerData();
	EnemyData enemyData = EnemyData();
	BulletData bulletData = BulletData();

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
			else if (temp == "Player") {
				fin >> playerData.shapeRadius >> playerData.collisionRadius >> playerData.speed >> playerData.r >> playerData.g >> playerData.b
					>> playerData.oR >> playerData.oG >> playerData.oB >> playerData.outlineThickness >> playerData.shapeVertices;
				std::cout << "Player Data: " << playerData.shapeRadius << playerData.collisionRadius << playerData.speed << playerData.r << playerData.g << playerData.b
					<< playerData.oR << playerData.oG << playerData.oB << playerData.outlineThickness << playerData.shapeVertices << '\n';
			}
			else if (temp == "Enemy") {
				fin >> enemyData.shapeRadius >> enemyData.collisionRadius >> enemyData.speed >> enemyData.r >> enemyData.g >> enemyData.b
					>> enemyData.oR >> enemyData.oG >> enemyData.oB >> enemyData.outlineThickness >> enemyData.minVert >> enemyData.maxVert >> enemyData.smallLifespan >> enemyData.spawnInterval;
				std::cout << "Enemy Data: " << enemyData.shapeRadius << enemyData.collisionRadius << enemyData.speed << enemyData.r << enemyData.g << enemyData.b
					<< enemyData.oR << enemyData.oG << enemyData.oB << enemyData.outlineThickness << enemyData.minVert << enemyData.maxVert << enemyData.smallLifespan << enemyData.spawnInterval << '\n';
			}
			else if (temp == "Bullet") {
				fin >> bulletData.shapeRadius >> bulletData.collisionRadius >> bulletData.speed >> bulletData.r >> bulletData.g >> bulletData.b
					>> bulletData.oR >> bulletData.oG >> bulletData.oB >> bulletData.outlineThickness >> bulletData.shapeVertices >> bulletData.lifespan;
				std::cout << "Bullet Data: " << bulletData.shapeRadius << bulletData.collisionRadius << bulletData.speed << bulletData.r << bulletData.g << bulletData.b
					<< bulletData.oR << bulletData.oG << bulletData.oB << bulletData.outlineThickness << bulletData.shapeVertices << bulletData.lifespan << '\n';
			}
		}
		return true;
	}

};