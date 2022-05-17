#ifndef __CODEGEN_H
#define __CODEGEN_H

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/Optional.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/AssemblyAnnotationWriter.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#include <cstdlib>
#include "declaration.h"
#include "expression.h"
#include "statement.h"
#include "main.h"

using namespace llvm;

static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);
static std::unique_ptr<Module> TheModule = std::make_unique<Module>("maggot", TheContext);
// static std::unique_ptr<legacy::FunctionPassManager> TheFPM;
static std::map<std::string, Value *> NamedValues;
static std::vector<CompoundStmtAST*> compoundstack;


/// LogError* - These are little helper functions for error handling.
std::unique_ptr<BaseAST> LogError(const char *Str);

Value *LogErrorV(const char *Str);

#endif