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

Scene::Scene(GameEngine* ge)
	:m_gameEngine{ge}
{
}

void Scene::simulate(int)
{
}