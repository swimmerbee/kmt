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

std::string readFile() {
  //get fn
  char fn[80];
  getstr(fn);
  // Need to remove file name in screen

  // reading in the file
  std::ifstream readFile(fn);

  if(readFile.is_open()) {
    while(!readFile.eof()) {
      // make var, read in curr line, add to scr, refresh
      std::string line = "";
      getline(readFile, line);
      const char * ln = line.c_str();
      addstr(ln);
      addstr("\n");
      refresh();
    }

  }
  std::string fileName(fn);
  readFile.close();
  return fileName;
}

void saveFile() {

}


int main() {
  initscr();

  return 0;
}
