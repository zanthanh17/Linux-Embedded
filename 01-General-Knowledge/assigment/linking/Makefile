

CUR_DIR := .
BIN_DIR := $(CUR_DIR)/bin
INC_DIR := $(CUR_DIR)/inc
OBJ_DIR := $(CUR_DIR)/obj
SRC_DIR := $(CUR_DIR)/src
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared

C_FLAGS := -I $(INC_DIR)

create_objs:
	gcc -c -fPIC $(SRC_DIR)/helloThanh.c -o $(OBJ_DIR)/helloThanh.o -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/helloWorld.c -o $(OBJ_DIR)/helloWorld.o -I $(INC_DIR)
	gcc -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)
create_shared_libs:
	gcc -shared $(OBJ_DIR)/helloThanh.o $(OBJ_DIR)/helloWorld.o -o $(LIB_SHARED_DIR)/libhello.so

create_static_libs:
	ar rcs $(LIB_STATIC_DIR)/libhello.a $(OBJ_DIR)/helloThanh.o $(OBJ_DIR)/helloWorld.o

all: create_objs create_shared_libs create_static_libs
	gcc  $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -lhello -o $(BIN_DIR)/use-shared-library
	gcc   $(OBJ_DIR)/main.o  -L$(LIB_STATIC_DIR) -lhello -o $(BIN_DIR)/statically-linked

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_SHARED_DIR)/*.so
	rm -rf $(LIB_STATIC_DIR)/*.a
	rm -rf $(BIN_DIR)/use-shared-library

