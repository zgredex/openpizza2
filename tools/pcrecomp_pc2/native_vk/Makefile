# Standalone native Vulkan sprite + FFmpeg Bink implementation smoke build.
# Use `make` for the host architecture, `make CC='gcc -m32'` with all i686 dev
# libraries for the current static-recompiled 32-bit engine architecture.
CC ?= cc
GLSLC ?= glslc
PKG_CONFIG ?= pkg-config
PKGS = sdl2 vulkan libavformat libavcodec libavutil libswscale libswresample
CFLAGS += -std=c11 -O2 -Wall -Wextra -Wno-missing-field-initializers $(shell $(PKG_CONFIG) --cflags $(PKGS))
LDFLAGS += $(shell $(PKG_CONFIG) --libs $(PKGS)) -lm
SHADERS = shaders/quad.vert.spv shaders/quad.frag.spv

all: $(SHADERS) smoke

shaders/%.vert.spv: shaders/%.vert
	$(GLSLC) -fshader-stage=vert $< -o $@
shaders/%.frag.spv: shaders/%.frag
	$(GLSLC) -fshader-stage=frag $< -o $@

smoke: smoke.c pc2_vk.c pc2_movie.c pc2_vk.h pc2_movie.h $(SHADERS)
	$(CC) $(CFLAGS) -o $@ smoke.c pc2_vk.c pc2_movie.c $(LDFLAGS)

clean:
	rm -f smoke $(SHADERS)
.PHONY: all clean
