cmake_minimum_required(VERSION 3.25)
project(JobBoards VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(jobboards_core STATIC
    src/job_posting.cpp
    src/scraper.cpp
    src/cli/scrape.cpp
)
target_include_directories(jobboards_core PUBLIC include)
if(MSVC)
    target_compile_options(jobboards_core PRIVATE /W4)
endif()

add_executable(jobboards src/cli/main.cpp)
target_link_libraries(jobboards PRIVATE jobboards_core)

enable_testing()
add_subdirectory(tests)
