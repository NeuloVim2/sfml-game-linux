#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "GameEngine.h"
#include "ScenePlay.h"

void GameEngine::init()
{
	m_config.parse("config.txt");
	m_window.create(
		sf::VideoMode(sf::Vector2u(m_config.window().width, m_config.window().height))
		,  "Mega Mario"
		, sf::Style::None
		, m_config.window().fullScreen ? sf::State::Fullscreen : sf::State::Windowed
	);

	m_window.setFramerateLimit(m_config.window().frameLimit);
	m_window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(m_window);

	ImGui::GetStyle().ScaleAllSizes(2.0f);
	ImGui::GetIO().FontGlobalScale = 2.0f;
}

void GameEngine::run()
{
    //std::unique_ptr<Scene> scene = std::make_unique<Scene>(Scene::main_menu, this);
	changeScene<ScenePlay>(SceneType::level_one);
    //std::unique_ptr<Scene> scene = std::make_unique<ScenePlay>(this);

    //scene->run();

}
void GameEngine::update()
{
	currentScene()->gameEngine()->sayHello();
	currentScene()->simulate(1);
}
GameEngine::~GameEngine()
{
	std::cout << "GameEngine descturctor is called" << std::endl;
	ImGui::SFML::Shutdown();
}