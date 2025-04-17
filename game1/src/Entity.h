#pragma once
#ifndef ENTIITY_H
#define ENTITY_H

#include <cstdint>
#include <string>

#include "components.hpp"
#include "typedefs.h"

class Entity 
{
private:
	ComponentTuple	m_components {};
	bool			m_alive { true };
	std::string		m_tag { "default" };
	uint8_t			m_id { 0 };

public:
	Entity() {};

	template<typename T>
	void add();

	template<typename T>
	T& get();

	template<typename T>
	const T& get() const;

	template<typename T>
	bool has();

	template<typename T>
	void remove();

	bool isAlive() const;
	uint8_t id() const;
	void destroy();
	const std::string& tag() const;
};

#endif