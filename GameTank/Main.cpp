#include <SDL.h>
#include <stdio.h>
#include "Game.h"
#include "Menu.h"
#include "Tank.h"

Game::Game() {
    running = true;
    window = NULL;
    surface = NULL;
    imageSurface = NULL;
    renderer = NULL;
    width = 640;
    height = 480;
    drawingRect.x=drawingRect.y=0;
    drawingRect.w=width;
    drawingRect.h=height;
    texture=nullptr;
    prevTime = 0;
    currentTime = 0;
    deltaTime = 0;
}

/*SDL_Texture* LoadTexture(std::string filepath, SDL_Renderer* renderTarget){
    SDL_Texture* texture = nullptr;
    SDL_Surface* surface = IMG_Load(filepath.c_str());
    if(surface == nullptr){
        printf( "surface could not be loaded! SDL_Error: %s\n", IMG_GetError() );
    }
    else{
        texture = SDL_CreateTextureFromSurface(renderTarget, surface);
        if(texture==nullptr){
            std::cout<<"Error \n";
        }
    }
    SDL_FreeSurface(surface);
    return texture;
}*/

int Game::onExecute() {
    if(onInit() == false) {
        return -1;
    }

    Tank tank(1);
    Tank tank2(2);
    tank.setSpeed(100);
    tank.setTextureRight("MulticolorTanks.png", renderer);
    tank.setTextureLeft("MulticolorTanksLeft.png", renderer);
    tank.setTextureUp("MulticolorTanksUp.png", renderer);
    tank.setTextureDown("MulticolorTanksDown.png", renderer);
    tank2.setTextureRight("MulticolorTanks.png", renderer);
    tank2.setTextureLeft("MulticolorTanksLeft.png", renderer);
    tank2.setTextureUp("MulticolorTanksUp.png", renderer);
    tank2.setTextureDown("MulticolorTanksDown.png", renderer);
    int framewidth = tank.getPos().w;
    int frameheight = tank.getPos().h;

    SDL_Event Event;
    const Uint8 *keyState;

    while(running) {
        prevTime = currentTime;
        currentTime = SDL_GetTicks();
        deltaTime = (currentTime - prevTime) / 1000.0f;
        while(SDL_PollEvent(&Event)) {
            onEvent(&Event);
        }

        std::cout << tank.getPos().x << "    " << tank.getPos().y <<std::endl;
        keyState = SDL_GetKeyboardState(NULL);

        tank.tankMove(keyState, deltaTime);
        tank2.tankMove(keyState, deltaTime);




        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        tank.draw(renderer);
        tank2.draw(renderer);
        //SDL_RenderCopy(renderer, tank.tankTextureRight, &pederas, &pederast);

        SDL_RenderPresent(renderer);

       // SDL_UpdateWindowSurface( window );

        onLoop();
        onRender();
    }

    onCleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    Game game;
    Menu menu;

    menu.Execute();
    game.onExecute();

    return 0;
}
