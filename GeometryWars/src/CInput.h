#pragma once

#include"Component.h"

class CInput : public Component {
public:
	CInput();

	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
private:
};
