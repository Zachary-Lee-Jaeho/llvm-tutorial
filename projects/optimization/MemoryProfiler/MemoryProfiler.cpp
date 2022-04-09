#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"

#include "MemoryProfiler.h"

bool MemoryProfiler::runOnModule(Module &M) {
    LLVMContext &Context = M.getContext();
    const DataLayout &Layout = M.getDataLayout();

    return false;
}

void MemoryProfiler::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char MemoryProfiler::ID = 0;
static RegisterPass<MemoryProfiler> Y("mem-prof", "MemoryProfiler Pass ");
