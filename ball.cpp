#include "ball.h"

Ball::Ball(int x, int y) {

	vertices = sf::VertexArray(sf::Quads, 4);

	vertices[0].position = sf::Vector2f(x, y);
	vertices[1].position = sf::Vector2f(x + BALLSIZE, y);
	vertices[2].position = sf::Vector2f(x + BALLSIZE, y + BALLSIZE);
	vertices[3].position = sf::Vector2f(x, y + BALLSIZE);

	vertices[0].color = sf::Color::Green;
	vertices[1].color = sf::Color::Green;
	vertices[2].color = sf::Color::Green;
	vertices[3].color = sf::Color::Green;

	xVelocity = 3;
	yVelocity = -3;
}

void Ball::move(float amount) {
	for (int i = 0; i < 4; i++) {
		vertices[i].position.x += xVelocity;
		vertices[i].position.y += yVelocity;
	}
}


void Ball::checkWallCollision() {
	int ballLeft = vertices[0].position.x;
	int ballRight = vertices[2].position.x;
	int ballTop = vertices[0].position.y;

	if (ballTop < 0) yVelocity *= -1;
	if (ballRight > WINDOWWIDTH) xVelocity *= -1;
	if (ballLeft < 0) xVelocity *= -1;
}

bool Ball::checkFallout() {
	int ballBottom = vertices[0].position.y;
	if (ballBottom > WINDOWHEIGHT) {
		yVelocity *= -1;
	};
}

bool Ball::checkCollision(sf::Vertex brick[], int position) {

	int ballLeft = vertices[0].position.x;
	int ballRight = vertices[2].position.x;
	int ballTop = vertices[0].position.y;
	int ballBottom = vertices[2].position.y;

	int brickLeft = brick[position].position.x;
	int brickRight = brick[position + 2].position.x;
	int brickTop = brick[position].position.y;
	int brickBottom = brick[position + 2].position.y;

	if  (ballLeft < brickRight &&
	        ballRight > brickLeft &&
	        ballTop < brickBottom &&
	        ballBottom > brickTop) {

		float b_collision = brickBottom - ballTop;
		float t_collision = ballBottom - brickTop;
		float l_collision = ballRight - brickLeft;
		float r_collision = brickRight - ballLeft;

		if ((b_collision < t_collision && b_collision < l_collision && b_collision < r_collision) || (t_collision < b_collision && t_collision < l_collision && t_collision < r_collision ))
		{
			yVelocity *= -1;
			return true;
		}

		if ((r_collision < l_collision && r_collision < t_collision && r_collision < b_collision ) || (l_collision < r_collision && l_collision < t_collision && l_collision < b_collision))
		{
			xVelocity *= -1;
			return true;
		}
	}
	return false;
}