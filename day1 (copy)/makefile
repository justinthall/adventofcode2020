CPPFILES = $(wildcard *.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
OUT      = main

CFLAGS = -Wall
LDLIBS = -lstdc++ -lm


make: $(OBJFILES)
	g++ $(OBJFILES) -o $(OUT) $(CFLAGS) $(LDLIBS)

$(OUT): $(OBJFILES)

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT)
