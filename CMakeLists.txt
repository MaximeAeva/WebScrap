cmake_minimum_required(VERSION 3.0.0)
project(WebScrap VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include)
include_directories(lib/curl-7.71.1-win64-mingw/include/curl)

add_executable(MyExec
  src/main.cpp
  src/com.cpp
  include/com.h
)



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
