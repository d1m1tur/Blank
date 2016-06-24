#ifndef ENTITY_H
#define ENTITY_H

#include "includes.h"
#include "LGTexture.h" // include light game texture class
#include <vector> // include the vectors

class Entity
{
    private:

        //a struct for the center of our entity
        struct point
        {
            int x;
            int y;
        }center;

        //a struct for the rect of our entity
        struct position
        {
            float x;
            float y;
            int w;
            int h;
        }rect;

        LGTexture Texture; // the entity texture
        std::string name; // our entity name

        bool enabled; // enabled or not
        float scale; // keeps how big to the original image is our entity


    public:

        Entity(); // Constructor
        Entity(const Entity &other); // Copy constructor
        virtual ~Entity(); // Destructor

        //Creates the Entity with a given name, rect, window size, renderer and path to the texture
        void createEntity(SDL_Renderer *Rend, char *FILE, std::string name_, float x_, float y_, float scale_ = 1);
        void render(SDL_Renderer *Rend); // Render the entity

        bool collision(); // Check if there is collision with another entity
        bool isHover(); // Check if the mouse is over the entity

        position getRect(); // Returns the rect of the entity
        point getCenter(); //Return the center point
        bool getState(); // Return if the entity is enabled or not
        void enable(); // Enables the entity
        void disable(); // Disables the entity

        static std::vector<Entity*> entities; // vector for keeping pointers to all entities
        static Entity *getEntity(std::string name_); // returns an entity by name

    protected:



};

#endif // ENTITY_H
