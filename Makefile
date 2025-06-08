# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-function
LEX = flex
BISON = bison

# Nombres de archivos
TARGET = Compilador
SOURCES = Bison.tab.c lex.yy.c Tabla_Simbolos.c Arbol_ABS.c
HEADERS = Bison.tab.h Tabla_Simbolos.h
LEX_FILE = Flex.l
YACC_FILE = Bison.y

# Regla principal
all: $(TARGET)

# Generación del ejecutable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

# Generación del parser
Bison.tab.c Bison.tab.h: $(YACC_FILE)
	$(BISON) -d $(YACC_FILE)

# Generación del lexer
lex.yy.c: $(LEX_FILE) Bison.tab.h
	$(LEX) $(LEX_FILE)

# Limpieza
clean:
	rm -f $(TARGET) Bison.tab.c Bison.tab.h lex.yy.c output.asm *.o

# Para evitar conflictos con archivos llamados 'clean'
.PHONY: all clean