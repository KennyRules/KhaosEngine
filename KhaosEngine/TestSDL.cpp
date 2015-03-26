#include <SDL.h>
#include <iostream>

void printSDLError() {
    std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
    std::cin.get();
}

int main(int argc, char ** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        printSDLError();

    // Create a window to draw into.
    SDL_Window* aWindow = SDL_CreateWindow("Hello World!", 500, 50, 700, 500, SDL_WINDOW_SHOWN);
    if (!aWindow) {
        printSDLError();

        SDL_Quit();
        return 1;
    }

    // Create a renderer.
    SDL_Renderer* aRenderer = SDL_CreateRenderer(aWindow, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!aRenderer) {
        printSDLError();
        SDL_DestroyWindow(aWindow);
        SDL_Quit();
        return 1;
    }

    // Load a file as a surface.
    std::string filePath = std::string(SDL_GetBasePath()) + "hello.bmp";
    SDL_Surface* aSurface = SDL_LoadBMP(filePath.c_str());
    if (!aSurface) {
        printSDLError();
        SDL_DestroyRenderer(aRenderer);
        SDL_DestroyWindow(aWindow);
        SDL_Quit();
        return 1;
    }

    // Turn that surface into a texture.
    SDL_Texture* aTexture = SDL_CreateTextureFromSurface(aRenderer, aSurface);
    SDL_FreeSurface(aSurface);

    if (!aTexture) {
        SDL_DestroyRenderer(aRenderer);
        SDL_DestroyWindow(aWindow);
        printSDLError();
        SDL_Quit();
        return 1;
    }

    SDL_RenderClear(aRenderer);
    SDL_RenderCopy(aRenderer, aTexture, nullptr, nullptr);
    SDL_RenderPresent(aRenderer);

    SDL_Delay(2000);

    SDL_DestroyTexture(aTexture);
    SDL_DestroyRenderer(aRenderer);
    SDL_DestroyWindow(aWindow);

    SDL_Quit();
    return 0;
}