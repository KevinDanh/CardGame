include ../cm/MakefileRules.mk
include ../cm/MakefileLocations.mk
.PHONY: all debug

BUILD   ?= $(CURDIR)/build
TARGET  := $(BUILD)/cardgame.exe
SRCS    := main.cpp CardGame.cpp
OBJS    := $(patsubst %.cpp, $(BUILD)/%.o, $(SRCS))
DEPS    := $(patsubst %.cpp, $(BUILD)/%.d, $(SRCS)) 

CXXFLAGS += -I$(COMMON)
LDFLAGS += -L$(COMMON_BUILD)
LDLIBS  += -lcommon

all: $(TARGET)

$(TARGET): $(OBJS) $(COMMON_LIB)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(BUILD)/%.o : %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
-include $(DEPS)

$(COMMON_LIB):
	$(MAKE) -C $(COMMON)

debug: CXXFLAGS += -g -O0 -DDEBUG
debug: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS) $(DEPS) $(BUILD)