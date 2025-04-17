#include "Entity.h"

template<typename T>
T& Entity::get()
{
	return std::get<T>(m_components);
}

template<typename T>
const T& Entity::get() const
{
	return std::get<T>(m_components);
}
