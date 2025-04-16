#ifndef GAME_H
#define GAME_H
#pragma once

#include <string>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp> 

class Game 
{
private:
	const int		  WIDTH;
	const int		  HEIGHT;
	const std::string TITLE;
	std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>();


public:
	Game(int height, int width, std::string& title);

	void run();

	Game() = default;
	~Game();
};

#endif