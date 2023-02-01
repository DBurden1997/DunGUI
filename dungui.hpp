//
//  dungui.hpp
//  DunGUI
//
//  Created by Dylan Burden on 2023-01-30.
//

#ifndef dungui_hpp
#define dungui_hpp

#include <stdio.h>

#include "sdlwrapper.hpp"

namespace DunGUI
{
    class Window
    {
        int                 mXOffset;
        int                 mYOffset;
        int                 mWidth;
        int                 mHeight;
        
    public:
        
        Window(int x, int y, int w, int h);
        
        void render(SDL_Renderer* renderer);
    };
};

#endif /* dungui_hpp */
