## Process this file with automake to produce Makefile.in: use toplevel
AUTOMAKE_OPTIONS = subdir-objects
bin_PROGRAMS = leetcode
leetcodedir= .
leetcode_CFLAGS= -Wall -Werror
leetcode_SOURCES= leetcode.c funcs/findball.c funcs/isSorted.c funcs/mergestrings.c funcs/removeelement.c funcs/helpers.c funcs/longcommonprefix.c funcs/multiplystrings.c funcs/removeNthFromEnd.c funcs/ishappynum.c funcs/sorts.c funcs/removeDupes.c funcs/spiralorder.c funcs/searches.c funcs/twosum.c
leetcode_HEADERS = headers/ishappynum.h headers/isSorted.h headers/removeNthFromEnd.h headers/longcommonprefix.h headers/mergestrings.h headers/sorts.h headers/multiplystrings.h headers/findball.h headers/removeDupes.h headers/removeelement.h headers/spiralorder.h headers/searches.h
leetcode_LDADD = $(LIBOBJS)
# libs to add
# leetcode_LDADD= 
# library options for inclusion in source (dynamic or static linking)
# leetcode_LDFLAGS= -static
# SUBDIRS = funcs 

## some rules to test...
# clean-local:
# 	@rm config.status configure config.log Makefile -r autom4te.cache/ aclocal.m4 compile install-sh missing Makefile.in depcomp config.guess config.h.in config.sub
#

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
