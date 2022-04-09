#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/IRBuilder.h"

#include "InsertIncFunction.h"

bool InsertIncFunction::runOnModule(Module &M) {
    return false;
}

void InsertIncFunction::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char InsertIncFunction::ID = 0;
static RegisterPass<InsertIncFunction> X("insert-inc-fun", "Hello World Pass ");
