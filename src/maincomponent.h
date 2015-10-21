#ifndef MAINCOMPONENT_H
#define MAINCOMPONENT_H

#include <memory>
#include "window.h"
#include "game.h"

class MainComponent
{
public:
    MainComponent();
    ~MainComponent();
    void start();
    void stop();

private:
    static constexpr int WIDTH{800};
    static constexpr int HEIGHT{600};
    const std::string TITLE{"3D Engine"};
    static constexpr double FRAME_CAP{5000.0};
    std::shared_ptr<Window> m_window;
    bool m_isRunning;
    std::shared_ptr<Game> m_game;

    void run();
    void render();
    void cleanUp();
    int getWidth();
    int getHeight();
    std::string getTitle() { return TITLE; }
};

#endif // MAINCOMPONENT_H
