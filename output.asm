.data
a: .word 7
b: .word 2
c: .word 0
t: .word 0

.text
.globl main
main:
    lw $t2, a
    lw $t3, b
    add $t4, $t2, $t3
    sw $t4, c
    lw $t5, c
    li $v0, 1
    move $a0, $t5
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    add $t8, $t6, $t7
    sw $t8, t
    lw $t9, t
    li $v0, 1
    move $a0, $t9
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    li $v0, 10
    syscall
