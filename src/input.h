#ifndef INPUT_H
#define INPUT_H

#include <memory>
#include "window.h"

class Input
{
public:
    //Input();
    //~Input();
    //Input(const Input &cpy) = delete;
    static void update();
    static bool getKey(std::shared_ptr<Window> win, int keyCode);
    static bool getKeyDown(int keyCode);

private:
};

#endif /* INPUT_H */
