#include <iostream>
#include "src/window.h"
#include "src/maincomponent.h"
#include "src/time.h"

int main()
{
    MainComponent game;

    //std::cout << Time::getTime() << " ns" << std::endl;

    game.start();

    return 0;
}

