/*
** $Id$
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
*/


#ifndef auxlib_h
#define auxlib_h


#include <tools/lua/lua.h>


struct luaL_reg {
  char *name;
  lua_CFunction func;
};

struct luaL_libList {
  luaL_reg *list;
  int number;
  luaL_libList *next;
};

extern luaL_libList *list_of_libs;

#define luaL_arg_check(cond,numarg,extramsg) if (!(cond)) \
                                               luaL_argerror(numarg,extramsg)

void luaL_openlib (struct luaL_reg *l, int n);
void luaL_addlibtolist(luaL_reg *l, int n);
void luaL_argerror (int numarg, char *extramsg);
#define luaL_check_string(n)  (luaL_check_lstr((n), NULL))
char *luaL_check_lstr (int numArg, long *len);
#define luaL_opt_string(n, d) (luaL_opt_lstr((n), (d), NULL))
char *luaL_opt_lstr (int numArg, char *def, long *len);
double luaL_check_number (int numArg);
double luaL_opt_number (int numArg, double def);
lua_Object luaL_functionarg (int arg);
lua_Object luaL_tablearg (int arg);
lua_Object luaL_nonnullarg (int numArg);
void luaL_verror (char *fmt, ...);
char *luaL_openspace (int size);
void luaL_resetbuffer (void);
void luaL_addchar (int c);
int luaL_getsize (void);
void luaL_addsize (int n);
int luaL_newbuffer (int size);
void luaL_oldbuffer (int old);
char *luaL_buffer (void);
int luaL_findstring (char *name, char *list[]);


#endif
