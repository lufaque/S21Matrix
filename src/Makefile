MAIN=s21_matrix_oop.a

CC=gcc
CFLAGS=-Wall -Werror -Wextra

TEST_DIR=./tests/
OBJ_DIR=./objects/
NON_GUI_OBJ_DIR=./objects/
INCLUDE_DIR=./include/
MAIN_DIR=./

INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)

PKG_CONFIG=$(shell which pkg-config)
PKG_CONFIG_FLAGS=--libs --cflags

DEBUG_FLAGS=-g
FULL_VAL_LEAK_CHECK=--leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck --show-reachable=yes
CREATE_VAL_LOGFILE=--log-file=valgrind.txt
INTERACTIVE_DOCKER_MODE=-it

RM=rm -f
RM_DIR=rm -rf
CLANG=clang-format -style=google

SRC=$(wildcard $(RENDER_DIR)*.c )
OBJ=$(patsubst $(RENDER_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: run

$(MAIN): $(OBJ)
	ar rcs $(OBJ_DIR)$(MAIN) $(OBJ)

$(OBJ_DIR)%.o: $(RENDER_DIR)%.c $(INCLUDE)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(NON_GUI_OBJ_DIR)%.o: $(RENDER_DIR)%.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

create_build_dir:
	mkdir -p $(BUILD_DIR)

run: $(MAIN)
	$(APP_DIR)$(MAIN)

rebuild: clean all

test:
	make -C $(VIEWER_DIR) all
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(INCLUDE_DIR) $(TEST_DIR)*.c -L$(OBJ_DIR) -l$(MAIN) -o $(OBJ_DIR)$(MAIN)Test.o -lm $(CHECK_LINK)

run_test: test
	$(OBJ_DIR)$(MAIN)Test.o

check_leaks: test
	leaks -atExit -- ./$(OBJ_DIR)$(MAIN)Test.o

clean:
	$(RM_DIR) $(OBJ_DIR)*
	$(RM) $(OBJ_DIR)*

format:
	$(CLANG) -i $(MAIN_DIR)*.c $(GUI_DIR)*.c $(TEST_DIR)*.c

docker_build:
	docker build . -t s21_3d
	docker container create -v $(PWD):/usr/src --name s21_3d_container s21_3d

docker_start:
	docker start -a s21_3d_container

valgrind: test
	valgrind $(FULL_VAL_LEAK_CHECK) $(OBJ_DIR)$(MAIN)Test.o

