#include <fstream>
#include <iostream>
#include "Parser.h"
#include "raylib.h"
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
    //cout << parser.consume_char() << endl;
    //cout << parser.parse_tag_name() << endl;
    cout<< "Input String: " << inputString << endl;
    Node rootNode = parser.parse(inputString);
    rootNode.printChildren();
    vector<Node> children = rootNode.getChildren();
    Node body;
    for (Node n : children) {
        if (n.name == "body") {
            body = n;
        }
    }
    body.printChildren();
    for (Node n : body.getChildren()) {
        n.printChildren();

    }
    body.printAttributes();
        // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}