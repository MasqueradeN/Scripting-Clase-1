#include "pch.h"
#include "GameScene.h"
#include "MenuScene.h"

void GameScene::InitButton()
{
	buttons["Pause"] = new GUI::Button(650, 350, 152, 52, &_font, "Pause", 20, sf::Color::Black, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, sf::Color::White, sf::Color::Black);
	buttons["Settings"] = new GUI::Button(650, 450, 152, 52, &_font, "Settings", 20, sf::Color::Black, sf::Color::Black, sf::Color::Cyan, sf::Color::Green, sf::Color::Yellow, sf::Color::Black);
	buttons["Exit"] = new GUI::Button(650, 550, 152, 52, &_font, "Exit Game", 20, sf::Color::Black, sf::Color::Black, sf::Color::Cyan, sf::Color::Red, sf::Color::Magenta, sf::Color::Black);
}

void GameScene::StartLua()
{
	luaReading = new LuaReader("GamingScene.lua");
	lua_pushlightuserdata(this->luaReading->getLuaState(), this);
	lua_setglobal(this->luaReading->getLuaState(), "Gaming");
	this->RegisterCPPFunctions(luaReading->getLuaState());
	this->luaReading->loadFile();

	lua_getglobal(luaReading->getLuaState(), "InitGaming");
	if (lua_pcall(luaReading->getLuaState(), 0, 0, 0) != 0)
	{
		std::cerr << "Error al llamar a InitGaming: " << lua_tostring(luaReading->getLuaState(), -1) << std::endl;
	}
}

void GameScene::InitKeys()
{
	newKeys["MOVE_UP"] = supportKeys->at("W");
	newKeys["MOVE_LEFT"] = supportKeys->at("A");
	newKeys["MOVE_DOWN"] = supportKeys->at("S");
	newKeys["MOVE_RIGHT"] = supportKeys->at("D");
	newKeys["CLOSE"] = supportKeys->at("Escape");
}

void GameScene::InitPlayerLua()
{
	luaReading = new LuaReader("Player.lua");
	lua_pushlightuserdata(this->luaReading->getLuaState(), this);
	lua_setglobal(this->luaReading->getLuaState(), "Players");
	this->RegisterCPPFunctions(luaReading->getLuaState());
	this->luaReading->loadFile();

	lua_getglobal(luaReading->getLuaState(), "InitPlayer");
	if (lua_pcall(luaReading->getLuaState(), 0, 0, 0) != 0)
	{
		std::cerr << "Error al llamar a InitPlayer: " << lua_tostring(luaReading->getLuaState(), -1) << std::endl;
	}
}

void GameScene::InitEnemyLua()
{
	luaReading = new LuaReader("Enemy.lua");
	lua_pushlightuserdata(this->luaReading->getLuaState(), this);
	lua_setglobal(this->luaReading->getLuaState(), "Enemies");
	this->RegisterCPPFunctions(luaReading->getLuaState());
	this->luaReading->loadFile();

	lua_getglobal(luaReading->getLuaState(), "InitEnemy");
	if (lua_pcall(luaReading->getLuaState(), 0, 0, 0) != 0)
	{
		std::cerr << "Error al llamar a InitEnemy: " << lua_tostring(luaReading->getLuaState(), -1) << std::endl;
	}
}

void GameScene::RegisterCPPFunctions(lua_State* L)
{
	lua_register(L, "setGamingFont", setFontLua);
	lua_register(L, "setBackgroundTexture", setBackGroundLua);
	lua_register(L, "SetPlayerSprite", setPlayerSpriteLua);
	lua_register(L, "SetPlayerPosition", setPlayerPositionLua);
	lua_register(L, "PlayerSpeed", setPlayerSpeedLua);
	lua_register(L, "SetEnemySprite", setEnemySpriteLua);
	lua_register(L, "SetEnemyPosition", setEnemyPositionLua);
	lua_register(L, "EnemySpeed", setEnemySpeedLua);
}

int GameScene::setFontLua(lua_State* L)
{
	lua_getglobal(L, "Gaming");
	GameScene* gameScene = (GameScene*)lua_touserdata(L, -1);
	const char* fontName = lua_tostring(L, 1);
	gameScene->_font.loadFromFile(fontName);
	return 0;
}

int GameScene::setBackGroundLua(lua_State* L)
{
	lua_getglobal(L, "Gaming");
	GameScene* gameScene = (GameScene*)lua_touserdata(L, -1);
	const char* textureName = lua_tostring(L, 1);
	gameScene->bgTexture.loadFromFile(textureName);
	gameScene->_rect.setTexture(&gameScene->bgTexture);
	return 0;
}

