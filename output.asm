.data
a: .word 98

.text
.globl main
main:
    # No se genera sw para a (no es int/float/bool)
    li $v0, 10
    syscall
