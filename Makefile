#Variables
NAME = webserv
CC = clang++
CFLAGS = -Wall -Wextra -Werror
MAIN = main.cpp
TEST_MAIN = TestMain.cpp
SRC_DIR = ./src
SRC_NAME = ConfigParser.cpp
ifdef TEST_MODE
	SRC_NAME += $(TEST_MAIN)
	CFLAGS += -g3 -std=c++0x -lgtest -lgtest_main -pthread
else
	SRC_NAME += $(MAIN)
	CFLAGS += -std=c++98
endif
SRC = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
INCLUDE = -I ./include -I$(LIB_DIR)
LIB_DIR = ./lib/libft_cpp
LIBFT = $(addprefix $(LIB_DIR)/,libft.a)
LIB = -L$(LIB_DIR) -lft
#Phony Target Rules
.PHONY : all test run clean re
all : $(NAME)

clean :
	rm -rf webserv
re : clean all

test :
	make TEST_MODE=1 all
	make TEST_MODE=1 run
run : all
	./$(NAME)
#Real Target Rules
$(NAME) : $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIB) $^ -o $@
$(LIBFT) :
	make -C $(LIB_DIR) all