//
// Created by StarredNaga on 20.09.2026.
//

#ifndef TEXTREDACTOR_EDITORENGINE_H
#define TEXTREDACTOR_EDITORENGINE_H

#include "Cursor.h"
#include "InputHandler.h"
#include "ScreenRenderer.h"
#include "TextBuffer.h"
#include "Viewport.h"


class EditorEngine {

    public:
    EditorEngine(const std::string &filePath);

    static constexpr int ArrowKeyCode = 224;

    static constexpr int UpArrowKeyCode = 72;
    static constexpr int DownArrowKeyCode = 80;
    static constexpr int LeftArrowKeyCode = 75;
    static constexpr int RightArrowKeyCode = 77;

    static constexpr int BackspaceKeyCode = 8;
    static constexpr int EnterKeyCode = 13;

    static constexpr int SaveKeyCode = 19;

    void initialize();

    private:
    Viewport viewport;
    std::string filePath;
    TextBuffer buffer;
    Cursor cursor;
    ScreenRenderer renderer;
    InputHandler inputHandler;
};


#endif //TEXTREDACTOR_EDITORENGINE_H
