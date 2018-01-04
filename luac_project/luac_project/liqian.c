#include "liqian.h"

#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"



static float add(float a, float b)
{
	return a + b;
}

static int lq_add (lua_State *L) {
	lua_pushnumber(L, add(luaL_checknumber(L, 1), luaL_checknumber(L, 2)));
	return 1;
}


static const luaL_Reg lqlib[] = {
	{"lq_add", lq_add},
};





int (luaopen_dog) (lua_State *L){
	luaL_register(L, "dog", lqlib);
	return 1;
}