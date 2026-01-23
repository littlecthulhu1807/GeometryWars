#pragma once

class Game {

	int m_entityManager;
	int m_window;
	bool m_paused = false;

public:



	Game();
	~Game();

	void gameInit();
	void run();
};
