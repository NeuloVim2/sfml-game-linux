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
#include "Components.hpp"

void Scene::setUp()
{
}

void Scene::run()
{
    std::vector<Entity> entityes;

    Entity ent1;
    ent1.add<CPosition>(1.0f, 30.0f);
    entityes.push_back(ent1);
    for (auto& e : entityes)
    {
        if(e.has<CPosition>())
            std::cout << "For enity " << e.tag() << " -> Position x: " << e.get<CPosition>().x << std::endl;
    };

    std::cout << "Scene::run() : " << "m_window (" << m_window.get() << ")" << std::endl;
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

    if (!font.openFromFile("../../resources/fonts/tech.ttf")) 
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

    while (m_window->isOpen()) {
        while (const std::optional event = m_window->pollEvent()) {
            ImGui::SFML::ProcessEvent(*m_window, *event);

            if (event->is<sf::Event::Closed>()) {
                m_window->close();
            }
        }

        ImGui::SFML::Update(*m_window, deltaClock.restart());

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

        m_window->clear();

        circle.setPointCount(pointCount);
        circle.setRadius(radius);
        circle.setPosition(sf::Vector2f(circle.getPosition().x + circleSpeedX, circle.getPosition().y + circleSpeedY));
        circle.setFillColor(sf::Color(std::uint8_t(c[0] * 255), std::uint8_t(c[1] * 255), std::uint8_t(c[2] * 255)));

        if(drawCircle)
            m_window->draw(circle);

        if(drawText)
            m_window->draw(text);
        
        ImGui::SFML::Render(*m_window);
        m_window->display();
    }
};
