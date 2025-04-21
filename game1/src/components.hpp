#pragma once

class Component
{
public:
	bool exists = false;
	Component() {};
};

class CPosition: public Component {
public:
	float x {};
	float y {};
	
	CPosition() {};
	CPosition(float x, float y): x{x}, y{y}
	{};

};

class CVelocity: public Component {
public:
	float dx {};
	float dy {};

	CVelocity() {};
	CVelocity(float dx, float dy) :dx{ dx }, dy { dy }
	{};
};
