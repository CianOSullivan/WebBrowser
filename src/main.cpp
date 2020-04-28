#include <fstream>
#include <iostream>
#include "Parser.h"
using namespace std;

int main() {
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
    Parser parser(inputString);
    // Output parsed string
    cout << parser.consume_char() << endl;
    cout << parser.parse_tag_name() << endl;
        
    return 0;
}