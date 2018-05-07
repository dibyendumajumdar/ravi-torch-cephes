#include "cephes.h"

#ifdef __cplusplus
extern "C" {
#endif
#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

CEPHES_API int luaopen_cephes(lua_State *L);

#ifdef __cplusplus
}
#endif

#include <stdio.h>


/ Convert a table array to an array of doubles
static double *to_double_array(lua_State *L, int &n) {
  n = lua_objlen(L, -1);
  double *x = calloc(sizeof(double), n);
  if (!x) return NULL;
  bool ok = true;
  for (int i = 0; i < n && ok; i++) {
    lua_rawgeti(L, -1, i + 1);
    if (lua_isnumber(L, -1))
      x[i] = lua_tonumber(L, -1);
    else
      ok = false;
    lua_pop(L, 1);
  }
  if (!ok) {
    free(x);
    x = NULL;
  }
  return x;
}

// name(D)->D
#define MAKE_FUNC_D_D(name)                                                    \
  static int lua_##name(lua_State *L) {                                        \
    double x = luaL_checknumber(L, 1);                                         \
    double y = torch_cephes_##name(x);                                         \
    lua_pushnumber(L, y);                                                      \
    return 1;                                                                  \
  }

// name(D, D)->D
#define MAKE_FUNC_DD_D(name)                                                   \
  static int lua_##name(lua_State *L) {                                        \
    double x1 = luaL_checknumber(L, 1);                                        \
    double x2 = luaL_checknumber(L, 2);                                        \
    double y = torch_cephes_##name(x1, x2);                                    \
    lua_pushnumber(L, y);                                                      \
    return 1;                                                                  \
  }

// name(D, D, D)->D
#define MAKE_FUNC_DDD_D(name)                                                  \
  static int lua_##name(lua_State *L) {                                        \
    double x1 = luaL_checknumber(L, 1);                                        \
    double x2 = luaL_checknumber(L, 2);                                        \
    double x3 = luaL_checknumber(L, 2);                                        \
    double y = torch_cephes_##name(x1, x2, x3);                                \
    lua_pushnumber(L, y);                                                      \
    return 1;                                                                  \
  }

// name(I)->D
#define MAKE_FUNC_I_D(name)                                                    \
  static int lua_##name(lua_State *L) {                                        \
    int x = (int)luaL_checkinteger(L, 1);                                      \
    double y = torch_cephes_##name(x);                                         \
    lua_pushnumber(L, y);                                                      \
    return 1;                                                                  \
  }

// name(I, D)->D
#define MAKE_FUNC_ID_D(name)                                                   \
  static int lua_##name(lua_State *L) {                                        \
    int x1 = (int)luaL_checkinteger(L, 1);                                     \
    double x2 = luaL_checknumber(L, 2);                                        \
    double y = torch_cephes_##name(x1, x2);                                    \
    lua_pushnumber(L, y);                                                      \
    return 1;                                                                  \
  }

// name(I, I, D)->D
#define MAKE_FUNC_IID_D(name)                                                  \
  static int lua_##name(lua_State *L) {                                        \
    int x1 = (int) luaL_checkinteger(L, 1);                                          \
    int x2 = (int) luaL_checkinteger(L, 2);                                          \
    double x3 = luaL_checknumber(L, 2);                                        \
    double y = torch_cephes_##name(x1, x2, x3);                                \
    lua_pushnumber(L, y);                                                      \
    return 1;                                                                  \
  }

