%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
[0-9]* {return NUMBER;}
\n {return 0;};
%%
