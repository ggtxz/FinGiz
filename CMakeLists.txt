cmake_minimum_required(VERSION 3.20)
project(fingiz VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Opções de compilação
if(MSVC)
    add_compile_options(/W4 /permissive- /Zc:preprocessor)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Buscar bibliotecas
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Executável principal
add_library(fingiz_lib
    src/lib/domain/account.cpp
    src/lib/service/finance_service.cpp
)
target_include_directories(fingiz_lib PUBLIC include)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    fmt::fmt
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    fingiz_lib
)

# Testes (opcional)
enable_testing()
add_subdirectory(tests)
