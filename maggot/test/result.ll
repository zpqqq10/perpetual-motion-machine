; ModuleID = 'maggot'
source_filename = "./test/sample.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@x = global [10 x i32] zeroinitializer
@test = global i32 0
@num = global i32 455
@flag = global i1 false

define i32 @minloc(i32 %low, i32 %high) {
minloc:
  %k = alloca i32
  %y = alloca i32
  %i = alloca i32
  %high2 = alloca i32
  %low1 = alloca i32
  store i32 %low, i32* %low1
  store i32 %high, i32* %high2
  store i32 0, i32* %i
  store i32 0, i32* %y
  store i32 0, i32* %k
  %low3 = load i32, i32* %low1
  %0 = getelementptr inbounds [10 x i32], [10 x i32]* @x, i32 0, i32 %low3
  %1 = load i32, i32* %0
  store i32 %1, i32* %k
  %low4 = load i32, i32* %low1
  %addtmp = add nsw i32 %low4, 1
  store i32 %addtmp, i32* %i
  br label %COND

COND:                                             ; preds = %IFCONT, %minloc
  %i5 = load i32, i32* %i
  %high6 = load i32, i32* %high2
  %cmplt = icmp slt i32 %i5, %high6
  br i1 %cmplt, label %LOOP, label %ENDLOOP

LOOP:                                             ; preds = %COND
  %i7 = load i32, i32* %i
  %2 = getelementptr inbounds [10 x i32], [10 x i32]* @x, i32 0, i32 %i7
  %3 = load i32, i32* %2
  %y8 = load i32, i32* %y
  %cmplt9 = icmp slt i32 %3, %y8
  br i1 %cmplt9, label %THEN, label %ELSE

ENDLOOP:                                          ; preds = %COND
  %k14 = load i32, i32* %k
  ret i32 %k14
  ret i32 0

THEN:                                             ; preds = %LOOP
  %i10 = load i32, i32* %i
  %4 = getelementptr inbounds [10 x i32], [10 x i32]* @x, i32 0, i32 %i10
  %5 = load i32, i32* %4
  store i32 %5, i32* %y
  %i11 = load i32, i32* %i
  store i32 %i11, i32* %k
  %i12 = load i32, i32* %i
  %addtmp13 = add nsw i32 %i12, 1
  store i32 %addtmp13, i32* %i
  br label %IFCONT

ELSE:                                             ; preds = %LOOP
  br label %IFCONT

IFCONT:                                           ; preds = %ELSE, %THEN
  br label %COND
}

define void @sort(i32 %low, i32 %high) {
sort:
  %t = alloca i32
  %k = alloca i32
  %i = alloca i32
  %high2 = alloca i32
  %low1 = alloca i32
  store i32 %low, i32* %low1
  store i32 %high, i32* %high2
  store i32 0, i32* %i
  store i32 0, i32* %k
  br label %COND

COND:                                             ; preds = %LOOP, %sort
  %i3 = load i32, i32* %i
  %high4 = load i32, i32* %high2
  %subtmp = sub nsw i32 %high4, 1
  %cmplt = icmp slt i32 %i3, %subtmp
  br i1 %cmplt, label %LOOP, label %ENDLOOP

LOOP:                                             ; preds = %COND
  store i32 0, i32* %t
  %i5 = load i32, i32* %i
  %high6 = load i32, i32* %high2
  %calltmp = call i32 @minloc(i32 %i5, i32 %high6)
  store i32 %calltmp, i32* %k
  %k7 = load i32, i32* %k
  %0 = getelementptr inbounds [10 x i32], [10 x i32]* @x, i32 0, i32 %k7
  %1 = load i32, i32* %0
  store i32 %1, i32* %t
  %k8 = load i32, i32* %k
  %2 = getelementptr inbounds [10 x i32], [10 x i32]* @x, i32 0, i32 %k8
  %i9 = load i32, i32* %i
  %3 = getelementptr inbounds [10 x i32], [10 x i32]* @x, i32 0, i32 %i9
  %4 = load i32, i32* %3
  store i32 %4, i32* %2
  %i10 = load i32, i32* %i
  %5 = getelementptr inbounds [10 x i32], [10 x i32]* @x, i32 0, i32 %i10
  %t11 = load i32, i32* %t
  store i32 %t11, i32* %5
  %i12 = load i32, i32* %i
  %addtmp = add nsw i32 %i12, 1
  store i32 %addtmp, i32* %i
  br label %COND

ENDLOOP:                                          ; preds = %COND
  ret void
}

define i32 @input() {
input:
  ret i32 1
  ret i32 0
}

define void @output(i32 %x) {
output:
  %x1 = alloca i32
  store i32 %x, i32* %x1
  ret void
}

define i32 @main() {
main:
  %b = alloca i1
  %f = alloca float
  %x = alloca [10 x i32]
  %a = alloca [2 x i32]
  %n = alloca i32
  %m = alloca i32
  %i = alloca i32
  store i32 0, i32* %i
  store i32 0, i32* %m
  store i32 0, i32* %n
  store i32 zeroinitializer, [2 x i32]* %a
  store i32 zeroinitializer, [10 x i32]* %x
  store double 0.000000e+00, float* %f
  store i1 false, i1* %b
  store float 0x3F50624DE0000000, float* %f
  store i1 true, i1* %b
  store i32 0, i32* %i
  %i1 = load i32, i32* %i
  %cmplt = icmp slt i32 %i1, 10
  br i1 %cmplt, label %THEN, label %ELSE

THEN:                                             ; preds = %main
  %i2 = load i32, i32* %i
  %0 = getelementptr inbounds [10 x i32], [10 x i32]* %x, i32 0, i32 %i2
  %calltmp = call i32 @input()
  store i32 %calltmp, i32* %0
  %i3 = load i32, i32* %i
  %addtmp = add nsw i32 %i3, 1
  store i32 %addtmp, i32* %i
  br label %IFCONT

ELSE:                                             ; preds = %main
  br label %IFCONT

IFCONT:                                           ; preds = %ELSE, %THEN
  %calltmp4 = call void @sort(i32 0, i32 10)
  %i5 = load i32, i32* %i
  br i32 %i5, label %THEN6, label %ELSE7

THEN6:                                            ; preds = %IFCONT
  br label %COND

ELSE7:                                            ; preds = %IFCONT
  br label %COND11

IFCONT8:                                          ; preds = %ENDLOOP13, %ENDLOOP
  ret i32 0
  ret i32 0

COND:                                             ; preds = %LOOP, %THEN6
  %i9 = load i32, i32* %i
  %cmptmp = icmp sgt i32 %i9, 0
  br i1 %cmptmp, label %LOOP, label %ENDLOOP

LOOP:                                             ; preds = %COND
  %i10 = load i32, i32* %i
  %subtmp = sub nsw i32 %i10, 1
  store i32 %subtmp, i32* %i
  br label %COND

ENDLOOP:                                          ; preds = %COND
  br label %IFCONT8

COND11:                                           ; preds = %LOOP12, %ELSE7
  %i14 = load i32, i32* %i
  %cmplt15 = icmp slt i32 %i14, 10
  br i1 %cmplt15, label %LOOP12, label %ENDLOOP13

LOOP12:                                           ; preds = %COND11
  %i16 = load i32, i32* %i
  %addtmp17 = add nsw i32 %i16, 1
  store i32 %addtmp17, i32* %i
  br label %COND11

ENDLOOP13:                                        ; preds = %COND11
  br label %IFCONT8
}
