//
// Created by StarredNaga on 11.10.2026.
//

#ifndef TEXTREDACTOR_FILEREDACTOR_H
#define TEXTREDACTOR_FILEREDACTOR_H
#include <string>
#include <vector>


class FileRedactor {

    public:
    static std::vector<std::string> ReadFile(const std::string &fileName);

    static void WriteFile(const std::string &fileName, const std::vector<std::string> &text);
};


#endif //TEXTREDACTOR_FILEREDACTOR_H
