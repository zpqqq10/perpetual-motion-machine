; ModuleID = './test/array.cpp'
source_filename = "./test/array.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@k = dso_local global [10 x i32] zeroinitializer, align 16

; Function Attrs: noinline norecurse optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca [10 x float], align 16
  store i32 0, i32* %1, align 4
  %3 = getelementptr inbounds [10 x float], [10 x float]* %2, i64 0, i64 0
  store float 2.000000e+00, float* %3, align 16
  %4 = getelementptr inbounds [10 x float], [10 x float]* %2, i64 0, i64 1
  store float 0x3FE3333340000000, float* %4, align 4
  %5 = getelementptr inbounds [10 x float], [10 x float]* %2, i64 0, i64 0
  %6 = load float, float* %5, align 16
  %7 = call i32 @_Z7print_ff(float %6)
  %8 = getelementptr inbounds [10 x float], [10 x float]* %2, i64 0, i64 1
  %9 = load float, float* %8, align 4
  %10 = call i32 @_Z7print_ff(float %9)
  ret i32 0
}

declare dso_local i32 @_Z7print_ff(float) #1

attributes #0 = { noinline norecurse optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
