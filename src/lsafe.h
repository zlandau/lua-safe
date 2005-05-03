/*
** $Id$
*/

#ifndef lsafe_h
#define lsafe_h


#include "lua.h"


#define SAFE_TAINT(o)                ((o)->tainted = 1)
#define SAFE_UNTAINT(o)              ((o)->tainted = 0)
#define SAFE_IS_TAINTED(o)           ((o)->tainted == 1)
#define SAFE_IS_TAINTED_TWO(o1, o2)  (SAFE_IS_TAINTED(o1) || SAFE_IS_TAINTED(o2))

#define _SAFE_CHECK_ASSIGN(L, o) \
    {if (SAFE_IS_TAINTED(o) && L->safelevel >= 4) \
        luaG_runerror(L, "safety violation: cannot assign tainted value");}
#define _SAFE_TAINT_ASSIGN(L, o) \
    {if (L->safelevel >= 4) \
        SAFE_TAINT(o);}
#define _SAFE_ALLOW_TAINT(L) \
    {if (L->safelevel >= 4) \
        luaG_runerror(L, "safety violation: cannot taint values");}
#define _SAFE_ALLOW_UNTAINT(L) \
    {if (L->safelevel >= 3) \
        luaG_runerror(L, "safety violation: cannot untaint values");}
#endif
