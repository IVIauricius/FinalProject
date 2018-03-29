#include <SFML/Graphics.hpp>
//#include <Box2D/Box2D.h>
#include "Player.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Asteroid.h"
#include "AsteroidManager.h"

int main()
{
	// Setup.
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!", sf::Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	// Physics world.
	// b2Vec2 gravity(0.0f, 0.0f);
	// b2World physicsWorld(gravity);

	// Create my objects.
	Player myPlayer(sf::Vector2f(200.0f, 540.0f), &window);
	BulletManager myBulletManager(&myPlayer.position, &window/*, &physicsWorld*/);
	AsteroidManager myAsteroidManager(&window, myBulletManager.myBullets);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// Update my objects.
		myPlayer.update();
		myBulletManager.update();
		myAsteroidManager.update();
		// physicsWorld.Step((1.0f / 60.0f), 8, 3);

		// Check exit.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			// Call destructors for all objects in array.
			return 0;
		}

		window.display();
	}

	return 0;
}