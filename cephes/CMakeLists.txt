option(USE_LUA53 "Controls whether the library will be for Lua 5.3 or Ravi, default is OFF" OFF)

find_package(Lua REQUIRED)

message(STATUS "LUA_INCLUDE_DIR: ${LUA_INCLUDE_DIR}")
message(STATUS "LUA_LIBRARIES  : ${LUA_LIBRARIES}")

message(STATUS "LUA_INCDIR     : ${LUA_INCDIR}")
message(STATUS "LUA_LIBDIR     : ${LUA_LIBDIR}")
message(STATUS "LUA_BINDIR     : ${LUA_BINDIR}")
message(STATUS "LUALIB         : ${LUALIB}")
message(STATUS "LIBDIR (LUA_CPATH)  : ${LIBDIR}")
message(STATUS "LUADIR (LUA_PATH)   : ${LUADIR}")

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}")
INCLUDE_DIRECTORIES("${LUA_INCDIR}")
LINK_DIRECTORIES("${LUA_LIBDIR}")


# locate all cephes subfolders to process
FILE(GLOB src
    "bessel/*.c"
    "cmath/*.c"
    "cprob/*.c"
    "misc/*.c"
    "ellf/*.c"
    "polyn/*.c"
    "torch_mtherr.c"
    "luabindings/cephes_lua_api.c"
    )

INCLUDE_DIRECTORIES("include")

# note: single/ is not compiled because it conflicts
# with many functions in cmath and cprob :(

# use our custom mtherr instead of cmath/mtherr.c
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/cmath/mtherr.c"
    )


# ignore files which have a main() 
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/cmath/mtst.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmath/dtestvec.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmath/mod2pi.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ellf/ellf.c")

# ignore files who are exact duplicates of cmath
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/cprob/drand.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cprob/const.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cprob/mtherr.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cprob/polevl.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/cprob/unity.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/misc/chbevl.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/misc/mtherr.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/misc/polevl.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ellf/cmplx.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ellf/const.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ellf/mtherr.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ellf/polevl.c"
    )

# ignore files in misc who are exact duplicates of any other
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/misc/psi.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/misc/revers.c"
    )

# ignore rational polynomials of polyr.c,
# because it conflict with the simpler polynomials of polyn.c
LIST(REMOVE_ITEM src
    "${CMAKE_CURRENT_SOURCE_DIR}/polyn/polyr.c"
    )

# install the lua code for the cephes package
FILE(GLOB luasrc "luasrc/*.lua")
# TODO: install the tests, too
# ADD_SUBDIRECTORY(tests)

# When using MSVC
IF(MSVC)
  # we want to respect the standard, and we are bored of those **** .
  ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE=1)
ENDIF(MSVC)

ADD_LIBRARY("cephes" SHARED ${src})
set_target_properties("cephes" PROPERTIES PREFIX "")
SET_TARGET_PROPERTIES("cephes" PROPERTIES
  DEFINE_SYMBOL "CEPHES_EXPORTS"
  IMPORT_PREFIX "lib")

IF(APPLE)
  SET_TARGET_PROPERTIES("cephes" PROPERTIES
    LINK_FLAGS "-undefined dynamic_lookup")
ENDIF()

# INSTALL(FILES ${luasrc} DESTINATION ${LUADIR}/cephes)
INSTALL(TARGETS cephes
  LIBRARY DESTINATION ${LIBDIR}
  RUNTIME DESTINATION ${LUA_BINDIR})

IF(LUALIB)
  TARGET_LINK_LIBRARIES(cephes ${LUALIB})
ENDIF()


