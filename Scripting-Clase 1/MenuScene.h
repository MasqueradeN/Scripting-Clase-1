#pragma once
#include "Scenes.h"
#include "GUI.h"
class MenuScene :
    public Scenes
{
private:
    sf::RectangleShape _rect;
    sf::RectangleShape bg;
    
    sf::Font _font;
    sf::Texture bgTexture;

    std::map<std::string, GUI::Button*> buttons;

    void InitButton();
    void StartLua();
    void RegisterCPPFunctions(lua_State* L);

protected:
    void InitKeys();
    void InitBackground();
    static int setFontLua(lua_State* L);
    static int setBackGroundLua(lua_State* L);

public:
    MenuScene(sf::RenderWindow* _target, std::map<std::string, int>* _supportKeys, std::stack<Scenes*>* _scenes, std::stack<LuaReader*>* _luaStack);
    virtual ~MenuScene();

    void Update(const float& dt);
    void UpdateButtons();
    void Render(sf::RenderTarget* _target);
};

