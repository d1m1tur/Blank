#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Includes.h"
#include "OnAnimate.h"
#include "Entity.h"
#include "Characters.h"

class Game
{
    private:

        bool Running;
        SDL_Event Event;

        SDL_Window* Window;
        SDL_Renderer* Renderer;
        //MYSQL *connect;

        SDL_Cursor* Cursor;
        SDL_Cursor* DragCursor;

        SDL_Texture* Splash;
        SDL_Texture* Background;
        SDL_Texture* Kapchica;
        SDL_Texture* backDay;
        SDL_Texture* backNight;
        SDL_Texture* R1;
        SDL_Texture* R2;
        SDL_Texture* R3;
        SDL_Texture* R4;
        SDL_Texture* R5;
        SDL_Texture* R6;

        SDL_Surface* Icon;

    public:

        Game();

        //Variables for the window

        int WindowHeight;
        int WindowWidth;
        bool Fullscreen;

        float Kx;
        float Ky;

        //Creating objects

        OnAnimate MySun;
        Entity Sun;

        OnAnimate MyMoon;
        Entity Moon;

        OnAnimate MyTree;
        Entity Tree;

        Entity Block;

        Entity Cloud;
        Entity Fertilizer;
        Entity Meter;
        Entity MeterF;
        Entity RecycleBin;
        Entity DayNight;

        Entity Rubish[10];
        Entity Level[5];

        int level;

        Entity Kapka[maxKapki];


        int lineX1;
        int lineY1;
        int lineX2;
        int lineY2;

        //Graphics functions

        bool Draw(SDL_Texture* Temp,
                  int x, int y, int w, int h,
                  SDL_RendererFlip Flip);
        bool Draw(SDL_Texture* Temp,
                  int x, int y, int w, int h,
                  int x2, int y2, int w2, int h2,
                  SDL_RendererFlip Flip);
        SDL_Texture* OnLoad( char* FILE );

        //Other functions

        int OnExecute();

        bool OnInit();
        bool LoadContent();

        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void Cleanup();

        int Frame;

        void MouseDrag(Entity *object);
        bool MouseDragReset(Entity *object);
        bool LeftButtonPressed;
        bool dragOne;

        bool SplashScreen();

        float water;
        SDL_Rect waterPointer;
        float waterX;
        float desert;
        float ocean;

        float fertilize;
        SDL_Rect fertilizePointer;
        float fertilizeX;
        float ferMax;
        float ferMin;

        bool beenDrop;

        int currentKapka;
        int currentRubbish;
        void RandomRubbish();

        void CreateKapka();
        int chorbi;

        void MakeResponsive();

        int timeRub;

        bool sunny;

        ifstream database;
        ofstream data;

        //The music that will be played
        Mix_Music *wind = NULL;

        //The sound effects that will be used
        Mix_Chunk *rain_drop1 = NULL;
        Mix_Chunk *rain_drop2 = NULL;
        Mix_Chunk *throw_trash1 = NULL;
        Mix_Chunk *throw_trash2 = NULL;

};
#endif // GAME_H_INCLUDED
