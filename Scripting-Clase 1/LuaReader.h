#pragma once
#include "pch.h"
class LuaReader
{
private:
	lua_State* L;
	std::string lua_state_file;
public:
	LuaReader(const char* lua_state_file);
	~LuaReader();

	void loadFile();

	inline lua_State* getLuaState() { return this->L; }

	void Update();
	void Render();
};

