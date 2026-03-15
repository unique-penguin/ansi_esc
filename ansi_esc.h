#ifndef ANSI_ESC_H
#define ANSI_ESC_H

#include <stddef.h> // for size_t
#include <string.h> // for strlen
#include <stdio.h> // for stderr, stdout
 
typedef enum {
    ANSI_BLACK = 30,
    ANSI_RED,
    ANSI_GREEN,
    ANSI_YELLOW,
    ANSI_BLUE,
    ANSI_MAGENTA,
    ANSI_CYAN,
    ANSI_WHITE,
    ANSI_DEFAULT = 39,
    ANSI_BRIGHT_BLACK = 90,
    ANSI_BRIGHT_RED,
    ANSI_BRIGHT_GREEN,
    ANSI_BRIGHT_YELLOW,
    ANSI_BRIGHT_BLUE,
    ANSI_BRIGHT_MAGENTA,
    ANSI_BRIGHT_CYAN,
    ANSI_BRIGHT_WHITE
} ANSI_colors;

// style flags
#define ANSI_RESET 0
#define ANSI_BOLD 1 << 0
#define ANSI_DIM 1 << 1
#define ANSI_ITALIC 1 << 2
#define ANSI_UNDERLINE 1 << 3
#define ANSI_SLOW_BLINK 1 << 4
#define ANSI_FAST_BLINK 1 << 5
#define ANSI_INVERT 1 << 6
#define ANSI_HIDE 1 << 7
#define ANSI_STRIKE 1 << 8
#define ANSI_DOUBLE_UNDERLINE 1 << 9

// style struct
typedef struct
{
    int fg_color;
    int bg_color;
    unsigned int style;
} ANSI_style;

/**
 * Writes formated string to buf with reset at the end
 */
int ANSI_style_str(char *buf, size_t buf_size, const char *s, size_t s_size, ANSI_style style);

/**
 * Writes formated string to buf with reset at the end
 */
static inline int ANSI_style_cstr(char *buf, size_t bufsize, const char *s, ANSI_style style) {
    return ANSI_style_str(buf, bufsize, s, strlen(s), style);
}


/**
 * Sets the style of stream
 */
int ANSI_fsetf(ANSI_style style, FILE *stream);

/**
 * Sets the style of stdout
 */
static inline int ANSI_setf(ANSI_style style){
    return ANSI_fsetf(style, stdout);
}


/**
 * Resets the style of stream
 */
int ANSI_fresetf(FILE *stream);

/**
 * Resets the style of stdout
 */
static inline int ANSI_resetf(){
    return ANSI_fresetf(stdout);
}

#endif // ANSI_ESC_H