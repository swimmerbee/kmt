#pragma once

class CmdBuffer {
 private:
  int mMod;
  bool mFinished;
 public:
  // Defualt constructer
  CmdBuffer();
  // Sets mMod to a new modifier
  void setMod(int newMod);
  // Returns the value of mFinished
  bool getFinished();
  // Returns mod if mMod is a valid modifier
  int checkMod();
};
