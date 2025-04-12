#pragma once

#include <unordered_map>
#include <cstdint>

#include "./typedefs.h"
#include "./components.hpp"
#include "./ComponentManager.h"


class Scene {
public:
	enum Type {
		main_menu,
		level_one,
	};


private:
	Type m_sceneType{};

	ComponentManager cm;

public:
	Scene(Type sceneType);

	Scene() = default;
	~Scene() = default;

	void setUp();

	void run();

};