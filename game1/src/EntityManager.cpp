#include <algorithm>

#include "EntityManager.h"

void EntityManager::update()
{
	for (auto e : m_toAdd) 
	{
		m_entities.push_back(e);
		m_enityMap[e->tag()].push_back(e);
	}

	m_toAdd.clear();

	m_entities.erase(
		std::remove_if(m_entities.begin(), m_entities.end(), 
			[](auto e) { return !e->isAlive(); }
		)
	, m_entities.end());

	std::for_each(m_enityMap.begin(), m_enityMap.end(), 
		[](auto mE) { 
			mE.second.erase(std::remove_if(mE.second.begin(), mE.second.end(),
				[](auto e) { 
					return !e->isAlive();
				})
			, mE.second.end());
		});

}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto ent = std::make_shared<Entity>(tag, m_totalentities++);
	m_toAdd.push_back(ent);
	return ent;
}

EntityVec& EntityManager::getEntities()
{
	return m_entities;
}

EntityVec& EntityManager::getEntitiesByTag(const std::string& tag)
{
	return m_enityMap[tag];
}
