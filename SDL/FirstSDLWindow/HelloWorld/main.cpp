#include <iostream>
#include "SDL.h"

int main(int args, char* argv[]) {

    /* Starting SDL */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    /* Create a Window */
    SDL_Window* window = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    /* Create a Render */
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    /* Load bitmap image */
    SDL_Surface* bmp = SDL_LoadBMP("./hello.bmp");
    if (bmp == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    /* Upload surface to render, and then, free the surface */
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, bmp);
    SDL_FreeSurface(bmp);
    if (texture == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    /* Draw the render on window */
    SDL_RenderClear(render); // Fill render with color
    SDL_RenderCopy(render, texture, NULL, NULL); // Copy the texture into render
    SDL_RenderPresent(render); // Show render on window

    /* Wait 2 seconds */
    SDL_Delay(5000);

    /* Free all objects*/
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);

    /* Quit program */
    SDL_Quit();

    return 0;
}