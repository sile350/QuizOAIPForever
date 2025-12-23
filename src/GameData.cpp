#include "GameData.h"

//Global data
int WIDTH_SCREEN = 1600;
int HEIGHT_SCREEN = 900;
GameState gameState = GameState::Menu;

int currentLevel = 0;
bool selectedAnswers[4] = { false, false, false, false };
int correctCount = 0;
int incorrectCount = 0;
std::vector<Question> questions;

Vector2 mousePosition;

//UI
int btnStartWidth = 400;
int btnStartHeight = 100;
Rectangle btnStart = { WIDTH_SCREEN / 2 - btnStartWidth / 2, HEIGHT_SCREEN / 2 - btnStartHeight / 2, 400, 100 };

int btnSubmitWidth = 400;
int btnSubmitHeight = 100;
Rectangle btnSubmit = { WIDTH_SCREEN / 2 - btnSubmitWidth / 2, HEIGHT_SCREEN - btnSubmitHeight / 2 - 100, 400, 100 };

int btnBackWidth = 400;
int btnBackHeight = 100;
Rectangle btnBack = { WIDTH_SCREEN / 2 - btnBackWidth / 2, HEIGHT_SCREEN - btnBackHeight / 2 - 100, 400, 100 };

int btnAnswerSize = 50;
Rectangle btnAnswers[4];

//Colors
Color clBackground = { 236, 216, 190, 255 };
Color clBtnPassive = { 235, 190, 132, 255 };
Color clBtnActive = { 255, 150, 80, 255 };

//Fonts
Font font40;
Font font60;
Font font120;

