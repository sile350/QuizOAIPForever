#include "Application.h"

void Init()
{
	InitWindow(WIDTH_SCREEN, HEIGHT_SCREEN, "QuizOAIPForever");
	SetTargetFPS(60);

    font40 = LoadFont("assets/fonts/NotoSansTC-Regular.ttf");
    font60 = LoadFont("assets/fonts/NotoSansTC-Regular.ttf");
    font120 = LoadFont("assets/fonts/NotoSansTC-Regular.ttf");

    AddCodepointRange(&font40, "assets/fonts/NotoSansTC-Regular.ttf", 0x400, 0x4ff, 40);
    AddCodepointRange(&font40, "assets/fonts/NotoSansTC-Regular.ttf", 0x500, 0x52f, 40);
    AddCodepointRange(&font40, "assets/fonts/NotoSansTC-Regular.ttf", 0x2de0, 0x2Dff, 40);
    AddCodepointRange(&font40, "assets/fonts/NotoSansTC-Regular.ttf", 0xa640, 0xA69f, 40);

    AddCodepointRange(&font60, "assets/fonts/NotoSansTC-Regular.ttf", 0x400, 0x4ff, 60);
    AddCodepointRange(&font60, "assets/fonts/NotoSansTC-Regular.ttf", 0x500, 0x52f, 60);
    AddCodepointRange(&font60, "assets/fonts/NotoSansTC-Regular.ttf", 0x2de0, 0x2Dff, 60);
    AddCodepointRange(&font60, "assets/fonts/NotoSansTC-Regular.ttf", 0xa640, 0xA69f, 60);

    AddCodepointRange(&font120, "assets/fonts/NotoSansTC-Regular.ttf", 0x400, 0x4ff, 120);
    AddCodepointRange(&font120, "assets/fonts/NotoSansTC-Regular.ttf", 0x500, 0x52f, 120);
    AddCodepointRange(&font120, "assets/fonts/NotoSansTC-Regular.ttf", 0x2de0, 0x2Dff, 120);
    AddCodepointRange(&font120, "assets/fonts/NotoSansTC-Regular.ttf", 0xa640, 0xA69f, 120);

	InitQuestions();
}

void Run() {
    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();

        if (IsWindowResized) {
            WIDTH_SCREEN = GetScreenWidth();
            HEIGHT_SCREEN = GetScreenHeight();
        }

        if (gameState == GameState::Menu) {
            HandleMenuInput();
        }
        else if (gameState == GameState::Levels) {
            HandleLevelInput();
        }
        else if (gameState == GameState::Results) {
            HandleResultsInput();
        }

        BeginDrawing();
        ClearBackground(clBackground);

        if (gameState == GameState::Menu) {
            RenderMenu();
        }
        else if (gameState == GameState::Results) {
            RenderResults();
        }
        else if (gameState == GameState::Levels) {
            RenderLevel();
        }

        EndDrawing();
    }
}

void Shutdown() {
    UnloadFont(font40);
    UnloadFont(font60);
    UnloadFont(font120);
    CloseWindow();
}