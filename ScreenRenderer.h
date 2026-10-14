//
// Created by StarredNaga on 20.09.2026.
//

#ifndef TEXTREDACTOR_SCREENRENDERER_H
#define TEXTREDACTOR_SCREENRENDERER_H
#include <string>
#include <vector>

class ScreenRenderer {

    public:
    ScreenRenderer();
    void renderScreen(const std::vector<std::string> &text);

    private:
    std::vector<std::vector<char>> screenBuffer;
};


#endif //TEXTREDACTOR_SCREENRENDERER_H
