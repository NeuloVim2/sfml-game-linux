#ifndef SCENE_LEVEL_H
#define SCENE_LEVEL_H
#include <string>

#include "Scene.h"

class ScenePlay : public Scene
{
private:
	std::string m_level{};

	void init();

	void sAnimation();
	void sMovement();
	void sEnemySpawner();
	void sCollision();
	void sDoAction(std::string action) override;
	void sRender() override;
	void sGUI();

public:
	void update() override;

	ScenePlay(GameEngine* ge)
		: Scene(ge)
	{ }
	ScenePlay() = default;
	~ScenePlay() = default;
};

#endif