//
// Created by StarredNaga on 20.09.2026.
//

#include "EditorEngine.h"
#include "RedactorConstants.h"

#include <conio.h>
#include <ranges>
#include <stdexcept>
#include <windows.h>

#include "FileRedactor.h"
#include "Viewport.h"

EditorEngine::EditorEngine(const std::string &filePath) : inputHandler(buffer, cursor) {

    if (filePath.empty()) throw std::invalid_argument("fileName is empty");

    this->filePath = filePath;

    cursor = Cursor();
    buffer = TextBuffer(FileRedactor::ReadFile(filePath));
    renderer = ScreenRenderer();

    viewport = Viewport();
}

void EditorEngine::initialize() {

    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hInput, &mode);

    mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);

    SetConsoleMode(hInput, mode);

    while (true) {

        if (!_kbhit()) {
            continue;
        }

        auto input = _getch();

        std::string command;

        if (input == ArrowKeyCode) {

            switch(_getch()) {

                case UpArrowKeyCode:
                    command = RedactorConstants::UpCommand;
                    break;

                case DownArrowKeyCode:
                    command = RedactorConstants::DownCommand;
                    break;

                case RightArrowKeyCode:
                    command = RedactorConstants::RightCommand;
                    break;

                case LeftArrowKeyCode:
                    command = RedactorConstants::LeftCommand;
                    break;

                default: return;
            }
        }
        else if (input == BackspaceKeyCode) command = RedactorConstants::BackspaceCommand;
        else if (input == EnterKeyCode) command = RedactorConstants::EnterCommand;
        else if (input == SaveKeyCode) {

            FileRedactor::WriteFile(filePath, buffer.getAllLines());

            continue;
        }

        if (command.empty()) inputHandler.handleInput((char)input);
        else inputHandler.handleCommand(command);

        std::vector<std::string> renderLines;
        auto lines = buffer.getAllLines();

        for (auto i = 0; i < lines.size(); i++) {

            if (renderLines.size() >= Viewport::getScreenHeight()) break;

            if (i < Viewport::getYOffset()) continue;

            if (Viewport::getXOffset() > lines[i].length()) {

                renderLines.emplace_back("");

                continue;
            }

            renderLines.push_back(lines[i].substr(Viewport::getXOffset()));
        }

        renderer.renderScreen(renderLines);

        auto x = cursor.getCurrentSymbolIndex();
        auto y = cursor.getCurrentLineNumber();

        if (x > Viewport::getScreenWidth()) x = Viewport::getScreenWidth() - 1;

        if (y >= Viewport::getScreenHeight()) {
            y = Viewport::getScreenHeight();
        }

        cursor.moveCursor(x, y);
    }
}

