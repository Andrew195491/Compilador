.data
a: .word 1 2 3

.text
.globl main
main:
    lw $t0, a
    la $t0, a
    li $t1, 0
    li $t2, 3
print_a_loop:
    bge $t1, $t2, print_a_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 1
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_a_loop
print_a_end:
    li $v0, 10
    syscall
