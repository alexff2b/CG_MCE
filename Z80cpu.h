#ifndef Z80CPU_H
#define Z80CPU_H

/*
========================================================
 CG_ / Z80 CPU MODULE
--------------------------------------------------------
 Base register layer for Z80 emulation
 Built on top of CPU.h (8-bit core brick)
--------------------------------------------------------
 This file defines:
 - Z80 register set
 - flag layout
 - register grouping (pairs, shadow)
========================================================
*/

#include "cpu.h"

// -----------------------------------------------------
// Z80 FLAGS (F register bit layout)
// -----------------------------------------------------
// Bit 0 : C  - Carry flag (перенос/заём)
// Bit 1 : N  - Subtract flag (операция вычитания)
// Bit 2 : P/V - Parity / Overflow (чётность / переполнение)
// Bit 3 : -  - не используется
// Bit 4 : H  - Half carry (перенос из младшей тетрады)
// Bit 5 : -  - не используется
// Bit 6 : Z  - Zero flag (результат == 0)
// Bit 7 : S  - Sign flag (знак, старший бит результата)

#define Z80_FLAG_C  (1 << 0)  // Carry
#define Z80_FLAG_N  (1 << 1)  // Subtract
#define Z80_FLAG_PV (1 << 2)  // Parity / Overflow
#define Z80_FLAG_H  (1 << 4)  // Half carry
#define Z80_FLAG_Z  (1 << 6)  // Zero
#define Z80_FLAG_S  (1 << 7)  // Sign

// -----------------------------------------------------
// Z80 REGISTER SET (logical layout)
// -----------------------------------------------------

typedef struct
{
    // main registers
    cpu_reg8_t A;
    cpu_reg8_t F;

    cpu_reg8_t B;
    cpu_reg8_t C;

    cpu_reg8_t D;
    cpu_reg8_t E;

    cpu_reg8_t H;
    cpu_reg8_t L;

    // shadow registers
    cpu_reg8_t A_;
    cpu_reg8_t F_;

    cpu_reg8_t B_;
    cpu_reg8_t C_;

    cpu_reg8_t D_;
    cpu_reg8_t E_;

    cpu_reg8_t H_;
    cpu_reg8_t L_;

    // special registers
//    uint16_t IX;
//    uint16_t IY;

//    uint16_t SP;
//    uint16_t PC;

    cpu_reg8_t I;
    cpu_reg8_t R;

} Z80CPU;

#endif // Z80CPU_H
