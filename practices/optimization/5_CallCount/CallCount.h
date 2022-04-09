#ifndef LLVM_TUTORIAL_OPTIMIZATION_CALL_COUNT_H
#define LLVM_TUTORIAL_OPTIMIZATION_CALL_COUNT_H

#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
    struct CallCount : public FunctionPass {
        static char ID; // Pass identification, replacement for typeid
        CallCount() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override;

        void getAnalysisUsage(AnalysisUsage &AU) const override;
    };
}

#endif
