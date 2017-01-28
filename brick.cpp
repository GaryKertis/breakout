#include "brick.h"
#include "constants.h"

Brick::Brick(int x, int y) {


	vertices[0].position = sf::Vector2f(x, y);
	vertices[1].position = sf::Vector2f(x + BRICKWIDTH - 2, y);
	vertices[2].position = sf::Vector2f(x + BRICKWIDTH - 2, y + BRICKHEIGHT - 2);
	vertices[3].position = sf::Vector2f(x, y + BRICKHEIGHT - 2);

	int r = rand() % 255;
	int g = 0;
    int b = rand() % 255;

	for (int i = 0; i < 4; i++) {
		vertices[i].color = sf::Color(r,g,b,255);
	}

}


