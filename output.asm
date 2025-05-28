.data
g: .word 0:100

.text
.globl main
main:
    la $t0, str_0
    sw $t0, g
    li $v0, 10
    syscall
