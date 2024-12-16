cmake_minimum_required(VERSION 3.30)
project(GraphAlgorithms)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphAlgorithms src/app/Main.cpp
        inc/algorithms/BellmanFord.h
        src/algorithms/BellmanFord.cpp
        inc/algorithms/Dijkstra.h
        src/algorithms/Dijkstra.cpp
        inc/algorithms/Kruskal.h
        src/algorithms/Kruskal.cpp
        inc/algorithms/Prim.h
        src/algorithms/Prim.cpp
        inc/structures/AdjacencyList.h
        src/structures/AdjacencyList.cpp
        inc/structures/IncidenceMatrix.h
        src/structures/IncidenceMatrix.cpp
        inc/structures/EdgesList.h
        inc/utilities/GenerateGraph.h
        src/utilities/GenerateGraph.cpp
        inc/ui/Menu.h
        src/ui/Menu.cpp
        inc/utilities/ReadGraph.h
        src/utilities/ReadGraph.cpp
        inc/utilities/Test.h
        src/utilities/Test.cpp
        inc/utilities/TransformGenerated.h
        src/utilities/TransformGenerated.cpp)

target_include_directories(GraphAlgorithms PRIVATE inc)