.data
ai: .word 1
bi: .word 2
ci: .word 0
as: .asciiz "Hola"
bs: .asciiz "Que"
cs: .asciiz "Tal"
af: .float 1.100000
bf: .float 2.200000
cf: .float 0.000000

.text
.globl main
main:
    # $t0 ya inicializado, se reutiliza
    # ai ya inicializado (int/bool), se omite sw
    # $t1 ya inicializado, se reutiliza
    # bi ya inicializado (int/bool), se omite sw
    lw $t2, ai
    lw $t3, bi
    add $t4, $t2, $t3
    li $t5, 3
    add $t6, $t4, $t5
    sw $t6, ci
    lw $t7, ai
    li $v0, 1
    move $a0, $t7
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    lw $t8, bi
    li $v0, 1
    move $a0, $t8
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    lw $t9, ci
    li $v0, 1
    move $a0, $t9
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    la $t0, as
    la $t1, bs
    la $t2, cs
    la $t3, as
    li $v0, 4
    move $a0, $t3
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    la $t4, bs
    li $v0, 4
    move $a0, $t4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    la $t5, cs
    li $v0, 4
    move $a0, $t5
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f12, af
    s.s $f12, af
    l.s $f13, bf
    mov.s $f12, $f13
    s.s $f12, bf
    l.s $f14, af
    l.s $f15, bf
    add.s $f16, $f14, $f15
    mov.s $f12, $f16
    s.s $f12, cf
    l.s $f17, af
    mov.s $f12, $f17
    li $v0, 2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f18, bf
    mov.s $f12, $f18
    li $v0, 2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f19, cf
    mov.s $f12, $f19
    li $v0, 2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    li $v0, 10
    syscall
