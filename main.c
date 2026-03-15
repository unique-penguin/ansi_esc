#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "ansi_esc.h"

int main(int argc, char *argv[]){
    char *text = argv[0];
    char *ansi_esc_sequence = "\x1b[90;101m";
    char *ansi_esc_end = "\x1b[0m";
    
    printf("%s%s%s\n", ansi_esc_sequence, text, ansi_esc_end);



    ANSI_style warning = {
        .bg_color = ANSI_DEFAULT,
        .fg_color = ANSI_DEFAULT,
        .style = ANSI_BOLD|ANSI_DIM,
    };

    char buffer[256];
    ANSI_style_str(buffer, sizeof(buffer), text, strlen(text), warning);

    printf("%s\n", buffer);
    return 0;
}