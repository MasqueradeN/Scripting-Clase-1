#pragma once
#include "LuaReader.h"
class Scenes
{
private:


protected:
	std::map<std::string, int>* supportKeys;
	std::map<std::string, int> newKeys;

	std::stack<Scenes*>* scenes;
	std::stack<LuaReader*>* luaStack;
	LuaReader* luaReading;

	sf::RenderWindow* _window;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2u mousePosGrid;

	bool quitScene;
	bool isPaused;
	float dts;
	virtual void InitKeys() = 0;

public:
	Scenes(sf::RenderWindow* _target, std::map<std::string, int>* _supportKeys, std::stack<Scenes*>* _scenes, std::stack<LuaReader*>* _luaStack);
	virtual ~Scenes();
	virtual void EndState();
	virtual void StartLua();
	virtual void LuaUpdate();
	virtual void LuaRender();
	virtual void Update(const float&  dt) = 0;
	virtual void Render(sf::RenderTarget* _target) = 0;

	virtual void UpdateMousePos();
	const bool GetQuitScene();
};

