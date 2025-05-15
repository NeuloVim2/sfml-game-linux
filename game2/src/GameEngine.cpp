#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "GameEngine.h"
#include "ScenePlay.h"
#include "SceneMenu.h"

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

void GameEngine::sUserInput()
{
	while (const std::optional event = m_window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			m_window.close();

		ImGui::SFML::ProcessEvent(m_window, *event);
		auto& io = ImGui::GetIO();

		// Block user input for Game if ImGui window focused
		if (io.WantCaptureKeyboard)
			continue;

		const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
		const auto* keyReleased = event->getIf<sf::Event::KeyReleased>();
		const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>();
		const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>();


		if (keyPressed)
		{
			if (currentScene()->keyboardActionMap().contains(keyPressed->scancode))
				continue;

			Action action(currentScene()->keyboardActionMap().at(keyPressed->scancode), Action::Phase::START);
			currentScene()->sDoAction(action);
		}

		if (keyReleased)
		{
			if (currentScene()->keyboardActionMap().contains(keyReleased->scancode))
				continue;

			Action action(currentScene()->keyboardActionMap().at(keyReleased->scancode), Action::Phase::END);
			currentScene()->sDoAction(action);
		}

		if (mouseButtonPressed)
		{
			if (currentScene()->mouseActionMap().contains(mouseButtonPressed->button))
				continue;

			Action action(currentScene()->mouseActionMap().at(mouseButtonPressed->button), Action::Phase::START);
			currentScene()->sDoAction(action);
		}

		if (mouseButtonReleased)
		{
			if (currentScene()->mouseActionMap().contains(mouseButtonReleased->button))
				continue;

			Action action(currentScene()->mouseActionMap().at(mouseButtonReleased->button), Action::Phase::END);
			currentScene()->sDoAction(action);
		}
	}
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