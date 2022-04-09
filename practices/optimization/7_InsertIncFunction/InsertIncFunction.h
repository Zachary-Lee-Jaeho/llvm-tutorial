#ifndef LLVM_TUTORIAL_OPTIMIZATION_INSERT_INC_FUNCTION_H
#define LLVM_TUTORIAL_OPTIMIZATION_INSERT_INC_FUNCTION_H

#include "llvm/IR/Module.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
  struct InsertIncFunction : public ModulePass {
    static char ID; // Pass identification, replacement for typeid
    InsertIncFunction() : ModulePass(ID) {}

    bool runOnModule(Module &M) override;

    void getAnalysisUsage(AnalysisUsage &AU) const override;
  };
}

#endif

