OBJ=main.o structure.o primitives.o utils.o
CC=gcc
FLG=-Wall -g -std=c99

interprete:	$(OBJ) stdafx.h
	$(CC) $(OBJ) $(FLG) -o interprete

%.o:	%.c
	$(CC) $(FLG) -c $<

clean:
	@rm -f *.o
	@rm -f core
	@rm -f *~
