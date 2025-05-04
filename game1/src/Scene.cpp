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
        Vector2f {static_cast<float>(m_config.window().width/ 2), static_cast<float>(m_config.window().height / 2)},
        Vector2f {11.3f, 3.5f}, 
        Vector2f {2.0f, 2.0f}, 
        0.0f
    );

    auto& playerCShape = player->add<CShape>(sf::CircleShape { 
        static_cast<float>(m_config.player().shapeConfig.shapeRadius), 
        static_cast<std::size_t>(m_config.player().shapeVertices)
    });

    player->add<CInput>();

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

    playerCShape.circle.setPosition(
        sf::Vector2f(
            playerCTransform.pos.x, 
            playerCTransform.pos.y)
    );
    playerCShape.circle.setOrigin(
        sf::Vector2f(
            playerCShape.circle.getRadius(), 
            playerCShape.circle.getRadius())
    );
}

void Scene::spawnEnemy()
{ 
    float diameter = 2 * m_config.enemy().shapeConfig.shapeRadius;
    float minX = diameter;
    float maxX = m_config.window().width - diameter;
    float minY = diameter;
    float maxY = m_config.window().height - diameter;
    float minVertices = m_config.enemy().minVerices;
    float maxVertices = m_config.enemy().maxVerices;

    //std::cout << "random number: " << rand() << std::endl;
    float randomX = minX + (rand() % (1 + (int)maxX - (int)minX));
    float randomY = minY + (rand() % (1 + (int)maxY - (int)minY));
    float randomPointCount = minVertices + (rand() % (1 + (int)maxVertices - (int)minVertices));

    std::cout << "random x: " << randomX << std::endl;
    std::cout << "random y: " << randomY << std::endl;

    auto enemy = m_entities.addEntity("enemy");
    auto& enemyCShape = enemy->add<CShape>(sf::CircleShape{
        static_cast<float> (m_config.enemy().shapeConfig.shapeRadius),
        static_cast<std::size_t> (m_config.enemy().maxVerices)
    });

    auto& enemyCTransform = enemy->add<CTransform>(
        Vector2f {static_cast<float>(randomX), static_cast<float>(randomY)},
        Vector2f {m_config.enemy().maxSpeed, m_config.enemy().maxSpeed},
        Vector2f {0.0f, 0.0f}, 
        0.0f
    );

    // Set up colors and border thickness
    enemyCShape.circle.setOutlineColor(sf::Color(
        m_config.enemy().shapeConfig.outlineColor[0],
        m_config.enemy().shapeConfig.outlineColor[1],
        m_config.enemy().shapeConfig.outlineColor[2]));
    enemyCShape.circle.setOutlineThickness(m_config.enemy().shapeConfig.outlineThickness);

    enemyCShape.circle.setPosition(sf::Vector2f(enemyCTransform.pos.x, enemyCTransform.pos.y));
    enemyCShape.circle.setPointCount(randomPointCount);
    enemyCShape.circle.setOrigin(sf::Vector2f(enemyCShape.circle.getRadius(), enemyCShape.circle.getRadius()));
}

void Scene::sMovement()
{
    for (auto e : m_entities.getEntitiesByTag("player"))
    {

        auto playerRadius = m_config.player().shapeConfig.shapeRadius;

        if (e->get<CInput>().up && e->get<CTransform>().pos.y - playerRadius > 0)
            e->get<CTransform>().pos.y = e->get<CTransform>().pos.y - m_config.player().speed;

        if (e->get<CInput>().down && m_config.window().height - (e->get<CTransform>().pos.y + playerRadius) >= 0)
            e->get<CTransform>().pos.y = e->get<CTransform>().pos.y + m_config.player().speed;

        if (e->get<CInput>().right && e->get<CTransform>().pos.x < (m_config.window().width - playerRadius))
            e->get<CTransform>().pos.x = e->get<CTransform>().pos.x + m_config.player().speed;

        if (e->get<CInput>().left && e->get<CTransform>().pos.x - playerRadius > 0)
            e->get<CTransform>().pos.x = e->get<CTransform>().pos.x - m_config.player().speed;

        e->get<CTransform>().angle += 0.01f;

        e->get<CShape>().circle.setRotation(sf::radians(e->get<CTransform>().angle));
		e->get<CShape>().circle.setPosition(
			sf::Vector2f(
				e->get<CTransform>().pos.x,
				e->get<CTransform>().pos.y
		));
    }

    for(auto e : m_entities.getEntities())
    {
        e->get<CShape>().circle.setPosition(
            sf::Vector2f(
				e->get<CTransform>().pos.x,
				e->get<CTransform>().pos.y
        ));
    }
}

