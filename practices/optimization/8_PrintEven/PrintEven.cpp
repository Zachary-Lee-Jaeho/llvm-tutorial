#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "PrintEven.h"
#include "llvm/IR/DerivedTypes.h"

bool PrintEven::runOnModule(Module &M) {
    return false;
}

void PrintEven::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char PrintEven::ID = 0;
static RegisterPass<PrintEven> X("print-even", "Control Flow Practice Pass");
