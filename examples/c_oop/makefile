CFLAGS = -g -Wall
LDFLAGS = 
SRCS = person.c main.c
OUT = oop

OBJS = $(SRCS:.c=.o)

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OUT) $(OBJS)

