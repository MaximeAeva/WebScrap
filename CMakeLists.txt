cmake_minimum_required(VERSION 3.0.0)

project(WebScrap)

include(CTest)
enable_testing()

file(

        GLOB_RECURSE

        SRCS

        src/*
)
    
file(

        GLOB_RECURSE

        HEADERS

        include/*
)

add_executable (WebScrap ${SRCS} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
