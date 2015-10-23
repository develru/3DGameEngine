#include <algorithm>
#include "input.h"

//Input::Input()
//{
//}
//
//Input::~Input()
//{
//}

std::vector<int> Input::m_currentKeys;
std::vector<int> Input::m_downKeys;
std::vector<int> Input::m_upKeys;

std::vector<int> Input::m_currentMouseButtons;
std::vector<int> Input::m_downMouseButtons;
std::vector<int> Input::m_upMouseButtons;


void Input::update(std::shared_ptr<Window> win)
{
    m_upKeys.clear();
    for (int i = 0; i < NUM_KEYCODES; i++)
        if (!getKey(win, i) && std::find(m_currentKeys.begin(), m_currentKeys.end(), i) != m_currentKeys.end()) {
            m_upKeys.push_back(i);
        }

    m_downKeys.clear();
    for (int i = 0; i < NUM_KEYCODES; i++)
        if (getKey(win, i) && std::find(m_currentKeys.begin(), m_currentKeys.end(), i) == m_currentKeys.end()) {
            m_downKeys.push_back(i);
        }

    m_currentKeys.clear();
    for (int i = 0; i < NUM_KEYCODES; i++)
        if (getKey(win, i)) {
            m_currentKeys.push_back(i);
        }

    m_upMouseButtons.clear();
    for (int i = 0; i < NUM_MOUSE_BUTTONS; i++)
        if (!getMouseButton(win, i) &&
                std::find(m_currentMouseButtons.begin(), m_currentMouseButtons.end(), i) != m_currentMouseButtons.end()) {
            m_upMouseButtons.push_back(i);
        }

    m_downMouseButtons.clear();
    for (int i = 0; i < NUM_MOUSE_BUTTONS; i++)
        if (getMouseButton(win, i) &&
                std::find(m_currentMouseButtons.begin(), m_currentMouseButtons.end(), i) == m_currentMouseButtons.end()) {
            m_downMouseButtons.push_back(i);
        }

    m_currentMouseButtons.clear();
    for (int i = 0; i < NUM_MOUSE_BUTTONS; i++)
        if (getMouseButton(win, i)) {
            m_currentMouseButtons.push_back(i);
        }
}

bool Input::getKey(std::shared_ptr<Window> win, int keyCode)
{
    return GLFW_PRESS == win->getKey(keyCode);
}

bool Input::getKeyDown(std::shared_ptr<Window> win, int keyCode)
{
    return  std::find(m_downKeys.begin(), m_downKeys.end(), keyCode) != m_downKeys.end();
}

bool Input::getKeyUp(std::shared_ptr<Window> win, int keyCode)
{
    return std::find(m_upKeys.begin(), m_upKeys.end(), keyCode) != m_upKeys.end();
}

bool Input::getMouseButton(std::shared_ptr< Window > win, int button)
{
    return GLFW_PRESS == win->getMouseButton(button);
}

bool Input::getMouseButtonDown(std::shared_ptr< Window > win, int button)
{
    return std::find(m_downMouseButtons.begin(), m_downMouseButtons.end(), button) != m_downMouseButtons.end();
}

bool Input::getMouseButtonUp(std::shared_ptr< Window > win, int button)
{
    return std::find(m_upMouseButtons.begin(), m_upMouseButtons.end(), button) != m_upMouseButtons.end();
}

