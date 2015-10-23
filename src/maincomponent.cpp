#include <iostream>
#include <thread>
#include <chrono>
#include "maincomponent.h"
#include "time.h"
#include "input.h"

MainComponent::MainComponent() :
    m_isRunning {false}
{
    //m_window = new Window(WIDTH, HEIGHT, TITLE);
    m_window = std::shared_ptr<Window> ( new Window ( WIDTH, HEIGHT, TITLE ) );

    m_window->makeContextCurrent();
    std::cout << glGetString ( GL_VERSION ) << std::endl;

    //m_game = new Game();
    m_game = std::shared_ptr<Game> ( new Game() );

}

MainComponent::~MainComponent()
{
    //delete m_game;
    //delete m_window;

}

void MainComponent::start()
{
    if ( !m_isRunning )
    {
        run();
    }
}

void MainComponent::stop()
{
    if ( m_isRunning )
    {
        m_isRunning = false;
    }

}

void MainComponent::run()
{
    m_isRunning = true;

    //std::shared_ptr<Input> inp(new Input());

    int frames = 0;
    long frameCounter = 0;

    double frameTime = 1 / FRAME_CAP;
    long lastTime = Time::getTime();
    double unprocessedTime = 0;

    while ( m_isRunning )
    {
        bool isRender = false;

        long startTime = Time::getTime();
        long passedTime = startTime - lastTime;
        lastTime = startTime;

        unprocessedTime += passedTime / ( double ) Time::SECOND;
        frameCounter += passedTime;

        while ( unprocessedTime > frameTime )
        {
            isRender = true;

            unprocessedTime -= frameTime;

            if ( m_window->shouldClose() )
            {
                stop();
            }

            if ( Input::getKey ( m_window, GLFW_KEY_ESCAPE ) )
            {
                stop();
            }

            m_game->input ( m_window );
            m_game->update ( m_window );

            //TODO: update game

            if ( frameCounter >= Time::SECOND )
            {
                std::cout << frames << std::endl;
                frames = 0;
                frameCounter = 0;
            }
        }

        if ( isRender )
        {

            // maybee all this transfer to the m_window render() methode
            glViewport ( 0, 0, m_window->getFrameBufferWidth(), m_window->getFrameBufferHeight() );
            glClear ( GL_COLOR_BUFFER_BIT );

            render();

            glfwPollEvents();
            m_window->swapBuffers();

            frames++;
        }
        else
        {
            std::this_thread::sleep_for ( std::chrono::milliseconds ( 1 ) );
        }
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

