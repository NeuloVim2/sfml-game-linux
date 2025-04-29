#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "Game.h"
#include "Scene.h"

Game::Game(int height, int width, std::string& title)
	: HEIGHT{ height }
	, WIDTH{ width }
	, TITLE{ title }
{
	std::cout << "Game constructor is called" << std::endl;
}

void Game::init()
{
	m_config.parse("config.txt");
	window->create(
		sf::VideoMode(sf::Vector2u(m_config.window().width, m_config.window().height))
		, TITLE
		, sf::Style::None
		, m_config.window().fullScreen ? sf::State::Fullscreen : sf::State::Windowed
	);

	window->setFramerateLimit(m_config.window().frameLimit);
	ImGui::SFML::Init(*window);

	ImGui::GetStyle().ScaleAllSizes(2.0f);
	ImGui::GetIO().FontGlobalScale = 2.0f;
}

void Game::run()
{
    std::unique_ptr<Scene> scene = std::make_unique<Scene>(Scene::main_menu, window);

    scene->run();

}
Game::~Game()
{
	std::cout << "Game descturctor is called" << std::endl;
	ImGui::SFML::Shutdown();
}