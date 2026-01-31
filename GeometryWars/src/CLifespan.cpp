#include"CLifespan.h"

CLifespan::CLifespan(){}

CLifespan::CLifespan(int lifespanIn):
lifespan(lifespanIn){}

void CLifespan::updateLifespan(){
	--lifespan;
	if (lifespan <= 0){
		kill();
	}
}

void CLifespan::kill(){

}
