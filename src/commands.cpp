#include "commands.h"
#include <fstream>
#include <ncurses.h>

Command::Command() {
  mMod = 0;
}

Command::Command(int mod) {
  mMod = mod;
}

void Command::runCmd() {
  
}
