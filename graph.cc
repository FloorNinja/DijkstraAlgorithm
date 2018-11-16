#include "graph.h"


Node* Graph::find_or_create(std::string& target) {
    auto node = find(target);
    if(node == nullptr) {
        node = addNode(target);
    }
    return node;
}

Graph::Graph(std::istream& in) {
    std::string line;
    while(std::getline(in, line)) {
        std::string from, to;
        int length{0};
        unsigned int prev_pos{0}, pos{0};

        // From
        pos = line.find(": ", pos+1);
        from = line.substr(0, pos);

        // Length
        prev_pos = pos;
        pos = line.find(" ", pos+2);
        length = stoi(line.substr(prev_pos+1, pos-1));

        // To
        to = line.substr(pos+1, line.size());

        auto node_from = find_or_create(from);
        auto node_to = find_or_create(to);
        node_from->addEdge(node_to, length);
    }

    #ifdef DEBUG
    // DEBUG: PRINT OUT ENTIRE GRAPH INCLUDING EDGES
    std::cout << "\nDEBUGGING:\n";
    for(auto node : nodes) {
        std::cout << " [N] " << node->getName() << "\n";
        for(auto edge : node->getEdges()) {
            std::cout << "  [E] " << edge.getDest()->getName() << " " << edge.getLength() << "\n";
        }
    }
    std::cout << "\n";
    #endif
}

Node* Graph::addNode(std::string name) {
    Node* node = new Node(name);
    nodes.push_back(node);
    return node;
}

Node* Graph::find(std::string find) {
    for(auto node : nodes) {
        if(find == node->getName()) {
            return node;
        }
    }
    return nullptr;
}

void Graph::resetVals() {
    for(auto node : nodes)
        node->setValue(Node::max_value);
}
