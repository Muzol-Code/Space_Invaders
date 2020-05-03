#include "button.hpp"
#include <stdio.h>

Button::Button(int x, int y, std::string text)
    : Widget(x, y)
    , m_text(text)
{
    m_active = true;
    m_state = IDLE;
    m_none_bt_color     = {0x00, 0xff, 0x0, 0xff};
    m_on_click_bt_color = {0x00, 0x00, 0xff, 0x80};
    m_hover_bt_color    = {0xff, 0x00, 0x0, 0xff};

    set_color(m_none_bt_color);
}

void Button::set_text_font(SDL_Renderer* render, TTF_Font* font)
{
    m_text.set_font(render, font);
    m_text.centralize(x, y, width, height);
}

void Button::events(SDL_Event event)
{
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT && m_active) {
                m_active = false;
                m_state = ON_CLICK;
                if (m_callback) {
                    m_callback();
                }
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT && !m_active) {
                m_active = true;
            }
            break;

        default: break;
    }
}


void Button::set_callback(Callback callback)
{
    this->m_callback = std::move(callback);
}

bool Button::is_mouse_on(int x, int y)
{
    if(x > this->x && x < (this->x + this->width) &&
       y > this->y && y < (this->y + this->height)) {
        return true;     
    }

    return false;
}

void Button::set_colors(ButtonState state, SDL_Color color)
{
    switch (state)
    {
    case IDLE:
        m_none_bt_color = color;
        break;
    case ON_CLICK:
        m_on_click_bt_color = color;
        break;
    case HOVER:
        m_hover_bt_color = color;
        break;
    
    default: break;
    }
}

void Button::update(SDL_Event event)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if(is_mouse_on(x, y)) {
        m_state = HOVER;
        events(event);
    } else {
        m_state = IDLE;
    }

    switch (m_state)
    {
    case IDLE:
        set_color(m_none_bt_color);
        break;
    case ON_CLICK:
        set_color(m_on_click_bt_color);
        break;
    case HOVER:
        set_color(m_hover_bt_color);
        break;
    
    default: break;
    }
}


void Button::set_size(int width, int height)
{
    m_body.w = this->width = width;
    m_body.h = this->height = height;

    m_text.centralize(x, y, width, height);
}

void Button::draw(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render, m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_RenderFillRect(render, &m_body);
    m_text.draw(render);
}
