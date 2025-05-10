#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include <cstdint>
#include <iostream>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "typedefs.h"
#include "GameEngine.h"
#include "Components.hpp"
#include "EntityManager.h"
#include "ConfigParser.h"

class GameEngine;
class Scene {
public:
	enum Type {
		main_menu,
		level_one,
	};

private:
	GameEngine* m_gameEngine{};
	EntityManager m_entities{};
	int m_frame{};
	std::unordered_map<int, std::string> m_actionMap{};
	bool m_paused{true};

public:
	Scene(GameEngine* ge);
	Scene() = default;
	~Scene() 
	{
		std::cout << "Scene destructor is called" << std::endl;
	};

	void virtual update() = 0;
	void virtual sDoAction(std::string action) = 0;
	void virtual sRender() = 0;

	void simulate(int);
	void doAction(std::string);
	void registerAction(std::string);

	GameEngine* gameEngine()
	{
		return m_gameEngine;
	};
};

#endif
