#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include "SDL_image.h"
#include "string"
#include "iostream"
#include "stdio.h"

class Menu
{
    public:
        Menu();
        virtual ~Menu();

        int Execute();

    protected:

    private:

        int exit_status;

        int WINDOW_WIDTH;
        int WINDOW_HEIGHT;

        bool running;

        SDL_Texture* Background;
        SDL_Renderer* Renderer;
        SDL_Window* Window;
        SDL_Event Event;
        SDL_Surface* Icon;
        SDL_Cursor* cursor;
        SDL_Surface* cursorSurf;

        bool Init();
        void onEvent(SDL_Event* event);
        void Cleanup();

        typedef struct button
        {
            ~button()
            {
                SDL_DestroyTexture(image);
            }

            SDL_Texture* image;
            SDL_Rect rect;

            void load(SDL_Renderer* Rend, std::string file, int w_, int h_);
            void render(SDL_Renderer* Rend, int x_, int y_);
            bool hover();
        };

        button single_Player;
        button two_Players;
        button exit;
};

#endif // MENU_H
