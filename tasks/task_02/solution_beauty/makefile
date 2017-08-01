SRC = main.cpp
CFLAGS = -g -Wall -std=c++11
LDFLAGS = -lpthread
OUT = consuments

OBJ = $(SRC:.cpp=.o)

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) -o $(OUT) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OUT) $(OBJ)

