/*************************************************/
/* Add some color to your output in the terminal */
/* Only uses ANSI colors			 */
/*************************************************/

#include <stdio.h>

#ifndef T_COLOR_DEF
#define T_COLOR_DEF

char *TC_reset = "\033[0m";

char *TC_color[] = {"\033[0;31m", "\033[1;31m",
    "\033[0;32m", "\033[1;32m",
    "\033[0;33m", "\033[1;33m",
    "\033[0;34m", "\033[1;34m",
    "\033[0;35m", "\033[1;35m",
    "\033[0;36m", "\033[1;36m"};

enum T_COLOR {T_COLOR_RED, T_COLOR_BOLD_RED,
    T_COLOR_GREEN, T_COLOR_BOLD_GREEN,
    T_COLOR_YELLOW, T_COLOR_BOLD_YELLOW,
    T_COLOR_BLUE, T_COLOR_BOLD_BLUE,
    T_COLOR_MAGENTA, T_COLOR_BOLD_MAGENTA,
    T_COLOR_CYAN, T_COLOR_BOLD_CYAN};

void TC_printf(char *str, enum T_COLOR color) {
    printf("%s%s%s", TC_color[color], str, TC_reset);
}

void TC_eprint(char *str, enum T_COLOR color) {
    fprintf(stderr, "%s%s%s", TC_color[color], str, TC_reset);
}

void TC_setColor(enum T_COLOR color) {
    printf("%s", TC_color[color]);
}

void TC_resetColor(void) {
    printf("%s", TC_reset);
}

#endif
