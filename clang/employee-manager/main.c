#include <libpq-fe.h>
#include <stdio.h>
#include <ncurses.h>

#include "src/headers/menu.h"
#include "src/headers/window.h"
#include "src/headers/employee.h"
#include "src/headers/form.h"
#include "src/headers/utils.h"
#include "src/headers/uuid.h"
#include "src/headers/db.h"

// main menu items
const int main_menu_size = 5;
const char* main_menu_items[] = {
  "  Search  Employee  " ,
  "  Create  Employee  ",
  "  Update  Employee  ",
  "  Remove  Employee  ",
  "       Quit         "
};

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

  // create new menu 
  Menu MainMenu = {main_menu_items, 0, 0};

  do {
    switch(MainMenu.state) {
      case 0: {
        print_header(&window);
        render_main_menu(&window, &MainMenu, main_menu_items, &main_menu_size);
        break;
      }
      // search employee
      case 1: {
				// get user input
				const char* user_input = print_search_form(&window);
				const char* const* queryParams = &user_input;
				char* sql_query = "SELECT * FROM employees WHERE id = $1 OR first = $1 OR last = $1";
				PGresult* query_result;

				// query db
				query_result = query_db(sql_query, queryParams, 1);

				// update menu state to 0 to return to main menu
        MainMenu.state = 0;
        
        // free up pointer returned from `print_search_form`
        free((char*)user_input);
        break;
      }
      // create employee
      case 2: {
        // @TODO: (nickkhall) Refactor me to be a more functional approach, this is a mess
        clear_screen(&window);
        const int size = 16;
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

        // user input data
        char** user_input = create(&window, temp_form_labels, &size);

        // write user input to data as employee
        write_to_file(temp_form_labels, user_input, &size);

        MainMenu.state = 0;
        break;
      }
      // quit
      case 5: {
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
}
