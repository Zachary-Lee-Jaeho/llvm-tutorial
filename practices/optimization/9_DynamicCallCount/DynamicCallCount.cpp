#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "DynamicCallCount.h"

bool DynamicCallCount::runOnModule(Module &M) {
    return false;
}

void DynamicCallCount::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char DynamicCallCount::ID = 0;
static RegisterPass<DynamicCallCount> Y("dyn-call-count", "DynamicCallCount Pass ");
