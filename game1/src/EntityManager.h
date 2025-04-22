#pragma once
#ifndef ENTITY_MANGER_H
#define ENTITY_MANGER_H

#include "Entity.h"
#include "typedefs.h"

class EntityManager
{ 
private:
	EntityVec m_entities;
	EntityVec m_enityMap;
	uint8_t m_totalentities = 0;
public:
	EntityManager() {};
};

#endif