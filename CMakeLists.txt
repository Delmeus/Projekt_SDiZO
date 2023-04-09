cmake_minimum_required(VERSION 3.24)
project(projekt_pierwszy)

set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(projekt_pierwszy main.cpp utils/FileRandomizer.cpp utils/FileRandomizer.h structures/table/Table.cpp structures/table/Table.h testers/Tester.cpp testers/Tester.h utils/Timer.cpp utils/Timer.h testers/AutomaticTester.cpp testers/AutomaticTester.h structures/list/List.cpp structures/list/List.h structures/list/ListElement.cpp structures/list/ListElement.h structures/heap/Heap.cpp structures/heap/Heap.h structures/tree/Tree.cpp structures/tree/Tree.h structures/tree/Node.cpp structures/tree/Node.h)


