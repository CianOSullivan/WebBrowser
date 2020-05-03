#include "Node.h"

Node::Node() {}

Node::Node(string name) {
        this->name = name;
}

Node::Node(string name, map<string, string> attrs, vector<Node> chillun){
    this->name = name;
    this->attributes = attrs;
    this->children = chillun;
}

void Node::printChildren() {
    cout << children.size() << endl;
    for (Node n : children) {
        cout << n.name << endl;
    }
}

void Node::printAttributes() {
    cout << "Printing attributes" << endl;
    for (auto item : attributes) {
        cout << item.first << " " << item.second << endl;
    }

}

vector<Node> Node::getChildren() {
    return children;
}