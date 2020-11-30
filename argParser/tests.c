#include <stdio.h>

#include "parseArgs.h"

int argc = 6;
char *argv[] = {"someProgram", "-clv", "--help", "--test-option", "./some-program", "-q"};

int main(void) {
    args_setup(argc, argv);

    printf("Testing arg_getOne\n");
    printf("First argument is 3 FLAGs : ");
    arg test;
    for (int i = 0; i < 3; i++) {
	test = args_getOne();
	if (test.type == FLAG)
	    printf("Y, %c | ", test.arg.flag);
	else printf("No, FAILED");
    }
    printf("\n");

    printf("Second and third arguments are an OPTION : ");
    for (int i = 0; i < 2; i++) {
	test = args_getOne();
	if (test.type == OPTION) {
	    printf("Y, %s | ", test.arg.argument);
	}
	else printf("N, FAILED\n");
    }
    printf("\n");

    printf("Fourth argument is a STRING : ");
    test = args_getOne();
    if (test.type == STRING) {
	printf("Y, %s\n", test.arg.argument);
    }
    else printf("N, FAILED\n");

    printf("Last (5th) argument is a FLAG : ");
    test = args_getOne();
    if (test.type == FLAG) {
	printf("Y, %c\n", test.arg.flag);
    }
    else printf("N, FAILED\n");

    printf("Trying to call getOne past the end of the args list should return type NONE : ");
    test = args_getOne();
    if (test.type == arg_NONE)
	printf("Y, PASS\n");
    else printf("N, FAILED\n");


    printf("\n\n");
    printf("Testing args_reset\n");
    args_reset();
    printf("Should find the first argument again : ");
    test = args_getOne();
    if (test.type == FLAG && test.arg.flag == 'c')
	printf("PASS\n");
    else printf("FAIL\n");

    args_reset();
    arg *test_vec = args_getAll();
    printf("Arguments list getAll should be length 7 : ");
    for (int i = 0; i < 8; i++) {
	if (test_vec[i].type == arg_NONE) {
	    printf("Length is %i, PASS\n", i + 1);
	}
    }
    args_freeAll();

    return 0;
}
