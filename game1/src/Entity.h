#pragma once
#ifndef ENTIITY_H
#define ENTITY_H

#include <cstdint>
#include <string>
#include <tuple>

#include "components.hpp"


class Entity 
{
private:
	std::tuple<Position, Velocity>	m_components {};
	bool			m_alive {};
	std::string		m_tag {};
	uint8_t			m_id {};

public:
	Enitty() {}

					template<typename T>
	void			add<T>();

					template<typename T>
	T&				get<T>();

					template<typename T>
	bool			has<T>();

					template<typename T>
	void			remove<T>();

	bool			isAlive() const;
	uint8_t			id() const;
	void			destroy();
	const			std::string& tag() const;
};

#endif