#include "pch.h"
#include "Scenes.h"
#include "GUI.h"
#include "MenuScene.h"

Scenes::Scenes(sf::RenderWindow* _target, std::map<std::string, int>* _supportKeys, std::stack<Scenes*>* _scenes, std::stack<LuaReader*>* _luaStack)
{
	_window = _target;
	supportKeys = _supportKeys;
	scenes = _scenes;
	luaStack = _luaStack;
	quitScene = false;
}

Scenes::~Scenes()
{

}

void Scenes::EndState()
{
	quitScene = true;
}

void Scenes::StartLua()
{

}

void Scenes::LuaUpdate()
{
	luaReading->Update();
}

void Scenes::LuaRender()
{
	luaReading->Render();
}

void Scenes::UpdateMousePos()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*_window);
	mousePosView = _window->mapPixelToCoords(mousePosWindow);
}

const bool Scenes::GetQuitScene()
{
	return quitScene;
}
