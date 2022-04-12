#ifndef LLVM_TUTORIAL_OPTIMIZATION_PRINT_EVEN_H
#define LLVM_TUTORIAL_OPTIMIZATION_PRINT_EVEN_H

#include "llvm/IR/Module.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
  struct PrintEven : public ModulePass {
    static char ID; // Pass identification, replacement for typeid
    PrintEven() : ModulePass(ID) {}

    bool runOnModule(Module &M) override;

    void getAnalysisUsage(AnalysisUsage &AU) const override;
  };
}

#endif

