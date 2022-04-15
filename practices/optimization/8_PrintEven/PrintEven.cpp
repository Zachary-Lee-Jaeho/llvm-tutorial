#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "PrintEven.h"
#include "llvm/IR/DerivedTypes.h"

bool PrintEven::runOnModule(Module &M) {

    //========--------  Answer --------==========
    LLVMContext &Context = M.getContext();

    Function *F = M.getFunction("printInt");
    if(!F) {
        return false;
    }

    BasicBlock &EntryBB = *F->begin();
    Instruction *PrintfCall = nullptr;

    for (Instruction &I : EntryBB) {
        if(CallInst *CI = dyn_cast<CallInst>(&I)) {
            if(CI->getCalledFunction()->getName() == "printf"){
                PrintfCall = CI;
            }
        }
    }

    if(!PrintfCall) {
        return false;
    }

    BasicBlock *PrintfBB = EntryBB.splitBasicBlock(PrintfCall);
    EntryBB.getTerminator()->eraseFromParent();

    BasicBlock *RetBB = BasicBlock::Create(Context, "retbb", F);
    IRBuilder<> RetBBBuilder(RetBB);
    RetBBBuilder.CreateRetVoid();

    IRBuilder<> EntryBBBuilder(&EntryBB);

    Argument *Arg = F->arg_begin();
    Constant *Two = ConstantInt::get(Type::getInt32Ty(Context), 2);
    Value *Remainder = EntryBBBuilder.CreateSRem(Arg, Two);

    Constant *One = ConstantInt::get(Type::getInt32Ty(Context), 1);
    Value *IsOdd = EntryBBBuilder.CreateICmpEQ(Remainder, One);

    EntryBBBuilder.CreateCondBr(IsOdd, RetBB, PrintfBB);

    return true;
    //========--------  Answer --------==========
}

void PrintEven::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
}

char PrintEven::ID = 0;
static RegisterPass<PrintEven> X("print-even", "Control Flow Practice Pass");
