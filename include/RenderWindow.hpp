#pragma once  // include guard
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Entity.hpp>

class RenderWindow
{
// FIXME: Make width, height const
public:
    RenderWindow(const char* title, int width, int height);

    // FIXME: Why not just use destructor?
    void cleanUp();

    SDL_Texture* loadTexture(const char* filePath);

    void clear();
    
    void render(Entity& entity);
    
    void display();

private:
    SDL_Window* Window;  // Window to draw on
    SDL_Renderer* Renderer;  // Renderer to use on Window (uses opengl)
};