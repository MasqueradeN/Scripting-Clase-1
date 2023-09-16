#include "pch.h"
#include "GameEngine.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "Player.h"

void GameEngine::InitWindow()
{
	_window = nullptr;
	_video = sf::VideoMode::getDesktopMode();
	_header = "Le vidiogeim window";
	fullScreen = false;

	if (fullScreen)
	{
		_window = new sf::RenderWindow(_video, _header);
	}
	else
	{
		_window = new sf::RenderWindow(_video, _header, sf::Style::Titlebar | sf::Style::Close);
	}

	_window->setFramerateLimit(60);
}

void GameEngine::InitKeys()
{
	supportedKeys["W"] = 22;
	supportedKeys["A"] = 0;
	supportedKeys["S"] = 18;
	supportedKeys["D"] = 3;
	supportedKeys["F"] = 16;
	supportedKeys["Escape"] = 36;
}

void GameEngine::InitScene()
{
	//game = new GameScene(_window, &supportedKeys);
	scenes.push(new MenuScene(_window, &supportedKeys, &scenes, &luaStack));
}

GameEngine::GameEngine()
{
	this->InitWindow();
	this->InitKeys();
	this->InitScene();
}

GameEngine::~GameEngine()
{

}

const bool GameEngine::GetWindowOpen() const
{
	return _window->isOpen();
}

void GameEngine::Update()
{
	//luatest->Update();

	if (!scenes.empty())
	{
		scenes.top()->Update(deltaTime);
		if (scenes.top()->GetQuitScene())
		{
			scenes.top()->EndState();
			delete scenes.top();
			scenes.pop();


			delete luaStack.top();
			luaStack.pop();
		}
	}
	else
	{
		_window->close();
	}
}

void GameEngine::UpdateDeltaTime()
{
	deltaTime = deltaClock.restart().asSeconds();
}

void GameEngine::Render()
{
	_window->clear();
	if (!scenes.empty())
	{
		scenes.top()->Render(_window);
	}
	_window->display();
}
