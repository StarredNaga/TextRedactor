//
// Created by StarredNaga on 20.09.2026.
//

#include "TextBuffer.h"
#include <stdexcept>

TextBuffer::TextBuffer() {
    text = std::vector<std::string>();
}

TextBuffer::TextBuffer(std::vector<std::string> text) {

    this->text = std::move(text);
}

const std::vector<std::string>& TextBuffer::getAllLines() const{
    return text;
}

std::string &TextBuffer::getLine(int lineNumber) {

    if (lineNumber < 0 || lineNumber >= text.size()) throw std::out_of_range("getLine");

    return text[lineNumber];
}


void TextBuffer::insertSymbol(int lineNumber, int symbolIndex, char symbol) {

    if (lineNumber < 0 || lineNumber >= text.size()) throw std::out_of_range("insertSymbol");

    std::string& line = text[lineNumber];

    if (symbolIndex < 0 || symbolIndex > line.size()) throw std::out_of_range("insertSymbol");

    line.insert(line.begin() + symbolIndex, symbol);
}

void TextBuffer::eraseSymbol(int lineNumber, int symbolIndex) {
    if (lineNumber < 0 || lineNumber >= text.size()) throw std::out_of_range("eraseSymbol");

    std::string& line = text[lineNumber];

    if (symbolIndex < 0 || symbolIndex >= line.size()) throw std::out_of_range("eraseSymbol");

    line.erase(line.begin() + symbolIndex);
}

void TextBuffer::insertText(int lineNumber, int startIndex, const std::string& insertedText) {
    if (lineNumber < 0 || lineNumber >= text.size()) throw std::out_of_range("insertText");

    std::string& line = text[lineNumber];

    if (startIndex < 0 || startIndex > line.size()) throw std::out_of_range("insertText");

    line.insert(startIndex, insertedText);
}

void TextBuffer::eraseSymbols(int lineNumber, int startIndex) {

    if (lineNumber < 0 || lineNumber >= text.size()) throw std::out_of_range("eraseSymbols");

    std::string& line = text[lineNumber];

    if (startIndex < 0 || startIndex > line.size()) throw std::out_of_range("eraseSymbols");

    line.erase(line.begin() + startIndex, line.end());
}

void TextBuffer::addLine() {
    text.emplace_back("");
}

void TextBuffer::insertLine(int lineNumber) {

    if (lineNumber < 0 || lineNumber > text.size()) throw std::out_of_range("insertLine");

    text.insert(text.begin() + lineNumber, "");
}

void TextBuffer::insertLine(int lineNumber, const std::string& lineText) {

    if (lineNumber < 0 || lineNumber > text.size()) throw std::out_of_range("insertLine");

    text.insert(text.begin() + lineNumber, lineText);
}

void TextBuffer::deleteLine() {

    text.pop_back();
}

void TextBuffer::eraseLine(int lineNumber) {

    if (lineNumber < 0 || lineNumber >= text.size()) throw std::out_of_range("eraseLine");

    text.erase(text.begin() + lineNumber);
}
