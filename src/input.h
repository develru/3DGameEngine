/*
 * 3D Game Engine
 * Copyright (C) 2015  Richard Schwalk richard[p]schwalk[at]gmail[p]com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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

    static const int NUM_MOUSE_BUTTONS = 5;
    static std::vector<int> m_currentMouseButtons;
    static std::vector<int> m_downMouseButtons;
    static std::vector<int> m_upMouseButtons;

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
    
    /**
     * @brief Get the status of the desired mouse button. Return true if the mouse button is pressed.
     * 
     * @param win The working window
     * @param button The desired button
     * @return bool
     */
    static bool getMouseButton ( std::shared_ptr<Window> win, int button );
    
    /**
     * @brief Return true if the mouse button was pressed down in the current frame.
     * 
     * @param win The working window
     * @param button The desired button
     * @return bool
     */
    static bool getMouseButtonDown ( std::shared_ptr<Window> win, int button );
    
    /**
     * @brief Return true if the butten released in the current frame.
     * 
     * @param win The working window
     * @param button The desired button
     * @return bool
     */
    static bool getMouseButtonUp ( std::shared_ptr<Window> win, int button );
};

#endif /* INPUT_H */
