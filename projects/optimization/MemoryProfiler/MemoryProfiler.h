#ifndef LLVM_TUTORIAL_OPTIMIZATION_MEMORY_PROFILER_H
#define LLVM_TUTORIAL_OPTIMIZATION_MEMORY_PROFILER_H

#include "llvm/IR/Module.h"
#include "llvm/Pass.h"

using namespace llvm;

namespace {
  struct MemoryProfiler : public ModulePass {
    static char ID; // Pass identification, replacement for typeid
    MemoryProfiler() : ModulePass(ID) {}

    bool runOnModule(Module &M) override;

    void getAnalysisUsage(AnalysisUsage &AU) const override;
  };
}

#endif
