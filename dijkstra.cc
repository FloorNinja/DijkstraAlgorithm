#include "dijkstra.h"


void Dijkstra::print_path(Node* dest) {
    
    int length = dest->getValue();
    if(length == Node::max_value) {
        std::cout << "The path isn't defined in the graph, you should take a look at 'graf.txt'!\n";
        return;
    }

    std::vector<Node*> path;
    path.push_back(dest);
    std::string str{""};

    // Spara undan kortaste vägen.
    for(unsigned int i{0}; path[i] != nullptr; ++i) {
        path.push_back(path[i]->get_parent());
    }

    // Omvänd ordning.
    for(int i = path.size()-1; i >= 0; --i) {
        if(path[i] != nullptr) {
           str += path[i]->getName() + " -> ";
        }
    }
    str.erase(str.size()-4, 4); // Remove last separating arrow.

    std::cout << str << ", Cost: " << length << std::endl;
}

void Dijkstra::dijkstra(Node* start, std::function<int(const Node*, const Edge*)> value) {
    NodeSet ns;
    std::vector<Edge> edges;

    start->setValue(0);
    start->set_parent(nullptr); // Rot-noden har ingen förälder-nod.
    ns.add(start);
    
    while(!ns.isEmpty()) {
        Node* node = ns.removeMin();
        edges = node->getEdges();

        for(auto edge : edges) {
            Node* dest = edge.getDest();

            // Avgör kostnaden att gå mellan noder.
            int cost = value(node, &edge);

            // Räkna ut lägsta kostnaden.
            if(cost < dest->getValue()) {
                dest->setValue(cost);
                dest->set_parent(node);
                ns.add(dest);
            }
        }
    }
}
