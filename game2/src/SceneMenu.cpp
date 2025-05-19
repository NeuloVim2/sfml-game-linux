#include <imgui.h>
#include <imgui-SFML.h>

#include "SceneMenu.h"

void SceneMenu::sDoAction(Action& action)
{
	if (action.phase() == Action::Phase::START)
		switch (action.name())
		{
			case Action::Name::UP:
				std::cout << "UP actoin started" << std::endl;
				break;
			case Action::Name::DOWN:
				std::cout << "DOWN actoin started" << std::endl;
				break;
			case Action::Name::QUIT:
				std::cout << "QUIT actoin started" << std::endl;
                m_gameEngine->window().close();
				break;
		};

	if (action.phase() == Action::Phase::END)
		switch (action.name())
		{
			case Action::Name::UP:
				std::cout << "UP actoin ended" << std::endl;
				break;
			case Action::Name::DOWN:
				std::cout << "DOWN actoin ended" << std::endl;
				break;
		};
}

void SceneMenu::sRender()
{
	m_gameEngine->window().clear(m_background);

	for (auto e : m_entities.getEntities())
	{
		e->get<CTransform>().angle += 0.04f;
		e->get<CShape>().circle.setRotation(sf::radians(e->get<CTransform>().angle));

		m_gameEngine->window().draw(e->get<CShape>().circle);
	}

  for(auto e : m_entities.getEntitiesByTag("menu_option"))
  {
	  m_gameEngine->window().draw(e->get<CText>().text);
  }

    ImGui::SFML::Render(m_gameEngine->window());
    m_gameEngine->window().display();
}

void SceneMenu::sGUI(sf::Clock& clock)
{
    ImGui::Begin("Geometry Wars GUI");
    ImGui::Text("Geometry Wars");
    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
//     if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
//     {
//         if (ImGui::BeginTabItem("Systems"))
//         {
// "
//             ImGui::SeparatorText("Movement systems");
//             ImGui::Checkbox("On/Off Movement System for ALL", &m_movementSystemEnabled);
//             ImGui::Checkbox("On/Off Movement System for BULLETS", &m_bulletMovementEnabled);
//
//             ImGui::SeparatorText("Other");
//             ImGui::Checkbox("On/Off Colision System", &m_colisionSystemEnabled);
//
//             ImGui::Checkbox("On/Off Enymy Spawn System", &m_enemySpawnerSystemEnabled);
//             ImGui::SliderInt("Enemy spawn rate", &m_spawnRate, 0, 220);
//             if (ImGui::Button("Manual Spawn"))
//             {
//                 spawnEnemy();
//             };
//
//             ImGui::Checkbox("On/Off Bullet Spawn System", &m_bulletSpawnerSystemEnabled);
//             ImGui::Checkbox("On/Off Render System", &m_renderSystemEnabled);
//             ImGui::Checkbox("On/Off GUI", &m_GUISystemEnabled);
//             ImGui::EndTabItem();
//         }
//         if (ImGui::BeginTabItem("Entites"))
//         {
//             if (ImGui::CollapsingHeader("player"))
//             {
//                 if (m_entities.getEntitiesByTag("player").size() != 0)
//                     for (auto e : m_entities.getEntitiesByTag("player"))
//                     {
//                         if (e != nullptr)
//                             displayEntityInfoOnGui(e);
//                     }
//             }
//             if (ImGui::CollapsingHeader("enemy"))
//             {
//                 for (auto e : m_entities.getEntitiesByTag("enemy"))
//                 {
//                     displayEntityInfoOnGui(e);
//                 }
//             }
//             if (ImGui::CollapsingHeader("enemy_fragment"))
//             {
//                 for (auto e : m_entities.getEntitiesByTag("enemy_fragment"))
//                 {
//                     displayEntityInfoOnGui(e);
//                 }
//             }
//             if (ImGui::CollapsingHeader("bullet"))
//             {
//                 for (auto e : m_entities.getEntitiesByTag("bullet"))
//                 {
//                     displayEntityInfoOnGui(e);
//                 }
//             }
//             if (ImGui::CollapsingHeader("special_bullet"))
//             {
//                 for (auto e : m_entities.getEntitiesByTag("special_bullet"))
//                 {
//                     displayEntityInfoOnGui(e);
//                 }
//             }
//
//
//             if (ImGui::CollapsingHeader("all entites"))
//             {
//                 for (auto e : m_entities.getEntities())
//                 {
//                     displayEntityInfoOnGui(e);
//                 }
//             }
//
//             ImGui::EndTabItem();
//         }
//         ImGui::EndTabBar();
//     }

    ImGui::End();
}

void SceneMenu::displayEntityInfoOnGui(const std::shared_ptr<Entity> e)
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

void SceneMenu::spawnPlayer()
{
	auto player = m_entities.addEntity("player");
	auto& playerCTransform = player->add<CTransform>(
		Vector2f{ static_cast<float>(m_gameEngine->config().window().width / 2), static_cast<float>(m_gameEngine->config().window().height / 2)},
		Vector2f{ 0.0f, 0.0f },
		Vector2f{ 2.0f, 2.0f },
		0.0f
	);
  auto& playerCShape = player->add<CShape>(sf::CircleShape { 
    static_cast<float>(m_gameEngine->config().player().shapeConfig.shapeRadius), 
    static_cast<std::size_t>(m_gameEngine->config().player().shapeVertices)
  });

  playerCShape.circle.setFillColor(sf::Color(200, 100, 123));
  playerCShape.circle.setOrigin(Vector2f{playerCShape.circle.getRadius(), playerCShape.circle.getRadius()});

  playerCShape.circle.setPosition(playerCTransform.pos);
}

void SceneMenu::addMenuOption(const std::string msg, const Vector2f& pos)
{
    auto menuOption = m_entities.addEntity("menu_option");
    auto& textC = menuOption->add<CText>(
        m_font,
        msg,
        static_cast<unsigned int>(100)
    );

    textC.text.setFillColor(sf::Color::White);

    auto& transformC = menuOption->add<CTransform>(
        pos,
        Vector2f{ 0.0f, 0.0f },
        Vector2f{ 0.0f, 0.0f },
        0.0f
  ); 

  textC.text.setPosition(sf::Vector2f(pos.x, pos.y));
};

void SceneMenu::init()
{
    registerKeyboardAction(sf::Keyboard::Scan::W, Action::UP);
    registerKeyboardAction(sf::Keyboard::Scan::S, Action::DOWN);
    registerKeyboardAction(sf::Keyboard::Scan::Enter, Action::PLAY);
    registerKeyboardAction(sf::Keyboard::Scan::Escape, Action::QUIT);


    std::cout << "Executable absolute path is " << std::filesystem::current_path() << std::endl;

    if (!m_font.openFromFile(m_gameEngine->config().font().fontFile)) 
    {
        std::cerr << "Could not load font!\n";
        exit(-1);
    };


    addMenuOption("LEVEL 1", Vector2f{100.0f, 100.0f});
    addMenuOption("QUIT", Vector2f{100.0f, 200.0f});
    // spawnPlayer();
}

void SceneMenu::update()
{
    ImGui::SFML::Update(m_gameEngine->window(), m_clock.restart());

	m_entities.update();
    sGUI(m_clock);
	sRender();
}
