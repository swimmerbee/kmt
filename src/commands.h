#pragma once

class Command {
 private:
  int mMod;
 public:
  // Defualt Constructer, not to be used
  Command();
  // Parameterized Constructer, used
  Command(int mod);
  // Runs Cmd based on modifier and sets finished to true
  void runCmd();
};
