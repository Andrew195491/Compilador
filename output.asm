.data
g: .word 0:100
h: .word 0:100

.text
.globl main
main:
    li $t0, 1
    li $t1, 2
    li $t2, 3
    sw (null), g
    li $t3, 1
    li $t4, 2
    li $t5, 2
    li $t6, 1
    sw (null), h
    li $v0, 10
    syscall
