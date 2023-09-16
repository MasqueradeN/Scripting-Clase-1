#pragma once
#include "MenuScene.h"
//#include "LuaReader.h"
#include "Player.h"

class Scene;
class GameEngine
{
private:
	sf::RenderWindow* _window;
	sf::VideoMode _video;
	sf::Event _event;
	sf::Clock deltaClock;
	std::string _header;
	std::stack<Scenes*> scenes;
	std::map<std::string, int> supportedKeys;
	
	bool fullScreen;
	float deltaTime;


	std::stack<LuaReader*> luaStack;
	Scenes* game;

	void InitWindow();
	void InitKeys();
	void InitScene();

public:
	GameEngine();
	~GameEngine();

	const bool GetWindowOpen() const;

	void Update();
	void UpdateDeltaTime();
	void Render();


};

