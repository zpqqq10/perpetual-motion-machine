; ModuleID = './test/uminus.cpp'
source_filename = "./test/uminus.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @_Z3aaav() #0 {
  %1 = alloca [10 x float], align 16
  %2 = alloca float, align 4
  store float 0x40099999A0000000, float* %2, align 4
  %3 = getelementptr inbounds [10 x float], [10 x float]* %1, i64 0, i64 2
  store float 2.000000e+00, float* %3, align 8
  store float 2.000000e+00, float* %2, align 4
  %4 = load float, float* %2, align 4
  %5 = getelementptr inbounds [10 x float], [10 x float]* %1, i64 0, i64 2
  store float %4, float* %5, align 8
  %6 = getelementptr inbounds [10 x float], [10 x float]* %1, i64 0, i64 2
  %7 = load float, float* %6, align 8
  store float %7, float* %2, align 4
  ret i32 1
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
