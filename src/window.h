#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height, std::string title);
    virtual ~Window();
    void makeContextCurrent();
    bool shouldClose();
    GLint getFrameBufferWidth();
    GLint getFrameBufferHeight();
    void swapBuffers();
    void render();
    int getKey(int keyCode);

private:
    static int instanceCount;
    GLFWwindow* m_window;
};

#endif // WINDOW_H
