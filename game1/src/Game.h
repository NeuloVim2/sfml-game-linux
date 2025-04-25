#pragma once
#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp> 

#include "EntityManager.h"

class Game 
{
private:
	const int		  WIDTH;
	const int		  HEIGHT;
	const std::string TITLE;
	std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>();
	std::shared_ptr <EntityManager> m_entities = std::make_shared<EntityManager>();

public:
	Game(int height, int width, std::string& title);

	void run();

	Game() = default;
	~Game();
};

#endif