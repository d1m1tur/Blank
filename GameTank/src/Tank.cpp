#include "Tank.h"

SDL_Texture* LoadImage(std::string file, SDL_Renderer* renderer){
        SDL_Texture* texture = nullptr;
        SDL_Surface* surface = IMG_Load(file.c_str());
        if(surface==NULL){
            std::cout<<"Error \n";
        }
        else{
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            if(texture==NULL){
                std::cout<<"Error"<<std::endl;
            }
        }
        SDL_FreeSurface(surface);
        return texture;
}

Tank::Tank(int num)
{
    tankSprite.h = tankSprite.w = tankSprite.x = tankSprite.y = 0;
    tankPos.h = tankPos.w =  tankPos.y = 0;
    tankPos.x = 0;
    direction = 0;
    frameCounter = 0;
    tankTextureRight = nullptr;
    tankTextureLeft = nullptr;
    tankTextureDown = nullptr;
    tankTextureUp = nullptr;
    tempT = nullptr;
    tankNum = num;
    if(tankNum == 1){
        key[0] = SDL_SCANCODE_RIGHT;
        key[1] = SDL_SCANCODE_DOWN;
        key[2] = SDL_SCANCODE_LEFT;
        key[3] = SDL_SCANCODE_UP;
    }
    if(tankNum == 2){
        key[0] = SDL_SCANCODE_D;
        key[1] = SDL_SCANCODE_S;
        key[2] = SDL_SCANCODE_A;
        key[3] = SDL_SCANCODE_W;
    }

}

