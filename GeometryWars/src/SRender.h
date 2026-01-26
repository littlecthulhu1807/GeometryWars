#pragma once

#include<SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include"EntityManager.h"


class SRender {

	bool m_rendering = true;
	sf::RenderWindow m_window;

public:
	SRender();

	void sRenderInit(unsigned int width, unsigned int height);
	void drawCalls(EntityManager& entityM);

	void setRendering(bool rendering);
	bool getRendering();

	sf::RenderWindow& getWindow(){
		return m_window;
	}


};
