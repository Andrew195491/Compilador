.data
n: .asciiz "Hola"
o: .word 42
p: .float 3.140000
q: .asciiz "Mundo"
r: .word 7
s: .float 2.710000
t: .asciiz "Ruby"
u: .word 100
v: .float 0.990000
w: .asciiz "Array"
x: .word 2024
y: .float 1.620000
z: .asciiz "Zeta"
a: .word 1 2 42
b: .float 3.50 3.14 9.80
c_str0: .asciiz "A"
c_str1: .asciiz "Hola"
c_str2: .asciiz "B"
c: .word c_str0 c_str1 c_str2
d: .word 7 4 5
e: .float 6.60 7.70 2.71
f_str0: .asciiz "Mundo"
f_str1: .asciiz "Q"
f_str2: .asciiz "Ruby"
f: .word f_str0 f_str1 f_str2
g: .word 8 9 100
h: .float 0.99 10.10 11.20
i_str0: .asciiz "I"
i_str1: .asciiz "Array"
i_str2: .asciiz "J"
i: .word i_str0 i_str1 i_str2
j: .word 2024 12 13
k: .float 14.14 1.62 15.15
l_str0: .asciiz "L"
l_str1: .asciiz "M"
l_str2: .asciiz "Zeta"
l: .word l_str0 l_str1 l_str2

.text
.globl main
main:
    li $t0, 7
    li $t1, 8
    add $t2, $t0, $t1
    la $t3, a
    sw $t2, 0($t3)
    li $t4, 7
    sw $t4, 4($t3)
    li $t0, 7
    li $t1, 8
    add $t2, $t0, $t1
    la $t3, d
    sw $t2, 0($t3)
    li $t4, 7
    sw $t4, 4($t3)
    li $t0, 7
    li $t1, 8
    add $t2, $t0, $t1
    la $t3, g
    sw $t2, 0($t3)
    li $t4, 7
    sw $t4, 4($t3)
    li $t0, 7
    li $t1, 8
    add $t2, $t0, $t1
    la $t3, j
    sw $t2, 0($t3)
    li $t4, 7
    sw $t4, 4($t3)
    la $t0, n
    # $t1 ya inicializado, se reutiliza
    # o ya inicializado (int/bool), se omite sw
    l.s $f12, p
    s.s $f12, p
    la $t2, q
    # $t3 ya inicializado, se reutiliza
    # r ya inicializado (int/bool), se omite sw
    l.s $f13, s
    mov.s $f12, $f13
    s.s $f12, s
    la $t4, t
    # $t5 ya inicializado, se reutiliza
    # u ya inicializado (int/bool), se omite sw
    l.s $f14, v
    mov.s $f12, $f14
    s.s $f12, v
    la $t6, w
    # $t7 ya inicializado, se reutiliza
    # x ya inicializado (int/bool), se omite sw
    # ERROR: float literal no encontrado en tabla de símbolos
    mov.s $f12, $f15
    s.s $f12, y
    la $t8, z
    la $t9, n
    li $v0, 4
    move $a0, $t9
    syscall
    lw $t0, o
    li $v0, 1
    move $a0, $t0
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f16, p
    mov.s $f12, $f16
    li $v0, 2
    syscall
    la $t1, q
    li $v0, 4
    move $a0, $t1
    syscall
    lw $t2, r
    li $v0, 1
    move $a0, $t2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f17, s
    mov.s $f12, $f17
    li $v0, 2
    syscall
    la $t3, t
    li $v0, 4
    move $a0, $t3
    syscall
    lw $t4, u
    li $v0, 1
    move $a0, $t4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f18, v
    mov.s $f12, $f18
    li $v0, 2
    syscall
    la $t5, w
    li $v0, 4
    move $a0, $t5
    syscall
    lw $t6, x
    li $v0, 1
    move $a0, $t6
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f19, y
    mov.s $f12, $f19
    li $v0, 2
    syscall
    la $t7, z
    li $v0, 4
    move $a0, $t7
    syscall
    lw $t8, a
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
    lw $t9, b
    la $t0, b
    li $t1, 0
    li $t2, 3
print_b_loop:
    bge $t1, $t2, print_b_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lwc1 $f12, 0($t4)
    li $v0, 2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_b_loop
print_b_end:
    lw $t0, c
    la $t0, c
    li $t1, 0
    li $t2, 3
print_c_loop:
    bge $t1, $t2, print_c_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_c_loop
print_c_end:
    lw $t1, d
    la $t0, d
    li $t1, 0
    li $t2, 3
print_d_loop:
    bge $t1, $t2, print_d_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 1
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_d_loop
print_d_end:
    lw $t2, e
    la $t0, e
    li $t1, 0
    li $t2, 3
print_e_loop:
    bge $t1, $t2, print_e_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lwc1 $f12, 0($t4)
    li $v0, 2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_e_loop
print_e_end:
    lw $t3, f
    la $t0, f
    li $t1, 0
    li $t2, 3
print_f_loop:
    bge $t1, $t2, print_f_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_f_loop
print_f_end:
    lw $t4, g
    la $t0, g
    li $t1, 0
    li $t2, 3
print_g_loop:
    bge $t1, $t2, print_g_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 1
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_g_loop
print_g_end:
    lw $t5, h
    la $t0, h
    li $t1, 0
    li $t2, 3
print_h_loop:
    bge $t1, $t2, print_h_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lwc1 $f12, 0($t4)
    li $v0, 2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_h_loop
print_h_end:
    lw $t6, i
    la $t0, i
    li $t1, 0
    li $t2, 3
print_i_loop:
    bge $t1, $t2, print_i_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_i_loop
print_i_end:
    lw $t7, j
    la $t0, j
    li $t1, 0
    li $t2, 3
print_j_loop:
    bge $t1, $t2, print_j_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 1
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_j_loop
print_j_end:
    lw $t8, k
    la $t0, k
    li $t1, 0
    li $t2, 3
print_k_loop:
    bge $t1, $t2, print_k_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lwc1 $f12, 0($t4)
    li $v0, 2
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_k_loop
print_k_end:
    lw $t9, l
    la $t0, l
    li $t1, 0
    li $t2, 3
print_l_loop:
    bge $t1, $t2, print_l_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_l_loop
print_l_end:
    li $v0, 10
    syscall
