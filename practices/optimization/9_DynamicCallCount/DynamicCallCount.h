#ifndef LLVM_TUTORIAL_OPTIMIZATION_DYNAMIC_CALL_COUNT_H
#define LLVM_TUTORIAL_OPTIMIZATION_DYNAMIC_CALL_COUNT_H

#include "llvm/IR/Module.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
    struct DynamicCallCount : public ModulePass {
        static char ID; // Pass identification, replacement for typeid
        DynamicCallCount() : ModulePass(ID) {}

        bool runOnModule(Module &M) override;

        void getAnalysisUsage(AnalysisUsage &AU) const override;
    };
}

#endif
