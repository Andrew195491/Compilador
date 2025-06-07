.data
buffer_concat: .space 256
x: .float 1.100000
y: .float 0.0
float_1: .float 2.200000

.text
.globl main
main:
    l.s $f12, x
    s.s $f12, x
    l.s $f13, x
    l.s $f14, float_1
    add.s $f15, $f13, $f14
    mov.s $f12, $f15
    s.s $f12, y
    l.s $f16, y
    mov.s $f12, $f16
    li $v0, 2
    syscall
    li $v0, 10
    syscall
