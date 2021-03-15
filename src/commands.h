#pragma once

class Command {
 private:
  bool mFinished;
  int mMod;
 public:
  // Defualt Constructer, not to be used
  Command();
  // Parameterized Constructer, used
  Command(int mod);
  // Returns the value of mFinished
  bool getFinished();
  // Runs Cmd based on modifier and sets finished to true
  void runCmd(int mod);
};
