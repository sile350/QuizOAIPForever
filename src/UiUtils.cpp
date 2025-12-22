#include "UiUtils.h"

Color DarkenColor(Color color, float factor) {
    return {
        (unsigned char)(color.r * factor),
        (unsigned char)(color.g * factor),
        (unsigned char)(color.b * factor),
        color.a
    };
}

void AddCodepointRange(Font* font, const char* fontPath, int start, int stop, int fontSize) {
    int rangeSize = stop - start + 1;
    int currentRangeSize = font->glyphCount;

    int updatedCodepointCount = currentRangeSize + rangeSize;
    int* updatedCodepoints = (int*)RL_CALLOC(updatedCodepointCount, sizeof(int));

    for (int i = 0; i < currentRangeSize; i++) 
        updatedCodepoints[i] = font->glyphs[i].value;

    for (int i = currentRangeSize; i < updatedCodepointCount; i++)
        updatedCodepoints[i] = start + (i - currentRangeSize);

    UnloadFont(*font);
    *font = LoadFontEx(fontPath, fontSize, updatedCodepoints, updatedCodepointCount);
    RL_FREE(updatedCodepoints);
}

