#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <SDL_surface.h>
#include <SDL_render.h>
#include <SDL_rect.h>
#include <SDL_image.h>
#include <string>

class Image
{
private:
    SDL_Rect m_body;
    SDL_Texture* m_texture;

public:
    Image(){}
    Image(int x, int y);
    ~Image();

    bool load_image(std::string file_path, SDL_Renderer* render);

    void set_position(int x, int y);

    void fit(int x, int y, int width, int height, int perc);

    void set_size(int width, int height);

    void draw(SDL_Renderer* render);
};

#endif //IMAGE_HPP
