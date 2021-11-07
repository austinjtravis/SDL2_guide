#pragma once

// FIXME: Template this
struct Vector2f
{
    Vector2f(float x, float y): x(x), y(y) {}
    Vector2f() {Vector2f(0.0f, 0.0f);}

    float x, y;
};
