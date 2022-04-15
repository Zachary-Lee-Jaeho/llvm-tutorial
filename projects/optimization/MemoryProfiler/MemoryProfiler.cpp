#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"

#include "MemoryProfiler.h"

bool MemoryProfiler::runOnModule(Module &M) {
    //========--------  Answer --------==========
    // [IMPORTANT] Open runtime.cpp to modify the runtime functions!!!
    // [IMPORTANT] Open runtime.cpp to modify the runtime functions!!!
    // [IMPORTANT] Open runtime.cpp to modify the runtime functions!!!
    LLVMContext &Context = M.getContext();
    const DataLayout &Layout = M.getDataLayout();

    Type *VoidTy = Type::getVoidTy(Context);
    Type *Int8PtrTy = Type::getInt8PtrTy(Context);
    Type *Int64Ty = Type::getInt64Ty(Context);

    FunctionType *Signature = FunctionType::get(VoidTy, {Int8PtrTy, Int64Ty}, false);

    FunctionCallee TraceMalloc = M.getOrInsertFunction("traceMalloc", Signature);
    FunctionCallee TraceLoad = M.getOrInsertFunction("traceLoad", Signature);
    FunctionCallee TraceStore = M.getOrInsertFunction("traceStore", Signature);

    std::vector<Value*> args(2);

    for(Function &F : M) {
        for(BasicBlock &BB : F) {
            for(Instruction &I : BB) {
                if(CallInst *CI = dyn_cast<CallInst>(&I)) {
                    if(CI->getCalledFunction()->getName() == "malloc") {
                        IRBuilder<> Builder(CI->getNextNode());

                        args[0] = CI;
                        args[1] = CI->getOperand(0);

                        Builder.CreateCall(TraceMalloc, args);
                    }
                } else if (LoadInst *LI = dyn_cast<LoadInst>(&I)) {
                    IRBuilder<> Builder(LI);
                    Value *Casted = Builder.CreatePointerCast(LI->getOperand(0), Int8PtrTy);
                    args[0] = Casted;

                    TypeSize Size = Layout.getTypeSizeInBits(LI->getType());
                    uint64_t SizeInBytes = Size.getFixedSize() / 8;
                    args[1] = ConstantInt::get(Int64Ty, SizeInBytes);

                    Builder.CreateCall(TraceLoad, args);
                } else if (StoreInst *SI = dyn_cast<StoreInst>(&I)) {
                    IRBuilder<> Builder(SI);
                    Value *Casted = Builder.CreatePointerCast(SI->getOperand(1), Int8PtrTy);
                    args[0] = Casted;

                    TypeSize Size = Layout.getTypeSizeInBits(SI->getOperand(0)->getType());
                    uint64_t SizeInBytes = Size.getFixedSize() / 8;
                    args[1] = ConstantInt::get(Int64Ty, SizeInBytes);

                    Builder.CreateCall(TraceStore, args);
                }
            }
        }
    }

    return true;
    //========--------  Answer --------==========
}

void MemoryProfiler::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char MemoryProfiler::ID = 0;
static RegisterPass<MemoryProfiler> Y("mem-prof", "MemoryProfiler Pass ");
