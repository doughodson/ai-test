#
include ../makedefs

PGM = repl

OBJS = main.o

CPPFLAGS += -I../clips-6.30

LDFLAGS += -L../lib -lclips

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)

