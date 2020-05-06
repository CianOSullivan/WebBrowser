#include "Canvas.h"

Canvas::Canvas(Node n) {
    rootNode = n;
    for (Node n : rootNode.getChildren()) {
        if (n.name == "header") {
            header = n;
        } else if (n.name == "body") {
            body = n;
        } else if (n.name == "footer") {
            footer = n;
        }
    }
    parseHeader();
}

void Canvas::printTree() {
    rootNode.printChildren();

    body.printChildren();
    for (Node n : body.getChildren()) {
        n.printChildren();

    }
    body.printAttributes();
}

void Canvas::parseHeader() {
    cout << "Parsing header" << endl;
    for (Node n : header.getChildren()) {
        cout << n.name << endl;
        if (n.name == "title") {
            windowTitle = n.getChildren()[0].name;
        }
    }
}

void Canvas::Draw() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char *title = windowTitle.c_str(); // Convert string to char array
    InitWindow(screenWidth, screenHeight, title);

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
}