#include "nodeset.h"


/** Väljer ut den nod som har lägst värde och returnerar den.
  Den returnerade noden tas bort ur mängden.
  Om mängden är tom returneras null. */
Node* NodeSet::removeMin() {
    if(!isEmpty()) {
        int min{Node::max_value};
        int mindex{0};

        for(unsigned int i{0}; i < setOfNodes.size(); ++i) {
            if(setOfNodes[i]->getValue() < min) {
                min = setOfNodes[i]->getValue();
                mindex = i;
            }
        }

        Node* node = setOfNodes[mindex];
        setOfNodes.erase(setOfNodes.begin()+mindex);
        return node;
    }

    return NULL;
}


/** Lägger till noden node till mängden,
  om mängden inte redan innehåller en nod med samma namn. */
void NodeSet::add(Node* node) {
    bool good{true};
    for(auto n : setOfNodes) {
        if(n->getName() == node->getName()) {
            good = false;
            break;
        }
    }
    if(good)
        setOfNodes.push_back(node);
}
