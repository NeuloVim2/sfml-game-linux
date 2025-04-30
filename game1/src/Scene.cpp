#include <iostream>
#include <filesystem>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
 
#include <imgui-SFML.h>
#include <imgui.h>

#include "Scene.h"
#include "Entity.h"
#include "EntityManager.h"
#include "Components.hpp"

void Scene::setUp()
{
}

void Scene::spawnPlayer() 
{
    auto player = m_entities.addEntity("player");
    auto& playerCTransform = player->add<CTransform>(
        Vector2f {100.0f, 100.0f}, 
        Vector2f {11.3f, 3.5f}, 
        Vector2f {2.0f, 2.0f}, 
        30.0f
    );

    auto& playerCShape = player->add<CShape>(sf::CircleShape { 
        static_cast<float>(m_config.player().shapeConfig.shapeRadius), 
        static_cast<std::size_t>(m_config.player().shapeVertices)
    });

    // Set up colors and border thickness
    playerCShape.circle.setFillColor(sf::Color(
        m_config.player().shapeConfig.fillColor[0], 
        m_config.player().shapeConfig.fillColor[1], 
        m_config.player().shapeConfig.fillColor[2]));
    playerCShape.circle.setOutlineColor(sf::Color(
        m_config.player().shapeConfig.outlineColor[0], 
        m_config.player().shapeConfig.outlineColor[1], 
        m_config.player().shapeConfig.outlineColor[2]));
    playerCShape.circle.setOutlineThickness(m_config.player().shapeConfig.outlineThickness);

    playerCShape.circle.setPosition(sf::Vector2f(playerCTransform.pos.x, playerCTransform.pos.y));
}

void Scene::spawnEnemy()
{ 
    auto enemy = m_entities.addEntity("enemy");
    auto& enemyCShape = enemy->add<CShape>(sf::CircleShape{
        static_cast<float> (m_config.enemy().shapeConfig.shapeRadius),
        static_cast<std::size_t> (m_config.enemy().maxVerices)
    });

    auto& enemyCTransform = enemy->add<CTransform>(
        Vector2f {500.0f, 500.0f}, 
        Vector2f {11.3f, 3.5f}, 
        Vector2f {2.0f, 2.0f}, 
        30.0f
    );

    // Set up colors and border thickness
    enemyCShape.circle.setOutlineColor(sf::Color(
        m_config.enemy().shapeConfig.outlineColor[0],
        m_config.enemy().shapeConfig.outlineColor[1],
        m_config.enemy().shapeConfig.outlineColor[2]));
    enemyCShape.circle.setOutlineThickness(m_config.enemy().shapeConfig.outlineThickness);

}

void Scene::run()
{
    auto player = m_entities.addEntity("player");
    player->add<CTransform>(Vector2f {3.3f, 4.5f}, Vector2f {11.3f, 3.5f}, Vector2f {2.0f, 2.0f}, 30.0f);

    auto e = m_entities.addEntity("test");
    e->add<CTransform>(Vector2f {2.3f, 10.5f}, Vector2f {11.3f, 3.5f}, Vector2f {2.0f, 2.0f}, 30.0f);

    m_entities.update();

    for (auto e : m_entities.getEntities()) {
        std::cout << e->id() << " : " << e->tag() << std::endl;
    }

    std::cout << "Scene::run() : " << "m_window (" << &m_window << ")" << std::endl;
    sf::Clock deltaClock;

    float c[3] = {1.0f, 2.0f, 0.0f};

    float radius = 50.0f;
    int pointCount = 30;
    float circleSpeedX = 1.0f;
    float circleSpeedY = 0.5f;
    char displayString[255]  = "Sample Text";

    bool drawCircle = true;
    bool drawText = true;

    sf::Font font;

    std::cout << "Executable absolute path is " << std::filesystem::current_path() << std::endl;

    if (!font.openFromFile("resources/fonts/tech.ttf")) 
    {
        std::cerr << "Could not load font!\n";
        exit(-1);
    };

    sf::Text text(font, "Sample Text", 24);

    text.setFillColor(sf::Color::White);

    text.setPosition(sf::Vector2f(0, HEIGHT - (float) text.getCharacterSize()));

	sf::CircleShape circle(radius, pointCount);

	circle.setFillColor(sf::Color(std::uint8_t(c[0] * 255), std::uint8_t(c[1] * 255), std::uint8_t(c[2] * 255)));
    circle.setPosition(sf::Vector2f(10.0f, 10.0f));

    while (m_window.isOpen()) {
        while (const std::optional event = m_window.pollEvent()) {
            ImGui::SFML::ProcessEvent(m_window, *event);

            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }
        }

        ImGui::SFML::Update(m_window, deltaClock.restart());

        ImGui::Begin("Window title");
        ImGui::Text("Window text!");
        ImGui::Checkbox("Draw Circle", &drawCircle);
        ImGui::SameLine();
        ImGui::Checkbox("Draw Text", &drawText);
        ImGui::SliderFloat("Radius", &radius, 0.0f, 300.0f);
        ImGui::SliderInt("Sides", &pointCount, 3, 64);
        ImGui::ColorEdit3("Color Circle", c);
        ImGui::InputText("Text", displayString, 255);
        if (ImGui::Button("Set Text"))
            text.setString(displayString);
        ImGui::SameLine();
        if (ImGui::Button("Reset Circle"))
            circle.setPosition(sf::Vector2f(10.0f, 10.0f));

        ImGui::End();

        m_window.clear();

        circle.setPointCount(pointCount);
        circle.setRadius(radius);
        circle.setPosition(sf::Vector2f(circle.getPosition().x + circleSpeedX, circle.getPosition().y + circleSpeedY));
        circle.setFillColor(sf::Color(std::uint8_t(c[0] * 255), std::uint8_t(c[1] * 255), std::uint8_t(c[2] * 255)));

        if(drawCircle)
            m_window.draw(circle);

        if(drawText)
            m_window.draw(text);
        
        ImGui::SFML::Render(m_window);
        m_window.display();
    }
};
