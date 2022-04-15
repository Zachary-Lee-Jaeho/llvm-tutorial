#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "DynamicCallCount.h"

bool DynamicCallCount::runOnModule(Module &M) {

    //========--------  Answer --------==========
    // [IMPORTANT] Go to Runtime directory for checking the runtime function countCall!!!!
    // [IMPORTANT] Go to Runtime directory for checking the runtime function countCall!!!!
    // [IMPORTANT] Go to Runtime directory for checking the runtime function countCall!!!!
    LLVMContext &Context = M.getContext();

    FunctionCallee CountCall = M.getOrInsertFunction(
            "countCall", Type::getVoidTy(Context));

    std::vector<Value*> args;

    for(Function &F : M) {
        for(BasicBlock &BB : F) {
            for(Instruction &I : BB) {
                if(CallInst *CI = dyn_cast<CallInst>(&I)) {
                    if(CI->getCalledFunction()->getName() != "countCall") {
                        IRBuilder<> Builder(CI);
                        Builder.CreateCall(CountCall);
                    }
                }
            }
        }
    }

    FunctionCallee PrintResult = M.getOrInsertFunction(
            "printResult", Type::getVoidTy(Context));

    Function *MainFun = M.getFunction("main");
    if(MainFun) {
        for(BasicBlock &BB : *MainFun) {
            for(Instruction &I : BB) {
                if(ReturnInst *RI = dyn_cast<ReturnInst>(&I)) {
                    IRBuilder<> Builder(RI);
                    Builder.CreateCall(PrintResult);
                }
            }
        }
    }

    return true;
    //========--------  Answer --------==========
}

void DynamicCallCount::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char DynamicCallCount::ID = 0;
static RegisterPass<DynamicCallCount> Y("dyn-call-count", "DynamicCallCount Pass ");
