#ifndef EDGE_H
#define EDGE_H

#include "node.h"


// Class-forwarding
class Node;

class Edge {
    public:
        /** Skapa en ny båge till noden destination, med längden length. */
        Edge(Node* destination, int length);

        /** Hämtar bågens destination. */
        Node* getDest() const { return destination; }
        
        /** Hämtar bågens längd. */
        int getLength() const { return length; }
    private:
        int length;
        Node* destination;
};

#endif
