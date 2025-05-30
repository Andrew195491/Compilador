.data
a: .word 0
b: .float 0.000000

.text
.globl main
main:
    add $t2, $t0, $t1
    sw $t2, a
    l.s $t3, 7.500000
    l.s $t4, 6.500000
    add $t5, $t3, $t4
    li $v0, 10
    syscall
