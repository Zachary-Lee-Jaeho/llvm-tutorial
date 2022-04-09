#include "llvm/Support/raw_ostream.h"

#include "HelloModule.h"

#define DEBUG_TYPE "hello"

bool HelloModule::runOnModule(Module &M) {
  return false;
}

void HelloModule::getAnalysisUsage(AnalysisUsage &AU) const {
  AU.setPreservesAll();
}

char HelloModule::ID = 0;
static RegisterPass<HelloModule> X("helloModule", "Hello World Pass ");
