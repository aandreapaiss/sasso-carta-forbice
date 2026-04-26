#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

enum MOVE{
	ROCK,
	PAPER,
	SCISSORS
};

int windowX = 800;
int windowY = 600;

int score = 0;
int opponentScore = 0;

void checkResult(int move, int opponentMove){
	if(move==0 && opponentMove==0){
			printf("Pareggio\n");
		}else if(move==1 && opponentMove==1){
			printf("Pareggio\n");
		}else if(move==2 && opponentMove==2){
			printf("Pareggio\n");
		}else if(move==0 && opponentMove==1){
			printf("Sconfitta\n");
			opponentScore++;
		}else if(move==0 && opponentMove==2){
			printf("Vittoria\n");
			score++;
		}else if(move==1 && opponentMove==0){
			printf("Vittoria\n");
			score++;			
		}else if(move==1 && opponentMove==2) {
			printf("Sconfitta\n");
			opponentScore++;
		}else if(move==2 && opponentMove==0){
			printf("Sconfitta\n");
			opponentScore++;
		}else if(move==2 && opponentMove==1){
			printf("Vittoria\n");
			score++;
		}
}

int main(void){
	printf("Hello, Funtana Niedda! \n");
	
	srand(time(NULL));
	
	Vector2 mousePoint = { 0.0f, 0.0f };

	InitWindow(windowX, windowY, "Sasso Carta Forbice");
	SetTargetFPS(60);
	
	size_t buttonSize = 96;
	size_t fontSize = 32;
	size_t moveWindowSize = buttonSize * 2;
	
	Texture2D rockTexture = LoadTexture("res/rock.png");
	Image rockSmallImage = LoadImage("res/rock.png");
	ImageResize(&rockSmallImage, 96, 96);
	Texture2D rockSmallTexture = LoadTextureFromImage(rockSmallImage);
	UnloadImage(rockSmallImage);
	Rectangle rockButton ={(windowX / 4) - buttonSize - 2, windowY - buttonSize - (buttonSize / 2) - 2, buttonSize + 4, buttonSize + 4};

	Texture2D scissorsTexture = LoadTexture("res/scissors.png");
	Image scissorsSmallImage = LoadImage("res/scissors.png");
	ImageResize(&scissorsSmallImage, 96, 96);
	Texture2D scissorsSmallTexture = LoadTextureFromImage(scissorsSmallImage);
	UnloadImage(scissorsSmallImage);
	Rectangle scissorsButton = {(windowX / 2) - (buttonSize / 2) - 2 , windowY - buttonSize - (buttonSize / 2) - 2, buttonSize + 4, buttonSize + 4};
	
	Texture2D paperTexture = LoadTexture("res/paper.png");
	Image paperSmallImage = LoadImage("res/paper.png");
	ImageResize(&paperSmallImage, 96, 96);
	Texture2D paperSmallTexture = LoadTextureFromImage(paperSmallImage);
	UnloadImage(paperSmallImage);
	Rectangle paperButton = {(windowX - (windowX / 4) - 2), windowY - buttonSize - (buttonSize / 2) - 2, buttonSize + 4, buttonSize + 4};
	
	int buttonState = 0;
	bool buttonAction = false;
	
	float displayTimer = 0.0f;
	
	int opponentMove = -1;

	while(!WindowShouldClose()){
		//Update
		mousePoint = GetMousePosition();
		
		buttonAction = false;
		
		/*if(CheckCollisionPointRec(mousePoint, rockButton)){
			if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) buttonState = 2;
			else buttonState = 0;
			
			if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) buttonAction = 1;
		}
		else buttonState = 0;
		
		if(buttonAction){
			printf("TEST------------------------------------------- \n");
		}
		*/
		
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			if(CheckCollisionPointRec(mousePoint, rockButton)){
				buttonState = ROCK;
				buttonAction = true;
			}else if(CheckCollisionPointRec(mousePoint, paperButton)){
				buttonState = PAPER;
				buttonAction = true;
			}else if(CheckCollisionPointRec(mousePoint, scissorsButton)){
				buttonState = SCISSORS;
				buttonAction = true;
			}
		}
		
		if(buttonAction){
			opponentMove = rand()%3;
			
			displayTimer = 2.0f;
			
			checkResult(buttonState, opponentMove);
		}
		
		if(displayTimer > 0.0f){
			displayTimer = displayTimer - GetFrameTime();
		}
		
		
		
		//Draw
		BeginDrawing();
		ClearBackground(WHITE);
		
		//Move Windows
		DrawRectangle((windowX / 3) - moveWindowSize, (windowY / 2) - (moveWindowSize / 1.5), moveWindowSize, moveWindowSize, WHITE);
		DrawRectangle((windowX - (windowX / 3)), (windowY / 2) - (moveWindowSize / 1.5), moveWindowSize, moveWindowSize, WHITE);
		
		if(displayTimer > 0.0f){
			switch(buttonState){
				case ROCK:
					DrawTexture(rockTexture, (windowX / 3) - moveWindowSize, (windowY / 2) - (moveWindowSize / 1.5), WHITE);
					break;
				case PAPER:
					DrawTexture(paperTexture, (windowX / 3) - moveWindowSize, (windowY / 2) - (moveWindowSize / 1.5), WHITE);
					break;
				case SCISSORS:
					DrawTexture(scissorsTexture, (windowX / 3) - moveWindowSize, (windowY / 2) - (moveWindowSize / 1.5), WHITE);
					break;
			}
			switch(opponentMove){
				case ROCK:
					DrawTexture(rockTexture, (windowX - (windowX / 3)), (windowY / 2) - (moveWindowSize / 1.5), WHITE);
					break;
				case PAPER:
					DrawTexture(paperTexture, (windowX - (windowX / 3)), (windowY / 2) - (moveWindowSize / 1.5), WHITE);
					break;
				case SCISSORS:
					DrawTexture(scissorsTexture, (windowX - (windowX / 3)), (windowY / 2) - (moveWindowSize / 1.5), WHITE);
					break;
			}
		}
		
		//Score Text
		char buf[256];
		sprintf(buf, "Score: Player %d | Opponent %d", score, opponentScore);
		DrawText(buf, fontSize, fontSize, fontSize, BLACK);
		
		//UI Game Buttons
		//Rock Button		
		DrawRectangleLinesEx(rockButton, 16, BLACK);
		DrawTexture(rockSmallTexture, (windowX / 4) - buttonSize, windowY - buttonSize - (buttonSize / 2), WHITE);
		
		
		//Scissors Button		
		DrawRectangleLinesEx(scissorsButton, 16, BLACK);
		DrawTexture(scissorsSmallTexture, (windowX / 2) - (buttonSize / 2) , windowY - buttonSize - (buttonSize / 2), WHITE);
		
		//Paper Button
		DrawRectangleLinesEx(paperButton, 16, BLACK);
		DrawTexture(paperSmallTexture, (windowX - (windowX / 4)), windowY - buttonSize - (buttonSize / 2), WHITE);
		
		EndDrawing();
	}
	
	UnloadTexture(rockTexture);
	UnloadTexture(rockSmallTexture);
	UnloadTexture(paperTexture);
	UnloadTexture(paperSmallTexture);
	UnloadTexture(scissorsTexture);
	UnloadTexture(scissorsSmallTexture);
	
	CloseWindow();
	
	return 0;
}