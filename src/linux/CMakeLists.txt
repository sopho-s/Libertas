add_library(cron cron.cpp cron.h)
add_library(filesystem filesystem.cpp filesystem.h)
add_library(exec exec.cpp exec.h)
target_link_libraries(filesystem
    exec
)
target_link_libraries(cron
    filesystem
    toolpage
)