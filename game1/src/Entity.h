#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>
#include <string>

#include "Components.hpp"
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

	template<typename T, typename ...TArgs>
	T& add(TArgs && ...mArgs)
	{
		auto& component = get<T>();
		component = T(std::forward<TArgs>(mArgs)...);
		component.exists = true;
		return component;
	}

	template<typename T>
	T& get()
	{
		return std::get<T>(m_components);
	}

	template<typename T>
	const T& get() const
	{
		return std::get<T>(m_components);
	}

	template<typename T>
	bool has()
	{
		return get<T>().exists;
	}

	template<typename T>
	void remove()
	{
		get<T>() = T();
	}

	bool isAlive() const;
	uint8_t id() const;
	void destroy();
	const std::string& tag() const;
};

#endif