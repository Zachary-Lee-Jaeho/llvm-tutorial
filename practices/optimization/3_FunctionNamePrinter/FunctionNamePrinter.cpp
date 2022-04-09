#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"

#include "FunctionNamePrinter.h"


bool FunctionNamePrinter::runOnFunction(Function &F) {
    return false;
}

void FunctionNamePrinter::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char FunctionNamePrinter::ID = 0;
static RegisterPass<FunctionNamePrinter> Y("fun-name-printer", "Hello World Pass ");
