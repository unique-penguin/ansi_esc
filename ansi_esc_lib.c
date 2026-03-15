#include "ansi_esc_lib.h"
#include <stdio.h>
#include <string.h>



int str_style(char *buffer, size_t buffer_size, const char *string, size_t string_size, ANSI_style style){

    if(style.fg_color < BLACK){
        return -1;
    }
    
    if(style.fg_color > BRIGHT_WHITE){
        return -1;
    }

    char style_string[64] = {0};
    size_t pos = 0;

    pos += snprintf(style_string + pos, sizeof(style_string) - pos, "%d;%d", style.fg_color, style.bg_color+10);

    if(style.style & BOLD) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";1");
    if(style.style & DIM) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";2");
    if(style.style & ITALIC) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";3");
    if(style.style & UNDERLINE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";4");
    if(style.style & SLOW_BLINK) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";5");
    if(style.style & FAST_BLINK) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";6");
    if(style.style & INVERT) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";7");
    if(style.style & HIDE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";8");
    if(style.style & STRIKE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";9");
    if(style.style & DOUBLE_UNDERLINE) pos += snprintf(style_string + pos, sizeof(style_string) - pos, ";21");

    int written = snprintf(
        buffer,
        buffer_size,
        "\x1b[%sm%.*s\x1b[0m",
        style_string,
        (int)string_size,
        string
    );

    return (written < 0 ? 0 : written);
}