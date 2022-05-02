%{
#include <stdio.h>
#include "y.tab.h"
// REAL    [-+]?(([0-9]*\.[0-9]+)|([0-9]+\.)|([0-9]+[eE][-+]?[0-9]+))
// real: 12.02e-2, +12.2, -1e+2
%}
%option noyywrap
WHITESPACE  [ \t]+
IDENTIFIER  [_a-zA-z][_a-zA-Z0-9]*
Digits  ([0-9]+)
Sign    ([-+]?)
Schar   (([^"\\\r\n])|(\\['"?abfnrtv\\])|(\\n)|(\\\r\n))
DEC     {Sign}([1-9][0-9]*)
OCT     {Sign}?(0)([0-7]*)
HEX     {Sign}?(0[xX])([0-9a-fA-F]+)
REAL    {Sign}?(((({Digits}?\.{Digits})|({Digits}\.))([eE]{Sign}{Digits})?)|({Digits}[eE]{Sign}{Digits}))
STRING  \"({Schar}+)?\"
LINECOMMENT     "//"[^\r\n]*
BLOCKCOMMENT    "/*""/"*([^*/]|[^*]"/"|"*"[^/])*"*"*"*/"
COMMENTS        ({LINECOMMENT})|({BLOCKCOMMENT})
%%
{WHITESPACE} {}
\[ {return LEFTSB;}
] {return RIGHTSB;}
\( {return LEFTP;}
\) {return RIGHTP;}
\{ {return LEFTCB;}
\} {return RIGHTCB;}
, {return COMMA;}
; {return SEMICOLON;}
: {return COLON;}

= {return ASSIGN;}
\+ {return ADD;}
\- {return SUB;}
\* {return MUL;}
\/ {return DIV;}
> {return GT;}
\< {return LT;}
== {return EQ;}
!= {cout<<"!="<<endl;return NEQ;}
\<= {return LE;}
>= {return GE;}
\| {return OR;}
& {return AND;}
\^ {return XOR;}

float {return FLOAT;}
int {return INT;}
bool { return BOOL;}
void {return VOID;}
string {return STRING;}

break {return BREAK;}
main { return MAIN;}
return {return RETURN;}
while {return WHILE;}
for {return FOR;}
in {return IN;}
to {return TO;}
if {return IF;}
else {return ELSE;}
false {return FALSE;}
true {return TRUE;}

{IDENTIFIER} {return IDENTIFIER;}

{DEC} {return INTEGER_VALUE;}

{OCT} {return INTEGER_VALUE;}

{HEX} {return INTEGER_VALUE;}

{REAL} {return FLOAT_VALUE;}

{STRING} {return STRING_VALUE;}

{COMMENTS} {return COMMENT;}
 // [0-9]* {return NUMBER;}
 // \n {return 0;};
%%
