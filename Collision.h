#pragma once
#include "Singletons.h"
#include <cmath>

template <typename T>
void Collision(SDL_Rect a, SDL_Rect b, T tx, T ty, T& x, T& y)
{
    tx = floor(tx);
    ty = floor(ty);
    x = floor(x);
    y = floor(y);

    if ((a.x > b.x || a.x + a.w > b.x) && a.x < b.x + b.w) {
        if ((a.y > b.y || a.y + a.h > b.y) && a.y < b.y + b.h) {
            if (tx + a.w <= b.x) {
                x = b.x - a.w;
                std::cout << "1" << std::endl;
            }
            else if (tx >= b.x + b.w) {
                x = b.x + b.w;
                std::cout << "2" << std::endl;
            }
            else if (ty + a.h <= b.y) {
                y = b.y - a.h;
                std::cout << "3" << std::endl;
            }
            else if (ty >= b.y + b.h) {
                y = b.y + b.h;
                std::cout << "4" << std::endl;
            }
        }
    }
}