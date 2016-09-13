#
include ../makedefs

PGM = test-lua

OBJS = main.o Account.o LuaState.o State.o

CPPFLAGS += -I../lua-5.3.3

LDFLAGS += -L../lib -llua

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
