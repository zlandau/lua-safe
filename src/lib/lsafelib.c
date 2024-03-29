/*
 * Safe check functions
 * Copyright (c) 2005 Zachary P. Landau <kapheine@divineinvasion.net>
 */

#include <sys/stat.h>

#define lsafelib_c

#include "lua.h"

#include "lauxlib.h"
#include "luasafe.h"

static int safe_check_world_writable(lua_State *L, int idx) {
  struct stat st;

  if (stat(lua_tostring(L, idx), &st) < 0)
    luaL_error(L, "could not stat %s", lua_tostring(L, idx));
  return ((st.st_mode & (S_IWOTH)) == (S_IWOTH));
}

LUALIB_API void safe_check_load (lua_State *L, int idx) {
  if (lua_gettaint(L, idx)) { 
    switch (lua_getsafelevel(L)) { 
      case 3: 
      case 2: 
	/* XXX: Really should check if the DIRECTORY is world writable, not the file */
        if (safe_check_world_writable(L, idx))
          luaL_error(L, "safety violation: cannot load from world-writable file");
      case 1: 
        luaL_error(L, "safety violation: cannot load tainted filename"); 
    } 
  } 
}
