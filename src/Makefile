OS := $(shell uname)

MAIN = s21_matrix_oop.a
CC := gcc
AR = ar rcs

# Change the compiler to g++ if the OS is Linux for compiling code in docker container
ifeq ($(OS), Linux)
    CC := g++
endif

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p

CPP_FLAGS = -Wall -Wextra -Werror -std=c++17
TEST_LIBS = -lgtest -lstdc++ -pthread -lm

DEBUG_FLAGS=-g
FULL_VAL_LEAK_CHECK=--leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck --show-reachable=yes
CREATE_VAL_LOGFILE=--log-file=valgrind.txt
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

INCLUDE_DIR = ./include
MAIN_DIR = ./S21Matrix
OBJ_DIR = ./objects
TEST_SRC_DIR = ./tests
TEST_OBJ_DIR = ./tests/objects
GCOV_DIR = ./gcov_report
GCOV_OBJ_DIR = ./gcov_report/objects

SRC = $(wildcard $(MAIN_DIR)/*.cpp)
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)
TEST_SRC = $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJ = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.cpp=.o)))
GCOV_OBJ = $(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

all: $(MAIN)

$(MAIN): $(OBJ)
	$(AR) $@ $?

run: $(MAIN) test
	./test

$(OBJ_DIR)/%.o: $(MAIN_DIR)/%.cpp $(INCLUDE)
	$(MKDIR) $(@D)
	$(CC) $(CPP_FLAGS) $(DEBUG_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

test: $(TEST_OBJ) $(MAIN)
	$(CC) -g -o $@ $? $(TEST_LIBS)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp $(INCLUDE)
	$(MKDIR) $(@D)
	$(CC) $(CPP_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

clean:
	$(RMDIR) $(TEST_OBJ_DIR)
	$(RM) ./test
	$(RMDIR) $(OBJ_DIR)
	$(RM) $(MAIN)
	$(RMDIR) $(GCOV_DIR)

docker_build:
	docker build . -t s21_matrix
	docker container create -v $(PWD):/usr/src --name s21_matrix_container s21_matrix

docker_start:
	docker start -a s21_matrix_container

valgrind: test
	valgrind $(FULL_VAL_LEAK_CHECK) ./test

gcov_report: $(GCOV_OBJ) $(TEST_OBJ)
	$(CC) $(GCOV_FLAGS) -o ./test $? $(TEST_LIBS)
	./test
	gcov $(GCOV_OBJ_DIR)/*.gcno
	mv *.gcov $(GCOV_OBJ_DIR)/
	lcov -c -t "s21_matrix_oop" -o $(GCOV_DIR)/report.info -d $(GCOV_OBJ_DIR)
	genhtml -o $(GCOV_DIR) $(GCOV_DIR)/report.info
	open $(GCOV_DIR)/index.html

$(GCOV_OBJ_DIR)/%.o: $(MAIN_DIR)/%.cpp $(INCLUDE)
	$(MKDIR) $(@D)
	$(CC) $(CPP_FLAGS) $(DEBUG_FLAGS) $(GCOV_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

format:
	clang-format -i $(SRC) $(TEST_SRC) $(INCLUDE)