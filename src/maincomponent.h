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

#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

#include <memory>
#include "window.h"
#include "game.h"

class MainComponent
{
public:
    MainComponent();
    ~MainComponent();
    void start();
    void stop();

private:
    static constexpr int WIDTH {800};
    static constexpr int HEIGHT {600};
    const std::string TITLE {"3D Engine"};
    static constexpr double FRAME_CAP {5000.0};
    std::shared_ptr<Window> m_window;
    bool m_isRunning;
    std::shared_ptr<Game> m_game;

    void run();
    void render();
    void cleanUp();
    int getWidth();
    int getHeight();
    std::string getTitle() {
        return TITLE;
    }
};

#endif // MAINCOMPONENT_H
