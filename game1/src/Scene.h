#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>
#include <cstdint>
#include <iostream>

#include <SFML/Graphics/Text.hpp>

#include "typedefs.h"
#include "Components.hpp"
#include "EntityManager.h"
#include "ConfigParser.h"


class Scene {
public:
	enum Type {
		main_menu,
		level_one,
	};

private:
	Type m_sceneType{};
	sf::RenderWindow& m_window;
	EntityManager& m_entities;
	ConfigParser& m_config;
	int m_spawnRate;

	bool m_paused{ false };
	bool m_running { false };

	bool m_movementSystemEnabled{ true };
	bool m_bulletMovementEnabled{ true };
	bool m_inputSystemEnabled{ true };
	bool m_colisionSystemEnabled{ true };
	bool m_enemySpawnerSystemEnabled{ true };
	bool m_bulletSpawnerSystemEnabled{ true };
	bool m_GUISystemEnabled{ true };
	bool m_renderSystemEnabled{ true };

	void spawnPlayer();
	void spawnEnemy();
	void spawnBullet();
	void displayEntityInfoOnGui(const std::shared_ptr<Entity> e);

	void sMovement();
	void sUserInput();
	void sEnemySpawner(int& framePassed);
	void sBulletSpawner();
	void sLifespan();
	void sCollision();
	void sGUI();
	void sRender(sf::Text&);

public:
	Scene(Type sceneType, sf::RenderWindow& window, EntityManager& eM, ConfigParser& config)
		: m_sceneType{ sceneType }
		, m_window { window }
		, m_entities { eM }
		, m_config { config }
	{
		std::cout << "Scene constructor is called" << std::endl;

		std::cout << "window address " << &window << std::endl;
		std::cout << "m_window address " << &m_window << std::endl;
	};

	Scene() = default;
	~Scene() 
	{
		std::cout << "Scene destructor is called" << std::endl;
	};

	void setUp();

	void run();

};

#endif
