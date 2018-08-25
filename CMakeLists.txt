cmake_minimum_required(VERSION 3.6)
project(ft_ssl_md5 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(ft_ssl_md5 src/main.c src/ft_ssl_md5.h)

target_link_libraries(ft_ssl_md5 ${CMAKE_SOURCE_DIR}/libft/libft.a)
