#ifndef CANVAS_H
#define CANVAS_H
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Node.h"
#include "raylib.h"

using namespace std;
class Canvas
{
    public:
        /**
         * Make a new canvas
         * 
         * @param Node the root node of the DOM tree
         */
        Canvas(Node);

        /**
         * Simple tree printing
         */
        void printTree();

        /**
         * Make a new window and draw html in window
         */
        void Draw();

    private:
        /**
         * Print all the nodes of the header
         */
        void parseHeader();

        Node rootNode;          // The root node of the DOM tree
        Node header;            // The html header node
        Node body;              // The html body node
        Node footer;            // The html footer node
        string windowTitle;     // The title of the html file
};
#endif