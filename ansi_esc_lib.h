#ifndef ANSI_ESC_LIB
#define ANSI_ESC_LIB

#include <stddef.h>

typedef enum {
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    DEFAULT = 39,
    BRIGHT_BLACK = 90,
    BRIGHT_RED,
    BRIGHT_GREEN,
    BRIGHT_YELLOW,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_CYAN,
    BRIGHT_WHITE
} ANSI_colors;



#define RESET 0
#define BOLD 1 << 0
#define DIM 1 << 1
#define ITALIC 1 << 2
#define UNDERLINE 1 << 3
#define SLOW_BLINK 1 << 4
#define FAST_BLINK 1 << 5
#define INVERT 1 << 6
#define HIDE 1 << 7
#define STRIKE 1 << 8
#define DOUBLE_UNDERLINE 1 << 9



typedef struct
{
    int fg_color;
    int bg_color;
    unsigned int style;
} ANSI_style;



int str_style(char *buffer, size_t buffer_size, const char *string, size_t string_size, ANSI_style style);

#endif