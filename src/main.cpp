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
  erase();

  // reading in the file
  std::ifstream read(fn);

  if(read.is_open()) {
    while(!read.eof()) {
      // make var, read in curr line, add to scr, refresh
      std::string line = "";
      getline(read, line);
      const char * ln = line.c_str();
      addstr(ln);
      addstr("\n");
      refresh();
    }

  }
  std::string fileName(fn);
  read.close();
  return fileName;
}

void saveFile(std::string fn) {
  // if filename is empty, make it untitled
  if (fn == "") {
    fn = "untitled";
  }

  // Convert string to const char
  const char * fileName = fn.c_str();

  // Put contentents of screen to file
  int success = 0;
  success = scr_dump(fileName);

  if (success == 0) {
    addstr("An error occured while saving.\n");
  }
}

int main() {
  initscr();

  return 0;
}
