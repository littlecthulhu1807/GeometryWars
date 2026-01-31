#pragma once

#include"Component.h"

class CLifespan : public Component {
public:
	CLifespan();
	CLifespan(int lifespanIn);

	int lifespan = 0;
	int lifespanLeft = 0;

	void updateLifespan();
	void kill();

private:

};
