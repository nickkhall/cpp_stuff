#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../headers/window.hpp"

class Menu {
  private:
		std::vector<std::string> items{};
    short int highlighted;
    short int state;

  public:
    std::vector<std::string> menu_items;

    Menu(const std::vector<std::string> &menu_items);
    
    const int render_menu(Window *window); 
		const short int* get_state() const;
    void update_state(int state);
		void handle_navigation(int key_code);
};

#endif