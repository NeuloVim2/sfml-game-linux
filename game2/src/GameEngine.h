#pragma once
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <string>
#include <memory>
#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp> 

#include "EntityManager.h"
#include "ConfigParser.h"

class GameEngine 
{
private:
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

	void run();

	template<class T>
	void changeScene()
	{

	}

	sf::RenderWindow& window()
	{
		return m_window;
	};

	~GameEngine();
};

#endif