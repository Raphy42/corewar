//
// Created by Raphaël Dantzer on 06/09/16.
//

#ifndef COREWAR_TERMCOLOR_H
#define COREWAR_TERMCOLOR_H

typedef enum            e_term_font_type
{
    NORMAL = 0,
    BOLD = 1,
    DIM = 2,
    UNDERLINED = 4,
    BLINK = 5,
    REVERSE = 7,
    HIDDEN = 8
}                       t_term_font_type;

typedef enum            e_term_attr_type
{
    FOREGROUND = 0,
    BACKGROUND = 10
}                       t_term_attr_type;

typedef enum            e_term_color
{
    DEFAULT_COLOR = 39,
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_RED,
    LIGHT_GREEN,
    LIGHT_YELLOW,
    LIGHT_BLUE,
    LIGHT_MAGENTA,
    LIGHT_CYAN,
    WHITE
}                       t_term_color;

#endif //COREWAR_TERMCOLOR_H
