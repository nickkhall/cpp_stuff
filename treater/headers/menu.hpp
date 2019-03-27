#include <iostream>
#include <vector>
#include <string>

#ifndef MENU_H
#define MENU_H

#include "./window.hpp"

class Menu {
private:
  std::vector<std::string> items;
  int selected;

public:
  int highlighted;
  int pageNum;
  std::vector<std::vector<std::string> > itemsContainer {};

	Menu(std::vector<std::string> items);

  // Getters
  int GetMenuSelected();

  // Setters
  void SetMenuSelected(int keyCode);
  int PrintMenu(Window* window, int yDividend, int xDividend);

  void PaginateItems();
  void IncrementPageNum();
};

#endif
