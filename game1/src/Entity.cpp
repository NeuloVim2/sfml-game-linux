#include "Entity.h"

Entity::Entity(const std::string& tag, uint32_t id) : m_tag{tag}, m_id{id}
{
}

bool Entity::isAlive() const
{
	return m_alive;
}

uint32_t Entity::id() const
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
