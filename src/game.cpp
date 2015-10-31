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

#include "game.h"

#include <iostream>
#include "input.h"

Game::Game()
{

}

Game::~Game()
{
}

void Game::input(std::shared_ptr< Window > win)
{
    if (Input::getKeyDown(win, GLFW_KEY_UP)) {
        std::cout << "We've just pressed up!" << std::endl;
    }

    if (Input::getKeyUp(win, GLFW_KEY_UP)) {
        std::cout << "We've just released up!" << std::endl;
    }
    
    if (Input::getMouseButtonDown(win, GLFW_MOUSE_BUTTON_LEFT)) {
	std::cout << "We've just pressed the left mouse button" << std::endl;
    }
    
    if (Input::getMouseButtonUp(win, GLFW_MOUSE_BUTTON_LEFT)) {
	std::cout << "We've just released the left mouse button" << std::endl;
    }
}

void Game::update(std::shared_ptr< Window > win)
{
    Input::update(win);
}

void Game::render()
{

}
