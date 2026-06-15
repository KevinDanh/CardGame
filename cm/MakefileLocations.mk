ROOT     := $(shell git rev-parse --show-toplevel)

# COMMON LIBRARIES 
COMMON         := $(ROOT)/common
COMMON_BUILD := $(COMMON)/build
COMMON_LIB := $(COMMON_BUILD)/libcommon.a

# GAMES
CARDGAME := $(ROOT)/cardgame