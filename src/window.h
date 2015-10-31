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

#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window ( int width, int height, std::string title );
    virtual ~Window();
    void makeContextCurrent();
    bool shouldClose();
    GLint getFrameBufferWidth();
    GLint getFrameBufferHeight();
    void swapBuffers();
    void render();
    int getKey ( int keyCode );
    int getMouseButton ( int button );

private:
    static int instanceCount;
    GLFWwindow* m_window;
};

#endif // WINDOW_H
