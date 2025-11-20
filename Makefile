CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=-ljpeg -lm

EXECUTABLES = mandel movie

MANDEL_SRC = mandel.c jpegrw.c
MOVIE_SRC  = movie.c

MANDEL_OBJ = $(MANDEL_SRC:.c=.o)
MOVIE_OBJ  = $(MOVIE_SRC:.c=.o)

all: $(EXECUTABLES)

mandel: $(MANDEL_OBJ)
	$(CC) $(MANDEL_OBJ) $(LDFLAGS) -o $@

movie: $(MOVIE_OBJ)
	$(CC) $(MOVIE_OBJ) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $< > $*.d

-include $(MANDEL_OBJ:.o=.d) $(MOVIE_OBJ:.o=.d)

clean:
	rm -f *.o *.d $(EXECUTABLES)