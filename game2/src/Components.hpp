#pragma once

#include <string>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Vector2f.h"

class Component
{
public:
	bool exists = false;
	Component() {};
};

class CSelect: public Component
{
public:
  int prev;
  int next;
  bool select = false;

  CSelect(bool select = false, int prev = 0, int next = 0)
    : select{select}, prev{prev}, next{next} 
  {};
};

class CText: public Component
{
public:
  sf::Text text;

  CText(const sf::Font& font = sf::Font(), const std::string& str = "", unsigned int characterSize = 30) : text{font} 
  {
    text.setString(str);
    text.setCharacterSize(characterSize);
  };
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
	{
	};
};

class CInput: public Component {
public:
	bool up{};
	bool down{};
	bool right{};
	bool left{};
	bool shoot{};
	bool special{};

	CInput() {};
	CInput(bool up, bool down, bool right, bool left, bool shoot)
		: up {up}, down{down}, right{right}, left{left}, shoot{shoot}
	{};
};

