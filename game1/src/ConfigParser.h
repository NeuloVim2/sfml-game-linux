#pragma once
#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include<string>
#include<fstream>

class ConfigParser
{
public:
	struct Window {
		int  width{};
		int  height{};
		int  frameLimit{};
		int fullScreen{ 0 };
	};

	struct Font {
		std::string fontFile{};
		int fontSize{};
		int rgb[3] {};
	};

	struct ShapeConfing 
	{
		int shapeRadius{};
		int collisionRadius{};
		int outlineColor[3]{};
		int outlineThickness{};
		int fillColor[3]{};
	};

	struct Player
	{
		ShapeConfing shapeConfig{};
		float speed{};
		int shapeVertices{};
	};

	struct Enemy 
	{
		ShapeConfing shapeConfig{};
		float minSpeed{};
		float maxSpeed{};
		int minVerices{};
		int maxVerices{};
		int smallLifespan{};
		int smallInterval{};
	};

	struct Bullet 
	{
		ShapeConfing shapeConfig{};
		float speed{};
		int shapeVertices{};
		int lifespan {};
	};

private:
	std::ifstream m_configFile{};

	Window m_window{};
	Font m_font{};
	Player m_player{};
	Enemy m_enemy{};
	Bullet m_bullet{};
	
public:
	ConfigParser() = default;
	~ConfigParser()
	{
		if (m_configFile.is_open())
			m_configFile.close();
	};

	void parse(const std::string& path);
	const Window& window() const;
	const Font& font() const;
	const Player& player() const;
	const Enemy& enemy() const;
	const Bullet& bullet() const;
};

#endif