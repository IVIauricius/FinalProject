#include "Player.h"



Player::Player(sf::Vector2f inPosition, sf::RenderWindow* inMainWindow)
{
	position = inPosition;
	velocity = sf::Vector2f(0.0f, 0.0f);
	health = 1;
	mainWindow = inMainWindow;

	myShape = sf::RectangleShape(sf::Vector2f(10.0f, 10.0f));
	myShape.setFillColor(sf::Color::Blue);
	myShape.setSize(sf::Vector2f(100, 100));
	myShape.setPosition(position);

	std::cout << "Player object created." << std::endl;
}


Player::~Player()
{
	std::cout << "Player object destroyed." << std::endl;
}

void Player::update()
{
	checkInput();
	position += velocity;
	myShape.setPosition(position);
	mainWindow->draw(myShape);
}

sf::Vector2f Player::getPosition()
{
	return position;
}

sf::Vector2f Player::getVelocity()
{
	return velocity;
}

void Player::checkInput()
{
	// Check up and down keys.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = 10;
	}
	else
	{
		velocity.x = 0;
	}

	// Check left and right keys.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y = -10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y = 10;
	}
	else
	{
		velocity.y = 0;
	}
}