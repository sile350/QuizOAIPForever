#pragma once

#include "stdlib.h"
#include "raylib.h"

Color DarkenColor(Color color, float factor = 0.8f);
void AddCodepointRange(Font* font, const char* fontPath, int start, int stop, int fontSize);

