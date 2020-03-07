#include <stdio.h>
#include <ncurses.h>

#include "headers/menu.h"
#include "headers/window.h"
#include "headers/employee.h"
#include "headers/form.h"

int main() {	
	// initialize screen
	initscr();
	noecho();
	curs_set(0);

	// create Window struct
  Window window;

	// assign new window instance to Window struct
	window.window = newwin(0,0,0,0);

	keypad(window.window, true);

	getmaxyx(stdscr, window.y_max, window.x_max);
	scrollok(window.window, true);

  // create main menu items
	const int main_menu_size = 5;
	const char* main_menu_items[] = {
		"  Search  Employee  " ,
		"  Create  Employee  ",
		"  Update  Employee  ",
		"  Remove  Employee  ",
		"       Quit         "
	};

  // create new menu 
	Menu MainMenu = {main_menu_items, 0, 0};

  do {
    switch(MainMenu.state) {
    	case 0: {
        print_header(&window);
				render_main_menu(&window, &MainMenu, main_menu_items, &main_menu_size);
				break;
      }
			case 1: {
				clear_screen(&window);
				const char* temp_form_labels[] = {
					"First Name: ",
					"Middle Name: ",
					"Last Name: ",
					"Suffix: ",
					"Email: ",
					"Home Phone: ",
					"Cell Phone: ",
					"Marital Status: ",
					"Social Security: ",
					"Hire Date: ",
					"Emergency Contact: ",
					"Gender: ",
					"Ethnicity: ",
					"Residence: ",
					"Job Title: ",
					"Salary: "
				};


				MainMenu.state = 0;
				break;
			}
			case 2: {
				clear_screen(&window);
				MainMenu.state = 0;
				break;
      }
			case 4: {
				clear_screen(&window);
				MainMenu.state = -1;
				break;
			}
      default : {
				clear_screen(&window);
        MainMenu.state = 0;
        break;
      }
    }
  } while (MainMenu.state > -1);

	printf("\nGoodbye...\n\n");

  // Turn back on cursor
  curs_set(1);
	echo();
	endwin();

  return 0;
};
