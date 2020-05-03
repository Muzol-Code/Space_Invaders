#ifndef TEXT_HPP
#define TEXT_HPP

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Text
{
private:
    SDL_Texture* m_texture;
    SDL_Color m_color;

    std::string m_text;

public:
    Text(std::string text);
    ~Text();

    void set_font(SDL_Renderer* render, TTF_Font* font);

    void set_string(std::string text);


    void set_position(int x, int y);

    void draw(SDL_Renderer *render);

    void centralize( int x, int y, int width, int height);

    int m_width;
    int m_height;
    int m_x;
    int m_y;
};


#endif // TEXT_HPP
