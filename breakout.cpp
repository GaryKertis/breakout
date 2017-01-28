#include <SFML/Graphics.hpp>
#include "level.h"
#include "ball.h"
#include "constants.h"

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "My window");
	window.setFramerateLimit(60); // call it once, after creating the window

	srand(time(0));

	Level level;
	Ball ball(310, 300);

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		for (int i = 0; i < level.remainingBricks; i++) {
			if (ball.checkCollision(level.vertices, i * 4)) {
				level.removeBrick(i * 4);
			}
		}

		ball.checkWallCollision();

		if (ball.checkFallout()) {
		}

		ball.move(3);

		window.draw(&level.vertices[0], level.remainingBricks * 4, sf::Quads);
		window.draw(ball);

		window.display();
	}

	return 0;
}
