CC = gcc
CFLAGS = -fdiagnostics-color=always -g
LDFLAGS = -lm

SRC = /home/pedro/Documentos/AEDs3/Trab2.c
OUT = /home/pedro/Documentos/AEDs3/Trab2

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

run: $(OUT)
	$(OUT)

clean:
	rm -f $(OUT)
