.data
a: .word 0

.text
.globl main
main:
    li $t0, -4
    li $t1, 6
    sub $t2, $t0, $t1
    sw $t2, a
    lw $t3, a
    li $v0, 1
    move $a0, $t3
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    li $v0, 10
    syscall
