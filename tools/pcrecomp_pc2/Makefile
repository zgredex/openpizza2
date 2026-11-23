CC ?= gcc
PC ?= /tmp/opencode/pcrecomp-pc2/pcrecomp
GEN ?= /tmp/opencode/pcrecomp-pc2/gen
SYS ?= /tmp/opencode/pcrecomp-pc2/sysroot32
VULKAN ?= /tmp/opencode/pcrecomp-pc2/vulkan-headers
FFMPEG32 ?= /tmp/opencode/pcrecomp-pc2/ffmpeg32
OUT ?= pc2
OBJ_DIR ?= obj
CAPTURE ?= 0

CFLAGS := -m32 -O0 -w -no-pie -D_GNU_SOURCE \
          -I$(PC)/runtime/win32hle -I$(PC)/runtime/recomp32 -I$(GEN) -I$(SYS)/include \
          -I$(VULKAN)/include -I$(FFMPEG32)/include -Inative_vk -I. -I$(OBJ_DIR) \
          -include $(GEN)/recomp_funcs.h
LDFLAGS := -m32 -no-pie -Wl,--wrap=sub_00403D90
SDL_LIBS := $(SYS)/lib/libSDL2_ttf.a $(SYS)/lib/libfreetype.a $(SYS)/lib/libSDL2.a
LIBS := $(SDL_LIBS) -L$(FFMPEG32)/lib -lavformat -lavcodec -lswscale -lswresample -lavutil -L/usr/lib32 -lvulkan -lpthread -lm -ldl

HLE_SRC := $(filter-out %_selftest.c %/screen.c %/bink.c,$(wildcard $(PC)/runtime/win32hle/*.c))
GEN_SRC := $(wildcard $(GEN)/recomp_*.c)
SRC := $(HLE_SRC) $(GEN_SRC) main.c pc2_shims.c pc2_vulkan.c pc2_native_movie.c native_vk/pc2_movie.c native_vk/pc2_vk.c trace_winmain.c
ifeq ($(CAPTURE),1)
SRC := $(filter-out $(PC)/runtime/win32hle/host_lite.c,$(SRC)) $(GEN)/host_lite.c capture.c
CFLAGS += -DPC2_CAPTURE -I. -MMD -MP
endif
OBJ := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(OUT)

$(OUT): $(OBJ) Makefile $(SDL_LIBS)
	$(CC) $(LDFLAGS) $(OBJ) $(LIBS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

SPV_HEADERS := $(OBJ_DIR)/pc2_present_vert.h $(OBJ_DIR)/pc2_present_frag.h

$(OBJ_DIR)/pc2_present_vert.h: pc2_present.vert
	@mkdir -p $(dir $@)
	glslangValidator -V --vn pc2_present_vert_spv -o $@ $<

$(OBJ_DIR)/pc2_present_frag.h: pc2_present.frag
	@mkdir -p $(dir $@)
	glslangValidator -V --vn pc2_present_frag_spv -o $@ $<

$(OBJ_DIR)/pc2_vulkan.o: $(SPV_HEADERS) pc2_vulkan.c pc2_vulkan.h

clean:
	rm -rf $(OBJ_DIR) $(OUT)

ifeq ($(CAPTURE),1)
-include $(OBJ:.o=.d)
endif

.PHONY: all clean
