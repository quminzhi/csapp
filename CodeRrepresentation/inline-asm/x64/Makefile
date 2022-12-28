BIN = recipes

CFLAGS = -O0 -g -Wall -Werror

all: $(BIN)

$(BIN): $(BIN).o
	gcc $(BIN).o -o $(BIN)

$(BIN).o: $(BIN).c
	gcc $(CFLAGS) -c $(BIN).c -o $(BIN).o

run:
	./$(BIN)

asm:
	gcc $(CFLAGS) -c $(BIN).c -o $(BIN).o
	objdump -d -S $(BIN).o > $(BIN).s

clean:
	rm -rf *.o *.s $(BIN)
