#include "Entity.h"

//initialize the vector
std::vector<Entity*> Entity::entities;
int WINDOW_WIDTH;
int WINDOW_HEIGHT;

Entity::Entity()
{
    //ctor
}

Entity::Entity(const Entity &other)
{
    //cpy ctor
}

//Destructor
Entity::~Entity()
{
    delete(&Texture); // call the destructor for the texture
    this->enabled = false; // set alive to false
}

//Return the entity with a given name
Entity *Entity::getEntity(std::string name_)
{
    //Iterate trough all of the entities
    for(std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
    {
        //if its the name we are looking for return it
        if((*it)->name == name_)
            return *it;
    }

    return NULL;
}

//Creates an entity with given parameters // read header for more info
void Entity::createEntity(SDL_Renderer *Rend, char *FILE, std::string name_, float x_, float y_, float scale_)
{
    this->enabled = true; // set alive to true

    this->name = name_; // name him

    this->rect.x = x_; // set position x
    this->rect.y = y_; // set position y
    this->scale = scale_; // set the scale of the entity

    this->center.x = rect.w / 2; // calculate center
    this->center.y = rect.h / 2; // calculate center

    this->Texture = LGTexture(); // Creates a LGTexture // read LGTexture.h for more info

    this->Texture.load(Rend, FILE, WINDOW_WIDTH, WINDOW_HEIGHT); // Load the texture with give path and window size

    this->rect.w = Texture.getWidth() * scale_; // calculate the width of the entity to the texture
    this->rect.h = Texture.getHeight() * scale_; // calculate the height of the entity to the texture

    Entity::entities.push_back(this); // save this entity to the vector of pointers
}

//Render the entity
void Entity::render(SDL_Renderer *Rend)
{
    // if its enabled render
    if(this->enabled == true)
        this->Texture.render(Rend, this->rect.x, this->rect.y, this->scale);
}

//Check if the mouse is over the entity
bool Entity::isHover()
{
    int x, y; // integers to store our mouse position
    SDL_GetMouseState(&x , &y); // gets the mouse position on the window

    if(x < this->rect.x * WINDOW_WIDTH) // if mouse is on the left side return false
        return false;
    if(x > (this->rect.x * WINDOW_WIDTH) + this->Texture.getWidth()) // if mouse is on the right side return false
        return false;
    if(y < this->rect.y * WINDOW_HEIGHT) // if mouse is above return false
        return false;
    if(y > (this->rect.y * WINDOW_HEIGHT) + this->Texture.getHeight()) // if mouse is below return false
        return false;

    return true; // return true if non of the above returned false ... its over the entity
}

//Respawn the entity
void Entity::enable()
{
    enabled = true; // set alive to true
}

//Return if the entity is alive
bool Entity::getState()
{
    return enabled;
}

//Return the entity rectangle
Entity::position Entity::getRect()
{
    return rect;
}

Entity::point Entity::getCenter()
{
    return center;
}
