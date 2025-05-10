#pragma once
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>

#include <SFML/Graphics/RenderWindow.hpp> 

#include "EntityManager.h"
#include "Scene.h"
#include "ConfigParser.h"

class Scene;

using SceneMap = std::unordered_map<std::string, std::shared_ptr<Scene>>;
class GameEngine 
{
private:
	SceneMap m_scenes;
	std::string m_scene;
	bool m_running{ true };

	sf::RenderWindow m_window{};
	EntityManager m_entities{};
	ConfigParser m_config{};


	void init();
public:
	GameEngine()
	{
		init();
		std::cout << "GameEngine constructor is called" << std::endl;
	};

	void sayHello()
	{
		std::cout << "Hello From Game Engine!!" << std::endl;
	}

	void run();
	void update();
	void quit();

	template<class T>
	void changeScene(std::string sceneName)
	{
		if (!m_scenes.contains(sceneName))
			m_scenes[sceneName] = std::make_shared<T>();

		m_scene = sceneName;
	}

	sf::RenderWindow& window()
	{
		return m_window;
	};

	std::shared_ptr<Scene> currentString()
	{
		return m_scenes[m_scene];
	}

	void sUserInput();
	~GameEngine();
};

#endif