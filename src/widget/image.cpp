#include "image.hpp"
#include <iostream>

Image::Image(int x, int y)
{
    m_body.x = x;
    m_body.y = y;
}

Image::~Image()
{
    SDL_DestroyTexture(m_texture);
}

bool Image::load_image(std::string file_path, SDL_Renderer* render)
{
    SDL_Surface* surface;
    if ((surface = IMG_Load(file_path.c_str())) == NULL) {
        std::cerr << "Couldn't find the file: " << file_path << "\n";
        surface = nullptr;
        return 1;
    }

    m_texture = SDL_CreateTextureFromSurface(render, surface);
    m_body.w = surface->w;
    m_body.h = surface->h;

    SDL_FreeSurface(surface);
    return 0;
}

void Image::set_position(int x, int y)
{
    m_body.x = x;
    m_body.y = y;
}

void Image::set_size(int width, int height)
{
    m_body.w = width;
    m_body.h = height;
}

void Image::fit(int x, int y, int width, int height, int perc)
{
    m_body.x = x + (width - (width / (100 / perc)) - m_body.w );
    m_body.y = y + (height / 2) - (m_body.h / 2);
}

void Image::draw(SDL_Renderer* render)
{
    SDL_RenderCopy(render, m_texture, NULL, &m_body);
}
