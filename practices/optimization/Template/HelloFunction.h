#ifndef LLVM_TUTORIAL_OPTIMIZATION_TEMPLATE_HELLO_FUNCTION_H
#define LLVM_TUTORIAL_OPTIMIZATION_TEMPLATE_HELLO_FUNCTION_H

#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
  struct HelloFunction : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    HelloFunction() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override;

    void getAnalysisUsage(AnalysisUsage &AU) const override;
  };
}

#endif
