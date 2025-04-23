#pragma once
#ifndef ENTITY_MANGER_H
#define ENTITY_MANGER_H

#include "memory"

#include "Entity.h"
#include "typedefs.h"

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::unordered_map<std::string, EntityVec>;

class EntityManager
{ 
private:
	EntityVec m_entities;
	EntityVec m_toAdd;
	EntityMap m_enityMap;
	uint8_t m_totalentities = 0;
public:
	EntityManager() {};
	void update();
	std::shared_ptr<Entity> addEntity(const std::string& tag);
};

#endif