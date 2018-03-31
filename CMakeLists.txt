cmake_minimum_required(VERSION 3.9)
project(lem_in C)

set(CMAKE_C_STANDARD 99)


include_directories(${CMAKE_SOURCE_DIR}/libft/includes)
include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${CMAKE_SOURCE_DIR}/visualize/includes)
include_directories(${CMAKE_SOURCE_DIR}/visualize/minilibx_macos)

add_executable(lem_in src/main.c
        src/print_error.c
        src/parse_edge.c
        src/parse_room.c
        src/read_file.c
        src/support_func.c
        src/tmp_debug.c
        src/valid_and_set_weight.c
        src/find_ways.c

        visualize/src/main.c visualize/src/run_hooks.c visualize/src/lemin_draw_edges.c visualize/src/lemin_draw_rooms.c visualize/src/scale_rooms_coord.c

        visualize/includes/lem_in_visualizer.h
        visualize/src/ant_move.c)

add_library(libft STATIC IMPORTED) # Создание статической библиотеки
find_library(_mlx mlx)

target_link_libraries(lem_in ${_mlx})
set_property(TARGET libft PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(lem_in libft)  # Линковка программы с библиотекой