/**
 *
 */

#ifndef luasafe_h
#define luasafe_h

#define SAFE_TAINT(o)           ((o)->tainted = 1)
#define SAFE_UNTAINT(o)         ((o)->tainted = 0)
#define SAFE_IS_TAINTED(o)      ((o)->tainted == 1)

extern void safe_check_load (lua_State *L, int idx);

#define SAFE_CHECK_EXECUTE(L, idx) \
    {if (lua_gettaint(L, idx) && lua_getsafelevel(L) >= 1) \
         luaL_error(L, "safety violation: cannot execute tainted value");}
#define SAFE_CHECK_EVAL(L, idx) \
    {if (lua_gettaint(L, idx) && lua_getsafelevel(L) >= 1) \
         luaL_error(L, "safety violation: cannot evaluate tainted value");}
#define SAFE_CHECK_FILE_DATA(L, idx) \
    {if (lua_gettaint(L, idx) && lua_getsafelevel(L) >= 1) \
	luaL_error(L, "safety violation: cannot modify files with tainted value"); \
     else if (lua_getsafelevel(L) >= 3) \
         luaL_error(L, "safety violation: cannot modify files");}
#define SAFE_CHECK_OS_EXIT(L) \
    {if (lua_getsafelevel(L) >= 3) \
         luaL_error(L, "safety violation: cannot call os.exit");}
#define SAFE_CHECK_FILE_MOD(L) \
    {if (lua_getsafelevel(L) >= 3) \
         luaL_error(L, "safety violation: cannot modify files");}
#define SAFE_CHECK_LOAD(L, idx) \
    safe_check_load(L, idx);
#endif
