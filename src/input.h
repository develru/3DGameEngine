#ifndef INPUT_H
#define INPUT_H

#include <memory>
#include <vector>
#include "window.h"

struct Input {
    static const int NUM_KEYCODES = 348;
    static std::vector<int> m_currentKeys;
    static std::vector<int> m_downKeys;
    static std::vector<int> m_upKeys;


    //Input();
    //~Input();
    //Input(const Input &cpy) = delete;
    /**
    * @brief Update and store the pressed or released keys.
    *
    * @param win The working window.
    * @return void
    */
    static void update ( std::shared_ptr< Window > win );

    /**
    * @brief Get the status the given keycode. Return tru if the key is pressed.
    *
    * @param win The working window
    * @param keyCode The key code
    * @return bool
    */
    static bool getKey ( std::shared_ptr<Window> win, int keyCode );

    /**
    * @brief Return true if the given key is pressen down in the current frame.
    *
    * @param win The working window
    * @param keyCode The key code
    * @return bool
    */
    static bool getKeyDown ( std::shared_ptr<Window> win, int keyCode );


    /**
     * @brief Return true if the given key is released in the current frame.
     *
     * @param win The working window
     * @param keyCode The key code
     * @return bool
     */
    static bool getKeyUp ( std::shared_ptr<Window> win, int keyCode );
};

#endif /* INPUT_H */
