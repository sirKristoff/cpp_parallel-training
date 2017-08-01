SRC = src/thread.cpp src/mutex.cpp src/condition_variable.cpp
CFLAGS = -g -Wall -error -fPIC -I./threading
LDFLAGS = -shared
OUT = libthreading.so

OBJ = $(SRC:.cpp=.o)

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) -o $(OUT) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OUT) $(OBJ)

