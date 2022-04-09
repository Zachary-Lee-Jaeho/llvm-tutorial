#include "llvm/Support/raw_ostream.h"

#include "HelloFunction.h"

#define DEBUG_TYPE "hello"

bool HelloFunction::runOnFunction(Function &F) {
  return false;
}

void HelloFunction::getAnalysisUsage(AnalysisUsage &AU) const {
  AU.setPreservesAll();
}

char HelloFunction::ID = 0;
static RegisterPass<HelloFunction> Y("helloFunction", "Hello World Pass ");
