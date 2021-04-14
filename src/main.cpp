#include <ncurses.h>
#include <fstream>
#include <vector>


std::string readFile(std::vector<char> &data) {
  erase();
  //get fn
  char fn[80];
  getstr(fn);
  erase();

  std::ifstream read(fn);

  if(read.is_open()) {
    while(!read.eof()) {
      // make var, read in curr line, add to scr, refresh
      std::string line = "";
      getline(read, line);

      // Convert line to c style string
      const char * ln = line.c_str();

      // Add the chars to the save vector
      int size = line.size();
      for (int i = 0; i < size; i++) {
          data.push_back(ln[i]);
      }

      addstr(ln);
      addstr("\n");
      data.push_back('\n');
      refresh();
    }

  }
  std::string fileName(fn);
  read.close();
  return fileName;
}

void saveFile(std::string fn, std::vector<char> saveData) {
  // if filename is empty, make it untitled
  if (fn == "") {
    fn = "untitled.txt";
  }

  // Convert string to const char
  const char * fileName = fn.c_str();

  std::ofstream save(fn);
  if(save.is_open()) {
    for (int i = 0; i < saveData.size(); i++) {
      save << saveData[i];
    }
  }
  save.close();

}

int main() {
  std::string currFileName = "";
  bool run = true;
  char c;
  int x = 0;
  int y = 0;
  std::vector<char> data;

  initscr();
  keypad(stdscr, true);
  noecho();
  raw();

  while(run == true) {
    c = getch();
    data.push_back(c);
    getyx(stdscr, y, x);

    switch (c) {
      case 263:
        mvdelch(y, x-1);
        break;
      case 258:
        y++;
        move(y, x);
        break;
      case 259:
        if(y-1 >= 0) {
          y--;
          move(y, x);
        }
        break;
      case 261:
        x++;
        move(y, x);
        break;
      case 260:
        if(x-1 >= 0) {
          x--;
          move(y, x);
        }
        break;
      case 15:
        data.erase(data.begin(), data.end());
        currFileName = readFile(data);
        break;
      case 1:
        data.pop_back();
        saveFile(currFileName, data);
        break;
      case 24:
        run = false;
        break;
      default:
        addch(c);
        refresh();
        break;
    }
  }

  endwin();
  return 0;
}
