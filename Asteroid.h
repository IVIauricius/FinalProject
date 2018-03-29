#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <vector>

class Asteroid
{
private:
	sf::Vector2f position;
	sf::Vector2f velocity;
	std::vector<Bullet*> gameBullets;
	sf::CircleShape myGraphicsShape;
	sf::RenderWindow* mainWindow;
	int* score;

public:
	Asteroid();
	Asteroid(sf::Vector2f inPosition, std::vector<Bullet*> inGameBullets, sf::RenderWindow* inMainWindow, int* inScore);
	~Asteroid();
	void setPosition(sf::Vector2f inPos);
	sf::Vector2f getPosition();
	bool checkOutsideScreen();
	void update();
	void checkCollision();
};

