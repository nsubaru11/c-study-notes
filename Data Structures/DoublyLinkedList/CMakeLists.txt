cmake_minimum_required(VERSION 3.31)
project(DoublyLinkedList C)

set(CMAKE_C_STANDARD 23)

add_executable(DoublyLinkedList main.c
        DoublyLinkedList.c
        DoublyLinkedList.h)
