.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    addi s0, a0, 0
    addi sp, sp, -8
    sw s0, 4(sp)
    sw ra, 0(sp)
    addi t0, x0, 1
    beq a0, t0, baseCase
    addi a0, a0, -1
    jal factorial
    
    j endFactorial
    
baseCase:
    addi a0, a0, 0
    
endFactorial:
    lw s0, 4(sp)
    lw ra, 0(sp)
    addi sp, sp, 8
    mul a0, a0, s0
    jr ra
    

   