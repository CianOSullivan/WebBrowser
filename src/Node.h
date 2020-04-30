#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <map>

using namespace std;
class Node
{
    public:
        Node(string name); // Text element
        Node(string name, map<string, string> attrs, vector<Node> chillun);
    private:
        string name;
        map<string, string> attributes;
        vector<Node> children;

};
#endif
