find_package(GTest CONFIG REQUIRED)

add_executable(account
    test_account.cpp
)

target_link_libraries(account
    PRIVATE
        GTest::gtest_main
        fingiz_lib
)

add_test(
    NAME account
    COMMAND account
)

include(GoogleTest)
gtest_discover_tests(account)

# Testes do FinanceService
add_executable(finance_service_test
    test_finance_service.cpp
)

target_link_libraries(finance_service_test
    PRIVATE
        GTest::gtest_main
        fingiz_lib
)

gtest_discover_tests(finance_service_test)
