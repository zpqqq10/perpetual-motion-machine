#include <stdio.h>
extern "C"
{
  extern int printd()
  {
    fprintf(stdout, "MAGGOT\n");
    return 0;
  }
  extern int print_i(int i)
  {
    fprintf(stdout, "the integer is %d\n", i);
    return 0;
  }
  extern int print_f(float f)
  {
    fprintf(stdout, "the float is %f\n", f);
    return 0;
  }
  extern int print_c(char c)
  {
    fprintf(stdout, "the char is %c\n", c);
    return 0;
  }
  extern int print(char* s)
  {
    fprintf(stdout, "%s\n", s);
    return 0;
  }
}