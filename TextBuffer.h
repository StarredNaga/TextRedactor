//
// Created by StarredNaga on 20.09.2026.
//

#ifndef TEXTREDACTOR_TEXTBUFFER_H
#define TEXTREDACTOR_TEXTBUFFER_H
#include <string>
#include <vector>


class TextBuffer {

    public:
    TextBuffer();
    TextBuffer(std::vector<std::string> text);

    std::string& getLine(int lineNumber);
    const std::vector<std::string>& getAllLines() const;

    void insertSymbol(int lineNumber, int symbolIndex, char symbol);

    void eraseSymbol(int lineNumber, int symbolIndex);

    void insertText(int lineNumber, int startIndex, const std::string& insertedText);

    void eraseSymbols(int lineNumber, int startIndex);

    void addLine();
    void insertLine(int lineNumber);
    void insertLine(int lineNumber, const std::string &text);

    void eraseLine(int lineNumber);
    void deleteLine();

    private:
    std::vector<std::string> text;
};


#endif //TEXTREDACTOR_TEXTBUFFER_H
