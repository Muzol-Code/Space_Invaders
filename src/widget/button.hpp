#ifndef BUTTON_HPP
#define BUTTON_HPP

/*
#include <SDL_rect.h> 
#include <SDL_events.h> 
*/
#include <SDL.h>
#include <SDL_ttf.h>

#include "widget.hpp"
#include "text.hpp"
#include <string>
#include <functional>
#include <memory>

enum ButtonState {
    IDLE,
    HOVER,
    ON_CLICK,
};

class Button : public Widget
{
public:
    typedef std::function<void()> Callback;

    Button();

    Button(int x, int y, std::string text);

    void set_colors(ButtonState state, SDL_Color color);

    void set_text_font(SDL_Renderer* render, TTF_Font* font);

    void set_callback(Callback callback);

    bool is_mouse_on(int x, int y);

    void events(SDL_Event event);

    void update(SDL_Event event);

    void set_size(int width, int height) override;

    void draw(SDL_Renderer* render) override;

private:
    bool m_active;
    Callback m_callback;
    ButtonState m_state;
    Text m_text;
    SDL_Color m_none_bt_color;
    SDL_Color m_on_click_bt_color;
    SDL_Color m_hover_bt_color;
};

#endif // BUTTON_HPP
