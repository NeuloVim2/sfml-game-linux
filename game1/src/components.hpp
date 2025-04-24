#pragma once

#include "vector.h"

class Component
{
public:
	bool exists = false;
	Component() {};
};

class CTransform: public Component {
public:

	Vector pos{};
	Vector vel{};
	Vector scale{};
	float angle{};
	
	CTransform() {};
	CTransform(Vector pos, Vector vel, Vector scale, float angle)
		: pos{pos}, vel{vel}, scale{scale}, angle{angle}
	{};

};
