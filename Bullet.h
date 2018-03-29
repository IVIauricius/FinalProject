#pragma once
#include <SFML/Graphics.hpp>
//#include <Box2D/Box2D.h>
#include <iostream>

class Bullet
{
private:
	// Members

	// Box2D
	//b2BodyDef myBodyDef;
	//b2Body* myBody;
	//b2CircleShape myPhysicsShape;
	//b2FixtureDef myFixtureDef;

	sf::Vector2f position;
	sf::Vector2f velocity;
	bool alive;
	sf::CircleShape myGraphicsShape;
	sf::RenderWindow* mainWindow;
public:
	Bullet();
	Bullet(sf::Vector2f inPosition, sf::RenderWindow* inMainWindow/*, b2World* inPhysicsWorld*/);
	~Bullet();
	// Methods
	void update();
	void checkCollision();
	void checkOutsideScreen();
	bool getAlive();
	void setAlive();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f inPosition);
	void setVelocity(sf::Vector2f inVelocity);
	void fire(sf::Vector2f inPosition);
};

