#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include <unordered_map>
#include <vector>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>

#include "GameEngine.h"
#include "Action.hpp"
#include "Entity.h"

class SceneMenu : public Scene
{
private:
	sf::Clock m_clock;
  sf::Color m_background {121, 206, 255};
  sf::Font m_font;

  const sf::Color m_optionSelectedColor = sf::Color::Black;
  const sf::Color m_optionColor = sf::Color::White;

  EntityManager m_entities;
  std::shared_ptr<Entity> m_currentOption;
  

	void init();
	void displayEntityInfoOnGui(const std::shared_ptr<Entity> entity);
  void addMenuOption(const std::string msg, const Vector2f& pos, bool select, int prev, int next);

	void sRender() override;
  void sSelect();
	void sGUI(sf::Clock& clock);

public:
	void spawnPlayer();
	void update() override;
	void sDoAction(Action& action) override;

	// constructors
	SceneMenu(GameEngine* ge)
		: Scene(ge)
	{
		init();
	};

	SceneMenu() = default;
	~SceneMenu() = default;
};

#endif
