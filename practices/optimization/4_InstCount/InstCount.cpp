#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "InstCount.h"

bool InstCount::runOnFunction(Function &F) {

    //========--------  Answer --------==========
    int count = 0;
    for(BasicBlock &BB : F) {
        for(Instruction &I : BB) {
            count++;
        }
    }

    dbgs() << "Function Name: " << F.getName() << "\n";
    dbgs() << "# of Instrunctions: " << count << "\n";
    //========--------  Answer --------==========

    return false;
}

void InstCount::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char InstCount::ID = 0;
static RegisterPass<InstCount> Y("inst-count", "InstCount Pass ");
