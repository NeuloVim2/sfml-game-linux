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
enum SceneType {
	main_menu,
	level_one,
};

using SceneMap = std::unordered_map<SceneType, std::shared_ptr<Scene>>;
class GameEngine 
{
private:
	SceneMap m_scenes;
	SceneType m_scene;
	bool m_running{ true };

	sf::RenderWindow m_window{};
	ConfigParser m_config{};


	void init();
	void sUserInput();
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
	void changeScene(SceneType sceneType)
	{
		if (!m_scenes.contains(sceneType))
			m_scenes[sceneType] = std::make_shared<T>(this);

		m_scene = sceneType;
	}

	sf::RenderWindow& window()
	{
		return m_window;
	};

	std::shared_ptr<Scene> currentScene()
	{
		return m_scenes[m_scene];
	}

	~GameEngine();
};

#endif