#pragma once

#include <cstdint>
#include <tuple>

#include "Components.hpp"

const int HEIGHT = 700;
const int WIDTH = 1280;

using ComponentTuple = std::tuple<
	CPosition,
	CVelocity
>;