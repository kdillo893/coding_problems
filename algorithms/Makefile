.DEFAULT_GOAL=
.PROXY= clean all

CC=gcc
CFLAGS= -I. -g 
WARNINGS= -Wall -Wextra
LIBS= 
#DEPS= nothing right now...

OBJDIR := objs

###### rule definitions

all:
	$(MAKE) clean huffman

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/hashtable.o: $(OBJDIR)
	$(CC) $(CFLAGS) $(WARNINGS) -c ../datastructs/c/hashtable.c -o $(OBJDIR)/hashtable.o

clean:
	rm $(OBJDIR)/*.o ./huffman

huffman: $(OBJDIR)/hashtable.o
	$(CC) $(CFLAGS) $(WARNINGS) -o huffman huffman.c $^

#Notes for self:
#	 $<  translates to "the first prereq"
#	 $@  translates to "the target of the make"
#	 $^  translates to "all prereqs" (objs would be every object file), spec by pattern
#	 %   is wildcard
#	 *   is a different wildcard...
#	 $() is reference to a variable defined in the makefile, substitutes the value in.
#	 ... didn't figure out how to "specify variable for sub-prereq"...
#
#	 normal prereqs | order-only-prereqs (see 4.2 of make manual)
#	 	normal prereqs assume "new prereq means we must rebuild the target"
#	 	order-only prereqs will not force a rebuild of the target.
