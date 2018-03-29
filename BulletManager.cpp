#include "BulletManager.h"



BulletManager::BulletManager(sf::Vector2f* inPlayerPosition, sf::RenderWindow* inMainWindow/*, b2World* inPhysicsWorld*/)
{
	playerPosition = inPlayerPosition;
	fireCooldown = 60;

	for (int i = 0; i < 3; i++)
	{
		myBullets.push_back(new Bullet(sf::Vector2f(-50.0f, -50.0f), inMainWindow/*, inPhysicsWorld*/));
	}

	std::cout << "BulletManager created." << std::endl;
}


BulletManager::~BulletManager()
{
	std::cout << "BulletManager destroyed." << std::endl;
}

void BulletManager::update()
{
	fireCooldown++;
	if (fireCooldown > 30)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			for (int i = 0; i < myBullets.size(); i++)
			{
				if (myBullets.at(i)->getAlive() == false)
				{
					myBullets.at(i)->fire(sf::Vector2f(playerPosition->x, playerPosition->y));
					break;
				}
			}
			fireCooldown = 0;
		}
	}

	for (int i = 0; i < myBullets.size(); i++)
	{
		myBullets.at(i)->update();
	}
}