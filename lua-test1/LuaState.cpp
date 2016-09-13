
#include "LuaState.h"

// Luna implementation
#define method(class, name)  {#name, &class::name}

// name to use to address class in Lua
const char LuaState::className[] = "LuaState";

// list of class properties that one can set/get from Lua
const Luna<LuaState>::PropertyType LuaState::properties[] =
{
   {0, 0}
};

// list of class methods to make available in Lua
const Luna<LuaState>::FunctionType LuaState::methods[] =
{
   method(LuaState, isAlive),
   method(LuaState, getRoll),
   method(LuaState, getPitch),
   {0, 0}
};

LuaState::LuaState(lua_State*)
{}

int LuaState::isAlive(lua_State* l)
{
   lua_pushboolean(l, State::isAlive());
   return 1;
}

int LuaState::getRoll(lua_State* l)
{
   lua_pushnumber(l, State::getRoll());
   return 1;
}

int LuaState::getPitch(lua_State* l)
{
   lua_pushnumber(l, State::getPitch());
   return 1;
}

