#include "Menu.h"

Menu::Menu()
{
    running = true;
    exit_status = 0;

    running = true;
    Window = NULL;
    Renderer = NULL;
    Icon = NULL;
    cursor = NULL;
    cursorSurf = NULL;
}

Menu::~Menu()
{
    //dtor
}

SDL_Texture* LoadKartinka(std::string file, SDL_Renderer* renderer)
{
        SDL_Texture* texture = nullptr;
        SDL_Surface* surface = IMG_Load(file.c_str());
        if(surface==NULL)
        {
            std::cout<<"Error \n";
        }
        else
        {
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            if(texture==NULL)
            {
                std::cout<<"Error"<<std::endl;
            }
        }
        SDL_FreeSurface(surface);
        return texture;
}

void Menu::onEvent(SDL_Event* event)
{
    if(event->type == SDL_QUIT)
    {
        running = false;
    }
    if(event->type == SDL_KEYDOWN)
    {

    }

    if(event->type == SDL_WINDOWEVENT)
    {
        SDL_GetWindowSize(Window, &WINDOW_WIDTH, &WINDOW_HEIGHT);
    }

    if(event->type == SDL_MOUSEBUTTONUP)
    {
        if(event->button.button == SDL_BUTTON_LEFT)
        {
            if(single_Player.hover())
            {
                exit_status = 1;
                running = false;
            }

            if(two_Players.hover())
            {
                exit_status = 2;
                running = false;
            }

            if(exit.hover())
            {
                exit_status = 3;
                running = false;
            }
        }
    }

}

bool Menu::Init()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    //Create window
    Window = SDL_CreateWindow( "Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480
                              , SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
    if( Window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    SDL_SetWindowMinimumSize(Window, 640, 480);
    SDL_GetWindowSize(Window, &WINDOW_WIDTH, &WINDOW_HEIGHT);

    Icon = IMG_Load("icon.png");
    if(Icon == NULL)
    {
        printf( "Icon could not be loaded! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    SDL_SetWindowIcon(Window, Icon);

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(Renderer == NULL){
        printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    cursorSurf = IMG_Load("cursor.png");
    if(cursorSurf == NULL)
    {
        printf( "Cursor image could not be loaded! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    cursor = SDL_CreateColorCursor(cursorSurf, 0, 0);
    if(cursor == NULL)
    {
        printf( "Cursor could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }

    SDL_SetCursor(cursor);


    Background = LoadKartinka("tank_back.png", Renderer);

    single_Player.load(Renderer, "single.png", 265, 116);
    two_Players.load(Renderer, "two.png", 265, 116);
    exit.load(Renderer, "exit.png", 265, 116);

    return true;
}

int Menu::Execute()
{
    Init();

    while(running)
    {
        while(SDL_PollEvent(&Event))
        {
            onEvent(&Event);
        }

        SDL_RenderClear(Renderer);

        SDL_RenderCopy(Renderer, Background, NULL, NULL);

        int pos =  (WINDOW_HEIGHT - (3 * 116)) / 3;

        single_Player.render(Renderer, (WINDOW_WIDTH - single_Player.rect.w) / 2,  pos / 2);
        two_Players.render(Renderer, (WINDOW_WIDTH - two_Players.rect.w) / 2, single_Player.rect.y + single_Player.rect.h + pos);
        exit.render(Renderer, (WINDOW_WIDTH - single_Player.rect.w) / 2,  two_Players.rect.y + single_Player.rect.h + pos);

        SDL_RenderPresent(Renderer);
    }

    Cleanup();

    return exit_status;
}

void Menu::button::load(SDL_Renderer* Rend, std::string file, int w_, int h_)
{
    rect.w = w_;
    rect.h = h_;

    image = LoadKartinka(file, Rend);
}

void Menu::button::render(SDL_Renderer* Rend , int x_, int y_)
{
    hover();

    rect.x = x_;
    rect.y = y_;

    SDL_RenderCopy(Rend, image, NULL, &rect);
}

bool Menu::button::hover()
{
    int mX, mY;
    SDL_GetMouseState(&mX, &mY);

    SDL_SetTextureColorMod(image, 255, 255, 255);

    if(mX < rect.x) return false;
    if(mX > rect.x + rect.w) return false;
    if(mY < rect.y) return false;
    if(mY > rect.y + rect.h) return false;

    SDL_SetTextureColorMod(image, 128, 255, 255);

    return true;
}

void Menu::Cleanup()
{
    delete(&single_Player);
    delete(&two_Players);
    delete(&exit);

    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_DestroyTexture(Background);

    IMG_Quit();
    SDL_Quit();
}
