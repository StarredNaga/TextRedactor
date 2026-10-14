//
// Created by StarredNaga on 20.09.2026.
//

#include "ScreenRenderer.h"

#include <format>
#include <iostream>
#include <ostream>

#include "Viewport.h"

ScreenRenderer::ScreenRenderer() {

    screenBuffer = std::vector(Viewport::getScreenHeight(), std::vector<char>(Viewport::getScreenWidth(), ' '));
}

void ScreenRenderer::renderScreen(const std::vector<std::string> &text) {

    std::vector nextScreenBuffer(Viewport::getScreenHeight(), std::vector<char>(Viewport::getScreenWidth(), ' '));

    for (int i = 0; i < Viewport::getScreenHeight(); i++) {

        for (int j = 0; j < Viewport::getScreenWidth(); j++) {
            if (i < text.size() && j < text[i].size()) nextScreenBuffer[i][j] = text[i][j];
        }
    }

    std::string outputBuffer;

    outputBuffer.reserve(1024);

    bool cursorMoved = true;

    for (int i = 0; i < Viewport::getScreenHeight(); i++) {
        for (int j = 0; j < Viewport::getScreenWidth(); j++) {
            if (screenBuffer[i][j] == nextScreenBuffer[i][j]) {
                cursorMoved = true;
                continue;
            }

            screenBuffer[i][j] = nextScreenBuffer[i][j];

            if (cursorMoved) {
                outputBuffer += std::format("\x1b[{};{}H", i + 1, j + 1);
                cursorMoved = false;
            }

            outputBuffer += screenBuffer[i][j];
        }
        cursorMoved = true;
    }

    if (!outputBuffer.empty()) {
        std::cout << outputBuffer << std::flush;
    }
}
