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

std::vector<std::vector<int>> Graph::getAdjacencyMatrix() const{
    return this->adjacencyMatrix;
}

std::vector<std::vector<int>> Graph::getAdjacencyList() const{
    return this->adjacencyList;
}

std::vector<std::vector<int>> Graph::matrixToList(const std::vector<std::vector<int>>& matrix){
    std::vector<std::vector<int>> adjacencyList(matrix.size());

    for(int i=1; i < matrix.size(); i++){
        for(int j=1; j< matrix.size(); j++){
            if(matrix[i][j]){
                adjacencyList[i].push_back(j);
            }
        }
    }

    return adjacencyList;
}

std::vector<std::vector<int>> Graph::listToMatrix(const std::vector<std::vector<int>> &list)
{
    std::vector<std::vector<int>> adjacencyMatrix(list.size(), std::vector<int>(list.size(), 0));

    for(int i=1; i<list.size(); i++){
        for(const auto& value : list[i]){
            adjacencyMatrix[i][value] = 1;
        }
    }

    return adjacencyMatrix;
}