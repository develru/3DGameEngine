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

#ifndef GAME_H
#define GAME_H

#include <memory>
#include "window.h"

class Game
{
public:
    Game();
    ~Game();
    void input ( std::shared_ptr<Window> win );
    void update ( std::shared_ptr< Window > win );
    void render();


};

#endif // GAME_H
