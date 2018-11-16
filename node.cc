#include <string>
#include <limits>
#include "node.h"
class Edge;

/**Skapar en nod med givet namn, utan bågar och med maximalt värde.*/
Node::Node(const std::string& name) {
    this->name = name; 
    this->value = max_value;
}
