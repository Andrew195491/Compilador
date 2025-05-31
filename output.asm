.data
a: .float 1.23 4.56 7.89 10.11

.text
.globl main
main:
    lw $t0, a
    li $v0, 1
    move $a0, $t0
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    li $v0, 10
    syscall
