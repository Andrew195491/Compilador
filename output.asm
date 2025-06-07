.data
buffer_concat: .space 256
i: .float 1.000000
float_1: .float 5.000000
float_2: .float 3.000000

.text
.globl main
main:
    l.s $f12, i
    s.s $f12, i
L0:
    l.s $f13, i
    l.s $f14, float_1
    c.lt.s $f13, $f14
    bc1f L1
    l.s $f15, i
    l.s $f16, float_2
    c.lt.s $f15, $f16
    # Error: condición no generó registro
    l.s $f17, i
    l.s $f18, i
    add.s $f19, $f17, $f18
    mov.s $f12, $f19
    s.s $f12, i
    j L0
L1:
    li $v0, 10
    syscall
