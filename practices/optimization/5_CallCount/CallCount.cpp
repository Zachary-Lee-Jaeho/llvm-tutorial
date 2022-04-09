#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "CallCount.h"

bool CallCount::runOnFunction(Function &F) {
    return false;
}

void CallCount::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char CallCount::ID = 0;
static RegisterPass<CallCount> Y("callcount", "CallCount Pass ");
