C = $(CXX)
SRC = main.cpp
CFLAGS = -std=c++11 -g -Wall -error -I./threading/
LDFLAGS = -L./threading -lthreading -lpthread
OUT = test

OBJ = $(SRC:.cpp=.o)

all: $(OUT)

$(OUT): libs $(OBJ)
	$(C) -o $(OUT) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(C) $(CFLAGS) -c $^ -o $@

libs:
	make -C threading/ all
clean:
	rm -f $(OUT) $(OBJ)
	make -C threading/ clean

