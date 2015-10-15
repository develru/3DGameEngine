#include <iostream>
#include "maincomponent.h"

MainComponent::MainComponent() :
    m_isRunning{false}
{
    m_window = new Window{WIDTH, HEIGHT, TITLE};

    m_window->makeContextCurrent();
    std::cout << glGetString(GL_VERSION) << std::endl;


}

void MainComponent::start()
{
    if (!m_isRunning) {
        run();
    }
}

void MainComponent::stop()
{
    if(m_isRunning) {
        m_isRunning = false;
    }

}

void MainComponent::run()
{
    m_isRunning = true;

    while (m_isRunning) {
        if (m_window->shouldClose()) {
            stop();
        }

        // maybee all this transfer to the m_window render() methode
        glViewport(0, 0, m_window->getFrameBufferWidth(), m_window->getFrameBufferHeight());
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwPollEvents();
        m_window->swapBuffers();
    }

    cleanUp();
}

void MainComponent::render()
{
    m_window->render();
}

void MainComponent::cleanUp()
{

}

int MainComponent::getWidth()
{
    return m_window->getFrameBufferWidth();
}

int MainComponent::getHeight()
{
    return m_window->getFrameBufferHeight();
}

