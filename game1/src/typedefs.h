#pragma once

#include <cstdint>
#include <tuple>
#include <unordered_map>

#include "Components.hpp"
#include "Entity.h"

const int HEIGHT = 700;
const int WIDTH = 1280;

using ComponentTuple = std::tuple<
	CPosition,
	CVelocity
>;