MAKE_FUNC_D_D(acosh)
MAKE_FUNC_D_D(asin)
MAKE_FUNC_D_D(acos)
MAKE_FUNC_D_D(asinh)
MAKE_FUNC_D_D(atan)
MAKE_FUNC_D_D(atanh)
MAKE_FUNC_D_D(cbrt)
MAKE_FUNC_D_D(cosh)
MAKE_FUNC_D_D(dawsn)
MAKE_FUNC_D_D(ellpe)
MAKE_FUNC_D_D(ellpk)
MAKE_FUNC_D_D(exp10)
MAKE_FUNC_D_D(exp2)
MAKE_FUNC_D_D(ceil)
MAKE_FUNC_D_D(fabs)
MAKE_FUNC_D_D(floor)
MAKE_FUNC_D_D(signbit)
MAKE_FUNC_D_D(isnan)
MAKE_FUNC_D_D(isfinite)
MAKE_FUNC_D_D(exp)
MAKE_FUNC_D_D(log)
MAKE_FUNC_D_D(sin)
MAKE_FUNC_D_D(cos)
MAKE_FUNC_D_D(sqrt)
MAKE_FUNC_D_D(gamma)
MAKE_FUNC_D_D(lgam)
MAKE_FUNC_D_D(i0)
MAKE_FUNC_D_D(i0e)
MAKE_FUNC_D_D(i1)
MAKE_FUNC_D_D(i1e)
MAKE_FUNC_D_D(j0)
MAKE_FUNC_D_D(y0)
MAKE_FUNC_D_D(j1)
MAKE_FUNC_D_D(y1)
MAKE_FUNC_D_D(k0)
MAKE_FUNC_D_D(k0e)
MAKE_FUNC_D_D(k1)
MAKE_FUNC_D_D(k1e)
MAKE_FUNC_D_D(log10)
MAKE_FUNC_D_D(log2)
MAKE_FUNC_D_D(ndtr)
MAKE_FUNC_D_D(erfc)
MAKE_FUNC_D_D(erf)
MAKE_FUNC_D_D(ndtri)
MAKE_FUNC_D_D(psi)
MAKE_FUNC_D_D(round)
MAKE_FUNC_D_D(sindg)
MAKE_FUNC_D_D(cosdg)
MAKE_FUNC_D_D(sinh)
MAKE_FUNC_D_D(spence)
MAKE_FUNC_D_D(tan)
MAKE_FUNC_D_D(cot)
MAKE_FUNC_D_D(tandg)
MAKE_FUNC_D_D(cotdg)
MAKE_FUNC_D_D(tanh)
MAKE_FUNC_D_D(log1p)
MAKE_FUNC_D_D(cosm1)
MAKE_FUNC_D_D(zetac)
MAKE_FUNC_D_D(kolmogorov)
MAKE_FUNC_D_D(kolmogi)
MAKE_FUNC_D_D(expm1)

MAKE_FUNC_DD_D(atan2)
MAKE_FUNC_DD_D(beta)
MAKE_FUNC_DD_D(lbeta)
MAKE_FUNC_DD_D(chdtrc)
MAKE_FUNC_DD_D(chdtr)
MAKE_FUNC_DD_D(chdtri)
MAKE_FUNC_DD_D(hypot)
MAKE_FUNC_DD_D(ellie)
MAKE_FUNC_DD_D(ellik)
MAKE_FUNC_DD_D(igamc)
MAKE_FUNC_DD_D(igam)
MAKE_FUNC_DD_D(igami)
MAKE_FUNC_DD_D(iv)
MAKE_FUNC_DD_D(jv)
MAKE_FUNC_DD_D(pow)
MAKE_FUNC_DD_D(struve)
MAKE_FUNC_DD_D(zeta)

MAKE_FUNC_DDD_D(btdtr)
MAKE_FUNC_DDD_D(gdtr)
MAKE_FUNC_DDD_D(gdtrc)
MAKE_FUNC_DDD_D(hyperg)
MAKE_FUNC_DDD_D(incbet)
MAKE_FUNC_DDD_D(incbi)
MAKE_FUNC_DDD_D(radian)

MAKE_FUNC_I_D(fac)

MAKE_FUNC_IID_D(bdtrc)
MAKE_FUNC_IID_D(bdtr)
MAKE_FUNC_IID_D(bdtri)
MAKE_FUNC_IID_D(fdtrc)
MAKE_FUNC_IID_D(fdtr)
MAKE_FUNC_IID_D(fdtri)
MAKE_FUNC_IID_D(nbdtrc)
MAKE_FUNC_IID_D(nbdtr)
MAKE_FUNC_IID_D(nbdtri)

MAKE_FUNC_ID_D(expn)
MAKE_FUNC_ID_D(jn)
MAKE_FUNC_ID_D(kn)
MAKE_FUNC_ID_D(pdtrc)
MAKE_FUNC_ID_D(pdtr)
MAKE_FUNC_ID_D(pdtri)
MAKE_FUNC_ID_D(stdtr)
MAKE_FUNC_ID_D(stdtri)
MAKE_FUNC_ID_D(yn)
MAKE_FUNC_ID_D(smirnov)
MAKE_FUNC_ID_D(smirnovi)

