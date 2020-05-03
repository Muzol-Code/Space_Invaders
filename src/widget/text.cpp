#include "text.hpp"

Text::Text(std::string text)
{
    m_x = 0;
    m_y = 0;
    m_width = 100;
    m_height = 50;

    m_color.r = 0xff;
    m_color.g = 0xff;
    m_color.b = 0xff;
    m_color.a = 0xff;

    m_text = text.c_str();
}

void Text::set_font(SDL_Renderer* render, TTF_Font* font)
{
    SDL_Surface* surface = TTF_RenderText_Blended(font, m_text.c_str(), m_color);
    m_texture = SDL_CreateTextureFromSurface(render, surface);
    m_width = surface->w;
    m_height = surface->h;

    SDL_FreeSurface(surface);
}

void Text::set_string(std::string text)
{
    m_text = text.c_str();
}

void Text::centralize(int x, int y, int width, int height)
{
    set_position((x + (width / 2)) - (m_width / 2), (y + (height / 2)) - (m_height / 2));
}

void Text::set_position(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Text::draw(SDL_Renderer *render) 
{
    SDL_Rect body = { m_x, m_y, m_width, m_height };
    SDL_RenderCopy(render, m_texture, NULL, &body);
}

Text::~Text()
{
    SDL_DestroyTexture(m_texture);
}
