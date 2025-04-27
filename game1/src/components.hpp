#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Vector2f.h"

class Component
{
public:
	bool exists = false;
	Component() {};
};

class CTransform: public Component {
public:

	Vector2f pos{};
	Vector2f vel{};
	Vector2f scale{};
	float angle{};
	
	CTransform() {};
	CTransform(Vector2f pos, Vector2f vel, Vector2f scale, float angle)
		: pos{pos}, vel{vel}, scale{scale}, angle{angle}
	{};

};

class CLifespan: public Component {
public:
	float lifespamTotal{};
	float lifespamRemaining{};
	
	CLifespan() {};
	CLifespan(float total, float remaining) 
		: lifespamTotal {total}, lifespamRemaining {remaining}
	{};
};

class CScore: public Component {
public:
	float score{};
	
	CScore() {};
	CScore(float score)
		: score{score}	
	{};
};

class CCollision: public Component {
public:
	float radius{};

	CCollision() {};
	CCollision(float radius)
		: radius{radius}
	{};
};

class CShape: public Component {
public:
	sf::CircleShape circle;
	CShape() {};
	CShape(sf::CircleShape circle)
		: circle {circle}	
	{};
};

class CInput: public Component {
public:
	int up{};
	int down{};
	int right{};
	int left{};
	int shoot{};

	CInput() {};
	CInput(int up, int down, int right, int left, int shoot)
		: up {up}, down{down}, right{right}, left{left}, shoot{shoot}
	{};
};

