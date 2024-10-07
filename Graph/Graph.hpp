#include <vector>
#include <string>
#ifndef GRAPH__H
#define GRAPH__H

#pragma once

class Graph{
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<std::vector<int>> adjacencyList;
public:
    Graph(const std::string& filePath, const bool& oriented=false);

    void printAdjacencyMatrix() const;
    void printAdjacencyList() const;

    static std::vector<std::vector<int>> matrixToList(const std::vector<std::vector<int>>& matrix);
    static std::vector<std::vector<int>> listToMatrix(const std::vector<std::vector<int>>& list);

    std::vector<std::vector<int>> getAdjacencyMatrix() const;
    std::vector<std::vector<int>> getAdjacencyList() const;

private:
    std::vector<std::vector<int>> makeAdjacencyMatrix(const std::string& filePath, const bool& oriented=false) const;
    std::vector<std::vector<int>> makeAdjacencyList(const std::string& filePath, const bool& oriented=false) const;
};

#endif