//==============================================================
// ansi_formatting.h
//
// ANSI / VT100 терминальное форматирование
// для CG_MCE
//
// Header-only модуль
//==============================================================

#ifndef ANSI_FORMATTING_H
#define ANSI_FORMATTING_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//==============================================================
// Цвета текста (foreground)
//==============================================================

typedef enum
{
    ANSI_FG_BLACK         = 30,
    ANSI_FG_RED           = 31,
    ANSI_FG_GREEN         = 32,
    ANSI_FG_YELLOW        = 33,
    ANSI_FG_BLUE          = 34,
    ANSI_FG_MAGENTA       = 35,
    ANSI_FG_CYAN          = 36,
    ANSI_FG_WHITE         = 37,

    ANSI_FG_BRIGHT_BLACK   = 90,
    ANSI_FG_BRIGHT_RED     = 91,
    ANSI_FG_BRIGHT_GREEN   = 92,
    ANSI_FG_BRIGHT_YELLOW  = 93,
    ANSI_FG_BRIGHT_BLUE    = 94,
    ANSI_FG_BRIGHT_MAGENTA = 95,
    ANSI_FG_BRIGHT_CYAN    = 96,
    ANSI_FG_BRIGHT_WHITE   = 97

} ANSI_FG_Color;

//==============================================================
// Цвета фона (background)
//==============================================================

typedef enum
{
    ANSI_BG_BLACK         = 40,
    ANSI_BG_RED           = 41,
    ANSI_BG_GREEN         = 42,
    ANSI_BG_YELLOW        = 43,
    ANSI_BG_BLUE          = 44,
    ANSI_BG_MAGENTA       = 45,
    ANSI_BG_CYAN          = 46,
    ANSI_BG_WHITE         = 47,

    ANSI_BG_BRIGHT_BLACK   = 100,
    ANSI_BG_BRIGHT_RED     = 101,
    ANSI_BG_BRIGHT_GREEN   = 102,
    ANSI_BG_BRIGHT_YELLOW  = 103,
    ANSI_BG_BRIGHT_BLUE    = 104,
    ANSI_BG_BRIGHT_MAGENTA = 105,
    ANSI_BG_BRIGHT_CYAN    = 106,
    ANSI_BG_BRIGHT_WHITE   = 107

} ANSI_BG_Color;

//==============================================================
// Атрибуты текста
//==============================================================

typedef enum
{
    ANSI_RESET_ALL = 0,
    ANSI_BOLD      = 1,
    ANSI_DIM       = 2,
    ANSI_ITALIC    = 3,
    ANSI_UNDERLINE = 4,
    ANSI_BLINK     = 5,
    ANSI_INVERSE   = 7,
    ANSI_HIDDEN    = 8

} ANSI_Text_Attribute;

//==============================================================
// Инициализация / завершение терминала
//==============================================================

static inline void ansi_init(void)
{
    printf("\033[?1049h"); // alt buffer
    printf("\033[2J");     // clear screen
    printf("\033[H");      // home cursor
    printf("\033[?25l");   // hide cursor
    printf("\033[0m");     // reset
}

static inline void ansi_shutdown(void)
{
    printf("\033[0m");
    printf("\033[?25h");   // show cursor
    printf("\033[?1049l"); // exit alt buffer
}

//==============================================================
// Курсор
//==============================================================

static inline void ansi_set_cursor(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

static inline void ansi_hide_cursor(void)
{
    printf("\033[?25l");
}

static inline void ansi_show_cursor(void)
{
    printf("\033[?25h");
}

//==============================================================
// Очистка
//==============================================================

static inline void ansi_clear_screen(void)
{
    printf("\033[2J");
    printf("\033[H");
}

static inline void ansi_clear_line(void)
{
    printf("\033[2K");
}

static inline void ansi_clear_to_end(void)
{
    printf("\033[K");
}

//==============================================================
// Цвета
//==============================================================

static inline void ansi_set_text_color(int color)
{
    printf("\033[%dm", color);
}

static inline void ansi_set_bg_color(int color)
{
    printf("\033[%dm", color);
}

static inline void ansi_reset_colors(void)
{
    printf("\033[0m");
}

//==============================================================
// Атрибуты
//==============================================================

static inline void ansi_set_attribute(ANSI_Text_Attribute attr)
{
    printf("\033[%dm", attr);
}

//==============================================================
// Курсор движение
//==============================================================

static inline void ansi_cursor_up(int n)    { printf("\033[%dA", n); }
static inline void ansi_cursor_down(int n)  { printf("\033[%dB", n); }
static inline void ansi_cursor_right(int n) { printf("\033[%dC", n); }
static inline void ansi_cursor_left(int n)  { printf("\033[%dD", n); }

//==============================================================
// Save / restore
//==============================================================

static inline void ansi_save_cursor(void)
{
    printf("\033[s");
}

static inline void ansi_restore_cursor(void)
{
    printf("\033[u");
}

//==============================================================
// Принт
//==============================================================

static inline void ansi_print(const char* text)
{
    printf("%s", text);
}

#endif // ANSI_FORMATTING_H
