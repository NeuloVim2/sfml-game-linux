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
	sf::RenderWindow& window;


public:
	Game(int height, int width, std::string& title);

	void run();

	Game() = default;
	~Game() = default;
};

#endif