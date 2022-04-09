#ifndef LLVM_TUTORIAL_OPTIMIZATION_FUNCTION_NAME_PRINTER_H
#define LLVM_TUTORIAL_OPTIMIZATION_FUNCTION_NAME_PRINTER_H

#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
    struct FunctionNamePrinter : public FunctionPass {
        static char ID; // Pass identification, replacement for typeid
        FunctionNamePrinter() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override;

        void getAnalysisUsage(AnalysisUsage &AU) const override;
    };
}

#endif
