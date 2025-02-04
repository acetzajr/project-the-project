file(GLOB_RECURSE SOURCE "source/*.c" "source/*.h")
add_executable(game-the-game ${SOURCE})
target_include_directories(game-the-game PRIVATE "include")
target_link_libraries(game-the-game m PkgConfig::SDL3)