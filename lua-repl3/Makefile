#
include ../makedefs

PGM = repl
#CPPFLAGS += -DLUA_COMPAT_MODULE

OBJS = main.o mylib.o

CPPFLAGS += -I../lua-5.3.3

LDFLAGS += -L../lib -llua

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
