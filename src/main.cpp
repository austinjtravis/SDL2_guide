#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include <RenderWindow.hpp>
#include <Entity.hpp>
#include <Math.hpp>

// int argv, char* args[] are required for SDL  
int main(int argv, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init FAILED. SDL_ERROR: " 
                  << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "IMG_Init FAILED. SDL_ERROR: "
                  << SDL_GetError() << std::endl;
    }
    const std::string windowTitle = "Game";
    //FIXME: See RenderWindow.hpp constructor FIXME
    const int windowWidth = 1280;
    const int windowHeight = 720; 
    RenderWindow Window(windowTitle.c_str(), windowWidth, windowHeight);
    
    // FIXME: Figure out why std::filesystem::absolute isn't working
    const std::string texturePath = "/home/tomatten/c++/sdl2_tutorial/res/imgs/grass.png";
    SDL_Texture* GrassTexture = Window.loadTexture(texturePath.c_str());

    std::vector<Entity> entities({
        Entity(Vector2f(0, 0), GrassTexture),
        Entity(Vector2f(128, 128), GrassTexture),
        Entity(Vector2f(0, 128), GrassTexture),
    });

    bool gameRunning = true;
    SDL_Event Event;
    while (gameRunning)
    {
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
        }

        Window.clear();
        for (auto& obj : entities)
        {
            Window.render(obj);
        }
        Window.display();
    }

    Window.cleanUp();
    SDL_Quit();
    return 0;
}