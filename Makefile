# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-function

LEX = flex
BISON = bison

# Nombres de archivos
TARGET = $(SRC_DIR)/Compilador
SRC_DIR = Ejecutable
TEST_DIR = Pruebas

SOURCES = $(SRC_DIR)/Bison.tab.c $(SRC_DIR)/lex.yy.c $(SRC_DIR)/Tabla_Simbolos.c $(SRC_DIR)/Arbol_ABS.c
HEADERS = $(SRC_DIR)/Bison.tab.h $(SRC_DIR)/Tabla_Simbolos.h
LEX_FILE = $(SRC_DIR)/Flex.l
YACC_FILE = $(SRC_DIR)/Bison.y

# Regla principal
all: $(TARGET)

# Generación del ejecutable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

# Generación del parser
$(SRC_DIR)/Bison.tab.c $(SRC_DIR)/Bison.tab.h: $(YACC_FILE)
	$(BISON) -d -o $(SRC_DIR)/Bison.tab.c $(YACC_FILE)

# Generación del lexer
$(SRC_DIR)/lex.yy.c: $(LEX_FILE) $(SRC_DIR)/Bison.tab.h
	$(LEX) -o $(SRC_DIR)/lex.yy.c $(LEX_FILE)

# Limpieza
clean:
	rm -f $(TARGET) $(SRC_DIR)/Bison.tab.c $(SRC_DIR)/Bison.tab.h $(SRC_DIR)/lex.yy.c $(TEST_DIR)/output.asm *.o

.PHONY: all clean
