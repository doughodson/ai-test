#
include ../makedefs

PGM = luac

OBJS = luac.o

CPPFLAGS += -I../lua-5.3.3

LDFLAGS += -L../lib -llua

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
