#include "cmdBuffer.h"

CmdBuffer::CmdBuffer() {
  mMod = 0;
  mFinished = false;
}

void CmdBuffer::setMod(int newMod) {
  mMod = newMod
}

bool CmdBuffer::getFinished() {
  return mFinished;
}

int CmdBuffer::checkMod() {
  if (mMod == 's' || mMod == 'o' || mMod == 'x') {
    return mMod;
  } else {
    return 0;
  }
  mFinished = true;
}
