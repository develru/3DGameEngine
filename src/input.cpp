#include "input.h"

//Input::Input()
//{
//}
//
//Input::~Input()
//{
//}

bool Input::getKey(std::shared_ptr<Window> win, int keyCode)
{
    bool state = false;

    if(GLFW_PRESS == win->getKey(keyCode))
        state = true;

    return state;
}

