#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Math.hpp>

class Entity
{
public:
    Entity(Vector2f pos, SDL_Texture* texture):
        pos(pos), texture(texture)
    {
        currentFrame.x = 0;
        currentFrame.y = 0;
        currentFrame.w = 128;
        currentFrame.h = 128;
    }

    Vector2f& getPos()
    {
        return pos;
    }

    SDL_Texture* getTexture()
    {
        return texture;
    }
    SDL_Rect getCurrentFrame()
    {
        return currentFrame;
    }

private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};