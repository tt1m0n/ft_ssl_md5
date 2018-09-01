cmake_minimum_required(VERSION 3.6)
project(ft_ssl_md5 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(ft_ssl_md5 src/ft_sha.c src/ft_md5.c
                src/ft_sha.h src/ft_md5.h src/main.c src/ft_global.h src/ft_global.c src/ft_sha_384_512.c src/init_start_words.c src/ft_main_hash_function.c src/ft_parse_and_read.c src/ft_parse_and_read.h src/ft_sha_helpers.c)

target_link_libraries(ft_ssl_md5 ${CMAKE_SOURCE_DIR}/libft/libft.a)
