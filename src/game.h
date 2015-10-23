#ifndef GAME_H
#define GAME_H

#include <memory>
#include "window.h"

class Game
{
public:
    Game();
    ~Game();
    void input(std::shared_ptr<Window> win);
    void update( std::shared_ptr< Window > win );
    void render();


};

#endif // GAME_H
