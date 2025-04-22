#include "EntityManager.h"

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag) 
{
	auto ent = std::make_shared<Entity>(tag, m_totalentities++);
	m_entities.push_back(ent);
	m_enityMap[tag].push_back(ent);
	return ent;
}