void Tank::setTextureRight(std::string file, SDL_Renderer* Renderer){
    tankTextureRight = LoadImage(file, Renderer);
    int texturewidth, textureheight;
    SDL_QueryTexture(tankTextureRight, NULL, NULL, &texturewidth, &textureheight);
    tankSprite.h = textureheight/8;
    tankSprite.w = texturewidth/8;
    tankPos.h = textureheight/8;
    tankPos.w = texturewidth/8;
}
void Tank::setTextureLeft(std::string file, SDL_Renderer* Renderer){
    tankTextureLeft = LoadImage(file, Renderer);
    int texturewidth, textureheight;
    SDL_QueryTexture(tankTextureLeft, NULL, NULL, &texturewidth, &textureheight);
    tankSprite.h = textureheight/8;
    tankSprite.w = texturewidth/8;
    tankPos.h = textureheight/8;
    tankPos.w = texturewidth/8;
}
void Tank::setTextureDown(std::string file, SDL_Renderer* Renderer){
    tankTextureDown = LoadImage(file, Renderer);
    int texturewidth, textureheight;
    SDL_QueryTexture(tankTextureDown, NULL, NULL, &texturewidth, &textureheight);
    tankSprite.h = textureheight/8;
    tankSprite.w = texturewidth/8;
    tankPos.h = textureheight/8;
    tankPos.w = texturewidth/8;
}
void Tank::setTextureUp(std::string file, SDL_Renderer* Renderer){
    tankTextureUp = LoadImage(file, Renderer);
    int texturewidth, textureheight;
    SDL_QueryTexture(tankTextureUp, NULL, NULL, &texturewidth, &textureheight);
    tankSprite.h = textureheight/8;
    tankSprite.w = texturewidth/8;
    tankPos.h = textureheight/8;
    tankPos.w = texturewidth/8;
}
/*void Tank::setSprite(SDL_Rect r){
    tankSprite.h = r.h;
    tankSprite.w = r.w;
    tankSprite.x = r.x;
    tankSprite.y = r.y;
}

void Tank::setPos(SDL_Rect r){
    tankPos.h = r.h;
    tankPos.w = r.w;
    tankPos.x = r.x;
    tankPos.y = r.y;
}*/
void Tank::setDirection (int i){
     direction = i;
}
float Tank::getSpeed(){
    return moveSpeed;
}
SDL_Rect Tank::getPos(){
    return tankPos;
}
SDL_Rect Tank::getSprite(){
    return tankSprite;
}
void Tank::setPosx(float a){
    tankPos.x = a;
}
void Tank::setPosy(float a){
    tankPos.x = a;
}
void Tank::setSpritex(float a){
    tankSprite.x = a;
}
void Tank::setSpritey(float a){
    tankSprite.y = a;
}
int Tank::getD(){
    return direction;
}
void Tank::tankMove(const Uint8 *keystate, float deltaTime){
    //keystate = SDL_GetKeyboardState(NULL);
    frameCounter+=deltaTime;
    if(keystate[key[0]]){
            tankPos.x += moveSpeed*deltaTime;
            tankSprite.y = (tankNum-1)*tankSprite.h;
            //tank.setPosx(tank.getPos().x + tank.getSpeed()*deltaTime);
            if (frameCounter >= 0.125f){
                frameCounter = 0;
                tankSprite.x += tankSprite.w;
                //tank.setSpritex(tank.getSprite().x + framewidth);

                if(tankSprite.x>=tankPos.w*8){
                    tankSprite.x = 0;
                }
            }
            tempT = tankTextureRight;

            //SDL_RenderClear(renderer);
            //SDL_RenderCopy(renderer, tankTextureRight, &tankSprite, &tankPos);
            //SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, imageSurface), NULL, &drawingRect);
            //SDL_RenderPresent(renderer);
    }

    else if(keystate[key[2]]){
            tankPos.x -= moveSpeed*deltaTime - 1;
            tankSprite.y = (7 - (tankNum - 1))*tankSprite.h;
            //tank.setPosx(tank.getPos().x + tank.getSpeed()*deltaTime);
            if (frameCounter >= 0.125f){
                frameCounter = 0;
                tankSprite.x += tankSprite.w;
                //tank.setSpritex(tank.getSprite().x + framewidth);

                if(tankSprite.x>=tankPos.w*8){
                    tankSprite.x = 0;
                }
            }
            tempT = tankTextureLeft;

            //SDL_RenderClear(renderer);
            //SDL_RenderCopy(renderer, tankTextureLeft, &tankSprite, &tankPos);
           // SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, imageSurface), NULL, &drawingRect);
            //SDL_RenderPresent(renderer);
    }
    else if(keystate[key[1]]){
            tankPos.y += moveSpeed*deltaTime;
            tankSprite.x = (7 - (tankNum - 1))*tankSprite.w;
            //tank.setPosx(tank.getPos().x + tank.getSpeed()*deltaTime);
            if (frameCounter >= 0.125f){
                frameCounter = 0;
                tankSprite.y += tankSprite.h;
                //tank.setSpritex(tank.getSprite().x + framewidth);

                if(tankSprite.y>=tankPos.h*7){
                    tankSprite.y = 0;
                }
            }
            tempT = tankTextureDown;

            //SDL_RenderClear(renderer);
            //SDL_RenderCopy(renderer, tankTextureDown, &tankSprite, &tankPos);
            //SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, imageSurface), NULL, &drawingRect);
            //SDL_RenderPresent(renderer);
    }
    else if(keystate[key[3]]){
            tankPos.y -= moveSpeed*deltaTime - 1;
            tankSprite.x = (tankNum - 1)*tankSprite.w;
            //tank.setPosx(tank.getPos().x + tank.getSpeed()*deltaTime);
            if (frameCounter >= 0.125f){
                frameCounter = 0;
                tankSprite.y += tankSprite.h;
                //tank.setSpritex(tank.getSprite().x + framewidth);

                if(tankSprite.y>=tankPos.w*7){
                    tankSprite.y = 0;
                }
            }
            tempT = tankTextureUp;

            //SDL_RenderClear(renderer);
            //SDL_RenderCopy(renderer, tankTextureUp, &tankSprite, &tankPos);
            //SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, imageSurface), NULL, &drawingRect);
            //SDL_RenderPresent(renderer);
    }
}
void Tank::draw(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, tempT, &tankSprite, &tankPos);
}

//bool Tank::intersectsWith(Tank t){
    //if(tankPos.x + tankPos.w < t.tankPos.x || tankPos.x > p.tankPos.x + p.tankPos.w)
//}

Tank::~Tank()
{
    //dtor
    SDL_DestroyTexture(tankTextureRight);
    SDL_DestroyTexture(tankTextureLeft);
    SDL_DestroyTexture(tankTextureDown);
    SDL_DestroyTexture(tankTextureUp);
}
