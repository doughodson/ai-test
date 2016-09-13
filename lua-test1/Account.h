
#ifndef __Account_H__
#define __Account_H__

#include "luna.h"

class Account
{
public:
   Account(lua_State*);
   ~Account();

   int setX(lua_State*);
   int getX(lua_State*);

   int deposit(lua_State*);
   int withdraw(lua_State*);
   int getBalance(lua_State*);

   static const char className[];
   static const Luna<Account>::PropertyType properties[];
   static const Luna<Account>::FunctionType methods[];

private:
   int balance;
   int x;

};

#endif
