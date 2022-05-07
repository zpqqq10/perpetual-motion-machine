#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdarg>
#include <getopt.h>

#include <main.h>
#include "../include/utils.h"
#include "../include/declaration.h"

using namespace std;

/*
 * global options
 */
bool option_debug = false;

/*
 * extern function declaration
 */
extern int yyparse();

/*
 * function declaration
 */
static void usage(FILE *stream, const char *progname);
void warning(const char *msg, ...);
void NO_RETURN error(const char *msg, ...);
void debugImpl(const char *msg, ...);

/*
 * type declaration
 */
enum Option
{
	OPTION_DEBUG,
	OPTION_HELP
};

Program* prog = new Program();

int main(int argc, char** argv)
{
	// const int req_arg = required_argument; /*opt_arg = optional_argument,*/
	const int no_arg  = no_argument;
	static const struct option long_options[] =
    {
        {"debug",         no_arg,  nullptr, OPTION_DEBUG},
		{"help",          no_arg,  nullptr, OPTION_HELP},
        {nullptr,         no_arg,  nullptr, 0}
    }; 
	while(true)
	{
		int idx;
		int opt = getopt_long_only(argc, argv, "h", long_options, &idx);
		if (opt < 0)
			break;
		switch(opt)
		{
			case OPTION_DEBUG:
				option_debug = true;
				break;
			case OPTION_HELP:
			case 'h':
				usage(stdout, argv[0]);
				return 0;
		}
	}
	if(option_debug)
		debug("test");
	yyparse();
	if(prog){
		
		prog->print();
	}
	else {
		cout << "nothing" << endl;
	}
	return 0;
}

static void usage(FILE *stream, const char *progname)
{
	fprintf(stream, "usage: %s [OPTIONS] \n\n"
		"OPTIONS:\n"
		"\n"
		"\t--debug[=false]\n"
		"\t\tEnable [disable] debug log messages.\n"
		"\t\tDefault: false (disabled)\n"
		"\n"
		"\t--help, -h\n"
        "\t\tPrint this help message.\n"
        "\n",
		progname);
}

/*  
 * Report an error and exit.
 */
void NO_RETURN error(const char *msg, ...)
{
    fprintf(stderr, "%serror%s: ", "\33[31m", "\33[0m");

    va_list ap;
    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    va_end(ap);
    
    putc('\n', stderr);

    _Exit(EXIT_FAILURE);
}

/*
 * Print a warning message.
 */
void warning(const char *msg, ...)
{
    fprintf(stderr, "%swarning%s: ", "\33[33m",  "\33[0m");

    va_list ap;
    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    va_end(ap);
    
    putc('\n', stderr);
}

void debugImpl(const char *msg, ...)
{
    fprintf(stderr, "%sdebug%s: ","\33[35m", "\33[0m");

    va_list ap;
    va_start(ap, msg);
    vfprintf(stderr, msg, ap);
    va_end(ap);

    putc('\n', stderr);
}