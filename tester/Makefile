SRC_DIR := ../src
SRC_NAME := WebServer.cpp \
			ServerFD.cpp \
			Location.cpp
SRC := $(addprefix $(SRC_DIR)/,$(SRC_NAME))
PARSE_TEST := $(SRC_DIR)/Parsetest.cpp
TEST_RESULT := ./result
CC := gcc -Wall -Wextra -Werror

parsetest : $(PARSE_TEST) $(SRC)
	gcc $? -o parsetest
	./parsetest.sh


.PHONY : parsetest