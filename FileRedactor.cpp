//
// Created by StarredNaga on 11.10.2026.
//

#include "FileRedactor.h"

#include <stdexcept>

#include <fstream>

using namespace std;

std::vector<std::string> FileRedactor::ReadFile(const std::string &fileName) {

    if (fileName.empty()) throw std::invalid_argument("fileName is empty");

    ifstream file(fileName);

    if (!file.is_open()) throw std::runtime_error("File not found");

    vector<string> lines;

    string line;

    while (getline (file, line)) lines.push_back(line);

    file.close();

    if (lines.empty()) lines.emplace_back("");

    return lines;
}

void FileRedactor::WriteFile(const std::string &fileName, const std::vector<std::string> &text) {

    if (fileName.empty()) throw std::invalid_argument("fileName is empty");

    if (text.empty()) throw std::invalid_argument("text is empty");

    ofstream file(fileName);

    if (!file.is_open()) throw std::runtime_error("File not found");

    for (const auto& line : text) {
        file << line << "\n";
    }

    file.close();

}
