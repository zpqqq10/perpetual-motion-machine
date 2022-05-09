%{
#include <iostream>
#include "declaration.h"
#include "expression.h"
#include "utils.h"
#include "y.tab.h"
using namespace std;
// REAL    [-+]?(([0-9]*\.[0-9]+)|([0-9]+\.)|([0-9]+[eE][-+]?[0-9]+))
// real: 12.02e-2, +12.2, -1e+2

%}
%option noyywrap
%option nounput
WHITESPACE  [ \t\n]+
IDENTIFIER  [_a-zA-Z][_a-zA-Z0-9]*
Digits  ([0-9]+)
Sign    ([-+]?)
Schar   (([^"\\\r\n])|(\\['"?abfnrtv\\])|(\\n)|(\\\r\n))
DEC     ([1-9][0-9]*)
OCT     (0)([0-7]*)
HEX     (0[xX])([0-9a-fA-F]+)
INT     ({OCT}|{HEX}|{DEC})
REAL    (((({Digits}?\.{Digits})|({Digits}\.))([eE]{Sign}{Digits})?)|({Digits}[eE]{Sign}{Digits}))
STRING  \"({Schar}+)?\"
LINECOMMENT     "//"[^\r\n]*
BLOCKCOMMENT    "/*""/"*([^*/]|[^*]"/"|"*"[^/])*"*"*"*/"
COMMENTS        ({LINECOMMENT})|({BLOCKCOMMENT})
%%
{WHITESPACE} {}
\[ {return LEFTSB;}
\] {return RIGHTSB;}
\( {return LEFTP;}
\) {return RIGHTP;}
\{ {return LEFTB;}
\} {return RIGHTB;}
, { return COMMA; }
; { return SEMICOLON;}
: {return COLON;}

= {return ASSIGN;}
\+ {return ADD;}
\- {return SUB;}
\* {return MUL;}
\/ {return DIV;}
> {return GT;}
\< {return LT;}
== {return EQ;}
!= {return NEQ;}
\<= {return LE;}
>= {return GE;}
\| {return OR;}
& {return AND;}
\^ {return XOR;}
\" {return DQUOTE;}
\' {return SQUOTE;}

float {return FLOAT;}
int {return INT;}
bool { return BOOL;}
void {return VOID;}
string {return STRING;}

break {return BREAK;}
return {return RETURN;}
while {return WHILE;}
for {return FOR;}
in {return IN;}
to {return TO;}
if {return IF;}
else {return ELSE;}
false {return FALSE;}
true {return TRUE;}

{STRING} {return STRING_VALUE;}

{IDENTIFIER} {yylval.str = new string(yytext); return IDENTIFIER;}

{INT} {yylval.valuetext = new string(yytext); return INTEGER_VALUE;}

{REAL} {yylval.valuetext = new string(yytext); return FLOAT_VALUE;}

{COMMENTS} {return COMMENT;}

%%

// int main(){
//     while(1){
//         yylex(); 
//     }
//     return 0;
// }