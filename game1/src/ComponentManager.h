#include <unordered_map>
#include <vector>
#include <memory>

#include "./typedefs.h"
#include "components.hpp"

class ComponentManager
{
private:
	//std::unordered_map<Entity, std::vector<std::unique_ptr<Component>>> entitesToComponents;

public:
	ComponentManager() = default;
	~ ComponentManager() = default;

	//void addComponent(Entity entity, Component && component);
};