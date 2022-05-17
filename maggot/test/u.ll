; ModuleID = 'maggot'
source_filename = "test/uminus.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i32 @aaa(i32 %a, i32 %b) {
aaa:
  %d = alloca i32
  %c = alloca i32
  %b2 = alloca i32
  %a1 = alloca i32
  store i32 %a, i32* %a1
  store i32 %b, i32* %b2
  store i32 1, i32* %c
  store i32 0, i32* %d
  br label %COND

COND:                                             ; preds = %ENDLOOP6, %aaa
  %c3 = load i32, i32* %c
  %cmptmp = icmp sgt i32 %c3, 2
  br i1 %cmptmp, label %LOOP, label %ENDLOOP

LOOP:                                             ; preds = %COND
  store i32 1, i32* %d
  br label %COND4

ENDLOOP:                                          ; preds = %COND
  %d9 = load i32, i32* %d
  ret i32 %d9
  ret i32 0

COND4:                                            ; preds = %LOOP5, %LOOP
  %c7 = load i32, i32* %c
  %cmptmp8 = icmp sgt i32 %c7, 4
  br i1 %cmptmp8, label %LOOP5, label %ENDLOOP6

LOOP5:                                            ; preds = %COND4
  store i32 5, i32* %d
  br label %COND4

ENDLOOP6:                                         ; preds = %COND4
  br label %COND
}
