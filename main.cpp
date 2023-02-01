//
//  main.cpp
//  SDL2
//
//  Created by Dylan Burden on 2022-07-08.
//

#include <iostream>

#include <memory>
//#include <SDL.h>
#include <SDL2/SDL.h>
//#include <SDL_image.h>
#include <SDL2_image/SDL_image.h>

#include "sdlwrapper.hpp"

#include "dungui.hpp"

sdl2::WindowPointer gWindow;
sdl2::RendererPointer gRenderer;

const static int WINDOW_WIDTH = 1280;
const static int WINDOW_HEIGHT = 720;

int main(int argv, char** args)
{
    bool success = true;
    
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO  ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        gWindow = sdl2::create_window( "Elementals Prototype", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
        if( !gWindow )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) )
            {
                printf( "Warning: Nearest neighbour filtering not enabled!\n" );
            }
            gRenderer = sdl2::create_renderer( gWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( !gRenderer )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor( gRenderer.get(), 0x00, 0x00, 0x00, 0xff );

                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    
    SDL_Event e;
    
    DunGUI::Window window = DunGUI::Window(0, 0, 320, 320);
    
    SDL_Rect rect;
    rect.x = 20;
    rect.y = 30;
    rect.w = 100;
    rect.h = 50;
    SDL_SetTextInputRect(&rect);
    SDL_StartTextInput();
    while(true)
    {
        SDL_RenderClear(gRenderer.get());
        
        window.render(gRenderer.get());
        
        SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderPresent(gRenderer.get());
        
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                return 0;
            }
            if(e.type == SDL_TEXTINPUT)
            {
                std::cout << e.text.text << "\n";;
            }
            if(e.type == SDL_TEXTEDITING)
            {
                std::cout << e.edit.text << "\n" << e.edit.start << "\n" << e.edit.length << "\n";
            }
            if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
            {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    {
                        return 0;
                        break;
                    }
                    default:
                        break;
                }
            }
        }
    }
}
