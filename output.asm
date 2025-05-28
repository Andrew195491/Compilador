.data

.text
.globl main
main:
    li $t0, 6
    li $v0, 1
    move $a0, $t0
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    li $v0, 10
    syscall
