#include "pch.h"
#include "MenuScene.h"
#include "GameScene.h"

void MenuScene::InitButton()
{
	buttons["New Game"] = new GUI::Button(350, 350, 152, 52, &_font, "New Game", 20, sf::Color::Black, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, sf::Color::White, sf::Color::Black);
	buttons["Settings"] = new GUI::Button(350, 450, 152, 52, &_font, "Settings", 20, sf::Color::Black, sf::Color::Black, sf::Color::Cyan, sf::Color::Green, sf::Color::Yellow, sf::Color::Black);
	buttons["Exit"] = new GUI::Button(350, 550, 152, 52, &_font, "Exit Game", 20, sf::Color::Black, sf::Color::Black, sf::Color::Cyan, sf::Color::Red, sf::Color::Magenta, sf::Color::Black);
}

void MenuScene::StartLua()
{
	luaReading = new LuaReader("MainMenu.lua");
	lua_pushlightuserdata(this->luaReading->getLuaState(), this);
	lua_setglobal(this->luaReading->getLuaState(), "MainMenu");
	this->RegisterCPPFunctions(luaReading->getLuaState());
	this->luaReading->loadFile();

	lua_getglobal(luaReading->getLuaState(), "InitMenu");
	if (lua_pcall(luaReading->getLuaState(), 0, 0, 0) != 0)
	{
		std::cerr << "Error al llamar a InitMenu: " << lua_tostring(luaReading->getLuaState(), -1) << std::endl;
	}
}

void MenuScene::RegisterCPPFunctions(lua_State* L)
{
	lua_register(L, "setFontFile", setFontLua);
	lua_register(L, "setBackGround", setBackGroundLua);
}

void MenuScene::InitBackground()
{
	_rect.setSize(sf::Vector2f(_window->getSize()));
	//_rect.setFillColor(sf::Color::White);
}

void MenuScene::InitKeys()
{
	newKeys["MOVE_UP"] = supportKeys->at("W");
	newKeys["MOVE_LEFT"] = supportKeys->at("A");
	newKeys["MOVE_DOWN"] = supportKeys->at("S");
	newKeys["MOVE_RIGHT"] = supportKeys->at("D");
	newKeys["CLOSE"] = supportKeys->at("Escape");
}

int MenuScene::setFontLua(lua_State* L)
{
	lua_getglobal(L, "MainMenu");
	MenuScene* mainMenu = (MenuScene*)lua_touserdata(L, -1);
	const char* fontName = lua_tostring(L, 1);
	//mainMenu->_font.loadFromFile(fontName);
	return 0;
}

int MenuScene::setBackGroundLua(lua_State* L)
{	
	lua_getglobal(L, "MainMenu");
	MenuScene* mainMenu = (MenuScene*)lua_touserdata(L, -1);
	const char* textureName = lua_tostring(L, 1);
	mainMenu->bgTexture.loadFromFile(textureName);
	mainMenu->_rect.setTexture(&mainMenu->bgTexture);
	return 0;
}

MenuScene::MenuScene(sf::RenderWindow* _target, std::map<std::string, int>* _supportKeys, std::stack<Scenes*>* _scenes, std::stack<LuaReader*>* _luaStack)
	:Scenes(_target, _supportKeys, _scenes, _luaStack)
{
	InitKeys();
	InitBackground();
	InitButton();
	StartLua();
}

MenuScene::~MenuScene()
{
	for (auto b : buttons)
	{
		delete b.second;
	}
}

void MenuScene::Update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_LEFT"))))
	{
		std::cout << "'Aight, we move, we move left, pt.2\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_RIGHT"))))
	{
		std::cout << "'Aight, we move, we move right, pt.2\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_UP"))))
	{
		std::cout << "'Aight, we move, we move up, pt.2\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("MOVE_DOWN"))))
	{
		std::cout << "'Aight, we move, we move down, pt.2\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(newKeys.at("CLOSE"))))
	{
		scenes->push(new GameScene(_window, supportKeys,scenes, luaStack));
		quitScene = true;
		this->GetQuitScene();
	}
	UpdateMousePos();
	UpdateButtons();
}

void MenuScene::UpdateButtons()
{
	for (auto b : buttons)
	{
		b.second->Update(mousePosView);
	}

	if (buttons["New Game"]->GetButtonPress())
	{
		scenes->push(new GameScene(_window, supportKeys, scenes, luaStack));
	}
	if (buttons["Exit"]->GetButtonPress())
	{
		EndState();
	}
}

void MenuScene::Render(sf::RenderTarget* _target)
{
	_target->draw(_rect);
	for (auto b : buttons)
	{
		b.second->Render(_target);
	}
}
