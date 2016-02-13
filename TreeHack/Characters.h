#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Entity.h"

class Characters : public Entity
{
    public:
        Characters();
        virtual ~Characters();

        bool CanMove;

        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();

        bool Gravity(int WindowHeight);

    protected:
    private:
};

#endif // CHARACTERS_H
