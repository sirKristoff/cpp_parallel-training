C = $(CXX)
SRC = main.cpp
#-error
CFLAGS = -g -Wall  -I./threading/ -std=c++11
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

run : $(OUT)
	./run.sh
