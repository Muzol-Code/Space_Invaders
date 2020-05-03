#include "entity.hpp"

Entity::Entity(int x, int y)
{
    this->x = m_body.x = x; 
    this->y = m_body.y = y; 
    this->width = m_body.w = 130;
    this->height = m_body.h = 30;
}

void Entity::update(SDL_Event event)
{
}

void Entity::draw(SDL_Renderer* render)
{
    SDL_SetRenderDrawColor(render, 0xff, 0xff, 0xff, 0xff); 
    SDL_RenderFillRect(render, &m_body);
}
