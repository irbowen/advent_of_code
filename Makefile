CXXFLAGS := -Wall -Werror -Wextra -ansi -pedantic -std=c++14 

DEPS := $(wildcard *.h)

PROG = santa
OBJS = day1.o 

all: release

release: CXXFLAGS += -O3
release: $(PROG)

debug: CXXFLAGS += -g
debug: $(PROG)

clean:
	rm -f *~ *.out *.o santa

%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(PROG) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
