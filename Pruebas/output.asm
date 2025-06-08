.data
buffer_concat: .space 256
x: .word 5
y: .float 3.500000
activo: .word 0
z: .word 0
w: .float 3.500000
resultado: .asciiz "Hola ""compilador"
comparacion: .word 0
numeros: .word 1 2 3
matriz: .word 1 2 3 4
mensajes_str0: .asciiz "hola"
mensajes_str1: .asciiz "adiós"
mensajes_str2: .asciiz "sí"
mensajes_str3: .asciiz "no"
mensajes: .word mensajes_str0 mensajes_str1 mensajes_str2 mensajes_str3
i: .word 0
str11: .asciiz "Hola "
str12: .asciiz "compilador"
str13: .asciiz "hola"
str14: .asciiz "adiós"
str15: .asciiz "sí"
str16: .asciiz "no"
str17: .asciiz "No está activo"
str18: .asciiz "Está activo"
float_1: .float 1.500000

.text
.globl main
main:
    li $t0, 5
    sw $t0, x
    l.s $f12, y
    s.s $f12, y
    li $t1, 0
    sw $t1, activo
    lw $t2, x
    li $t3, 2
    add $t4, $t2, $t3
    sw $t4, z
    l.s $f13, y
    l.s $f14, float_1
    mul.s $f15, $f13, $f14
    mov.s $f12, $f15
    s.s $f12, w
    lw $t5, z
    li $v0, 1
    move $a0, $t5
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    l.s $f16, w
    mov.s $f12, $f16
    li $v0, 2
    syscall
    la $t6, str11
    la $t7, str12
    la $t0, str11
    la $t1, buffer_concat
copy_str1_loop_8:
    lb $t2, 0($t0)
    beqz $t2, copy_str2_start_8
    sb $t2, 0($t1)
    addiu $t0, $t0, 1
    addiu $t1, $t1, 1
    j copy_str1_loop_8
copy_str2_start_8:
    la $t0, str12
copy_str2_loop_8:
    lb $t2, 0($t0)
    beqz $t2, end_concat_8
    sb $t2, 0($t1)
    addiu $t0, $t0, 1
    addiu $t1, $t1, 1
    j copy_str2_loop_8
end_concat_8:
    sb $zero, 0($t1)
    la $t9, resultado
    la $a0, buffer_concat
    li $v0, 4
    syscall
    lw $t0, x
    li $t1, 2
    sgt $t2, $t0, $t1
    sw $t2, comparacion
    lw $t3, comparacion
    li $v0, 1
    move $a0, $t3
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    lw $t4, numeros
    la $t0, numeros
    li $t1, 0
    li $t2, 3
print_numeros_loop:
    bge $t1, $t2, print_numeros_end
    sll $t3, $t1, 2
    add $t4, $t0, $t3
    lw $a0, 0($t4)
    li $v0, 1
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_numeros_loop
print_numeros_end:
    lw $t5, matriz
    la $t0, matriz
    li $t1, 0
    li $t3, 2
    li $t4, 2
print_matriz_outer:
    bge $t1, $t3, print_matriz_end
    li $t2, 0
print_matriz_inner:
    bge $t2, $t4, print_matriz_next_row
    mul $t5, $t1, $t4
    add $t5, $t5, $t2
    sll $t5, $t5, 2
    add $t6, $t0, $t5
    lw $a0, 0($t6)
    li $v0, 1
    syscall
    li $a0, 32
    li $v0, 11
    syscall
    addi $t2, $t2, 1
    j print_matriz_inner
print_matriz_next_row:
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_matriz_outer
print_matriz_end:
    lw $t6, mensajes
    la $t0, mensajes
    li $t1, 0
    li $t3, 2
    li $t4, 2
print_mensajes_outer:
    bge $t1, $t3, print_mensajes_end
    li $t2, 0
print_mensajes_inner:
    bge $t2, $t4, print_mensajes_next_row
    mul $t5, $t1, $t4
    add $t5, $t5, $t2
    sll $t5, $t5, 2
    add $t6, $t0, $t5
    lw $a0, 0($t6)
    li $v0, 4
    syscall
    li $a0, 32
    li $v0, 11
    syscall
    addi $t2, $t2, 1
    j print_mensajes_inner
print_mensajes_next_row:
    li $a0, 10
    li $v0, 11
    syscall
    addi $t1, $t1, 1
    j print_mensajes_outer
print_mensajes_end:
    lw $t7, activo
    seq $t8, $t7, $zero
    beqz $t8, L0
    la $t9, str17
    la $a0, str17
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    j L1
L0:
    la $t0, str18
    la $a0, str18
    li $v0, 4
    syscall
    li $a0, 10
    li $v0, 11
    syscall
L1:
    li $t1, 0
    sw $t1, i
L2:
    lw $t2, i
    li $t3, 3
    slt $t4, $t2, $t3
    beqz $t4, L3
    lw $t5, i
    li $v0, 1
    move $a0, $t5
    syscall
    li $a0, 10
    li $v0, 11
    syscall
    lw $t6, i
    li $t7, 1
    add $t8, $t6, $t7
    sw $t8, i
    j L2
L3:
    li $v0, 10
    syscall
