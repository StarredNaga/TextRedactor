//
// Created by StarredNaga on 20.09.2026.
//

#ifndef TEXTREDACTOR_CURSOR_H
#define TEXTREDACTOR_CURSOR_H


class Cursor {
    public:
    Cursor();
    Cursor(int x, int y);

    int getCurrentLineNumber() const;
    int getCurrentSymbolIndex() const;

    void setCurrentLineNumber(int lineNumber);
    void setCurrentSymbolIndex(int symbolIndex);

    void moveCursor() const;
    void moveCursor(int x, int y) const;

    private:
    int currentLine;
    int currentSymbol;
};


#endif //TEXTREDACTOR_CURSOR_H
