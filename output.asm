.data
buffer_concat: .space 256
i: .asciiz "Hola""siiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"
str1: .asciiz "Hola"
str2: .asciiz "siiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"

.text
.globl main
main:
    la $t0, str1
    la $t1, str2
    # Concatenación de strings: (null) + (null)
    la $t0, str1
    la $t1, buffer_concat
copy_str1_loop_2:
    lb $t2, 0($t0)
    beqz $t2, copy_str2_start_2
    sb $t2, 0($t1)
    addiu $t0, $t0, 1
    addiu $t1, $t1, 1
    j copy_str1_loop_2
copy_str2_start_2:
    la $t0, str2
copy_str2_loop_2:
    lb $t2, 0($t0)
    beqz $t2, end_concat_2
    sb $t2, 0($t1)
    addiu $t0, $t0, 1
    addiu $t1, $t1, 1
    j copy_str2_loop_2
end_concat_2:
    sb $zero, 0($t1)
    la $t3, i
    la $a0, buffer_concat
    li $v0, 4
    syscall
    li $v0, 10
    syscall
