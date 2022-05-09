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