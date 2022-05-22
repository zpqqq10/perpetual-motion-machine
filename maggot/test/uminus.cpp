// rm test/uminus.ll
// clang++ -emit-llvm -S -O0  ./test/uminus.cpp -o ./test/uminus.ll
//int aaa(int a, int b);
int print_i(int i);
int main()
{
    int a = 1;
    if (a <= 1) {
        while(a <= 5) {
            print_i(a);
            a = a + 1;
        }
    }
    return 0;
}

