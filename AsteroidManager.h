#pragma once
#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include "Bullet.h"
#include <vector>
#include <random>

class AsteroidManager
{
private:
	std::vector<Asteroid*> gameAsteroids;
	sf::RenderWindow* mainWindow;
	std::vector<Bullet*> gameBullets;
	sf::Font font;
	sf::Text scoreText;
	int score;
public:
	AsteroidManager();
	AsteroidManager(sf::RenderWindow* inMainWindow, std::vector<Bullet*> inGameBullets);
	~AsteroidManager();
	void createAsteroid(/*sf::Vector2f inPosition*/);
	void update();
};

