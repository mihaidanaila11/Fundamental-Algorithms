#include "Graph.hpp"
#include <fstream>
#include <iostream>

Graph::Graph(const std::string& filePath, const bool& oriented){
    int nodes, edges;
    std::ifstream in(filePath);

    in >> nodes >> edges;

    // Indexed from 1 for more intuitive operations.
    adjacencyMatrix = std::vector<std::vector<int>>(nodes+1, std::vector<int>(nodes+1,0));

    for(int i=0; i < edges; i++){
        int node1, node2;
        in >> node1 >> node2;

        adjacencyMatrix[node1][node2] = 1;

        if(!oriented){
            adjacencyMatrix[node2][node1] = 1;
        } 
    }
}

void Graph::printAdjacencyMatrix() const{
    for(const auto& line : adjacencyMatrix){
        for(const auto& value : line){
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}