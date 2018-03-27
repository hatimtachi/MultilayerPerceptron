CC=gcc
SRC=CalculatedNeuron.c Network.c NeuronConfiguration.c readFile.c main.c
CFLAGS=-Wall 
LDFLAGS = 
PROGRAMS = Pmc
platform=$(shell uname -s)
ifeq ($(platform),Darwin)
	OBJ=$(SRC:.c=.o) 
else
	OBJ=$(SRC:.c=.o) -lm
endif
all : $(PROGRAMS) ${ARGS}
Pmc:    $(OBJ) NeuronStructure.h 
	$(CC)  -o $@ $(OBJ) ${ARGS}
%.o:	%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(PROGRAMS) *.o 
