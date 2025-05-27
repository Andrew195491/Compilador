.data
g: .word 0:100

.text
.globl main
main:
    la $a0, g
    li $t0, 1
    sw $t0, 0($a0)
    li $t1, 0
    sw $t1, 4($a0)
    li $t2, 1
    sw $t2, 8($a0)
    li $v0, 10
    syscall
