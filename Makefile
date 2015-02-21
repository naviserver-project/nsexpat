ifndef NAVISERVER
    NAVISERVER  = /usr/local/ns
endif

ifndef EXPAT
    EXPAT = /usr
endif

MOD      =  nsexpat.so
MODOBJS     =  nsexpat.o tclexpat.o
HDRS     =
MODLIBS  =  -L$(EXPAT)/lib -lexpat

CFLAGS   =  -I$(EXPAT)/include

include  $(NAVISERVER)/include/Makefile.module

nsexpat.c: check-env

.PHONY: check-env

check-env:
	@if [ "$(EXPAT)" = "" ]; then \
	    echo "** "; \
	    echo "** EXPAT variable not set."; \
	    echo "** expat.so will not be built."; \
	    echo "** Usage: make EXPAT=/path/to/expat"; \
	    echo "** Usage: make install EXPAT=/path/to/expat INST=/path/to/aolserver"; \
	    echo "** "; \
	    exit 1; \
	fi

