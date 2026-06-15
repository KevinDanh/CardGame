ROOT    := $(shell git rev-parse --show-toplevel)
BUILD   ?= $(CURDIR)/build
include ../cm/MakefileRules.mk

LIB     := $(BUILD)/libcommon.a
SRCS    := Deck.cpp Player.cpp
OBJS    := $(patsubst %.cpp, $(BUILD)/%.o, $(SRCS))
DEPS    := $(patsubst %.cpp, $(BUILD)/%.d, $(SRCS))

$(LIB) : $(OBJS)
	mkdir -p $(dir $@)
	ar rcs $(LIB) $(OBJS)

$(BUILD)/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	rm -rf $(TARGET) $(OBJS) $(LIB) $(DEPS) $(BUILD)