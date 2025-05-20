# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-function
LEX = flex
BISON = bison

# Nombres de archivos
TARGET = latino_compiler
SOURCES = parser_latino.tab.c lex.yy.c tabla_simbolos.c
HEADERS = parser_latino.tab.h tabla_simbolos.h
LEX_FILE = scanner_latino.l
YACC_FILE = parser_latino.y

# Regla principal
all: $(TARGET)

# Generación del ejecutable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

# Generación del parser
parser_latino.tab.c parser_latino.tab.h: $(YACC_FILE)
	$(BISON) -d $(YACC_FILE)

# Generación del lexer
lex.yy.c: $(LEX_FILE) parser_latino.tab.h
	$(LEX) $(LEX_FILE)

# Limpieza
clean:
	rm -f $(TARGET) parser_latino.tab.c parser_latino.tab.h lex.yy.c output.asm *.o

# Para evitar conflictos con archivos llamados 'clean'
.PHONY: all clean