#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
class Node
{
    public:
        /**
         * Create an empty node
         */
        Node();

        /**
         * Make a new text node
         */
        Node(string name);

        /**
         * Make a new element node
         */
        Node(string name, map<string, string> attrs, vector<Node> chillun);

        /**
         * Print the name of the children of the node
         */
        void printChildren();

        /**
         * Prints the attributes of the node
         */
        void printAttributes();

        /**
         * Get the chidren of this node
         * 
         * @return a vector of the children nodes
         */
        vector<Node> getChildren();

        string name;                    // The name of the node

    private:
        map<string, string> attributes; // The attributes of the node
        vector<Node> children;          // The nodes children

};
#endif
