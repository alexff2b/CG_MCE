/*
    test.c

    Демонстрация работы CPU.h

    Компиляция:
    gcc test.c -o test
*/

#include <stdio.h>
#include "cpu.h"

void print_register(cpu_reg8_t *reg)
{
    printf("HEX : 0x%02X | ", cpu_reg_read(reg));
    printf("DEC : %3u | ", cpu_reg_read(reg));

    printf("BIN : ");

    for (int i = 7; i >= 0; i--)
    {
        printf("%u", cpu_bit_read(reg, i));
    }

    printf("\n");
}

int main(void)
{
    cpu_reg8_t reg;

    printf("Начальное состояние:\n");
    cpu_reg_write(&reg, 0x00);
    print_register(&reg);

    printf("\nЗапись 0x55:\n");
    cpu_reg_write(&reg, 0x55);
    print_register(&reg);

    printf("\nУстановка бита 7:\n");
    cpu_bit_set(&reg, 7);
    print_register(&reg);

    printf("\nУстановка бита 0:\n");
    cpu_bit_set(&reg, 0);
    print_register(&reg);

    printf("\nСброс бита 4:\n");
    cpu_bit_clear(&reg, 4);
    print_register(&reg);

    printf("\nЗапись в бит 3 значения 1:\n");
    cpu_bit_write(&reg, 3, 1);
    print_register(&reg);

    printf("\nЗапись в бит 6 значения 0:\n");
    cpu_bit_write(&reg, 6, 0);
    print_register(&reg);

    printf("\nЧтение всех битов:\n");

    for (int i = 7; i >= 0; i--)
    {
        printf("bit[%d] = %u\n", i, cpu_bit_read(&reg, i));
    }

    return 0;
}
