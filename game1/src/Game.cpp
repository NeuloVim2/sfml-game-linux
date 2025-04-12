#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

#include "Game.h"
#include "Scene.h"

Game::Game(int height, int width, std::string& title)
	: HEIGHT{ height }
	, WIDTH{ width }
	, TITLE{ title }
{
	sf::RenderWindow wind(sf::VideoMode(WIDTH, HEIGHT), TITLE);
	window = &wind;

	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);
};

void Game::run()
{
    std::shared_ptr<Scene> scene = std::make_shared<Scene>(Scene::main_menu);

    scene->run();

};