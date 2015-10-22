#include "input.h"

//Input::Input()
//{
//}
//
//Input::~Input()
//{
//}

void Input::update()
{
}

bool Input::getKey(std::shared_ptr<Window> win, int keyCode)
{
    bool state = false;

    if(GLFW_PRESS == win->getKey(keyCode))
        state = true;

    return state;
}

bool Input::getKeyDown(int keyCode)
{
  return false;
}

