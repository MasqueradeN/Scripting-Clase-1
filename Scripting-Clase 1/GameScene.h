#pragma once
#include "Scenes.h"
#include "Player.h"
#include "GUI.h"
#include "AgresiveEnemy.h"
#include "LuaReader.h"

class GameScene :
    public Scenes
{
private:
    sf::RectangleShape _rect;
    sf::RectangleShape bg;

    sf::Texture bgTexture;
    sf::Texture playerTexture;
    sf::Texture agEnTexture;
    
    sf::Font _font;

    std::map<std::string, GUI::Button*> buttons;

    Player* _player;
    float initPosX;
    float initPosY;
    float initSpeed;
    AgresiveEnemy* agEnemy;
    float enePosX;
    float enePosY;
    float eneSpeed;

    void InitButton();

protected:
    void StartLua();
    void InitKeys();
    void InitPlayerLua();
    void InitEnemyLua();

    void RegisterCPPFunctions(lua_State* L);

    static int setFontLua(lua_State* L);
    static int setBackGroundLua(lua_State* L);
    static int setPlayerSpriteLua(lua_State* L);
    static int setPlayerPositionLua(lua_State* L);
    static int setPlayerSpeedLua(lua_State* L);
    static int setEnemySpriteLua(lua_State* L);
    static int setEnemyPositionLua(lua_State* L);
    static int setEnemySpeedLua(lua_State* L);

    void initPlayer();
    void InitEnemy();

public:
    GameScene(sf::RenderWindow* _target, std::map<std::string, int>* _supportKeys, std::stack<Scenes*>* _scenes, std::stack<LuaReader*>* _luaStack);
    virtual ~GameScene();

    virtual void Update(const float& dt);
    virtual void Render(sf::RenderTarget* _target);

    void UpdateButtons();
};

