#pragma once

#include <cstdint>
#include <tuple>

#include "components.hpp"

const int HEIGHT = 700;
const int WIDTH = 1280;

using ComponentTuple = std::tuple<
	Position,
	Velocity
>;