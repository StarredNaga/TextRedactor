//
// Created by StarredNaga on 04.10.2026.
//

#include "InputHandler.h"
#include "RedactorConstants.h"
#include "Viewport.h"

InputHandler::InputHandler(TextBuffer& buffer, Cursor& cursor)
        : buffer(buffer), cursor(cursor) {}

void InputHandler::handleCommand(const std::string &command) {

    auto currentLineNumber = cursor.getCurrentLineNumber();
    auto currentSymbolIndex = cursor.getCurrentSymbolIndex();

    auto lines = buffer.getAllLines();
    auto currentLine = buffer.getLine(currentLineNumber);

    if (command == RedactorConstants::LeftCommand) {

        if (currentSymbolIndex == 0) return;

        cursor.setCurrentSymbolIndex(currentSymbolIndex - 1);

        updateXOffset();

        return;
    }

    if (command == RedactorConstants::RightCommand) {

        if (currentSymbolIndex == currentLine.size()) return;

        cursor.setCurrentSymbolIndex(currentSymbolIndex + 1);

        updateXOffset();

        return;
    }

    if (command == RedactorConstants::UpCommand) {

        if (currentLineNumber == 0) return;

        auto previousLine = buffer.getLine(currentLineNumber - 1);

        if (currentSymbolIndex > previousLine.size()) cursor.setCurrentSymbolIndex(previousLine.size());

        cursor.setCurrentLineNumber(currentLineNumber - 1);

        updateYOffset();

        return;
    }

    if (command == RedactorConstants::DownCommand) {

        if (currentLineNumber == lines.size() - 1) return;

        auto nextLine = buffer.getLine(currentLineNumber + 1);

        if (currentSymbolIndex > nextLine.size()) cursor.setCurrentSymbolIndex(nextLine.size());

        cursor.setCurrentLineNumber(currentLineNumber + 1);

        updateYOffset();

        return;
    }

    if (command == RedactorConstants::BackspaceCommand) {

        if (currentSymbolIndex == 0 && currentLineNumber == 0) return;

        if (currentSymbolIndex == 0 && currentLineNumber > 0) {

            auto previousLine = buffer.getLine(currentLineNumber - 1);

            buffer.insertText(currentLineNumber - 1, previousLine.size()
                ,currentLine);

            cursor.setCurrentSymbolIndex(buffer.getLine(currentLineNumber - 1).size());

            cursor.setCurrentLineNumber(currentLineNumber - 1);

            buffer.eraseLine(currentLineNumber);

            updateYOffset();

            return;
        }

        buffer.eraseSymbol(currentLineNumber, currentSymbolIndex - 1);

        cursor.setCurrentSymbolIndex(currentSymbolIndex - 1);

        updateXOffset();

        return;
    }

    if (command == RedactorConstants::EnterCommand) {

        std::string lineText = currentLine.substr(currentSymbolIndex);

        buffer.eraseSymbols(currentLineNumber, currentSymbolIndex);

        buffer.insertLine(currentLineNumber + 1,
            lineText);

        cursor.setCurrentSymbolIndex(0);

        cursor.setCurrentLineNumber(currentLineNumber + 1);

        updateYOffset();

        return;
    }
}

void InputHandler::handleInput(char input) {

    auto currentLineNumber = cursor.getCurrentLineNumber();
    auto currentSymbolIndex = cursor.getCurrentSymbolIndex();

    buffer.insertSymbol(currentLineNumber, currentSymbolIndex, input);

    cursor.setCurrentSymbolIndex(currentSymbolIndex + 1);

    updateXOffset();
}

void InputHandler::updateXOffset() {

    if (cursor.getCurrentSymbolIndex() < Viewport::getScreenWidth() + Viewport::getXOffset()
        && Viewport::getXOffset() > 0) {
        Viewport::setXOffset(Viewport::getXOffset() - 1);

        return;
    }

    if (cursor.getCurrentSymbolIndex() >= Viewport::getScreenWidth() + Viewport::getXOffset()) {
        Viewport::setXOffset(Viewport::getXOffset() + 1);

        return;
    }
}

void InputHandler::updateYOffset() {

    if (cursor.getCurrentLineNumber() < Viewport::getScreenHeight() + Viewport::getYOffset() && Viewport::getYOffset() > 0) {

        Viewport::setYOffset(Viewport::getYOffset() - 1);

        return;
    }

    if (cursor.getCurrentLineNumber() >= Viewport::getScreenHeight() + Viewport::getYOffset()) {
        Viewport::setYOffset(Viewport::getYOffset() + 1);
    }
}
