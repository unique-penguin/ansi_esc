#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "ansi_esc_lib.h"

int main(int argc, char *argv[]){
    char *text = argv[0];
    char *ansi_esc_sequence = "\x1b[90;101m";
    char *ansi_esc_end = "\x1b[0m";
    
    printf("%s%s%s\n", ansi_esc_sequence, text, ansi_esc_end);



    ANSI_style warning = {
        .bg_color = DEFAULT,
        .fg_color = DEFAULT,
        .style = BOLD|DIM,
    };

    char buffer[128];
    str_style(buffer, sizeof(buffer), text, strlen(text), warning);

    printf("%s\n", buffer);
    return 0;
}