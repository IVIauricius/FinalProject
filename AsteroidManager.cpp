#include "AsteroidManager.h"



AsteroidManager::AsteroidManager()
{
}

AsteroidManager::AsteroidManager(sf::RenderWindow* inMainWindow, std::vector<Bullet*> inGameBullets)
{
	mainWindow = inMainWindow;
	gameBullets = inGameBullets;
	std::cout << "AsteroidManager created." << std::endl;
	font.loadFromFile("font.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	score = 0;
	std::cout << &score << std::endl;
}

AsteroidManager::~AsteroidManager()
{
}

void AsteroidManager::createAsteroid(/*sf::Vector2f inPosition*/)
{
	gameAsteroids.push_back(new Asteroid(sf::Vector2f(2000.0f, (rand() % 900 + 180)), gameBullets, mainWindow, &score));
}

void AsteroidManager::update()
{
	if ((rand() % 100) == 0)
	{
		createAsteroid();
	}
	for (int i = 0; i < gameAsteroids.size(); i++)
	{
		gameAsteroids.at(i)->update();
	}

	// Update score.
	scoreText.setString("Score: " + std::to_string(score));
	mainWindow->draw(scoreText);
}