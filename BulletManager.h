#pragma once
#include <SFML/Graphics.hpp>
//#include <Box2D/Box2D.h>
#include "Player.h"
#include "Bullet.h"
#include <vector>
#include <iostream>

class BulletManager
{
private:
	// Members
	sf::Vector2f* playerPosition;
	int fireCooldown;
public:
	std::vector<Bullet*> myBullets;
	BulletManager(sf::Vector2f* inPlayerPosition, sf::RenderWindow* inMainWindow/*, b2World* inPhysicsWorld*/);
	~BulletManager();
	// Methods
	void update();
};

