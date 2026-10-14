//
// Created by StarredNaga on 04.10.2026.
//

#ifndef TEXTREDACTOR_INPUTHANDLER_H
#define TEXTREDACTOR_INPUTHANDLER_H
#include "Cursor.h"
#include "TextBuffer.h"


class InputHandler {
    public:
    InputHandler(TextBuffer& buffer, Cursor& cursor);

    void handleInput(char input);

    void handleCommand(const std::string &command);

    private:
    void updateYOffset();
    void updateXOffset();
    TextBuffer& buffer;
    Cursor& cursor;
};


#endif //TEXTREDACTOR_INPUTHANDLER_H
