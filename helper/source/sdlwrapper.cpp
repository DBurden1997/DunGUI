//
//  sdl_wrapper.cpp
//  SDL2
//
//  Created by Dylan Burden on 2022-07-09.
//

#include "sdlwrapper.hpp"

sdl2::SurfacePointer
sdl2::load_image(std::string path)
{
    return sdl2::SurfacePointer(IMG_Load(path.c_str()),
                                sdl2::SDL_Deleter());
}

sdl2::SurfaceShrPointer
sdl2::load_shared_image(std::string path)
{
    return sdl2::SurfaceShrPointer(IMG_Load(path.c_str()));
}

sdl2::WindowPointer
sdl2::create_window(char const *title,
              int x, int y, int w, int h,
              Uint32 flags)
{
    return sdl2::WindowPointer(SDL_CreateWindow(title, x, y, w, h, flags),
                               sdl2::SDL_Deleter());
}

sdl2::WindowShrPointer
sdl2::create_shared_window(char const *title,
                           int x, int y, int w, int h,
                           Uint32 flags)
{
    return sdl2::WindowShrPointer(SDL_CreateWindow(title, x, y, w, h, flags));
}

sdl2::RendererPointer
sdl2::create_renderer(SDL_Window * window,
                      int index, Uint32 flags)
{
    return sdl2::RendererPointer(SDL_CreateRenderer(window, index, flags),
                                 sdl2::SDL_Deleter());
}

sdl2::RendererShrPointer
sdl2::create_shared_renderer(SDL_Window * window,
                             int index, Uint32 flags)
{
    return sdl2::RendererShrPointer(SDL_CreateRenderer(window, index, flags));
}

sdl2::TexturePointer
sdl2::create_texture_from_surface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    return sdl2::TexturePointer(SDL_CreateTextureFromSurface(renderer, surface),
                                sdl2::SDL_Deleter());
}

sdl2::TextureShrPointer
sdl2::create_shared_texture_from_surface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    return sdl2::TextureShrPointer(SDL_CreateTextureFromSurface(renderer, surface));
}


