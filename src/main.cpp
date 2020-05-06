#define SDL_MAIN_HANDLED
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "widget/button.hpp"
#include "widget/text.hpp"
#include "widget/image.hpp"
#include "entity/entity.hpp"

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
    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);


    TTF_Font* font = TTF_OpenFont("res\\fonts\\Roboto-Regular.ttf", 22); 
    if( font == nullptr) {
        std::cerr << "Could not find the font\n";
    }

    Button bt(200, 100, "Start");
    bt.set_size(200, 70);
    bt.set_colors(HOVER, {0x16, 0x9C, 0x99, 0xff});
    bt.set_colors(IDLE, {0x34, 0x40, 0x40, 0xff});
    bt.set_text_font(render, font);
    bt.set_callback([] () 
    {
        std::cout << "You clicked me!\n";
    });

    Image img(360, 115);
    std::string path = "res/textures/power_icon.png";  
    img.load_image(path, render);
    img.fit(bt.x, bt.y, bt.width, bt.height, 5);

    /*
    Text text("Test");
    text.set_font(render, font);
    text.centralize(bt.x, bt.y, bt.width, bt.height);
    */

    /*
    std::vector<Widget> bt_pack;
    bt_pack.push_back(bt);
    */

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

        SDL_SetRenderDrawColor(render, 0x15, 0x15, 0x15, 0xff);
        SDL_RenderClear(render);

        bt.update(event);
        bt.draw(render);

        img.draw(render);

        /*
        for (auto &bt: bt_pack) {
            bt.draw(render);
        }*/

        //text.draw(render);

        SDL_RenderPresent(render);
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(render);
    SDL_Quit();
    return 0;
}
