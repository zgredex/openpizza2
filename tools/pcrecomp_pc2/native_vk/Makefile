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

# Optional X11 readback test; it only needs the 2D renderer's dependencies.
QUAD_TEST_CFLAGS ?= $(shell $(PKG_CONFIG) --cflags sdl2 vulkan x11)
QUAD_TEST_LIBS ?= $(shell $(PKG_CONFIG) --libs sdl2 vulkan x11) -lm
source-quad-smoke: source_quad_smoke.c pc2_vk.c pc2_vk.h pc2_sprite_decode.c pc2_sprite_decode.h $(SHADERS)
	$(CC) $(CPPFLAGS) -std=c11 -O2 -Wall -Wextra $(QUAD_TEST_CFLAGS) -o $@ \
		source_quad_smoke.c pc2_vk.c pc2_sprite_decode.c $(QUAD_TEST_LIBS)

check-source-quads: source-quad-smoke
	./source-quad-smoke

TARGET_TEST_CFLAGS ?= $(shell $(PKG_CONFIG) --cflags sdl2 vulkan)
TARGET_TEST_LIBS ?= $(shell $(PKG_CONFIG) --libs sdl2 vulkan) -lm
indexed-target-test: indexed_target_test.c pc2_vk.c pc2_vk.h pc2_sprite_decode.c pc2_sprite_decode.h $(SHADERS)
	$(CC) $(CPPFLAGS) -std=c11 -O2 -Wall -Wextra $(TARGET_TEST_CFLAGS) -o $@ \
		indexed_target_test.c pc2_vk.c pc2_sprite_decode.c $(TARGET_TEST_LIBS)

sprite-decode-test: sprite_decode_test.c pc2_sprite_decode.c pc2_sprite_decode.h
	$(CC) $(CPPFLAGS) -std=c11 -O2 -Wall -Wextra -o $@ sprite_decode_test.c pc2_sprite_decode.c

check-sprite-decode: sprite-decode-test
	./sprite-decode-test

clean:
	rm -f smoke source-quad-smoke sprite-decode-test indexed-target-test $(SHADERS)
.PHONY: all clean check-source-quads check-sprite-decode
