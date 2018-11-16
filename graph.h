#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include "node.h"
#include "edge.h"


class Graph {
    public:
        Graph() {}
        Graph(std::istream& in);
        Node* addNode(std::string name);
        Node* find(std::string find);
        Node* find_or_create(std::string& target);
        void resetVals();

        std::vector<Node*>::iterator begin() { return nodes.begin(); }
        std::vector<Node*>::iterator end() { return nodes.end(); }
    private:
        std::vector<Node*> nodes;
};

#endif
