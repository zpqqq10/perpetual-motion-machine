// rm test/uminus.ll
// clang++ -emit-llvm -S -O0  ./test/uminus.cpp -o ./test/uminus.ll
int aaa();
int aaa()
{
    float k[10];
    float a = 3.2;
    // int x = 3 * 4;
    k[2] = 2.0;
    a = 2.0;
    k[2] = a;
    a = k[2];
    {
        // float b = k[3];
    }
    return 1;

}