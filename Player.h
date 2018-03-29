#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	// Members
	sf::Vector2f velocity;
	int health;
	sf::RectangleShape myShape;
	sf::RenderWindow* mainWindow;
public:
	// Members
	sf::Vector2f position;

	Player(sf::Vector2f inPos, sf::RenderWindow* inMainWindow);
	~Player();

	// Methods
	void update();
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	void checkInput();
};

