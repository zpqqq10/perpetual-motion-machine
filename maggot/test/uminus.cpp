// rm test/uminus.ll
// clang++ -emit-llvm -S -O0  ./test/uminus.cpp -o ./test/uminus.ll
//int aaa(int a, int b);
int aaa(int a, int b)
{
    int c = 1, d = 0;
    while(c < 10) {
        while(c < 10) {
        d = d + a;
        c = c + 1;
        }
    }
    return d;
}

