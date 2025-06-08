.data
buffer_concat: .space 256
x: .word 2

.text
.globl main
main:
    li $t0, 2
    sw $t0, x
    li $v0, 10
    syscall
