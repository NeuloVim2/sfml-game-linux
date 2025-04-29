#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp> 

#include "EntityManager.h"
#include "ConfigParser.h"

class Game 
{
private:
	const int		  WIDTH;
	const int		  HEIGHT;
	const std::string TITLE;
	sf::RenderWindow m_window{};
	EntityManager m_entities{};

	ConfigParser m_config{};

public:
	Game(int height, int width, std::string& title);

	void init();
	void run();

	Game() = default;
	~Game();
};

#endif