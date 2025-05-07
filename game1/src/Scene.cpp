#include <filesystem>
#include <vector>
#include <string>
#include <cmath>

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

    float randomX = minX + (rand() % (1 + (int)maxX - (int)minX));
    float randomY = minY + (rand() % (1 + (int)maxY - (int)minY));
    float randomPointCount = minVertices + (rand() % (1 + (int)maxVertices - (int)minVertices));

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

    float randomRedMax = m_config.enemy().shapeConfig.outlineColor[0];
    float randomGreenMax = m_config.enemy().shapeConfig.outlineColor[1];
    float randomBlueMax = m_config.enemy().shapeConfig.outlineColor[2];

    auto randomRed = 0 + (rand() % (1 + (int)randomRedMax - 0)); 
    auto randomGreen = 0 + (rand() % (1 + (int)randomGreenMax - 0)); 
    auto randomBlue = 0 + (rand() % (1 + (int)randomBlueMax - 0)); 

    enemyCShape.circle.setFillColor(sf::Color(randomRed,
        randomGreen,
        randomBlue));

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

void Scene::spawnBullet()
{
    auto bullet = m_entities.addEntity("bullet");
    auto& bulletCShape = bullet->add<CShape>(sf::CircleShape{
        static_cast<float> (m_config.bullet().shapeConfig.shapeRadius),
        static_cast<std::size_t> (m_config.bullet().shapeVertices)
    });

    auto& playerPos = m_entities.getEntitiesByTag("player")[0]->get<CTransform>().pos;
    auto& bulletCTransform = bullet->add<CTransform>(
        Vector2f{ playerPos.x, playerPos.y },
        Vector2f{ m_config.bullet().speed, m_config.bullet().speed },
        Vector2f{ 0.0f, 0.0f },
        0.0f);

    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    Vector2f differanceVector = Vector2f(
        (float)mousePos.x - playerPos.x, 
        (float)mousePos.y - playerPos.y);

    float differanceVectorLength = sqrt((differanceVector.x * differanceVector.x) + (differanceVector.y * differanceVector.y));
    Vector2f normilizedDifferanceVector { differanceVector.x / differanceVectorLength, differanceVector.y / differanceVectorLength };

    bulletCTransform.vel = Vector2f(normilizedDifferanceVector.x * m_config.bullet().speed, normilizedDifferanceVector.y * m_config.bullet().speed);
    bulletCTransform.pos += bulletCTransform.vel;

    bulletCShape.circle.setPosition(bulletCTransform.pos);
    bulletCShape.circle.setOutlineColor(sf::Color(
        m_config.bullet().shapeConfig.outlineColor[0],
        m_config.bullet().shapeConfig.outlineColor[1],
        m_config.bullet().shapeConfig.outlineColor[2]));
    bulletCShape.circle.setFillColor(sf::Color(
        m_config.bullet().shapeConfig.fillColor[0],
        m_config.bullet().shapeConfig.fillColor[1],
        m_config.bullet().shapeConfig.fillColor[2]));
    bulletCShape.circle.setOutlineThickness(m_config.bullet().shapeConfig.outlineThickness);
    bulletCShape.circle.setPointCount(m_config.bullet().shapeVertices);
}


