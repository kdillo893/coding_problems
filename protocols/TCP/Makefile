CC=gcc
CFLAGS= -I. -g 
WARNINGS= -Wall -Wextra
LIBS= 
#DEPS= nothing right now...

OBJDIR := objs
OBJS := $(addprefix $(OBJDIR)/, tcp.o tcp_client.o)

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) $(WARNINGS) -c $<

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

all: $(OBJS)
	$(MAKE) tcp_server tcp_client

tcp_server: 
	$(CC) $(CFLAGS) $(WARNINGS) -o tcp_server $(OBJDIR)/tcp.o

tcp_client: 
	$(CC) $(CFLAGS) $(WARNINGS) -o tcp_client $(OBJDIR)/tcp_client.o

.PHONY: clean

clean:
	rm ./objs/*.o ./tcp_server ./tcp_client

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
