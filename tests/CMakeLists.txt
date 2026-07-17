find_package(Catch2 3 CONFIG REQUIRED)

add_executable(jobboards_tests test_job_posting.cpp)
target_link_libraries(jobboards_tests PRIVATE jobboards_core Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(jobboards_tests)
