//
//  dungui.cpp
//  DunGUI
//
//  Created by Dylan Burden on 2023-01-30.
//

#include "dungui.hpp"

using namespace DunGUI;

Window::Window(int x, int y, int w, int h) :
    mXOffset(x),
    mYOffset(y),
    mWidth(w),
    mHeight(h)
{}

void Window::render(SDL_Renderer* renderer)
{
    SDL_Rect windowRect;
    windowRect.x = mXOffset;
    windowRect.y = mYOffset;
    windowRect.w = mWidth;
    windowRect.h = mHeight;
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &windowRect);
}
