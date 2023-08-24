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

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)
TEST_SRC = $(wildcard $(TEST_SRC_DIR)/*.cpp)
TEST_OBJ = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.cpp=.o)))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $?

run: $(NAME) test
	./test

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE)
	$(MKDIR) $(@D)
	$(CC) $(CPP_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

test: $(TEST_OBJ) $(NAME)
	$(CC) -g -o $@ $? $(TEST_LIBS)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp $(INCLUDE)
	$(MKDIR) $(@D)
	$(CC) $(CPP_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

clean:
	$(RMDIR) $(TEST_OBJ_DIR)
	$(RM) ./test
	$(RMDIR) $(OBJ_DIR)
	$(RM) $(NAME)