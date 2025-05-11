#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include <unordered_map>

#include <SFML/Window/Event.hpp>

#include "GameEngine.h"
#include "Action.hpp"

class SceneMenu : public Scene
{
private:
	void init();

	void sRender() override;
public:
	void update() override;
	void sDoAction(Action& action) override;

	// constructors
	SceneMenu(GameEngine* ge)
		: Scene(ge)
	{};

	SceneMenu() = default;
	~SceneMenu() = default;
};

#endif