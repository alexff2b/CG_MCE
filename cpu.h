#ifndef CPU_H
#define CPU_H

#include <stdint.h>

// --------------------------------------------------
// 8-bit register
// --------------------------------------------------

typedef union
{
    uint8_t data;
} cpu_reg8_t;

// --------------------------------------------------
// Bit operations
// --------------------------------------------------

static inline void cpu_bit_set(cpu_reg8_t *reg, uint8_t bit)
{
    reg->data |= (1u << bit);
}

static inline void cpu_bit_clear(cpu_reg8_t *reg, uint8_t bit)
{
    reg->data &= ~(1u << bit);
}

static inline void cpu_bit_write(cpu_reg8_t *reg, uint8_t bit, uint8_t value)
{
    if (value)
        cpu_bit_set(reg, bit);
    else
        cpu_bit_clear(reg, bit);
}

static inline uint8_t cpu_bit_read(const cpu_reg8_t *reg, uint8_t bit)
{
    return (reg->data >> bit) & 1u;
}

static inline void cpu_reg_write(cpu_reg8_t *reg, uint8_t value)
{
    reg->data = value;
}

static inline uint8_t cpu_reg_read(const cpu_reg8_t *reg)
{
    return reg->data;
}

#endif
