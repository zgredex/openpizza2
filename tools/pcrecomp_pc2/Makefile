CC ?= gcc
PC ?= /tmp/opencode/pcrecomp-pc2/pcrecomp
GEN ?= /tmp/opencode/pcrecomp-pc2/gen
SYS ?= /tmp/opencode/pcrecomp-pc2/sysroot32
OUT ?= pc2
OBJ_DIR ?= obj
CAPTURE ?= 0

CFLAGS := -m32 -O0 -w -no-pie -D_GNU_SOURCE \
          -I$(PC)/runtime/win32hle -I$(PC)/runtime/recomp32 -I$(GEN) -I$(SYS)/include \
          -include $(GEN)/recomp_funcs.h
LDFLAGS := -m32 -no-pie -Wl,--wrap=sub_00403D90
LIBS := -L$(SYS)/lib -lSDL2_ttf -lSDL2 -lpthread -lm -ldl

HLE_SRC := $(filter-out %_selftest.c,$(wildcard $(PC)/runtime/win32hle/*.c))
GEN_SRC := $(wildcard $(GEN)/recomp_*.c)
SRC := $(HLE_SRC) $(GEN_SRC) main.c pc2_shims.c trace_winmain.c
ifeq ($(CAPTURE),1)
SRC := $(filter-out $(PC)/runtime/win32hle/host_lite.c,$(SRC)) $(GEN)/host_lite.c capture.c
CFLAGS += -DPC2_CAPTURE -I. -MMD -MP
endif
OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) $(LIBS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(OUT)

ifeq ($(CAPTURE),1)
-include $(OBJ:.o=.d)
endif

.PHONY: all clean
