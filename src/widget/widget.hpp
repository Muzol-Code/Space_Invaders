#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SDL_rect.h>
#include <SDL_render.h>

class Widget
{
protected:
    SDL_Rect m_body;
    SDL_Color m_color;
public:
    Widget(int x, int y);
    Widget() {}
    ~Widget();

    void set_position(int x, int y);

    void set_color(SDL_Color color);

    virtual void set_size(int width, int height);

    virtual void draw(SDL_Renderer* render);

    int x;
    int y;
    int width;
    int height;
};


#endif // WIDGET_HPP
