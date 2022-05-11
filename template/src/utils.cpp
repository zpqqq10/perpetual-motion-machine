#include "utils.h"

std::string get_type_name(int type)
{
	switch (type)
	{
	case TYPEVOID:
		return "void";
	case TYPEINT:
		return "int";
	case TYPEFLOAT:
		return "float";
	case TYPECHAR:
		return "char";
	case TYPEBOOL:
		return "bool";
	case TYPEINTPTR:
		return "int *";
	case TYPEFLOATPTR:
		return "float *";
	case TYPECHARPTR:
		return "char *";
	default:
		// error
		return "invalid";
		break;
	}
}
std::string get_op_name(int op)
{
	switch (op)
	{
	case OPADD:
		return "+";
	case OPSUB:
		return "-";
	case OPMUL:
		return "*";
	case OPDIV:
		return "/";
	case OPAND:
		return "&";
	case OPOR:
		return "|";
	case OPXOR:
		return "^";
	case OPGT:
		return ">";
	case OPLT:
		return "<";
	case OPEQ:
		return "==";
	case OPNEQ:
		return "!=";
	case OPLE:
		return "<=";
	case OPGE:
		return ">=";	
	case OPASSIGN:
		return "=";	
	case OPUMINUS:
		return "-";	
	default:
		// error
		return "invalid";
		break;
	}
}
std::string get_ref_name(int ref)
{
	switch(ref)
	{
	case REFFUNC:
		return "Func";
	case REFVAR:
		return "Var";
	default:
		// error
		return "invalid";
		break;
	}
}
void padding(int level)
{
	int i = 0;
	while(i++ < level){
		// if(i % 2 == 0) std::cout << "  ";
		// else std::cout << "| ";
		std::cout << "  ";
	}
	std::cout << "`-";
	return ;
}