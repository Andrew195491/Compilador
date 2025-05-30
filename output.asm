.data
x: .word 1
y: .word 0

.text
.globl main
main:
    sw $t1, y
    li $v0, 10
    syscall
