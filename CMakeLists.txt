CMAKE_MINIMUM_REQUIRED(VERSION 3.10 FATAL_ERROR)

include(${CMAKE_INSTALL_PREFIX}/cmake/lua-config.cmake)
INCLUDE(${CMAKE_INSTALL_PREFIX}/share/cmake/torch/TorchConfig.cmake)

IF (MSVC)
	ADD_DEFINITIONS("/DCEPHES_EXPORTS")
ENDIF()

# libcephes compilation and installation is in its own subdirectory
ADD_SUBDIRECTORY(cephes)
