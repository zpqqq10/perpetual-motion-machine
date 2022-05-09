// clang -fsyntax-only -Xclang -ast-dump test/sample.c

int x[10], test = 0x22, f = 0.25, num = 222 - -233;
bool flag = false;

int minloc (int a[], int low, int high);
void sort(int a[], int low, int high);

int minloc (int a[], int low, int high)
{
    int i; 
    int x; 
    int k;
    k = a[low];
    i = low + 1;
    while(i < high){
        if(a[i] < x){
            x = a[i];
            k = i;
        }
        i = i + 1;
    }
    return k;
}

// sort a list
void sort(int a[], int low, int high)
{
    // sort a list
    int i; 
    int k;
    // loop
    while(i < high-1){
        int t;
        k = minloc(a, i, high);
        t = a[k];
        a[k] = a[i]; 
        a[i] = t;
        i = i + 1;
    }
}

int main()
{
    int i, m, n, a[2];
    float f;
    bool b;
    f = 0.001;
    b = true;
    i = 0;
    while(i < 10){
        x[i] = input();
        i = i + 1;
    }
    sort(x, 0, 10);
    i = 0;
    while(i < 10){
        output(x[i]);
        i = i + 1;
    }
    {
        output(233);
    }
    return 0;
}