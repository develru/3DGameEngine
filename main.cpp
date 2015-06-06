#include <iostream>
#include "src/window.h"

int main()
{
    constexpr int WIDTH{800};
    constexpr int HEIGHT{600};
    const std::string TITLE{"3D Engine"};

    Window window{WIDTH, HEIGHT, TITLE};

    window.makeContextCurrent();
    std::cout << glGetString(GL_VERSION) << std::endl;

    while (!window.shouldClose()) {
        glViewport(0, 0, window.getFrameBufferWidth(), window.getFrameBufferHeight());
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        window.swapBuffers();
    }

    return 0;
}