void Scene::sMovement()
{
    if (m_entities.getEntitiesByTag("player").size() > 0)
    {
        for (auto e : m_entities.getEntitiesByTag("player"))
        {
            auto playerRadius = m_config.player().shapeConfig.shapeRadius;

            if (e->get<CInput>().up && e->get<CTransform>().pos.y - playerRadius > 0)
                //e->get<CTransform>().pos.y = e->get<CTransform>().pos.y - m_config.player().speed;
                e->get<CTransform>().vel -= Vector2f{ 0.0f, 1.0f };

            if (e->get<CInput>().down && m_config.window().height - (e->get<CTransform>().pos.y + playerRadius) >= 0)
                //e->get<CTransform>().pos.y = e->get<CTransform>().pos.y + m_config.player().speed;
                e->get<CTransform>().vel += Vector2f{ 0.0f, 1.0f };

            if (e->get<CInput>().right && e->get<CTransform>().pos.x < (m_config.window().width - playerRadius))
                //e->get<CTransform>().pos.x = e->get<CTransform>().pos.x + m_config.player().speed;
                e->get<CTransform>().vel += Vector2f{ 1.0f, 0.0f };

            if (e->get<CInput>().left && e->get<CTransform>().pos.x - playerRadius > 0)
                //e->get<CTransform>().pos.x = e->get<CTransform>().pos.x - m_config.player().speed;
                e->get<CTransform>().vel -= Vector2f{ 1.0f, 0.0f };


            // calcualate velocity vector x and y when moving at 45(W-D, W-A, etc.) angle
            // cos(45) and sin(45) are 0.70710678118
            float finalSpeed = m_config.player().speed;
            if (e->get<CTransform>().vel.x != 0 && e->get<CTransform>().vel.y)
                finalSpeed = m_config.player().speed * 0.70710678118;

            e->get<CTransform>().pos += e->get<CTransform>().vel * finalSpeed;
            e->get<CShape>().circle.setPosition(e->get<CTransform>().pos);

            e->get<CTransform>().angle += 0.01f;
            e->get<CShape>().circle.setRotation(sf::radians(e->get<CTransform>().angle));

            // reset velocity
            e->get<CTransform>().vel = Vector2f(0.0f, 0.0f);
        }
    }
    for(auto e : m_entities.getEntitiesByTag("bullet"))
    {
        e->get<CTransform>().pos += e->get<CTransform>().vel;
        e->get<CShape>().circle.setPosition(
				e->get<CTransform>().pos
        );
    }
}

void Scene::sUserInput()
{ 
    std::shared_ptr<Entity> player = nullptr;
    if(m_entities.getEntitiesByTag("player").size() > 0)
        player = m_entities.getEntitiesByTag("player")[0];

	while (const std::optional event = m_window.pollEvent()) {
		ImGui::SFML::ProcessEvent(m_window, *event);
        auto& io = ImGui::GetIO();

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (io.WantCaptureKeyboard) 
                return;

            if (keyPressed->scancode == sf::Keyboard::Scan::Escape)
			    m_window.close();
            if (player != nullptr)
            {
                if (keyPressed->scancode == sf::Keyboard::Scan::W)
                    player->get<CInput>().up = true;
                if (keyPressed->scancode == sf::Keyboard::Scan::S)
                    player->get<CInput>().down = true;
                if (keyPressed->scancode == sf::Keyboard::Scan::A)
                    player->get<CInput>().left = true;
                if (keyPressed->scancode == sf::Keyboard::Scan::D)
                    player->get<CInput>().right = true;
            }
        }
        if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) 
        {
            if (player != nullptr)
            {
                if (keyReleased->scancode == sf::Keyboard::Scan::W)
                    player->get<CInput>().up = false;
                if (keyReleased->scancode == sf::Keyboard::Scan::S)
                    player->get<CInput>().down = false;
                if (keyReleased->scancode == sf::Keyboard::Scan::A)
                    player->get<CInput>().left = false;
                if (keyReleased->scancode == sf::Keyboard::Scan::D)
                    player->get<CInput>().right = false;
            }

        }
        if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
        {
            if (io.WantCaptureMouse)
                return;

            if (player != nullptr)
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    player->get<CInput>().shoot = true;
                }
            }
        }
        if (const auto* mouseButtonReleased = event->getIf<sf::Event::MouseButtonReleased>())
        {
            if (player != nullptr)
            {
                if (mouseButtonReleased->button == sf::Mouse::Button::Left)
                {
                    player->get<CInput>().shoot = false;
                }
            }
        }
		if (event->is<sf::Event::Closed>()) {
			m_window.close();
		}

	}
}

void Scene::sEnemySpawner(int& framePassed)
{
    if (framePassed == m_spawnRate)
    {
        spawnEnemy();
        framePassed = 0;
    }
}

void Scene::sBulletSpawner()
{
    std::shared_ptr<Entity> player = nullptr;
    if (m_entities.getEntitiesByTag("player").size() > 0)
    {
	    player = m_entities.getEntitiesByTag("player")[0];
		if (player->get<CInput>().shoot)
			spawnBullet();
        player->get<CInput>().shoot = false;
    }
}

