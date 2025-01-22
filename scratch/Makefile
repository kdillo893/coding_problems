CC=gcc
CFLAGS=-Wall -Werror -g 

ODIR=obj
LDIR =../lib

LIBS=-lm

all: typecheck relearning simple_filewrite

#make condition for "objdir/%.o", then need to find ways for objects to make here.
$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

_TC_OBJS = typecheck.o
_SW_OBJS = simple_filewrite.o
_RL_OBJS = relearning.o

typecheck: $(ODIR)/$(_TC_OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

simple_filewrite: $(ODIR)/$(_SW_OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

relearning: $(ODIR)/relearning.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -I $(ODIR)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o testfile.txt simple_filewrite typecheck relearning
