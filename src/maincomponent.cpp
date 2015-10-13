#include <iostream>
#include "maincomponent.h"

MainComponent::MainComponent()
{
    m_window = new Window{WIDTH, HEIGHT, TITLE};

    m_window->makeContextCurrent();
    std::cout << glGetString(GL_VERSION) << std::endl;

}

void MainComponent::start()
{
    run();
}

void MainComponent::stop()
{

}

void MainComponent::run()
{
    while (!m_window->shouldClose()) {
        glViewport(0, 0, m_window->getFrameBufferWidth(), m_window->getFrameBufferHeight());
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        m_window->swapBuffers();
    }
}

void MainComponent::render()
{

}

void MainComponent::cleanUp()
{

}

