#include <fstream>
#include <iostream>

#include "ConfigParser.h"

void ConfigParser::parse(const std::string& path)
{
	m_configFile.open(path);

	if (!m_configFile.is_open())
	{
		std::cerr << "Could not load config!\n";
		exit(-1);
	}


	std::string token{};

	while (m_configFile >> token)
	{
		if (token == "Window") 
		{
			m_configFile >> m_window.width;
			m_configFile >> m_window.height;
			m_configFile >> m_window.frameLimit;
			m_configFile >> m_window.fullScreen;
		}

		if (token == "Font") 
		{
			m_configFile >> m_font.fontFile;
			m_configFile >> m_font.fontSize;
			m_configFile >> m_font.rgb[0];
			m_configFile >> m_font.rgb[1];
			m_configFile >> m_font.rgb[2];
		}

		if (token == "Player") 
		{
			m_configFile >> m_player.shapeConfig.shapeRadius;
			m_configFile >> m_player.shapeConfig.collisionRadius;
			m_configFile >> m_player.speed;

			m_configFile >> m_player.shapeConfig.fillColor[0];
			m_configFile >> m_player.shapeConfig.fillColor[1];
			m_configFile >> m_player.shapeConfig.fillColor[2];

			m_configFile >> m_player.shapeConfig.outlineColor[0];
			m_configFile >> m_player.shapeConfig.outlineColor[1];
			m_configFile >> m_player.shapeConfig.outlineColor[2];

			m_configFile >> m_player.shapeConfig.outlineThickness;
			m_configFile >> m_player.shapeVertices;
		}

		if (token == "Enemy") 
		{
			m_configFile >> m_enemy.shapeConfig.shapeRadius;
			m_configFile >> m_enemy.shapeConfig.collisionRadius;
			m_configFile >> m_enemy.minSpeed;
			m_configFile >> m_enemy.maxSpeed;
			m_configFile >> m_enemy.shapeConfig.outlineColor[0];
			m_configFile >> m_enemy.shapeConfig.outlineColor[1];
			m_configFile >> m_enemy.shapeConfig.outlineColor[2];
			m_configFile >> m_enemy.shapeConfig.outlineThickness;
			m_configFile >> m_enemy.minVerices;
			m_configFile >> m_enemy.maxVerices;
			m_configFile >> m_enemy.smallLifespan;
			m_configFile >> m_enemy.smallInterval;
		}

		if (token == "Bullet")
		{
			m_configFile >> m_bullet.shapeConfig.shapeRadius;
			m_configFile >> m_bullet.shapeConfig.collisionRadius;
			m_configFile >> m_bullet.speed;
			m_configFile >> m_bullet.shapeConfig.fillColor[0];
			m_configFile >> m_bullet.shapeConfig.fillColor[1];
			m_configFile >> m_bullet.shapeConfig.fillColor[2];
			m_configFile >> m_bullet.shapeConfig.outlineColor[0];
			m_configFile >> m_bullet.shapeConfig.outlineColor[1];
			m_configFile >> m_bullet.shapeConfig.outlineColor[2];
			m_configFile >> m_bullet.shapeConfig.outlineThickness;
			m_configFile >> m_bullet.shapeVertices;
			m_configFile >> m_bullet.lifespan;
		}
	}
	std::cout << "some text " << std::endl;
}

const ConfigParser::Window& ConfigParser::window() const
{
	return m_window;
}

const ConfigParser::Font& ConfigParser::font() const
{
	return m_font;
}

const ConfigParser::Player& ConfigParser::player() const
{
	return m_player;
}

const ConfigParser::Enemy& ConfigParser::enemy() const
{
	return m_enemy;
}

const ConfigParser::Bullet& ConfigParser::bullet() const
{
	return m_bullet;
}
