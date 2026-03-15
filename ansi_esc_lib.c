#include "ansi_esc_lib.h"
#include <stdio.h>
#include <string.h>



int ANSI_style_str(char *buffer, size_t buffer_size, const char *string, size_t string_size, ANSI_style style){
    // check if the colors are in range
    if(style.fg_color < ANSI_BLACK){
        return -1;
    }
    if(style.fg_color > ANSI_BRIGHT_WHITE){
        return -1;
    }

    char style_string[64] = {0};
    size_t pos = 0;

    // FG and BG colors
    pos += snprintf(style_string + pos, sizeof(style_string) - pos, "%d;%d", style.fg_color, style.bg_color+10);

    // styles
    if(style.style & ANSI_BOLD) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";1");
    if(style.style & ANSI_DIM) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";2");
    if(style.style & ANSI_ITALIC) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";3");
    if(style.style & ANSI_UNDERLINE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";4");
    if(style.style & ANSI_SLOW_BLINK) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";5");
    if(style.style & ANSI_FAST_BLINK) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";6");
    if(style.style & ANSI_INVERT) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";7");
    if(style.style & ANSI_HIDE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";8");
    if(style.style & ANSI_STRIKE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";9");
    if(style.style & ANSI_DOUBLE_UNDERLINE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";21");

    // Compose final string
    int written = snprintf(buffer, buffer_size, "\x1b[%sm%.*s\x1b[0m", style_string, (int)string_size, string);
    return (written < 0 ? 0 : written);
}