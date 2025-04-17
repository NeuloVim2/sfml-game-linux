#pragma once

#include <cstdint>
#include <tuple>

#include "components.hpp"

const int HEIGHT = 700;
const int WIDTH = 1280;

typedef uint32_t Entity;
using ComponentTuple = std::tuple<
	Position,
	Velocity
>;