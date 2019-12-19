cmake_minimum_required(VERSION 3.15)
project(_ordering_food C)

set(CMAKE_C_STANDARD 99)

add_executable(_ordering_food main.c input_from_customer.c input_from_customer.h display_menu.c display_menu.h display_order.c display_order.h loading_data.c loading_data.h drinks.c drinks.h foods.c foods.h types.c types.h)