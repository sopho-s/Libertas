project(libertas)

add_subdirectory(linux)

add_subdirectory(shared)

add_executable(libertas linux.cpp)

target_link_libraries(libertas
    argparser
    cron
    )