#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(sf::Vector2f inPosition, sf::RenderWindow* inMainWindow/*, b2World* inPhysicsWorld*/)
{
	/*
	myBodyDef.position = b2Vec2(inPosition.x, inPosition.y);
	myBodyDef.type = b2_dynamicBody;
	myBody = inPhysicsWorld->CreateBody(&myBodyDef);
	myPhysicsShape.m_p.Set(inPosition.x, inPosition.y);
	myPhysicsShape.m_radius = (25.0f);
	myFixtureDef.density = 10.f;
	myFixtureDef.friction = 0.1f;
	myFixtureDef.shape = &myPhysicsShape;
	myBody->CreateFixture(&myFixtureDef);
	*/

	position = inPosition;
	mainWindow = inMainWindow;
	velocity = sf::Vector2f(0.0f, 0.0f);
	alive = false;

	myGraphicsShape = sf::CircleShape(20);
	myGraphicsShape.setFillColor(sf::Color::Green);
	myGraphicsShape.setPosition(position);

	std::cout << "Bullet created." << std::endl;
}


Bullet::~Bullet()
{
	std::cout << "Bullet destroyed." << std::endl;
}

void Bullet::update()
{
	checkCollision();
	position += velocity;
	checkOutsideScreen();
	myGraphicsShape.setPosition(position.x, position.y);
	mainWindow->draw(myGraphicsShape);
}

void Bullet::checkCollision()
{

}

void Bullet::checkOutsideScreen()
{
	if (position.x < -100 || position.x > 2020 || position.y < -100 || position.y > 1180)
	{
		alive = false;
		position.x = -50;
		position.y = -50;
		velocity.x = 0;
		velocity.y = 0;
	}
}

bool Bullet::getAlive()
{
	return alive;
}

void Bullet::setAlive()
{
	alive = true;
}

sf::Vector2f Bullet::getPosition()
{
	return position;
}

void Bullet::setPosition(sf::Vector2f inPosition)
{
	position = inPosition;
}

void Bullet::setVelocity(sf::Vector2f inVelocity)
{
	velocity = inVelocity;
}

void Bullet::fire(sf::Vector2f inPosition)
{
	alive = true;
	velocity.x = 10.0f;
	position = inPosition;
}