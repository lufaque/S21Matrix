NAME = s21_matrix.a
CC = gcc
AR = ar rcs

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p

CPP_FLAGS = -Wall -Wextra -Werror -std=c++17
TEST_LIBS = -lgtest -lstdc++ -pthread -lm

INCLUDE_DIR = ./include
SRC_DIR = ./
OBJ_DIR = ./objects
TEST_SRC_DIR = ./tests
TEST_OBJ_DIR = ./tests/objects

GTEST_LINK=$(shell pkg-config --libs --cflags gtest)

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)
TEST_SRC = $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJ = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $?

run: $(NAME) test
	./$(TEST_OBJ_DIR)/$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
	$(MKDIR) $(@D)
	$(CC) $(CPP_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

test: $(TEST_OBJ) $(NAME)
	$(CC) -g -o $@ $? $(TEST_LIBS)
	./test

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp $(INCLUDE)
	$(MKDIR) $(@D)
	$(CC) $(CPP_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

$(REPORT): $(GCOV_OBJ) $(TEST_OBJ)
	$(CC) $(GCOV_FLAGS) -o $(TEST) $? $(TEST_LIBS)
	./$(TEST)
	$(RM) stl_algobase.h.gcov move.h.gcov
	gcov $(GCOV_OBJ_DIR)/*.gcno
	mv *.gcov $(GCOV_OBJ_DIR)/
	lcov -c -t "s21_matrix_oop" -o $(GCOV_DIR)/report.info -d $(GCOV_OBJ_DIR)
	genhtml -o $(GCOV_DIR) $(GCOV_DIR)/report.info

clean:
	$(RMDIR) $(TEST_OBJ_DIR)
	$(RM) $(TEST)
	$(RMDIR) $(OBJ_DIR)
	$(RM) $(NAME)