#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h" #include "llvm/IR/Instructions.h"
//========--------  Answer --------==========
#include "llvm/Analysis/LoopInfo.h"
//========--------  Answer --------==========

#include "LoopInfoPrinter.h"

bool LoopInfoPrinter::runOnFunction(Function &F) {

    //========--------  Answer --------==========
    LoopInfo &LI = getAnalysis< LoopInfoWrapperPass >().getLoopInfo();

    for (Loop *L : LI) {
        dbgs() << "Loop Name: " << L->getName() << "\n";
        dbgs() << "  Depth of Loop: " << L->getLoopDepth() << "\n";
        PHINode *Node = L->getCanonicalInductionVariable();
        if (Node) {
            dbgs() << "  Induction Variable: \n";
            Node->dump();
        }
    }
    //========--------  Answer --------==========

    return false;
}

void LoopInfoPrinter::getAnalysisUsage(AnalysisUsage &AU) const {

    //========--------  Answer --------==========
    AU.addRequired< LoopInfoWrapperPass >();
    //========--------  Answer --------==========
    AU.setPreservesAll();
}

char LoopInfoPrinter::ID = 0;
static RegisterPass<LoopInfoPrinter> Y("loop-info-printer", "LoopInfoPrinter Pass ");
