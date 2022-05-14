; ModuleID = './test/uminus.cpp'
source_filename = "./test/uminus.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@j = dso_local global float 0.000000e+00, align 4
@k = dso_local global [10 x float] zeroinitializer, align 16
@l = dso_local global float 1.000000e+00, align 4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z3aaabb(i1 zeroext %0, i1 zeroext %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i8, align 1
  %5 = alloca i8, align 1
  %6 = alloca float, align 4
  %7 = alloca float, align 4
  %8 = zext i1 %0 to i8
  store i8 %8, i8* %4, align 1
  %9 = zext i1 %1 to i8
  store i8 %9, i8* %5, align 1
  store float 0.000000e+00, float* %6, align 4
  store float 1.000000e+00, float* %7, align 4
  %10 = load i8, i8* %4, align 1
  %11 = trunc i8 %10 to i1
  br i1 %11, label %12, label %13

12:                                               ; preds = %2
  store i32 0, i32* %3, align 4
  br label %14

13:                                               ; preds = %2
  store i32 1, i32* %3, align 4
  br label %14

14:                                               ; preds = %13, %12
  %15 = load i32, i32* %3, align 4
  ret i32 %15
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
