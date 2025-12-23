#include "Rendering.h"
#include "GameData.h"
#include "GameLogic.h"
#include "UiUtils.h"

void RenderMenu() {
    bool isHoverStart = CheckCollisionPointRec(mousePosition, btnStart);
    Color btnStartColor = isHoverStart ? DarkenColor(clBtnPassive) : clBtnPassive;
    DrawRectangleRounded(btnStart, 0.5f, 10, btnStartColor);
    
    Vector2 titleSize = MeasureTextEx(font120, "Quiz OAIP", 120, 3);
    DrawTextEx(font120, "Quiz OAIP", 
        { (WIDTH_SCREEN / 2.0f) - titleSize.x / 2, (HEIGHT_SCREEN / 2.0f) - titleSize.y / 2 - 200 }, 
        120, 3, BLACK);
    
    Vector2 btnTextSize = MeasureTextEx(font60, "СТАРТ", 60, 0);
    DrawTextEx(font60, "СТАРТ", 
        { (WIDTH_SCREEN / 2.0f) - btnTextSize.x / 2, (HEIGHT_SCREEN / 2.0f) - btnTextSize.y / 2 }, 
        60, 0, BLACK);
}

void RenderLevel() {
    std::string levelText = "ВОПРОС " + std::to_string(currentLevel + 1);
    Vector2 levelTextSize = MeasureTextEx(font120, levelText.c_str(), 120, 3);
    DrawTextEx(font120, levelText.c_str(), 
        { (float)(WIDTH_SCREEN / 2) - levelTextSize.x / 2, 50 }, 
        120, 3, BLACK);
    
    const char* questionText = questions[currentLevel].text.c_str();
    Vector2 questionSize = MeasureTextEx(font40, questionText, 40, 3);
    float questionX = (float)(WIDTH_SCREEN / 2) - questionSize.x / 2;
    float questionY = 200;
    
    DrawTextEx(font40, questionText, 
        { questionX, questionY }, 
        40, 3, BLACK);
    
    for (int i = 0; i < 4; i++) {
        float yOffset = 50 + i * 80;
        float yPos = HEIGHT_SCREEN / 2 - 100 + yOffset;
        
        bool isHoverAnswer = CheckCollisionPointRec(mousePosition, btnAnswers[i]);
        Color baseColor = selectedAnswers[i] ? clBtnActive : clBtnPassive;
        Color btnColor = isHoverAnswer ? DarkenColor(baseColor) : baseColor;
        DrawRectangleRounded(btnAnswers[i], 0.3f, 10, btnColor);
        
        const char* answerText = questions[currentLevel].answers[i].c_str();
        float answerX = (float)(WIDTH_SCREEN / 2 - 450);
        
        DrawTextEx(font40, answerText, 
            { answerX, yPos }, 
            40, 3, BLACK);
    }
    
    bool hasSelection = false;
    for (int i = 0; i < 4; i++) {
        if (selectedAnswers[i]) {
            hasSelection = true;
            break;
        }
    }
    
    bool isHoverSubmit = CheckCollisionPointRec(mousePosition, btnSubmit);
    Color baseSubmitColor = hasSelection ? clBtnPassive : GRAY;
    Color submitColor = (isHoverSubmit && hasSelection) ? DarkenColor(baseSubmitColor) : baseSubmitColor;
    DrawRectangleRounded(btnSubmit, 0.5f, 10, submitColor);
    
    Vector2 submitTextSize = MeasureTextEx(font60, "ОТПРАВИТЬ", 60, 0);
    DrawTextEx(font60, "ОТПРАВИТЬ", 
        { (float)(WIDTH_SCREEN / 2) - submitTextSize.x / 2, 
          (float)(HEIGHT_SCREEN - btnSubmitHeight / 2 - 50 - submitTextSize.y / 2) }, 
        60, 0, BLACK);
}

void RenderResults() {
    std::string resultsTitle = "РЕЗУЛЬТАТЫ";
    Vector2 titleSize = MeasureTextEx(font120, resultsTitle.c_str(), 120, 3);
    DrawTextEx(font120, resultsTitle.c_str(), 
        { (float)(WIDTH_SCREEN / 2) - titleSize.x / 2, 100 }, 
        120, 3, BLACK);
    
    int roundedGrade = CalculateGrade();
    
    std::string correctText = "Правильных ответов: " + std::to_string(correctCount);
    Vector2 correctSize = MeasureTextEx(font60, correctText.c_str(), 60, 3);
    DrawTextEx(font60, correctText.c_str(), 
        { (float)(WIDTH_SCREEN / 2) - correctSize.x / 2, 300 }, 
        60, 3, BLACK);
    
    std::string incorrectText = "Неправильных ответов: " + std::to_string(incorrectCount);
    Vector2 incorrectSize = MeasureTextEx(font60, incorrectText.c_str(), 60, 3);
    DrawTextEx(font60, incorrectText.c_str(), 
        { (float)(WIDTH_SCREEN / 2) - incorrectSize.x / 2, 400 }, 
        60, 3, BLACK);
    
    std::string gradeText = "Оценка: " + std::to_string(roundedGrade);
    Vector2 gradeSize = MeasureTextEx(font120, gradeText.c_str(), 120, 3);
    DrawTextEx(font120, gradeText.c_str(), 
        { (float)(WIDTH_SCREEN / 2) - gradeSize.x / 2, 520 }, 
        120, 3, BLACK);
    
    bool isHoverBack = CheckCollisionPointRec(mousePosition, btnBack);
    Color btnBackColor = isHoverBack ? DarkenColor(clBtnPassive) : clBtnPassive;
    DrawRectangleRounded(btnBack, 0.5f, 10, btnBackColor);
    
    Vector2 backTextSize = MeasureTextEx(font60, "В МЕНЮ", 60, 0);
    DrawTextEx(font60, "В МЕНЮ", 
        { (float)(WIDTH_SCREEN / 2) - backTextSize.x / 2, 
          (float)(HEIGHT_SCREEN - btnBackHeight / 2 - 50 - backTextSize.y / 2) }, 
        60, 0, BLACK);
}

