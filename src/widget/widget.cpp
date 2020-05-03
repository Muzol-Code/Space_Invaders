#include "widget.hpp"

Widget::Widget(int x, int y)
{
    m_body.x = this->x = x;
    m_body.y = this->y = y;
    m_body.w = this->width  = 100;
    m_body.h = this->height = 50;

    m_color.r = 0xff;
    m_color.g = 0xff;
    m_color.b = 0xff;
    m_color.a = 0xff;
}

Widget::~Widget()
{
}

void Widget::set_size(int width, int height)
{
    m_body.w = this->width = width;
    m_body.h = this->height = height;
}

void Widget::set_position(int x, int y)
{
    m_body.x = this->x = x;
    m_body.y = this->y = y;
}

void Widget::set_color(SDL_Color color)
{
    m_color.r = color.r;
    m_color.g = color.g;
    m_color.b = color.b;
    m_color.a = color.a;
}

void Widget::draw(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render, m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_RenderFillRect(render, &m_body);
}
