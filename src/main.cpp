#include <ncurses.h>
#include <fstream>

int checkMod(int mod) {
  if (mod == 's' || mod == 'o' || mod == 'x') {
    return mod;
  } else {
    return 0;
  }
}

void initCurses() {
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, true);
}

void readFile() {
  //get fn
  char * fn;
  getstr(fn);

  // reading in the file
  std::ifstream readFile(fn);

  if(readFile.is_open()) {
    while(!readFile.eof()) {
      // make var, read in curr line, add to scr, refresh
      std::string line = "";
      getline(readFile, line);
      const char * ln = line.c_str();
      addstr(ln);
      refresh();
    }
    readFile.close();
  }
}

int main() {
  initCurses();
  std::string hi;
  getstr(hi);
  printf(hi);
}
