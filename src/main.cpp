#include <fstream>
#include <iostream>
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

    while (!inFile.eof()) {
        getline(inFile, tmp);
        inputString += tmp;
    }
    cout << inputString << endl;
    inFile.close();
    return 0;
    // Get the length in bytes
    // Read the file into a string
    // Pass the string the parser
    // Output parsed string
}