// clang -fsyntax-only -Xclang -ast-dump test/sample.cpp
// rm test/sample.ll
// clang++ -emit-llvm -S -O0  ./test/sample.cpp -o ./test/sample.ll

int x[10], oct = 0x22, num = 222 - -233;
bool flag = false;

int print_i(int i);
int minloc(int low, int high);
int sort(int low, int high, char t);

int minloc(int low, int high)
{
    int i, y, k;
    k = low;
    y = x[low];
    i = low + 1;
    while (i < high)
    {
        if (x[i] < y)
        {
            y = x[i];
            k = i;
        }
        i = i + 1;
    }
    return k;
}

// sort a list
int sort(int low, int high, char t)
{
    // sort a list
    int i, k;
    char tt = t;
    // loop
    i = low;
    while (i < high - 1)
    {
        int t;
        k = minloc(i, high);
        t = x[k];
        x[k] = x[i];
        x[i] = t;
        i = i + 1;
        // print_i(i); 
    }
    return 0;
}
int input()
{
    return 1;
}

int main()
{
    int i, m, n, a[2];
    float f;
    bool b;
    f = 1e6;
    b = true;
    i = 0;
    x[0] = 23;
    x[1] = 44;
    x[2] = 5; 
    x[3] = 9;
    x[4] = 50;
    x[5] = 14;
    sort(0, 6, 'x');
    // if (i != 0)
    // {
    //     while (i > 0)
    //         i = i - 1;
    // }
    // else {
    //     while (i < 10)
    //         i = i + 1;
    // }
    while(i<6){
        print_i(x[i]);
        i = i + 1;
    }
    return 0;
}
