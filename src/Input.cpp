#include "Input.h"
#include "GameData.h"
#include "GameLogic.h"

void HandleMenuInput() {
    if (CheckCollisionPointRec(mousePosition, btnStart)) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            StartQuiz();
        }
    }
}

void HandleLevelInput() {
    for (int i = 0; i < 4; i++) {
        float yOffset = 50 + i * 80;
        btnAnswers[i] = { 
            (float)(WIDTH_SCREEN / 2 - 550), 
            (float)(HEIGHT_SCREEN / 2 - 100 + yOffset),
            (float)btnAnswerSize, 
            (float)btnAnswerSize 
        };
    }
    
    btnSubmit = { 
        (float)(WIDTH_SCREEN / 2 - btnSubmitWidth / 2), 
        (float)(HEIGHT_SCREEN - btnSubmitHeight - 50), 
        (float)btnSubmitWidth, 
        (float)btnSubmitHeight 
    };
    
    for (int i = 0; i < 4; i++) {
        if (CheckCollisionPointRec(mousePosition, btnAnswers[i])) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                selectedAnswers[i] = !selectedAnswers[i];
            }
        }
    }
    
    bool hasSelection = false;
    for (int i = 0; i < 4; i++) {
        if (selectedAnswers[i]) {
            hasSelection = true;
            break;
        }
    }
    
    if (CheckCollisionPointRec(mousePosition, btnSubmit)) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && hasSelection) {
            bool isCorrect = CheckAnswer();
            
            if (isCorrect) {
                correctCount++;
            } else {
                incorrectCount++;
            }
            
            NextQuestion();
        }
    }
}

void HandleResultsInput() {
    btnBack = { 
        (float)(WIDTH_SCREEN / 2 - btnBackWidth / 2), 
        (float)(HEIGHT_SCREEN - btnBackHeight - 50), 
        (float)btnBackWidth, 
        (float)btnBackHeight 
    };
    
    if (CheckCollisionPointRec(mousePosition, btnBack)) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            gameState = GameState::Menu;
        }
    }
}

