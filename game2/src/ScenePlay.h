#ifndef SCENE_LEVEL_H
#define SCENE_LEVEL_H
#include <string>

#include "Scene.h"
#include "Action.hpp"

class ScenePlay : public Scene
{
private:
	std::string m_level{};

	void init();

	void sAnimation();
	void sMovement();
	void sEnemySpawner();
	void sCollision();
	void sRender() override;
	void sGUI();

public:
	void sDoAction(Action& action) override;
	void update() override;

	ScenePlay(GameEngine* ge)
		: Scene(ge)
	{ }
	ScenePlay() = default;
	~ScenePlay() = default;
};

#endif