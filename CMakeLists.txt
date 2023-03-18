cmake_minimum_required(VERSION 3.0.0)
project(edge-app VERSION 0.1.0)

include(CTest)
enable_testing()

link_directories(/media/psf/share/edge-guard/edge-lib/build)
include_directories(/media/psf/share/edge-guard/edge-lib/)

add_executable(edge-app main.c)
target_link_libraries(edge-app edge-lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
