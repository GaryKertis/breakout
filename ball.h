#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265


class Ball : public sf::Drawable, public sf::Transformable {
public:
	Ball(int x, int y);
	bool checkCollision(sf::Vertex arr[], int position);
	void checkWallCollision();
	bool checkFallout();
	sf::VertexArray vertices;
	void move(float amount);
	void bounce();
private:
	float xVelocity;
	float yVelocity;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable
		target.draw(vertices, states);
	}
};

#endif