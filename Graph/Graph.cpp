#include "Graph.hpp"
#include <fstream>
#include <iostream>

Graph::Graph(const std::string& filePath, const bool& oriented){
    this->adjacencyMatrix = makeAdjacencyMatrix(filePath, oriented);
    this->adjacencyList = makeAdjacencyList(filePath, oriented);
}

void Graph::printAdjacencyMatrix() const{
    for(const auto& line : adjacencyMatrix){
        for(const auto& value : line){
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void Graph::printAdjacencyList() const{
    for(const auto& line : adjacencyList){
        for(const auto& value : line){
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<int>> Graph::makeAdjacencyMatrix(const std::string& filePath, const bool& oriented) const{
    int nodes, edges;
    std::ifstream in(filePath);

    in >> nodes >> edges;

    // Indexed from 1 for more intuitive operations.
    std::vector<std::vector<int>> adjacencyMatrix(nodes+1, std::vector<int>(nodes+1,0));

    for(int i=0; i < edges; i++){
        int node1, node2;
        in >> node1 >> node2;

        adjacencyMatrix[node1][node2] = 1;

        if(!oriented){
            adjacencyMatrix[node2][node1] = 1;
        } 
    }
    in.close();

    return adjacencyMatrix;
}

std::vector<std::vector<int>> Graph::makeAdjacencyList(const std::string& filePath, const bool& oriented) const{
    int nodes, edges;
    std::ifstream in(filePath);

    in >> nodes >> edges;

    // Indexed from 1 for more intuitive operations.
    std::vector<std::vector<int>> adjacencyList(nodes+1);

    for(int i=0; i<edges; i++){
        int node1, node2;
        in >> node1 >> node2;

        adjacencyList[node1].push_back(node2);

        if(!oriented){
            adjacencyList[node2].push_back(node1);
        }
    }
    in.close();

    return adjacencyList;
}