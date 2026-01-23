#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class Game {

	int m_entityManager;
	sf::RenderWindow m_window;
	sf::Clock m_deltaClock;
	bool m_paused = false;

public:



	Game();
	~Game();

	void gameInit();
	void run();
};
