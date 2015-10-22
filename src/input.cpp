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

void Input::update(std::shared_ptr<Window> win)
{
  m_upKeys.clear();
  
  for(int i = 0; i < NUM_KEYCODES; i++)
    if(!getKey(win, i) && std::find(m_currentKeys.begin(), m_currentKeys.end(), i) != m_currentKeys.end())
      m_upKeys.push_back(i);
  
  m_downKeys.clear();
  
  for(int i = 0; i < NUM_KEYCODES; i++)
    if(getKey(win, i) && std::find(m_currentKeys.begin(), m_currentKeys.end(), i) == m_currentKeys.end())
      m_downKeys.push_back(i);
  
  m_currentKeys.clear();
  
  for(int i = 0; i < NUM_KEYCODES; i++)
    if(getKey(win, i))
      m_currentKeys.push_back(i);
}

bool Input::getKey(std::shared_ptr<Window> win, int keyCode)
{
    bool state = false;

    if(GLFW_PRESS == win->getKey(keyCode))
        state = true;

    return state;
}

bool Input::getKeyDown(int keyCode)
{
  if(std::find(m_downKeys.begin(), m_downKeys.end(), keyCode) != m_downKeys.end())
    return true;
  
  return false;
}

bool Input::getKeyUp(int keyCode)
{
  if(std::find(m_upKeys.begin(), m_upKeys.end(), keyCode) != m_upKeys.end())
    return true;
  
  return false;
}

