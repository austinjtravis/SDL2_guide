#include <iostream>

#include <RenderWindow.hpp>

//FIXME: just use nullptr?
RenderWindow::RenderWindow(const char* title, int width, int height) :
    Window(NULL), Renderer(NULL)
{
    // FIXME: Video mentioned this is raw pointer and need to handle deletion
    //        to avoid memory leak.  Just use std::shared_ptr
    Window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            SDL_WINDOW_SHOWN);
    
    if (Window == NULL)
    {
        std::cout << "Window failed to initialize. Error: " 
                  << SDL_GetError() << std::endl; 
    }

    // Note: -1: Look for graphics driver instead of directly configuring
    Renderer = SDL_CreateRenderer(
        Window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Renderer == NULL)
    {
        std::cout << "Renderer failed to initialize. Error: " 
                  << SDL_GetError() << std::endl; 
    }
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(Window);
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
    SDL_Texture* Texture = NULL;
    Texture = IMG_LoadTexture(Renderer, filePath);

    if (Texture == NULL)
    {
        std::cout << "Failed to load texture. Error: "
                  << SDL_GetError() << std::endl;
    }
    return Texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(Renderer);
}

void RenderWindow::render(Entity& entity)
{
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = entity.getPos().x;
    dst.y = entity.getPos().y;
    dst.w = entity.getCurrentFrame().w;
    dst.h = entity.getCurrentFrame().h;

    SDL_RenderCopy(Renderer, entity.getTexture(), &src, &dst);
    
    //SDL_RenderCopy(Renderer, Texture, NULL, NULL);
}

void RenderWindow::display()
{
    SDL_RenderPresent(Renderer);
}

