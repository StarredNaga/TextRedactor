//
// Created by StarredNaga on 20.09.2026.
//

#include "Cursor.h"

#include <format>
#include <iostream>
#include <stdexcept>

#include "Viewport.h"

Cursor::Cursor() {
    currentLine = 0;
    currentSymbol = 0;
}

Cursor::Cursor(int x, int y) {

    if (x < 0 || y < 0) throw std::out_of_range("Cursor::Cursor");

    currentSymbol = x;
    currentLine = y;
}

int Cursor::getCurrentLineNumber() const {
    return currentLine;
}

int Cursor::getCurrentSymbolIndex() const {
    return currentSymbol;
}

void Cursor::setCurrentLineNumber(int lineNumber) {

    if (lineNumber < 0) throw std::out_of_range("Cursor::setCurrentLineNumber");

    currentLine = lineNumber;
}

void Cursor::setCurrentSymbolIndex(int symbolIndex) {

    if (symbolIndex < 0) throw std::out_of_range("Cursor::setCurrentSymbolIndex");

    currentSymbol = symbolIndex;
}

void Cursor::moveCursor() const {

    std::string move = std::format("\x1b[{};{}H", currentLine + 1, currentSymbol + 1);

    std::cout << move;
}

void Cursor::moveCursor(int x, int y) const {

    if (y > Viewport::getScreenHeight()) y = Viewport::getScreenHeight();

    if (x > Viewport::getScreenWidth()) x = Viewport::getScreenWidth();

    std::string move = std::format("\x1b[{};{}H", y + 1, x + 1);

    std::cout << move;
}