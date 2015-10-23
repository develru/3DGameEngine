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
