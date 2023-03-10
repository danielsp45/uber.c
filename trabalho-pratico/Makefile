CC := gcc

EXEC := programa-principal
FLAGS := -Wall -Wextra -Wdouble-promotion -Werror=pedantic -Werror=vla -pedantic-errors -Wfatal-errors

DEBUG ?= 0
GRAPH ?= 0
ifeq ($(DEBUG), 1)
	FLAGS += -O0 -g
else ifeq ($(GRAPH), 1)
	FLAGS += -O3 -pg
else
	FLAGS += -O3
endif

LIBS := -lm `pkg-config --libs glib-2.0 ncursesw`
PKG_CONFIG := `pkg-config --cflags glib-2.0 ncursesw`
INC := -I includes/
SRC := $(shell find src/ -name "*.c")
OBJ := $(SRC:src/%.c=build/%.o)

EXEC_TEST := programa-testes
FLAGS_TEST := $(FLAGS) -Wno-unused-function
INC_TEST := $(INC)
SRC_TEST := $(shell find tests/ -name "*.c")
OBJ_TEST := $(filter-out build/main.o, $(OBJ)) $(SRC_TEST:tests/%.c=build/%.o)

BUILD_DIR := $(shell mkdir -p build/views build/base build/io build/entities build/utils build/catalogs build/queries)
INCLUDE_FILES := $(shell find includes/ -name "*.h")

DATASET_PATH ?= 0
QUERIES_PATH ?= 0

.SUFFIXES:

.PHONY: all
all: $(EXEC) $(EXEC_TEST)

$(EXEC): $(OBJ)
	@$(CC) $(FLAGS) $^ ${PKG_CONFIG} $(LIBS) -o $@ ; echo "[Compiling] $@"

build/%.o: src/%.c
	@$(CC) $(FLAGS) -c $< ${PKG_CONFIG} $(LIBS) $(INC) -o $@ ; echo "[Linking] $@"

test: $(EXEC_TEST)
	@if [ "$(DATASET_PATH)" == 0 ]; then \
	  echo -e "\033[0;31mYou should pass DATASET_PATH to the command\033[0m"; \
	else \
	  /usr/bin/time -v ./$(EXEC_TEST) $(DATASET_PATH); \
	fi

$(EXEC_TEST): $(OBJ_TEST)
	@$(CC) $(FLAGS_TEST) $^ ${PKG_CONFIG} $(LIBS) -o $@ ; echo "[Compiling] $@"

build/%.o: tests/%.c
	@$(CC) $(FLAGS_TEST) -c $< ${PKG_CONFIG} $(LIBS) $(INC_TEST) -o $@ ; echo "[Linking] $@"

.PHONY: leaks
leaks: $(EXEC)
	@if [ "$(DATASET_PATH)" == 0 ] || [ "$(QUERIES_PATH)" == 0 ]; then \
	  echo -e "\033[0;31mYou should pass DATASET_PATH and QUERIES_PATH to the command\033[0m"; \
	else \
	 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(EXEC) $(DATASET_PATH) $(QUERIES_PATH); \
	fi

.PHONY: graph
graph:
	@gprof $(EXEC) | python -m gprof2dot | dot -Tpng -o gprof.png ; echo "[Graph] gprof.png"

.PHONY: clean
clean:
	@rm -f programa-principal ; echo "[Cleaning] programa-principal"
	@rm -f programa-testes ; echo "[Cleaning] programa-testes"
	@rm -rf build/ ; echo "[Cleaning] build/"
	@rm -rf Resultados/ ; echo "[Cleaning] Resultados/"

.PHONY: format
format:
	@clang-format -i --verbose $(SRC) $(INCLUDE_FILES) $(SRC_TEST)

.DELETE_ON_ERROR:
