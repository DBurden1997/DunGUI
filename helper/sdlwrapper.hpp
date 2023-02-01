//
//  sdl_wrapper.hpp
//  SDL2
//
//  Created by Dylan Burden on 2022-07-09.
//

#ifndef sdlwrapper_hpp
#define sdlwrapper_hpp

#include <memory>
#include <string>
//#include <SDL.h>
#include <SDL2/SDL.h>
//#include <SDL_image.h>
#include <SDL2_image/SDL_image.h>

template<class T, class D = std::default_delete<T>>
struct shared_ptr_with_deleter : public std::shared_ptr<T>
{
    explicit shared_ptr_with_deleter(T* t = nullptr) :
        std::shared_ptr<T>(t, D())
    {}
    
    void reset(T* t = nullptr)
    {
        std::shared_ptr<T>::reset(t, D());
    }
};

namespace sdl2
{
    struct SDL_Deleter
    {
        void operator() (SDL_Surface*   p) const { if (p)   SDL_FreeSurface(p);     }
        void operator() (SDL_Window*    p) const { if (p)   SDL_DestroyWindow(p);   }
        void operator() (SDL_Renderer*  p) const { if (p)   SDL_DestroyRenderer(p); }
        void operator() (SDL_Texture*   p) const { if (p)   SDL_DestroyTexture(p);  }
    };

    using SurfacePointer        = std::unique_ptr<SDL_Surface,  SDL_Deleter>;
    using WindowPointer         = std::unique_ptr<SDL_Window,   SDL_Deleter>;
    using RendererPointer       = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
    using TexturePointer        = std::unique_ptr<SDL_Texture,  SDL_Deleter>;

    using SurfaceShrPointer     = shared_ptr_with_deleter<SDL_Surface,  SDL_Deleter>;
    using WindowShrPointer      = shared_ptr_with_deleter<SDL_Window,   SDL_Deleter>;
    using RendererShrPointer    = shared_ptr_with_deleter<SDL_Renderer, SDL_Deleter>;
    using TextureShrPointer     = shared_ptr_with_deleter<SDL_Texture,   SDL_Deleter>;

    SurfacePointer
    load_image(std::string path);

    SurfaceShrPointer
    load_shared_image(std::string path);

    WindowPointer
    create_window(char const *title,
                  int x, int y, int w, int h,
                  Uint32 flags);
    
    WindowShrPointer
    create_shared_window(char const *title,
                         int x, int y, int w, int h,
                         Uint32 flags);

    RendererPointer
    create_renderer(SDL_Window * window,
                    int index, Uint32 flags);

    RendererShrPointer
    create_shared_renderer(SDL_Window * window,
                           int index, Uint32 flags);

    TexturePointer
    create_texture_from_surface(SDL_Renderer* renderer,
                                SDL_Surface* surface);

    TextureShrPointer
    create_shared_texture_from_surface(SDL_Renderer* renderer,
                                       SDL_Surface* surface);
}

#endif /* sdlwrapper_hpp */
