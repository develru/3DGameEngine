#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

#include "window.h"

class MainComponent
{
public:
    MainComponent();
    void start();
    void stop();
    void run();
    void render();
    void cleanUp();

private:
    static constexpr int WIDTH{800};
    static constexpr int HEIGHT{600};
    const std::string TITLE{"3D Engine"};
    Window* m_window;
};

#endif // MAINCOMPONENT_H
