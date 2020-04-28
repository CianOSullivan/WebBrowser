#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

class Node
{
    public:
        Node(std::string name);
    private:
        std::vector<Node> children;

};
#endif
