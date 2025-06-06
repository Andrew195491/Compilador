.data
x: .float 3.100000
str1: .asciiz "Mayor"
str2: .asciiz "Menor"

.text
.globl main
main:
    l.s $f12, x
    s.s $f12, x
    l.s $f13, x
    # ERROR: float literal no encontrado en tabla de símbolos
    c.le.s $f13, $f14
    beqz FLOAT_CMP_GT, L0
    la $t1, str1
    la $a0, str1
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    j L1
L0:
    la $t2, str2
    la $a0, str2
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
L1:
    li $v0, 10
    syscall
