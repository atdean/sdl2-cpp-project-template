#include <SDL2/SDL.h>

int main(int argc, const char* argv[])
{
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL2 Starter Project",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    while (!quit)
    {
        SDL_Delay(10);
        SDL_PollEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }

        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
