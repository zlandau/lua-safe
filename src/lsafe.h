/*
** $Id$
*/

#ifndef lsafe_h
#define lsafe_h


#include "lua.h"


#define SAFE_TAINT(o)           ((o)->tainted = 1)
#define SAFE_UNTAINT(o)         ((o)->tainted = 0)
#define SAFE_IS_TAINTED(o)      ((o)->tainted == 1)

#define _SAFE_CHECK_ASSIGN(L, o) \
    {if (SAFE_IS_TAINTED(o) && L->safelevel >= 5) \
        luaG_runerror(L, "safety violation: cannot assign tainted value");}
#define _SAFE_TAINT_ASSIGN(L, o) \
    {if (L->safelevel >= 5) \
        SAFE_TAINT(o);}

#endif
