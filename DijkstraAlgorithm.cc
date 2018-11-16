#include <iostream>
#include <fstream>
#include <cassert>
#include "dijkstra.h"
#include "graph.h"
#include "nodeset.h"
#include "node.h"


int main () {
    std::ifstream infile("graf.txt");
    Graph g(infile);

    std::string from, to;

    std::cout << "From: ";
    std::getline(std::cin, from);
    Node* nodeFrom = g.find(from);
    if(nodeFrom == nullptr) {
        std::cout << "Error: '" << from << "' isn't in the graph!\n";
        return 1;
    }

    std::cout << "To: ";
    std::getline(std::cin, to);
    Node* nodeTo = g.find(to);
    if(nodeTo == nullptr) {
        std::cout << "Error: '" << to << "' isn't in the graph!\n";
        return 1;
    }

    unsigned int option;
    std::cout << "How do you want to calculate the cost?\n"
              << " [1] By distance.\n"
              << " [2] By amount of nodes traversed.\n"
              << "Choose: ";
    std::cin >> option;
    
    switch(option) {
        case 1:
            Dijkstra::dijkstra(nodeFrom, 
                [](const Node* node, const Edge* edge) {
                    return node->getValue() + edge->getLength();
                });
            break;
        case 2:
            Dijkstra::dijkstra(nodeFrom, 
                [](const Node* node, const Edge* edge) {
                    return 1;
                });
            break;
        default:
            std::cout << "Error: Not a real option.\n";
            return 1;
    }

    Dijkstra::print_path(nodeTo);

    return 0;
}
