; ModuleID = 'maggot'
source_filename = "./output.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

declare i32 @printd()

define i32 @main() {
main:
  %calltmp = call i32 @printd()
  ret i32 0
  ret i32 0
}
