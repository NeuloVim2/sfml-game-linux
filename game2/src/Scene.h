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
#include "Action.hpp"
#include "Components.hpp"
#include "EntityManager.h"
#include "ConfigParser.h"

using KeyboardActionMap = std::unordered_map<sf::Keyboard::Scan, Action::Name>;
using MouseActionMap = std::unordered_map<sf::Mouse::Button, Action::Name>;

class GameEngine;
class Scene {
protected:
	GameEngine* m_gameEngine{};
	EntityManager m_entities{};
	int m_frame{};
	KeyboardActionMap m_keyboardActionMap{};
	MouseActionMap m_mouseActionMap{};
	bool m_paused{true};

	void virtual sRender() = 0;

public:
	void virtual update() = 0;
	void virtual sDoAction(Action& action) = 0;

	void simulate(int);

	void registerKeyboardAction(sf::Keyboard::Scan inputKey, Action::Name actionName)
	{
		m_keyboardActionMap[inputKey] = actionName;
	};

	const KeyboardActionMap& keyboardActionMap() const
	{
		return m_keyboardActionMap;
	};

	void registerMouseAction(sf::Mouse::Button inputKey, Action::Name actionName)
	{
		m_mouseActionMap[inputKey] = actionName;
	};

	const MouseActionMap& mouseActionMap() const
	{
		return m_mouseActionMap;
	};

	GameEngine* gameEngine()
	{
		return m_gameEngine;
	};

	Scene(GameEngine* ge);
	Scene() = default;
	~Scene() 
	{
		std::cout << "Scene destructor is called" << std::endl;
	};
};

#endif
