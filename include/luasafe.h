/**
 *
 */

#ifndef luasafe_h
#define luasafe_h

#define SAFE_TAINT(o)           ((o)->tainted = 1)
#define SAFE_UNTAINT(o)         ((o)->tainted = 0)
#define SAFE_IS_TAINTED(o)      ((o)->tainted == 1)

#define SAFE_CHECK_EXECUTE(L, idx) \
    {if (lua_gettaint(L, idx) && lua_getsafelevel(L) >= 3) \
         luaL_error(L, "safety violation: cannot execute tainted value");}

#endif
