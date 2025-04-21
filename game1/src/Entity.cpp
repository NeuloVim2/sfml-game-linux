#include "Entity.h"

bool Entity::isAlive() const
{
	return m_alive;
}

uint8_t Entity::id() const
{
	return m_id;
}

void Entity::destroy()
{
	m_alive = false;
}

const std::string& Entity::tag() const
{
	return m_tag;
}
