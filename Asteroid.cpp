#include "Asteroid.h"



Asteroid::Asteroid()
{
}

Asteroid::Asteroid(sf::Vector2f inPosition, std::vector<Bullet*> inGameBullets, sf::RenderWindow* inMainWindow, int* inScore)
{
	position = inPosition;
	velocity.x = -10.0f;
	gameBullets = inGameBullets;
	mainWindow = inMainWindow;

	myGraphicsShape = sf::CircleShape(20.0f);
	myGraphicsShape.setFillColor(sf::Color::Yellow);
	myGraphicsShape.setPosition(inPosition);

	score = inScore;

	std::cout << "Asteroid created." << std::endl;
}


Asteroid::~Asteroid()
{
	std::cout << "Asteroid destroyed." << std::endl;
}

void Asteroid::setPosition(sf::Vector2f inPos)
{
	position = inPos;
}

sf::Vector2f Asteroid::getPosition()
{
	return position;
}

bool Asteroid::checkOutsideScreen()
{
	if (position.x < -50)
		return true;
}

void Asteroid::update()
{
	position += velocity;
	myGraphicsShape.setPosition(position);
	mainWindow->draw(myGraphicsShape);
	checkOutsideScreen();
	checkCollision();
}

void Asteroid::checkCollision()
{
	// Go through bullets list.
	for (int i = 0; i < gameBullets.size(); i++)
	{
		// Get absolute value of X.
		int AbsX = gameBullets.at(i)->getPosition().x - position.x;
		if (AbsX < 0)
			AbsX *= -1;

		// Get absolute value of Y.
		int AbsY = gameBullets.at(i)->getPosition().y - position.y;
		if (AbsY < 0)
			AbsY *= -1;

		if ((AbsX < 40.0f && AbsY < 40.0f))
		{
			std::cout << "Collision has occured." << std::endl;
			gameBullets.at(i)->setPosition(sf::Vector2f(-1000.0f, 0.0f));
			position.x = -1000.0f;
			*score += 1;
			std::cout << &score << std::endl;
		}
	}
}