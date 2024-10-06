#include <vector>
#include <string>
#ifndef GRAPH__H
#define GRAPH__H

#pragma once

class Graph{
private:
    std::vector<std::vector<int>> adjacencyMatrix;
public:
    Graph(const std::string& filePath, const bool& oriented=false);

    void printAdjacencyMatrix() const;
};

#endif