int GameScene::setPlayerSpriteLua(lua_State* L)
{
	lua_getglobal(L, "Players");
	GameScene* mainPlayer = (GameScene*)lua_touserdata(L, -1);
	const char* textureName = lua_tostring(L, 1);
	mainPlayer->playerTexture.loadFromFile(textureName);
	return 0;
}

int GameScene::setPlayerPositionLua(lua_State* L)
{
	lua_getglobal(L, "Players");
	GameScene* mainPlayer = (GameScene*)lua_touserdata(L, -1);
	mainPlayer->initPosX = lua_tonumber(L, 1);
	mainPlayer->initPosY = lua_tonumber(L, 2);
	return 0;
}

int GameScene::setPlayerSpeedLua(lua_State* L)
{
	lua_getglobal(L, "Players");
	GameScene* mainPlayer = (GameScene*)lua_touserdata(L, -1);
	float speedy = lua_tonumber(L, 1);
	mainPlayer->initSpeed = speedy;
	return 0;
}

int GameScene::setEnemySpriteLua(lua_State* L)
{
	lua_getglobal(L, "Enemies");
	GameScene* mainEnemy = (GameScene*)lua_touserdata(L, -1);
	const char* textureName = lua_tostring(L, 1);
	mainEnemy->agEnTexture.loadFromFile(textureName);;
	return 0;
}

int GameScene::setEnemyPositionLua(lua_State* L)
{
	lua_getglobal(L, "Enemies");
	GameScene* mainEnemy = (GameScene*)lua_touserdata(L, -1);
	mainEnemy->enePosX = lua_tonumber(L, 1);
	mainEnemy->enePosY = lua_tonumber(L, 2);
	return 0;
}

int GameScene::setEnemySpeedLua(lua_State* L)
{
	lua_getglobal(L, "Enemies");
	GameScene* mainEnemy = (GameScene*)lua_touserdata(L, -1);
	float speedy = lua_tonumber(L, 1);
	mainEnemy->eneSpeed = speedy;
	return 0;
}

void GameScene::initPlayer()
{
	_player = new Player(playerTexture, initPosX, initPosY);
}

void GameScene::InitEnemy()
{
	agEnemy = new AgresiveEnemy(agEnTexture, enePosX, enePosY);
}

GameScene::GameScene(sf::RenderWindow* _target, std::map<std::string, int>* _supportKeys, std::stack<Scenes*>* _scenes, std::stack<LuaReader*>* _luaStack)
	:Scenes(_target, _supportKeys, _scenes, _luaStack)
{
	StartLua();
	InitKeys();
	InitButton();
	InitPlayerLua();
	InitEnemyLua();
	initPlayer();
	InitEnemy();
	isPaused = false;
}

GameScene::~GameScene()
{
	delete _player;
	delete agEnemy;

	for (auto b : buttons)
	{
		delete b.second;
	}
}

void GameScene::Update(const float& dt)
{
	dts = dt;
	_player->moveSpeed = initSpeed;

	if (isPaused == true)
	{
		dts = 0;
	}
	else
	{
		dts = dt;
	}

	UpdateButtons();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_LEFT"))))
	{
		std::cout << "'Aight, we move, we move left\n";
		_player->Move(-_player->moveSpeed, 0, dts);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_RIGHT"))))
	{
		std::cout << "'Aight, we move, we move right\n";
		_player->Move(_player->moveSpeed, 0, dts);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_UP"))))
	{
		std::cout << "'Aight, we move, we move up\n";
		_player->Move(0, -_player->moveSpeed, dts);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_DOWN"))))
	{
		std::cout << "'Aight, we move, we move down\n";
		_player->Move(0, _player->moveSpeed, dts);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("CLOSE"))))
	{
		std::cout << "OOOOH NOOOOOOOUUUUUUUU\n";
		if (isPaused == false)
		{
			isPaused = true;
		}
		else if (isPaused == true)
		{
			isPaused = false;
		}
	}

	agEnemy->NearPlayer(_player->posX, _player->posY, dts, eneSpeed);
	UpdateMousePos();
}

void GameScene::Render(sf::RenderTarget* _target)
{
	_target->draw(_rect);
	_player->Render(_target);
	agEnemy->Render(_target);
	for (auto b : buttons)
	{
		b.second->Render(_target);
	}
}

void GameScene::UpdateButtons()
{
	for (auto b : buttons)
	{
		b.second->Update(mousePosView);
	}

	if (buttons["Pause"]->GetButtonPress() && isPaused == false)
	{
		isPaused = true;
	}
	else if (buttons["Pause"]->GetButtonPress() && isPaused == true)
	{
		isPaused = false;
	}
	if (buttons["Exit"]->GetButtonPress())
	{
		EndState();
	}
}
