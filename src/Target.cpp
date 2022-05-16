#include "../include/Target.h"

Target::spawnTarget(int screenSize){
	srand( (unsigned)time( NULL ) );
	posX = (rand() % screenSize) - (screenSize / 2);
	posY = (rand() % screenSize) - (screenSize / 2)
}