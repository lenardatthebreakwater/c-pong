#include "raylib.h"
#include <string.h>

typedef struct Ball {
	int x;
	int y;
	float radius;
	int speedX;
	int speedY;
	Color color;
} Ball;


typedef struct Player {
	int x; 
	int y;
	int speed;
	int width;
	int height;
	Color color;
} Player;


int main(void) {

	int screenWidth = 800;
	int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Pong");
	SetTargetFPS(60);
	
	Ball ball = {screenWidth / 2, screenHeight / 2, 15, 5, 5, WHITE};
	Player player1 = {10 , (screenHeight / 2) - 75, 6, 14, 150, WHITE};
	Player player2 = {(screenWidth - 14) - 10, (screenHeight / 2) - 75, 6, 14, 150, WHITE};

	Rectangle player1Rect = {player1.x, player1.y, player1.width, player1.height};
	Rectangle player2Rect = {player2.x, player2.y, player2.width, player2.height};

	char winnerText[30] = { 0 };

	while (!WindowShouldClose()) {

		ball.x += ball.speedX;
		ball.y += ball.speedY;
		if (ball.y < 0) {
			ball.y = 0;
			ball.speedY *= -1;
		}
		if (ball.y > (screenHeight - ball.radius)) {
			ball.y = (screenHeight - ball.radius);
			ball.speedY *= -1;
		}
		if (ball.x < 0) {
			memcpy(winnerText, "Player 2 Wins", 14);
		}
		if (ball.x > screenWidth) {
			memcpy(winnerText, "Player 1 Wins", 14);
		}
		if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, player1Rect)) {
			if (ball.speedX < 0) {
				ball.speedX *= -1;
			}
		}
		if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, player2Rect)) {
			if (ball.speedX > 0) {
				ball.speedX *= -1;
			}
		}


		if (IsKeyDown(KEY_W)) {
			player1Rect.y -= player1.speed; 			
		}
		if (IsKeyDown(KEY_S)) {
			player1Rect.y += player1.speed;
		}
		if (player1Rect.y < 0) {
			player1Rect.y = 0;
		}
		if (player1Rect.y > (screenHeight - player1Rect.height)) {
			player1Rect.y = (screenHeight - player1Rect.height);
		}


		if (IsKeyDown(KEY_UP)) {
			player2Rect.y -= player2.speed;			
		}
		if (IsKeyDown(KEY_DOWN)) {
			player2Rect.y += player2.speed;
		}
		if (player2Rect.y < 0) {
			player2Rect.y = 0;
		}
		if (player2Rect.y > (screenHeight - player2Rect.height)) {
			player2Rect.y = (screenHeight - player2Rect.height);
		}


		if (winnerText && IsKeyPressed(KEY_SPACE)) {
			ball.x = screenWidth / 2;
			ball.y = screenHeight / 2;
			memcpy(winnerText, "", 1);
		}


		BeginDrawing();
		ClearBackground(BLACK);
		DrawCircle(ball.x, ball.y, ball.radius, ball.color);
		DrawRectangleRec(player1Rect, player1.color);
		DrawRectangleRec(player2Rect, player2.color);
		if (winnerText) {
			int winnerTextWidth = MeasureText(winnerText, 40);
			DrawText(winnerText, screenWidth / 2 - winnerTextWidth / 2, screenHeight / 2 - 30, 40, YELLOW);
		}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
