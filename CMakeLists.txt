cmake_minimum_required(VERSION 4.3)
project(TextRedactor)

set(CMAKE_CXX_STANDARD 20)

add_executable(TextRedactor
        main.cpp
        TextBuffer.cpp
        TextBuffer.h
        Cursor.cpp
        Cursor.h
        ScreenRenderer.cpp
        ScreenRenderer.h
        EditorEngine.cpp
        EditorEngine.h
        InputHandler.cpp
        InputHandler.h
        RedactorConstants.h
        FileRedactor.cpp
        FileRedactor.h
        Viewport.cpp
        Viewport.h
)
