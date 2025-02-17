#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    x >>= n;
    return x & 1;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    unsigned helper = 1;
    helper <<= n;
    if (v == 1) {
        *x = *x | helper;
    } else {
        helper = ~helper;
        *x = *x & helper; 
    }
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
// 用 ^1 反转 
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    unsigned helper = 1;
    helper <<= n;
    *x = *x ^ helper;
}

