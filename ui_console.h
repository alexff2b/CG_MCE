//==============================================================
// ui_console.h
//
// Консольный UI CG_MCE
//
// Добавлено:
//     - текстовые метки (UI_Label)
//     - вывод текста по координатам
//==============================================================

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//==============================================================
// Псевдографика рамок
//==============================================================

#define UI_CORNER_TL "╔"
#define UI_CORNER_TR "╗"
#define UI_CORNER_BL "╚"
#define UI_CORNER_BR "╝"

#define UI_LINE_H "═"
#define UI_LINE_V "║"

//==============================================================
// Окно
//==============================================================

typedef struct
{
    int x;
    int y;
    int width;
    int height;
    const char* title;

} UI_Window;

//==============================================================
// Текстовая метка (LABEL)
//
// Используется для вывода статического текста на экране
//
// name     - логическое имя метки (для отладки/логики)
// text     - отображаемый текст
// x, y     - координаты на экране
//==============================================================

typedef struct
{
    const char* name;
    const char* text;

    int x;
    int y;

} UI_Label;

//==============================================================
// ANSI базовые функции
//==============================================================

static inline void ui_clear_screen(void)
{
    printf("\033[2J");
    printf("\033[H");
}

static inline void ui_set_cursor(int x, int y)
{
    printf("\033[%d;%dH", y, x);
}

static inline void ui_put_string(const char* str)
{
    printf("%s", str);
}

//==============================================================
// Окна
//==============================================================

static inline void ui_draw_frame(int x, int y, int width, int height)
{
    ui_set_cursor(x, y);

    printf("%s", UI_CORNER_TL);
    for (int i = 0; i < width - 2; i++) printf("%s", UI_LINE_H);
    printf("%s", UI_CORNER_TR);

    for (int row = 1; row < height - 1; row++)
    {
        ui_set_cursor(x, y + row);
        printf("%s", UI_LINE_V);

        ui_set_cursor(x + width - 1, y + row);
        printf("%s", UI_LINE_V);
    }

    ui_set_cursor(x, y + height - 1);

    printf("%s", UI_CORNER_BL);
    for (int i = 0; i < width - 2; i++) printf("%s", UI_LINE_H);
    printf("%s", UI_CORNER_BR);
}

static inline void ui_draw_title(int x, int y, const char* title)
{
    ui_set_cursor(x + 2, y);
    printf("[ %s ]", title);
}

static inline void ui_draw_window(UI_Window* w)
{
    ui_draw_frame(w->x, w->y, w->width, w->height);
    ui_draw_title(w->x, w->y, w->title);
}

//==============================================================
// LABEL SYSTEM
//==============================================================

static inline void ui_draw_label(UI_Label* label)
{
    if (!label) return;

    ui_set_cursor(label->x, label->y);
    printf("%s", label->text);
}

static inline void ui_update_label_text(UI_Label* label, const char* new_text)
{
    if (!label) return;
    label->text = new_text;
}

static inline void ui_move_label(UI_Label* label, int x, int y)
{
    if (!label) return;
    label->x = x;
    label->y = y;
}

#endif // UI_CONSOLE_H
