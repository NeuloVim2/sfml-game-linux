#pragma once

#include <cstdint>
#include <tuple>
#include <unordered_map>

#include "Components.hpp"

const int HEIGHT = 700;
const int WIDTH = 1280;

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::unordered_map<std::string, EntityVec>;

using ComponentTuple = std::tuple<
	CPosition,
	CVelocity
>;