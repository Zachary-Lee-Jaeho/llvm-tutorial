#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"

#include "LoopInfoPrinter.h"

bool LoopInfoPrinter::runOnFunction(Function &F) {
    return false;
}

void LoopInfoPrinter::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char LoopInfoPrinter::ID = 0;
static RegisterPass<LoopInfoPrinter> Y("loop-info-printer", "LoopInfoPrinter Pass ");
