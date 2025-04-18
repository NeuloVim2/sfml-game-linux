#pragma once

class Component
{
private:
	bool exists = false;
public:
	Component() {};
};

struct Position{
	float x {};
	float y {};
};

struct Velocity {
	float dx {};
	float dy {};
};
