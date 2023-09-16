#include "pch.h"
#include <iostream>

#include "GameEngine.h"

int main()
{
    GameEngine game;
    while (game.GetWindowOpen())
    {
        game.UpdateDeltaTime();
        game.Update();
        game.Render();
    }
    //lua_State* L = luaL_newstate();

    //luaL_openlibs(L);

    //lua_pushnumber(L, 20);
    //lua_pushstring(L, "Bruh");
    //lua_pushnumber(L, 32);

    //std::cout << lua_tonumber(L, -1) << "\n";
    //std::cout << lua_tostring(L, -2) << "\n";
    //std::cout << lua_tonumber(L, -3) << "\n";

    //lua_close(L);
    //sf::RenderWindow();
    return 0;
}
