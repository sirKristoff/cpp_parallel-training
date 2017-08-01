C = $(CXX)
SRC = ToTest.cpp main_test.cpp
CFLAGS = -g -Wall -error
LDFLAGS = -lgtest -lgmock -lpthread
OUT = test

OBJ = $(SRC:.cpp=.o)

all: $(OUT)

$(OUT): $(OBJ)
	$(C) -o $(OUT) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(C) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OUT) $(OBJ)
	make -C threading/ clean

