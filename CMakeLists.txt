cmake_minimum_required(VERSION 3.16)

cmake_policy(SET CMP0135 NEW)

project(Compliment VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------- QT --------------------

set(QT_DLL_DIR "C:/Qt/6.10.1/mingw_64/bin")  
set(QT_PLUGINS_DIR "C:/Qt/6.10.1/mingw_64/plugins")

set(QT_DLLS
    Qt6Core.dll
    Qt6Gui.dll
    Qt6Widgets.dll
    Qt6Network.dll
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# -------------------- INCLUDES --------------------

include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/inc/base)

include_directories(${PROJECT_SOURCE_DIR}/inc/color)
include_directories(${PROJECT_SOURCE_DIR}/inc/color/colorSetters)
include_directories(${PROJECT_SOURCE_DIR}/inc/color/gradient)

include_directories(${PROJECT_SOURCE_DIR}/inc/complimentWidgets)

include_directories(${PROJECT_SOURCE_DIR}/inc/shape)
include_directories(${PROJECT_SOURCE_DIR}/inc/shape/creators)
include_directories(${PROJECT_SOURCE_DIR}/inc/shape/shapes)

# -------------------- GOOGLE TEST --------------------

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# -------------------- SOURCES --------------------

set(PROJECT_SOURCES
    src/main.cpp
   
    src/base/shape.cpp
    src/base/basicOperations.cpp
    src/base/basicTypes.cpp

    src/shape/creators/diskCreator.cpp
    src/shape/creators/filler.cpp
    src/shape/creators/lineCreator.cpp
    src/shape/creators/donatCreator.cpp

    src/shape/shapes/disk.cpp
    src/shape/shapes/donat.cpp

    src/color/gradient/intervalConditions.cpp
    src/color/gradient/conditionExecutor.cpp
    src/color/gradient/gradientCreator.cpp
    src/color/gradient/intervalConditionsFactories.cpp
    src/color/gradient/conditionDefiner.cpp

    src/color/colorSetters/IttentGradientColorSetter.cpp

    src/complimentWidgets/colorIndicator.cpp
    src/complimentWidgets/circle.cpp

    inc/complimentWidgets/circle.h
    inc/complimentWidgets/colorIndicator.h
)

# -------------------- MAIN APP --------------------

qt_add_executable(Compliment
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(Compliment PRIVATE Qt6::Widgets)

set_target_properties(Compliment PROPERTIES WIN32_EXECUTABLE TRUE)
qt_finalize_executable(Compliment)

# -------------------- TESTS --------------------

add_executable(ComplimentTests
    src/base/basicTypes.cpp
    src/color/gradient/conditionExecutor.cpp
    tests/test_main.cpp
    tests/test_angle.cpp
    tests/test_conditonExecutor.cpp
)


# set_target_properties(ComplimentTests PROPERTIES
#     AUTOMOC OFF
#     AUTOUIC OFF
#     AUTORCC OFF
# )

target_link_libraries(ComplimentTests
    PRIVATE
    gtest_main
    gtest
    Qt6::Widgets
)

include(GoogleTest)
gtest_discover_tests(ComplimentTests)


# -------------------- POST BUILD (QT DLLS) --------------------

add_custom_command(TARGET Compliment POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:Compliment>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QT_DLL_DIR}/Qt6Core.dll $<TARGET_FILE_DIR:Compliment>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QT_DLL_DIR}/Qt6Gui.dll $<TARGET_FILE_DIR:Compliment>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QT_DLL_DIR}/Qt6Widgets.dll $<TARGET_FILE_DIR:Compliment>
)

add_custom_command(TARGET Compliment POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:Compliment>/platforms
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${QT_PLUGINS_DIR}/platforms/qwindows.dll
        $<TARGET_FILE_DIR:Compliment>/platforms
)
