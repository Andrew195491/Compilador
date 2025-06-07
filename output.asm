.data
x: .float 1.000000
y: .float 2.000000

.text
.globl main
main:
    l.s $f12, x
    s.s $f12, x
    l.s $f13, y
    mov.s $f12, $f13
    s.s $f12, y
    l.s $f14, x
    l.s $f15, y
    add.s $f16, $f14, $f15
    mov.s $f12, $f16
    s.s $f12, x
    l.s $f17, x
    mov.s $f12, $f17
    li $v0, 2
    syscall
    li $v0, 10
    syscall
