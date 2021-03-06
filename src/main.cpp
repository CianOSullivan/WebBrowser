#include <fstream>
#include <iostream>
#include "Parser.h"
#include "Canvas.h"
using namespace std;

int main(int argc, char* argv[]) {
    // Open test.html
    ifstream inFile;
    string inputString, tmp;
    inFile.open("src/test.html");
    if (!inFile) {
        cout << "Unable to open file" << endl;
        exit(1); // terminate with error
    }
    // Read the file into a string
    while (!inFile.eof()) {
        getline(inFile, tmp);
        inputString += tmp;
    }

    inFile.close();
    // Get the length in bytes
    int length = inputString.length();
    // Pass the string the parser
    Parser parser;
    // Output parsed string
    cout<< "Input String: " << inputString << endl;
    Node rootNode = parser.parse(inputString);
    Canvas canvas(rootNode);
    canvas.Draw();
    canvas.printTree();

    return 0;
}