CC = gcc
CFLAGS = -g -Wall -ansi -pedantic

all:	invert makeRed  fixUnderwater

invert:	ppmtools.o invert.o
	$(CC)  -o $@ $^ 

%.o:	 %.c $(INCL)
	$(CC) $(CFLAGS) -c -o $@ $< 
	
makeRed:	ppmtools.o makeRed.o
	$(CC)  -o $@ $^ 	

fixUnderwater:	ppmtools.o fixUnderwater.o
	$(CC)  -o $@ $^ 