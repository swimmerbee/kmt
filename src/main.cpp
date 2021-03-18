#include <ncurses.h>
#include <fstream>

int checkMod() {
  if (mMod == 's' || mMod == 'o' || mMod == 'x') {
    return mMod;
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
  std::string fn = "";
  getstr(fn);

  // reading in the file
  ifstream readFile(fn);
    
  if(readFile.is_open()) {
    while(!readFile.eof()) {
      std::string line;
      getline(readFile, line);
      addstr(line);  
    }
}

int main() {

}
