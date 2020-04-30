#include "Node.h"

Node::Node(string name) {
        this->name = name;
}

Node::Node(string name, map<string, string> attrs, vector<Node> chillun){
    this->name = name;
    this->attributes = attrs;
    this->children = chillun;
}
