cmake_minimum_required(VERSION 2.8)

set(DEFERRED_DIR src/cthis)
set(DEFERRED_SRC ${DEFERRED_DIR}/cthis.c)

set(EXEMPLE1_DIR src/exemples)
set(EXEMPLE1_SRC ${EXEMPLE1_DIR}/main1.c ${EXEMPLE1_DIR}/car.c)


include_directories(src/cthis)
add_library(cthis STATIC ${DEFERRED_SRC})

add_executable(exemple1 ${EXEMPLE1_SRC})
target_link_libraries(exemple1 cthis)