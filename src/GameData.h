#pragma once

#include "raylib.h"
#include <string>
#include <vector>

enum class GameState {
    Menu,
    Levels,
    Results
};

struct Question {
    std::string text;
    std::vector<std::string> answers;
    std::vector<int> correctAnswers;
};

//Global data
extern int WIDTH_SCREEN;
extern int HEIGHT_SCREEN;
extern GameState gameState;

extern int currentLevel;
extern bool selectedAnswers[4];
extern int correctCount;
extern int incorrectCount;

extern Vector2 mousePosition;

extern std::vector<Question> questions;

//UI
extern int btnStartWidth;
extern int btnStartHeight;
extern Rectangle btnStart;

extern int btnSubmitWidth;
extern int btnSubmitHeight;
extern Rectangle btnSubmit;

extern int btnBackWidth;
extern int btnBackHeight;
extern Rectangle btnBack;

extern int btnAnswerSize;
extern Rectangle btnAnswers[4];

//Colors
extern Color clBackground;
extern Color clBtnPassive;
extern Color clBtnActive;

//Fonts
extern Font font40;
extern Font font60;
extern Font font120;

