#include <iostream>
#include "raylib.h"
#include "displayWindow.h"


void windowDisplayClass::showWindow() {
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Menu Screen");
	SetTargetFPS(60);
	
	Rectangle rect1 = {(float)screenWidth/2, (float)screenHeight/2, 30, 30};

	// main event loop
	while (!WindowShouldClose()) {
		//implement key events
		if (IsKeyDown(KEY_UP)) { rect1.y -= 3.0f;}
		if (IsKeyDown(KEY_DOWN)) { rect1.y += 3.0f; }
		if (IsKeyDown(KEY_RIGHT)) { rect1.x += 3.0f; }
		if (IsKeyDown(KEY_LEFT)) { rect1.x -= 3.0f; }

		//colision detection for x axis
		if ((rect1.x + rect1.width) >= screenWidth){ rect1.x = screenWidth - rect1.width; }
		else if (rect1.x <= 0) { rect1.x = 0;}

		//collision detection for y axis
		if ((rect1.y + rect1.height) >= screenHeight) { rect1.y = screenHeight - rect1.height; }
		else if (rect1.y <= 0) { rect1.y = 0; }

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Move player with arrow keys!", 10, 10, 15, WHITE);
		
		//draw player
		DrawRectangle(rect1.x, rect1.y, 30, 30, WHITE);

		//add enemies
		//add score
		//add game over screen
		//add death
		//add on death button to restart
		
		EndDrawing();
	}
	CloseWindow();
}

