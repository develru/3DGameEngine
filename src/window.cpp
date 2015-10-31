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

#include <iostream>

#include "window.h"

int Window::instanceCount = 0;

Window::Window ( int width, int height, std::string title )
{
    if ( instanceCount == 0 )
    {
        GLint glfwStatus = glfwInit();
        if ( glfwStatus != GL_TRUE )
        {
            std::cout << "GLFW Failed to initialize!" << std::endl;
            glfwTerminate();
        }

        glfwWindowHint ( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
        glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
        glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 2 );
    }

    std::cout << "GLFW initialized!" << std::endl;

    instanceCount++;

    m_window = glfwCreateWindow ( width, height, title.c_str(), NULL, NULL );
}

Window::~Window()
{
    glfwDestroyWindow ( m_window );
    instanceCount--;
    if ( instanceCount == 0 )
    {
        glfwTerminate();
        std::cout << "GLFW deinitialized!" << std::endl;
    }
}

void Window::makeContextCurrent()
{
    glfwMakeContextCurrent ( m_window );
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose ( m_window );
}

GLint Window::getFrameBufferWidth()
{
    GLint width;
    glfwGetFramebufferSize ( m_window, &width, NULL );
    return width;
}

GLint Window::getFrameBufferHeight()
{
    GLint height;
    glfwGetFramebufferSize ( m_window, NULL, &height );
    return height;
}

void Window::swapBuffers()
{
    glfwSwapBuffers ( m_window );
}

void Window::render()
{

}

int Window::getKey ( int keyCode )
{
    return glfwGetKey ( m_window, keyCode );
}

int Window::getMouseButton ( int button )
{
    return glfwGetMouseButton ( m_window, button );
}

