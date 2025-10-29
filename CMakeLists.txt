cmake_minimum_required(VERSION 3.31)
project(c-study-notes C)

set(CMAKE_C_STANDARD 23)

# Data Structures: Binary Search Tree
add_executable(BinarySearchTree "Data Structures/BinarySearchTree/main.c" "Data Structures/BinarySearchTree/BinarySearchTree.c" "Data Structures/BinarySearchTree/BinarySearchTree.h")

# Data Structures: String
add_executable(String "Data Structures/String/main.c" "Data Structures/String/string.c" "Data Structures/String/string.h")

# Data Structures: Doubly Linked List
add_executable(DoublyLinkedList "Data Structures/DoublyLinkedList/main.c" "Data Structures/DoublyLinkedList/DoublyLinkedList.c" "Data Structures/DoublyLinkedList/DoublyLinkedList.h")

# Data Structures: Hash MultiSet
add_executable(HashMultiSet "Data Structures/HashMultiSet/main.c" "Data Structures/HashMultiSet/HashMultiSet.c" "Data Structures/HashMultiSet/HashMultiSet.h")

# Data Structures: Printer
add_executable(Printer "Data Structures/Printer/main.c" "Data Structures/Printer/printer.c" "Data Structures/Printer/printer.h")

# Data Structures: Scanner
add_executable(Scanner 
        "Data Structures/Scanner/main.c" 
        "Data Structures/Scanner/scanner.c" 
        "Data Structures/Scanner/scanner.h"
        "Data Structures/String/string.c"
        "Data Structures/String/string.h"
)
