#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "CallCount.h"

bool CallCount::runOnFunction(Function &F) {

    //========--------  Answer --------==========
    int count = 0;
    for(BasicBlock &BB : F) {
        for(Instruction &I : BB) {
            if(CallInst *CI = dyn_cast<CallInst>(&I)) {
                count++;
            }
        }
    }

    dbgs() << "Function Name: " << F.getName() << "\n";
    dbgs() << "# of CallInst: " << count << "\n";
    //========--------  Answer --------==========

    return false;
}

void CallCount::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char CallCount::ID = 0;
static RegisterPass<CallCount> Y("callcount", "CallCount Pass ");
