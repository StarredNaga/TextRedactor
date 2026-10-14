//
// Created by StarredNaga on 11.10.2026.
//

#ifndef TEXTREDACTOR_VIEWPORT_H
#define TEXTREDACTOR_VIEWPORT_H


class Viewport {
    public:
    Viewport();

    static void setYOffset(int yOffset);
    static void setXOffset(int yOffset);

    static int getYOffset();
    static int getXOffset();
    static int getScreenHeight();
    static int getScreenWidth();

    private:
    inline static int screenWidth;
    inline static int screenHeight;
    inline static int yOffset;
    inline static int xOffset;
};


#endif //TEXTREDACTOR_VIEWPORT_H
