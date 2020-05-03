/*#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

#include "widget/button.hpp"
#include "widget/text.hpp"

class Window
{
private:
    SDL_Window* win = nullptr;
puclic:
    static SDL_Renderer* render;
};

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "[ERROR] SDL_Init: " << SDL_GetError() << "\n";
        exit(1);
    }

    if (TTF_Init() < 0)
    {
        std::cerr << "[ERROR] TTF_Init: " << SDL_GetError() << "\n";
        exit(1);
    }
}

int main(int argc, char const *argv[])
{
    init();

    SDL_Window* win = SDL_CreateWindow("Template", 100, 100, 1080, 720, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cerr << "[ERROR] SDL_Window: " << SDL_GetError() << "\n";
        return EXIT_FAILURE;
    }

    SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == nullptr) {
        std::cerr << "[ERROR] SDL_Renderer: " << SDL_GetError() << "\n";
        return EXIT_FAILURE;
    }

    Button bt(100, 100, "That's me");
    bt.set_color(SDL_Color{0xff, 0x0, 0x0, 0xff});
    bt.set_size(100, 50);
    std::cout << bt.m_color.r << " " << bt.m_color.g << " " << bt.m_color.b << "\n";

    TTF_Font* font = TTF_OpenFont("res\\fonts\\Roboto-Regular.ttf", 22); 
    if( font == nullptr) {
        std::cerr << "Could not find the font\n";
    }

    Text text("Hello");
    text.set_font(render, font);
    text.centralize(100, 100, 100, 50);

    std::vector<Widget> bt_pack;
    bt_pack.push_back(bt);

    bool running = true;

    SDL_Event event;
    while(running) {
        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(render, 0x0, 0x0, 0x0, 0x0);
        SDL_RenderClear(render);

        for (auto &bt: bt_pack) {
            bt.draw(render);
        }

        text.draw(render);

        SDL_RenderPresent(render);
    }

    SDL_Quit();
    return 0;
}*/
