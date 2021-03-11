// Bryce Walther (envious)
// KMT : KMT Manipulates Text
// envious@pen-guin.net
// Started 2/12/21
// Finished

#include <fstream>
#include <ncurses.h>

using namespace std;

int main () {
  // Initilization stuff
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, true);


  //Variables
  // int ch;
  // bool on = true;

  // //entering characters
  // while (on == true) {
  //   ch = getch();
  //   if (ch == 0550) { // If is control
  //     on = false;
  //     endwin();
  //   } else {
  //     addch(ch);
  //     refresh();
  //   }
  // }

}
