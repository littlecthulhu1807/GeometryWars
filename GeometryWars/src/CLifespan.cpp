#include"CLifespan.h"

CLifespan::CLifespan(){}

CLifespan::CLifespan(int lifespanIn):
lifespan(lifespanIn){
	lifespanLeft = lifespan;
}

void CLifespan::updateLifespan(){
	--lifespanLeft;
}
