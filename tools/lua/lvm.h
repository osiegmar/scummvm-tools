/*
** $Id$
** Lua virtual machine
** See Copyright Notice in lua.h
*/

#ifndef lvm_h
#define lvm_h


#include <tools/lua/ldo.h>
#include <tools/lua/lobject.h>


#define tonumber(o) ((ttype(o) != LUA_T_NUMBER) && (luaV_tonumber(o) != 0))
#define tostring(o) ((ttype(o) != LUA_T_STRING) && (luaV_tostring(o) != 0))


void luaV_pack (StkId firstel, int nvararg, TObject *tab);
int luaV_tonumber (TObject *obj);
int luaV_tostring (TObject *obj);
void luaV_gettable (void);
void luaV_settable (TObject *t, int mode);
void luaV_getglobal (TaggedString *ts);
void luaV_setglobal (TaggedString *ts);
StkId luaV_execute (struct CallInfo *ci);
void luaV_closure (int nelems);

#endif
