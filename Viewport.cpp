//
// Created by StarredNaga on 11.10.2026.
//

#include "Viewport.h"

#include <stdexcept>
#include <windows.h>


Viewport::Viewport() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    screenWidth = columns;
    screenHeight = rows;

    yOffset = 0;
    xOffset = 0;
}

int Viewport::getScreenWidth() {
    return screenWidth;
}

int Viewport::getScreenHeight() {
    return screenHeight;
}

int Viewport::getYOffset() {
    return yOffset;
}

int Viewport::getXOffset() {
    return xOffset;
}

void Viewport::setYOffset(const int offset) {

    if (offset < 0) throw std::invalid_argument("yOffset must be greater than 0");

    yOffset = offset;
}

void Viewport::setXOffset(const int offset) {

    if (offset < 0) throw std::invalid_argument("yOffset must be greater than 0");

    xOffset = offset;
}