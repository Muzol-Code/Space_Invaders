#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_events.h>

class Entity
{
protected:
    SDL_Rect m_body; 
public:
    int x, y;
    int width, height;
    Entity(){}
    Entity(int x, int y);
    
    virtual void draw(SDL_Renderer* render);
    virtual void update(SDL_Event event);
};

#endif // ENTITY_HPP
