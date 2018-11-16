#ifndef NODE_H
#define NODE_H

#include <string>
#include <limits>
#include <vector>
#include "edge.h"


// Class-forwarding
class Edge;

class Node {
    public:
        /**Skapar en nod med givet namn, utan bågar och med maximalt värde.*/
        Node(const std::string& name);

        /**Destruerar Node* parent. Destruering av std::vector<Edge> edges, sköter std::vector.*/
        //~Node() { delete parent; }

        /**Hämtar nodens namn.*/
        std::string getName() const { return name; }

        /**Sätter nodens värde till v.*/
        void setValue(int v) { value = v; }

        /**Hämtar nodens värde.*/
        int getValue() const { return value; }

        /**Lägger till en ny båge från denna nod till en given destination.
          Bågen ska ha längden length.*/
        void addEdge(Node* destination, int length) { edges.emplace_back(destination, length); }

        /**Hämtar de bågar som utgår från denna nod.*/
        const std::vector<Edge>& getEdges() const { return edges; }
        
        /**Hämtar förälder-noden.*/
        Node* get_parent() { return parent; }

        /**Sätter förälder-noden.*/
        void set_parent(Node* parent) { this->parent = parent; }

        const static int max_value{std::numeric_limits<int>::max()};
    private:
        int value;
        std::string name;
        std::vector<Edge> edges;
        Node* parent;
};

#endif
