// clang -fsyntax-only -Xclang -ast-dump test/sample.cpp
// rm test/sample.ll
// clang++ -emit-llvm -S -O0  ./test/sample.cpp -o ./test/sample.ll

int x[10], test = 0x22, num = 222 - -233;
bool flag = false;

int minloc(int low, int high);
void sort(int low, int high);

int minloc(int low, int high)
{
    int i;
    int y;
    int k;
    k = x[low];
    i = low + 1;
    while (i < high)
    {
        if (x[i] < y)
        {
            y = x[i];
            k = i;
            i = i + 1;
        }
    }
    return k;
}

// sort a list
void sort(int low, int high)
{
    // sort a list
    int i;
    int k;
    // loop
    while (i < high - 1)
    {
        int t;
        k = minloc(i, high);
        t = x[k];
        x[k] = x[i];
        x[i] = t;
        i = i + 1;
    }
}
int input()
{
    return 1;
}
void output(int x)
{
}
int main()
{
    int i, m, n, a[2], x[10];
    float f;
    bool b;
    f = 0.001;
    b = true;
    i = 0;
    if (i < 10)
    {
        x[i] = input();
        i = i + 1;
    }
    sort(0, 10);
    if (i)
    {
        while (i > 0)
            i = i - 1;
    }
    else {
        while (i < 10)
            i = i + 1;
    }
    return 0;
}
