#ifndef LLVM_TUTORIAL_OPTIMIZATION_LOOP_INFO_PRINTER_H
#define LLVM_TUTORIAL_OPTIMIZATION_LOOP_INFO_PRINTER_H

#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
    struct LoopInfoPrinter : public FunctionPass {
        static char ID; // Pass identification, replacement for typeid
        LoopInfoPrinter() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override;

        void getAnalysisUsage(AnalysisUsage &AU) const override;
    };
}

#endif
