// rm test/uminus.ll
// clang++ -emit-llvm -S -O0  ./test/uminus.cpp -o ./test/uminus.ll
//int aaa(int a, int b);
int main(int a, int b)
{
    int c = 1, d = 0;
    while(c > 2){
        d = 1;
        while(c > 4)
            d = 5;
    }
    return d;
}

