
#include "Account.h"

#define method(class, name) {#name, &class::name}

// name to use to address the class in Lua
const char Account::className[] = "Account";

// list of class properties that one can set/get from Lua
const Luna<Account>::PropertyType Account::properties[] = {
  {"X", &Account::getX, &Account::setX},
  {0,0,0}
};

// list of class methods to make available in Lua
const Luna<Account>::FunctionType Account::methods[] = {
  method(Account, deposit),
  method(Account, withdraw),
  method(Account, getBalance),
  {0,0}
};

Account::Account(lua_State* l)
{
   balance = lua_tointeger(l, 1);
   x = 0;
}

Account::~Account()
{
   printf("C++: Deleted Account (%p)\n", this);
}

int Account::setX(lua_State* l)
{
   x = lua_tointeger(l, 1);
   return 0;
}

int Account::getX(lua_State* l)
{
   lua_pushnumber(l, x);
   return 1;
}

int Account::deposit(lua_State* l)
{
   balance += lua_tointeger(l, 1);
   return 0;
}

int Account::withdraw(lua_State* l)
{
   balance -= lua_tointeger(l, 1);
   return 0;
}

int Account::getBalance(lua_State* l)
{
   lua_pushnumber(l, balance);
   return 1;
}
