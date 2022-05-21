int k[10];
int print_f(float f);
int print_i(int i);
int print_c(char c);

int array_aaa(char x[])
{
    x[0] = 1;
    return 0;
}
int main(void)
{
    char y[10]= "aaa";
    // y[0]=2;
    array_aaa(y);
    print_c(y[0]);
    return 0;
}