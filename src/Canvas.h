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
        Canvas(Node);
        void printTree();
        void Draw();

    private:
        Node rootNode;
};
#endif