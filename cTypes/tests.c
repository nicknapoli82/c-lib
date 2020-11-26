#include <stdio.h>

#include "c_types.h"

int main(void) {
    if (sizeof(i8) == 1) 
	printf("i8 size is correct\n");
    else printf("i8 size is not correct\n");

    if (sizeof(i16) == 2)
	printf("i16 size is correct\n");
    else printf("i16 size is not correct\n");

    if (sizeof(i32) == 4)
	printf("i32 size is correct\n");
    else printf("i32 size is not correct\n");

    if (sizeof(i64) == 8)
	printf("i64 size is correct\n");
    else printf("i64 size is not correct\n");
}
