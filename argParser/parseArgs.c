#include <stdlib.h>

#include "parseArgs.h"

unsigned int args_at = 1;
unsigned int args_until;
char **args_vec;
arg *all_args;
unsigned int next_is_flag;
unsigned int flag_at;

void args_setup(unsigned int argc, char *argv[]) {
    args_until = argc;
    args_vec = argv;
    next_is_flag = 0;
    flag_at = 1;
}

arg args_getOne() {
    arg result = {arg_NONE, .arg={.flag=arg_NONE}};

    if(args_at == args_until) {
	return result;
    }

    if(args_vec[args_at][0] != '-') {
	result.type = STRING;
	result.arg.argument = args_vec[args_at];
	args_at++;
	return result;
    }

    if(args_vec[args_at][1] != '-') {
	result.type = FLAG;
	result.arg.flag = args_vec[args_at][flag_at];
	flag_at++;
	if(args_vec[args_at][flag_at]) {
	    next_is_flag = 1;	    
	}
	else {
	    flag_at = 1;
	    next_is_flag = 0;
	    args_at++;
	}
	return result;
    }

    result.type = OPTION;
    result.arg.argument = &args_vec[args_at][2];
    args_at++;

    return result;
}

arg *args_getAll() {
    all_args = calloc(args_until + 1, sizeof(arg));
    if(all_args == NULL)
	return NULL;
    int additional_args = 1; // Start at one for last NULL
    for (unsigned int a = 0; a < args_until; a++) {
	all_args[a] = args_getOne();
	if(next_is_flag) {
	    additional_args++;
	    all_args = realloc(all_args, sizeof(arg) * (args_until + additional_args));
	    if(all_args == NULL)
		return NULL;
	}
    }
    return all_args;
}

void args_reset() {
    args_at = 0;
}

void args_setArgc(unsigned int num) {
    args_at = num;
}

void args_freeAll() {
    if(all_args != NULL) {
	free(all_args);
    }
    all_args = NULL;
}
