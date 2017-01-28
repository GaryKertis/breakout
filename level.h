#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include "level.h"
#include "brick.h"
#include "constants.h"
#include <iostream>

class Level {
public:
	Level();
	void removeBrick(int);
	sf::Vertex vertices[NUMBRICKS * 4];	
	int remainingBricks;
};

#endif