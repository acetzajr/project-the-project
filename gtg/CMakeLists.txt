file(GLOB_RECURSE SOURCE "source/*.c" "source/*.h")
add_executable(gtg ${SOURCE})
target_include_directories(gtg PRIVATE "include")
target_link_libraries(gtg m PkgConfig::SDL3)