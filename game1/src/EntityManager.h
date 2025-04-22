#pragma once
#ifndef ENTITY_MANGER_H
#define ENTITY_MANGER_H

#include "memory"

#include "Entity.h"
#include "typedefs.h"

class EntityManager
{ 
private:
	EntityVec m_entities;
	EntityMap m_enityMap;
	uint8_t m_totalentities = 0;
public:
	EntityManager() {};

	std::shared_ptr<Entity> addEntity(const std::string& tag);
};

#endif