find_package(GTest CONFIG REQUIRED)

# add_executable(units_tests
#     #test_main.cpp
# )

add_executable(account
    test_account.cpp
)

target_link_libraries(account
    PRIVATE
        GTest::gtest_main
        domain_lib
)

target_include_directories(domain_lib PUBLIC include)

add_test(
    NAME account
    COMMAND account
)

include(GoogleTest)
gtest_discover_tests(account)