void Scene::sUserInput()
{ 
    auto player = m_entities.getEntitiesByTag("player")[0];

	while (const std::optional event = m_window.pollEvent()) {
		//ImGui::SFML::ProcessEvent(m_window, *event);

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
            {
			    m_window.close();
            }
            if (keyPressed->scancode == sf::Keyboard::Scan::W)
            {
                player->get<CInput>().up = true;
                std::cout << player->get<CInput>().up << std::endl;
            }
            if (keyPressed->scancode == sf::Keyboard::Scan::S)
            {
                player->get<CInput>().down = true;
                std::cout << player->get<CInput>().down << std::endl;
            }

            if (keyPressed->scancode == sf::Keyboard::Scan::A)
            {
                player->get<CInput>().left = true;
                std::cout << player->get<CInput>().left << std::endl;
            }
            if (keyPressed->scancode == sf::Keyboard::Scan::D)
            {
                player->get<CInput>().right = true;
                std::cout << player->get<CInput>().right << std::endl;
            }
        }
        if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) 
        {
            if (keyReleased->scancode == sf::Keyboard::Scan::W)
            {
                player->get<CInput>().up = false;
                std::cout << player->get<CInput>().up << std::endl;
            }
            if (keyReleased->scancode == sf::Keyboard::Scan::S)
            {
                player->get<CInput>().down = false;
                std::cout << player->get<CInput>().down << std::endl;
            }
            if (keyReleased->scancode == sf::Keyboard::Scan::A)
            {
                player->get<CInput>().left = false;
                std::cout << player->get<CInput>().left << std::endl;
            }
            if (keyReleased->scancode == sf::Keyboard::Scan::D)
            {
                player->get<CInput>().right = false;
                std::cout << player->get<CInput>().right << std::endl;
            }

        }

		if (event->is<sf::Event::Closed>()) {
			m_window.close();
		}

	}
}

void Scene::sEnemySpawner(int& framePassed)
{
    if (framePassed >= 90)
    {
        spawnEnemy();
        framePassed = 0;
    }
}

void Scene::sRender(sf::Text& text)
{
    m_window.clear();

    for (auto e : m_entities.getEntities())
    {
        m_window.draw(e->get<CShape>().circle);
    }
    m_window.draw(text);

    //ImGui::SFML::Render(m_window);
    m_window.display();
}

void Scene::run()
{
  /*  auto player = m_entities.addEntity("player1");
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
    bool drawText = true;*/

    sf::Font font;

    std::cout << "Executable absolute path is " << std::filesystem::current_path() << std::endl;

    if (!font.openFromFile(m_config.font().fontFile)) 
    {
        std::cerr << "Could not load font!\n";
        exit(-1);
    };

   sf::Text text(font, "0", m_config.font().fontSize);

    text.setFillColor(sf::Color(m_config.font().rgb[0], m_config.font().rgb[1], m_config.font().rgb[2]));

    text.setPosition(sf::Vector2f(10.0f, 0.0f + (float)text.getCharacterSize()));

	//sf::CircleShape circle(radius, pointCount);

	//circle.setFillColor(sf::Color(std::uint8_t(c[0] * 255), std::uint8_t(c[1] * 255), std::uint8_t(c[2] * 255)));
 //   circle.setPosition(sf::Vector2f(10.0f, 10.0f));

    spawnPlayer();

    int framePassed{};

    sf::Clock clock;

    srand(time(NULL));
    while (m_window.isOpen()) {
        text.setString(std::to_string((int)(1.0f / clock.restart().asSeconds())));
     /*   ImGui::SFML::Update(m_window, deltaClock.restart());

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
            circle.setPosition(sf::Vector2f(10.0f, 10.0f));*/

        //ImGui::End();

        m_entities.update();
        sUserInput();
        sMovement();
        sEnemySpawner(framePassed);
        sRender(text);

        ++framePassed;
     }
};
