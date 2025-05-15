#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include <unordered_map>

#include <SFML/Window/Event.hpp>

#include "GameEngine.h"
#include "Action.hpp"

class SceneMenu : public Scene
{
private:
	sf::Clock m_clock;

	void init();
	void displayEntityInfoOnGui(const std::shared_ptr<Entity> entity);

	void sRender() override;
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