void Scene::displayEntityInfoOnGui(const std::shared_ptr<Entity> e)
{
    float c[3]{
		 e->get<CShape>().circle.getFillColor().r / (float)255,
		 e->get<CShape>().circle.getFillColor().g / (float)255,
		 e->get<CShape>().circle.getFillColor().b / (float)255
    };

    ImGui::PushID(e->id());
    ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(c[0], c[1], c[2]));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(c[0], c[1] - 0.1, c[2] + 0.01));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(c[0], c[1], c[2]));
    if (ImGui::Button("D"))
        e->destroy();
	ImGui::PopStyleColor(3);
	ImGui::PopID();
	ImGui::SameLine();
	ImGui::Text(std::to_string(e->id()).c_str());
	ImGui::SameLine();
	ImGui::Text(e->tag().c_str());
	ImGui::SameLine();
	ImGui::Text(("( " + std::to_string(e->get<CTransform>().pos.x) + " " + std::to_string(e->get<CTransform>().pos.y) + " )").c_str());
}


void Scene::sGUI()
{
	ImGui::Begin("Geometry Wars GUI");
	ImGui::Text("Geometry Wars");
    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
    if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
    {
        if (ImGui::BeginTabItem("Systems"))
        {
            ImGui::Checkbox("On/Off Movement System", &m_movementSystemEnabled);
            ImGui::Checkbox("On/Off Colision System", &m_colisionSystemEnabled);

            ImGui::Checkbox("On/Off Enymy Spawn System", &m_enemySpawnerSystemEnabled);
            ImGui::SliderInt("Enemy spawn rate", &m_spawnRate, 0, 220);
            if(ImGui::Button("Manual Spawn"))
            {
                spawnEnemy();
            };

            ImGui::Checkbox("On/Off Bullet Spawn System", &m_bulletSpawnerSystemEnabled);
            ImGui::Checkbox("On/Off Render System", &m_renderSystemEnabled);
            ImGui::Checkbox("On/Off GUI", &m_GUISystemEnabled);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Entites"))
        {
            if (ImGui::CollapsingHeader("player"))
            {
                if(m_entities.getEntitiesByTag("player").size() != 0)
					for (auto e : m_entities.getEntitiesByTag("player"))
					{
						if(e != nullptr)
							displayEntityInfoOnGui(e);
					}
            }
            if (ImGui::CollapsingHeader("enemy"))
            {
                for (auto e : m_entities.getEntitiesByTag("enemy"))
                {
                    displayEntityInfoOnGui(e);
                }
            }
            if (ImGui::CollapsingHeader("bullet"))
            {
                for (auto e : m_entities.getEntitiesByTag("bullet"))
                {
                    displayEntityInfoOnGui(e);
                }
            }
            if (ImGui::CollapsingHeader("all entites"))
            {
                for (auto e : m_entities.getEntities())
                {
                    displayEntityInfoOnGui(e);
                }
            }

		    ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
	//ImGui::Checkbox("Draw Circle", &drawCircle);
	//ImGui::SameLine();
	//ImGui::Checkbox("Draw Text", &drawText);
	//ImGui::SliderFloat("Radius", &radius, 0.0f, 300.0f);
	//ImGui::SliderInt("Sides", &pointCount, 3, 64);
	//ImGui::ColorEdit3("Color Circle", c);
	//ImGui::InputText("Text", displayString, 255);
	//if (ImGui::Button("Set Text"))
	//text.setString(displayString);
	//ImGui::SameLine();
	//if (ImGui::Button("Reset Circle"))

    ImGui::End();
}

void Scene::sRender(sf::Text& text)
{
    m_window.clear();

    if (m_renderSystemEnabled)
    {
        for (auto e : m_entities.getEntities())
        {
            m_window.draw(e->get<CShape>().circle);
        }
        m_window.draw(text);
    }

    ImGui::SFML::Render(m_window);
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
    m_spawnRate = m_config.enemy().smallInterval;

    sf::Clock clock;
    sf::Clock deltaClock;

    srand(time(NULL));
    while (m_window.isOpen()) {
        text.setString(std::to_string((int)(1.0f / clock.restart().asSeconds())));
        ImGui::SFML::Update(m_window, deltaClock.restart());

        m_entities.update();
        if(m_inputSystemEnabled)
            sUserInput();
        if(m_bulletSpawnerSystemEnabled)
            sBulletSpawner();
        if(m_movementSystemEnabled)
            sMovement();
        if(m_enemySpawnerSystemEnabled)
            sEnemySpawner(framePassed);
        if(m_GUISystemEnabled)
            sGUI();

        sRender(text);

        ++framePassed;
     }
};
