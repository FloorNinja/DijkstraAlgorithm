#include "node.h"
#include "edge.h"
class Node;

/** Skapa en ny båge till noden destination, med längden length. */
Edge::Edge(Node* destination, int length) {
    this->destination = destination;
    this->length = length;
}
