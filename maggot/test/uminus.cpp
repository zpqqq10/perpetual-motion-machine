// rm test/uminus.ll
// clang++ -emit-llvm -S -O0  ./test/uminus.cpp -o ./test/uminus.ll
int aaa(int a, int b);
int aaa(int a, int b)
{
    int c;
    c = a + b;
    a = c;
    int d = b;
    return a + b + c + d;

}