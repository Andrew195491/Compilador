.data
x: .asciiz "Hola"
y: .asciiz "si"

.text
.globl main
main:
    la $t0, x
    la $t1, y
    la $t2, x
    la $t3, y
    move $a0, $t2
    move $a1, $t3
    jal strcmp
    seq $t4, $v0, $zero
    beqz $t4, L0
    li $t5, 66
    li $a0, 66
    li $v0, 1
    syscall
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    j L1
L0:
    li $t6, 77
    li $a0, 77
    li $v0, 1
    syscall
    syscall
    li $a0, 10
    li $v0, 11
    syscall
L1:
    li $v0, 10
    syscall
