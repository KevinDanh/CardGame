include MakefileRules.mk
.PHONY: all debug run

TARGET  := cardgame.exe
SRCS    := main.cpp CardGame.cpp
OBJS    := $(SRCS:.cpp=.o)
DEPS    := $(SRCS:.cpp=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
-include $(DEPS)

debug: CXXFLAGS += -g -O0 -DDEBUG
debug: $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)