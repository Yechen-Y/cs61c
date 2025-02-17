#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

uint16_t get_bit(uint16_t num, uint8_t pos);

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t MSB = get_bit(*reg, 0) ^ get_bit(*reg, 2) ^ get_bit(*reg, 3) ^ get_bit(*reg, 5);
    *reg >>= 1;
    MSB <<= 15;
    *reg = *reg | MSB;
}

uint16_t get_bit(uint16_t num, uint8_t pos) {
    num >>= pos;
    return num & 1;
}
