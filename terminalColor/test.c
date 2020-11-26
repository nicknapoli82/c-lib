#include <stdio.h>

#include "t_color.h"

int main(void) {
    TC_printf("Color red\n", T_COLOR_RED);
    TC_printf("Color green\n", T_COLOR_GREEN);
    TC_printf("Color blue\n", T_COLOR_BLUE);
    TC_printf("Color bold red\n", T_COLOR_BOLD_RED);
    TC_printf("Color bold green\n", T_COLOR_BOLD_GREEN);
    TC_printf("Color bold blue\n", T_COLOR_BOLD_BLUE);

    printf("%s\n", TC_reset);
}
