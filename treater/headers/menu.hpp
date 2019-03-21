#include <iostream>
#include <vector>
#include <string>

#ifndef MENU_H
#define MENU_H

#include "./window.hpp"

class Menu {
private:
  std::vector<std::string> items;
  std::string type;

public:
  int selected;
  int highlighted {0};
  int yPos;
  int xPos;

	Menu(std::string type, std::vector<std::string> items);

  // Getters
  int GetMenuSelected();
  std::string GetMenuType();
  int GetYPos();
  int GetXPos();

  // Setters
  void SetMenuSelected(int keyCode);
  void SetMenuYPosXPos(Window* window);
  int PrintMenu(Window* window);
};

#endif
