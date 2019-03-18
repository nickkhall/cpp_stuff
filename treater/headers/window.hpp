#include <iostream>
#include <ncurses.h>

#ifndef WINDOW_H
#define WINDOW_H

class Window {
public:
	Window();

  int yMax;
  int xMax;
  WINDOW* windowInstance;

  // Setters
  void SetMaxYX();
  void ConfigureWindow();
};

#endif
