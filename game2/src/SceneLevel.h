#ifndef SCENE_LEVEL_H
#define SCENE_LEVEL_H
#include <string>

#include "Scene.h"

class SceneLevel : public Scene
{
private:
	void init();

public:
	void update() override;
	void sDoAction(std::string action) override;
	void sRender() override;

	SceneLevel(GameEngine* ge)
		: Scene(ge)
	{ }
	SceneLevel() = default;
	~SceneLevel() = default;
};

#endif