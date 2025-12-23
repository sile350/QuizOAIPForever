#include "GameLogic.h"
#include "GameData.h"

void ResetGame() {
    currentLevel = 0;
    correctCount = 0;
    incorrectCount = 0;
    for (int i = 0; i < 4; i++) {
        selectedAnswers[i] = false;
    }
}

void StartQuiz() {
    gameState = GameState::Levels;
    ResetGame();
}

bool CheckAnswer() {
    bool isCorrect = true;
    
    int selectedCount = 0;
    for (int i = 0; i < 4; i++) {
        if (selectedAnswers[i]) selectedCount++;
    }
    
    if (selectedCount != questions[currentLevel].correctAnswers.size()) {
        isCorrect = false;
    } else {
        for (int i = 0; i < 4; i++) {
            if (selectedAnswers[i]) {
                bool found = false;
                for (int correctIdx : questions[currentLevel].correctAnswers) {
                    if (i == correctIdx) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    isCorrect = false;
                    break;
                }
            }
        }
    }
    
    return isCorrect;
}

void NextQuestion() {
    currentLevel++;
    for (int i = 0; i < 4; i++) {
        selectedAnswers[i] = false;
    }
    
    if (currentLevel >= questions.size()) {
        gameState = GameState::Results;
        currentLevel = 0;
    }
}

int CalculateGrade() {
    int totalQuestions = questions.size();
    float grade = ((float)correctCount / totalQuestions) * 10.0f;
    return (int)(grade + 0.5f);
}