static int lua_airy(lua_State *L) {
  double x = luaL_checknumber(L, 1);
  double ai, aip, bi, bip;
  int rc = torch_cephes_airy(x, &ai, &aip, &bi, &bip);
  if (rc < 0) {
    luaL_argerror(L, 1, "Invalid argument");
    return 0;
  }
  lua_pushnumber(L, ai);
  lua_pushnumber(L, aip);
  lua_pushnumber(L, bi);
  lua_pushnumber(L, bip);
  return 4;
}

#undef MAKE_FUNC_D_D
#define MAKE_FUNC_D_D(name)                                                    \
  { #name, lua_##name }

#undef MAKE_FUNC_DD_D
#define MAKE_FUNC_DD_D(name)                                                   \
  { #name, lua_##name }

#undef MAKE_FUNC_DDD_D
#define MAKE_FUNC_DDD_D(name)                                                  \
  { #name, lua_##name }

#undef MAKE_FUNC_I_D
#define MAKE_FUNC_I_D(name)                                                    \
  { #name, lua_##name }

#undef MAKE_FUNC_ID_D
#define MAKE_FUNC_ID_D(name)                                                   \
  { #name, lua_##name }

#undef MAKE_FUNC_IID_D
#define MAKE_FUNC_IID_D(name)                                                  \
  { #name, lua_##name }

static const struct luaL_Reg mylib[] = {MAKE_FUNC_D_D(acosh),
                                        MAKE_FUNC_D_D(asin),
                                        MAKE_FUNC_D_D(acos),
                                        MAKE_FUNC_D_D(asinh),
                                        MAKE_FUNC_D_D(atan),
                                        MAKE_FUNC_D_D(atanh),
                                        MAKE_FUNC_D_D(cbrt),
                                        MAKE_FUNC_D_D(cosh),
                                        MAKE_FUNC_D_D(dawsn),
                                        MAKE_FUNC_D_D(ellpe),
                                        MAKE_FUNC_D_D(ellpk),
                                        MAKE_FUNC_D_D(exp10),
                                        MAKE_FUNC_D_D(exp2),
                                        MAKE_FUNC_D_D(ceil),
                                        MAKE_FUNC_D_D(fabs),
                                        MAKE_FUNC_D_D(floor),
                                        MAKE_FUNC_D_D(signbit),
                                        MAKE_FUNC_D_D(isnan),
                                        MAKE_FUNC_D_D(isfinite),
                                        MAKE_FUNC_D_D(exp),
                                        MAKE_FUNC_D_D(log),
                                        MAKE_FUNC_D_D(sin),
                                        MAKE_FUNC_D_D(cos),
                                        MAKE_FUNC_D_D(sqrt),
                                        MAKE_FUNC_D_D(gamma),
                                        MAKE_FUNC_D_D(lgam),
                                        MAKE_FUNC_D_D(i0),
                                        MAKE_FUNC_D_D(i0e),
                                        MAKE_FUNC_D_D(i1),
                                        MAKE_FUNC_D_D(i1e),
                                        MAKE_FUNC_D_D(j0),
                                        MAKE_FUNC_D_D(y0),
                                        MAKE_FUNC_D_D(j1),
                                        MAKE_FUNC_D_D(y1),
                                        MAKE_FUNC_D_D(k0),
                                        MAKE_FUNC_D_D(k0e),
                                        MAKE_FUNC_D_D(k1),
                                        MAKE_FUNC_D_D(k1e),
                                        MAKE_FUNC_D_D(log10),
                                        MAKE_FUNC_D_D(log2),
                                        MAKE_FUNC_D_D(ndtr),
                                        MAKE_FUNC_D_D(erfc),
                                        MAKE_FUNC_D_D(erf),
                                        MAKE_FUNC_D_D(ndtri),
                                        MAKE_FUNC_D_D(psi),
                                        MAKE_FUNC_D_D(round),
                                        MAKE_FUNC_D_D(sindg),
                                        MAKE_FUNC_D_D(cosdg),
                                        MAKE_FUNC_D_D(sinh),
                                        MAKE_FUNC_D_D(spence),
                                        MAKE_FUNC_D_D(tan),
                                        MAKE_FUNC_D_D(cot),
                                        MAKE_FUNC_D_D(tandg),
                                        MAKE_FUNC_D_D(cotdg),
                                        MAKE_FUNC_D_D(tanh),
                                        MAKE_FUNC_D_D(log1p),
                                        MAKE_FUNC_D_D(cosm1),
                                        MAKE_FUNC_D_D(zetac),
                                        MAKE_FUNC_D_D(kolmogorov),
                                        MAKE_FUNC_D_D(kolmogi),
                                        MAKE_FUNC_D_D(expm1),
                                        MAKE_FUNC_DD_D(atan2),
                                        MAKE_FUNC_DD_D(beta),
                                        MAKE_FUNC_DD_D(lbeta),
                                        MAKE_FUNC_DD_D(chdtrc),
                                        MAKE_FUNC_DD_D(chdtr),
                                        MAKE_FUNC_DD_D(chdtri),
                                        MAKE_FUNC_DD_D(hypot),
                                        MAKE_FUNC_DD_D(ellie),
                                        MAKE_FUNC_DD_D(ellik),
                                        MAKE_FUNC_DD_D(igamc),
                                        MAKE_FUNC_DD_D(igam),
                                        MAKE_FUNC_DD_D(igami),
                                        MAKE_FUNC_DD_D(iv),
                                        MAKE_FUNC_DD_D(jv),
                                        MAKE_FUNC_DD_D(pow),
                                        MAKE_FUNC_DD_D(struve),
                                        MAKE_FUNC_DD_D(zeta),
                                        MAKE_FUNC_DDD_D(btdtr),
                                        MAKE_FUNC_DDD_D(gdtr),
                                        MAKE_FUNC_DDD_D(gdtrc),
                                        MAKE_FUNC_DDD_D(hyperg),
                                        MAKE_FUNC_DDD_D(incbet),
                                        MAKE_FUNC_DDD_D(incbi),
                                        MAKE_FUNC_DDD_D(radian),
                                        MAKE_FUNC_I_D(fac),

                                        MAKE_FUNC_IID_D(bdtrc),
                                        MAKE_FUNC_IID_D(bdtr),
                                        MAKE_FUNC_IID_D(bdtri),
                                        MAKE_FUNC_IID_D(fdtrc),
                                        MAKE_FUNC_IID_D(fdtr),
                                        MAKE_FUNC_IID_D(fdtri),
                                        MAKE_FUNC_IID_D(nbdtrc),
                                        MAKE_FUNC_IID_D(nbdtr),
                                        MAKE_FUNC_IID_D(nbdtri),

                                        MAKE_FUNC_ID_D(expn),
                                        MAKE_FUNC_ID_D(jn),
                                        MAKE_FUNC_ID_D(kn),
                                        MAKE_FUNC_ID_D(pdtrc),
                                        MAKE_FUNC_ID_D(pdtr),
                                        MAKE_FUNC_ID_D(pdtri),
                                        MAKE_FUNC_ID_D(stdtr),
                                        MAKE_FUNC_ID_D(stdtri),
                                        MAKE_FUNC_ID_D(yn),
                                        MAKE_FUNC_ID_D(smirnov),
                                        MAKE_FUNC_ID_D(smirnovi),
                                        {"airy", lua_airy},
                                        {NULL, NULL}};

// adds to an existing table
// table must be on stop of the stack
static void add_to_library(lua_State *L, const struct luaL_Reg *regs) {
  int i = 0;
  for (; regs[i].name != NULL; i++) {
    lua_pushcclosure(L, regs[i].func, 0);
    lua_setfield(L, -2, regs[i].name);
  }
}

// creates a table of functions which is a library in Lua
// terms. We use this as a portable way across 5.1 and 5.2 which
// follows the latest conventions - i.e. avoid polluting global
// namespace
static void create_library(lua_State *L, const struct luaL_Reg *regs) {
  int count = 0;
  int i = 0;
  for (; regs[i].name != NULL; i++) {
    count++;
  }
  lua_createtable(L, 0, count);
  add_to_library(L, regs);
  // leave table on the stack
}

int luaopen_cephes(lua_State *L) {
  fprintf(stderr, "Initializing Cephes\n");
  create_library(L, mylib);
  fprintf(stdout, "Cephes initialized successfully\n");
  return 1;
}
