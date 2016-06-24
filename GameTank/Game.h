#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"


class Game{
private:

    bool running;
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Surface* imageSurface;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    SDL_Rect drawingRect;
    int width;
    int height;
    float frameTime;
    int prevTime;
    int currentTime;
    float deltaTime;

public:

    Game();

    int onExecute();

    bool onInit();

    void onEvent(SDL_Event* event);

    void onLoop();

    void onRender();

    void onCleanup();
};


#endif
