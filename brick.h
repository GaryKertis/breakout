#ifndef BRICK_H
#define BRICK_H
#include <SFML/Graphics.hpp>

class Brick {
public:
	Brick(int x, int y);
	sf::Vertex vertices[4];
};

#endif