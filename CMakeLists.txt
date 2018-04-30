CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.6)

INCLUDE(${CMAKE_INSTALL_PREFIX}/share/cmake/torch/TorchConfig.cmake)

IF (MSVC)
	ADD_DEFINITIONS("/DCEPHES_EXPORTS")
ENDIF()

# libcephes compilation and installation is in its own subdirectory
ADD_SUBDIRECTORY(cephes)
