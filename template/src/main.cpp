#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
extern int yyparse();

int main()
{
	yyparse();
	return 0;
}