#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "nodeset.h"
#include "node.h"
#include "edge.h"


namespace Dijkstra {
    void print_path(Node* dest);
    void dijkstra(Node* start, std::function<int(const Node*, const Edge*)> value);
}

#endif
