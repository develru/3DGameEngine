#ifndef INPUT_H
#define INPUT_H

#include <memory>
#include <vector>
#include "window.h"

struct Input
{
    static const int NUM_KEYCODES = 300;
    static std::vector<int> m_currentKeys;
    static std::vector<int> m_downKeys;
    static std::vector<int> m_upKeys;
    
  
    //Input();
    //~Input();
    //Input(const Input &cpy) = delete;
    static void update(std::shared_ptr< Window > win);
    static bool getKey(std::shared_ptr<Window> win, int keyCode);
    static bool getKeyDown(std::shared_ptr<Window> win, int keyCode);
    static bool getKeyUp(std::shared_ptr<Window> win, int keyCode);
};

#endif /* INPUT_H */
