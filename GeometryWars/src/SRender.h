#pragma once

#include<SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"


class SRender {

	bool rendering = true;
	sf::RenderWindow m_window;

public:
	SRender();

	void sRenderInit();
	void drawCalls();

	void setRendering(bool rendering);


};
