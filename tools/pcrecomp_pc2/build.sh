#!/usr/bin/env bash
# Reproducible native-Linux bring-up for Pizza Connection 2's static
# recompilation. No sudo, no game files in the repository.
set -euo pipefail

REPO_ROOT=$(cd "$(dirname "$0")/../.." && pwd)
WORK=${PC2_WORK:-/tmp/opencode/pcrecomp-pc2}
PC="$WORK/pcrecomp"
GEN="$WORK/gen"
SYS="$WORK/sysroot32"
HOSTDIR="$WORK/pc2-native"
EXE="$REPO_ROOT/game/fastfood2.exe"
LIFT_DRIVER="$REPO_ROOT/tools/pcrecomp_pc2/lift.py"
FRAME_DUMP="${PC2_FRAME_DUMP:-}"
DDBLT_TRACE="${PC2_TRACE_DDBLT:-}"

EXE_SHA256=18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd
PCRECOMP_REPO=https://github.com/sp00nznet/pcrecomp.git
PCRECOMP_COMMIT=621860a9d22c9b25ae2be4575b956596f4ddaeeb

SDL2_VERSION=2.30.9
SDL2_URL="https://github.com/libsdl-org/SDL/releases/download/release-${SDL2_VERSION}/SDL2-${SDL2_VERSION}.tar.gz"
SDL2_SHA256=24b574f71c87a763f50704bbb630cbe38298d544a1f890f099a4696b1d6beba4

SDL2TTF_VERSION=2.22.0
SDL2TTF_URL="https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL2TTF_VERSION}/SDL2_ttf-${SDL2TTF_VERSION}.tar.gz"
SDL2TTF_SHA256=d48cbd1ce475b9e178206bf3b72d56b66d84d44f64ac05803328396234d67723

VULKAN_TAG=vulkan-sdk-1.4.363.0
VULKAN_URL="https://github.com/KhronosGroup/Vulkan-Headers/archive/refs/tags/${VULKAN_TAG}.tar.gz"
VULKAN_SHA256=4a078be12bef21cfebc09d878b77a63cff9d68f899254a0b00d0e37ef73e7f7e
VULKAN="$WORK/vulkan-headers"
FFMPEG32="$WORK/ffmpeg32"

need() {
    command -v "$1" >/dev/null 2>&1 || { echo "missing required tool: $1" >&2; exit 1; }
}

need git
need gcc
need cmake
need ninja
need python3
need curl
need sha256sum
need tar
need make
need glslangValidator
need pkg-config
need wayland-scanner

actual=$(sha256sum "$EXE" | cut -d' ' -f1)
if [ "$actual" != "$EXE_SHA256" ]; then
    echo "fastfood2.exe SHA-256 mismatch: $actual" >&2
    exit 1
fi

mkdir -p "$WORK/src" "$WORK/sysroot32"

if [ ! -f "$VULKAN/include/vulkan/vulkan.h" ]; then
    if [ ! -f "$WORK/Vulkan-Headers-${VULKAN_TAG}.tar.gz" ]; then
        curl -fL "$VULKAN_URL" -o "$WORK/Vulkan-Headers-${VULKAN_TAG}.tar.gz"
    fi
    echo "$VULKAN_SHA256  $WORK/Vulkan-Headers-${VULKAN_TAG}.tar.gz" | sha256sum -c -
    mkdir -p "$VULKAN"
    tar -C "$VULKAN" -xf "$WORK/Vulkan-Headers-${VULKAN_TAG}.tar.gz" --strip-components=1
fi

if [ ! -d "$PC/.git" ]; then
    git clone "$PCRECOMP_REPO" "$PC"
fi
if [ "$(git -C "$PC" rev-parse HEAD)" != "$PCRECOMP_COMMIT" ]; then
    git -C "$PC" fetch --depth 1 origin "$PCRECOMP_COMMIT" 2>/dev/null || true
    git -C "$PC" checkout -f "$PCRECOMP_COMMIT"
fi
if ! git -C "$PC" diff --quiet; then
    echo "pcrecomp has tracked local changes; use a clean PC2_WORK" >&2
    exit 1
fi

VENV="$WORK/venv"
if [ ! -x "$VENV/bin/python" ]; then
    python3 -m venv "$VENV"
fi
if ! "$VENV/bin/python" -c 'import capstone, pefile, unicorn' >/dev/null 2>&1; then
    "$VENV/bin/pip" -q install --upgrade pip
    "$VENV/bin/pip" -q install capstone==5.0.7 pefile==2024.8.26 unicorn==2.1.4
fi

SDL2_CONFIG="x11=on wayland=shared libdecor=off vulkan=on alsa=off pulseaudio=off pipewire=off"
SDL2_STAMP="$SYS/lib/.pc2-sdl2-config"
if [ ! -f "$SYS/lib/libSDL2.a" ] || [ "$(cat "$SDL2_STAMP" 2>/dev/null || true)" != "$SDL2_CONFIG" ]; then
    rm -rf "$WORK/src/SDL2-build32"
    rm -f "$SYS/lib/libSDL2.a" "$SYS/lib/libSDL2main.a" "$SDL2_STAMP"
    if [ ! -f "$WORK/SDL2-${SDL2_VERSION}.tar.gz" ]; then
        curl -fL "$SDL2_URL" -o "$WORK/SDL2-${SDL2_VERSION}.tar.gz"
    fi
    echo "$SDL2_SHA256  $WORK/SDL2-${SDL2_VERSION}.tar.gz" | sha256sum -c -
    tar -C "$WORK/src" -xf "$WORK/SDL2-${SDL2_VERSION}.tar.gz"
    cmake -S "$WORK/src/SDL2-${SDL2_VERSION}" -B "$WORK/src/SDL2-build32" -G Ninja \
        -DCMAKE_INSTALL_PREFIX="$SYS" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 \
        -DCMAKE_EXE_LINKER_FLAGS=-m32 -DCMAKE_SHARED_LINKER_FLAGS=-m32 \
        -DSDL_SHARED=OFF -DSDL_STATIC=ON -DSDL_TEST=OFF -DSDL_TESTS=OFF \
        -DSDL_X11=ON -DSDL_WAYLAND=ON -DSDL_WAYLAND_SHARED=ON -DSDL_WAYLAND_LIBDECOR=OFF \
        -DSDL_VULKAN=ON -DVulkan_INCLUDE_DIR="$VULKAN/include" -DVulkan_LIBRARY=/usr/lib32/libvulkan.so \
        -DSDL_ALSA=OFF -DSDL_PULSEAUDIO=OFF -DSDL_JACK=OFF -DSDL_ESD=OFF -DSDL_NAS=OFF \
        -DSDL_PIPEWIRE=OFF -DSDL_SNDIO=OFF -DSDL_DSP=OFF \
        -DSDL_DISKAUDIO=ON -DSDL_DUMMYAUDIO=ON \
        -DSDL_DBUS=OFF -DSDL_IBUS=OFF -DSDL_LIBUDEV=OFF \
        -DSDL_OPENGL=OFF -DSDL_RPATH=OFF > "$WORK/sdl2-configure.log" 2>&1
    if ! grep -q '^#define SDL_VIDEO_DRIVER_WAYLAND_DYNAMIC ' \
        "$WORK/src/SDL2-build32/include-config-release/SDL2/SDL_config.h"; then
        echo "SDL2 did not configure its dynamic Wayland backend. See $WORK/sdl2-configure.log." >&2
        exit 1
    fi
    cmake --build "$WORK/src/SDL2-build32" -j "${JOBS:-4}" > "$WORK/sdl2-build.log" 2>&1
    cmake --install "$WORK/src/SDL2-build32" > "$WORK/sdl2-install.log" 2>&1
    echo "$SDL2_CONFIG" > "$SDL2_STAMP"
fi

SDL2TTF_STAMP="$SYS/lib/.pc2-sdl2-ttf-config"
SDL2TTF_CONFIG="$SDL2_CONFIG ttf=static freetype=vendored"
if [ ! -f "$SYS/lib/libSDL2_ttf.a" ] || [ ! -f "$SYS/lib/libfreetype.a" ] || \
    [ "$(cat "$SDL2TTF_STAMP" 2>/dev/null || true)" != "$SDL2TTF_CONFIG" ]; then
    if [ ! -f "$WORK/SDL2_ttf-${SDL2TTF_VERSION}.tar.gz" ]; then
        curl -fL "$SDL2TTF_URL" -o "$WORK/SDL2_ttf-${SDL2TTF_VERSION}.tar.gz"
    fi
    echo "$SDL2TTF_SHA256  $WORK/SDL2_ttf-${SDL2TTF_VERSION}.tar.gz" | sha256sum -c -
    tar -C "$WORK/src" -xf "$WORK/SDL2_ttf-${SDL2TTF_VERSION}.tar.gz"
    cmake -S "$WORK/src/SDL2_ttf-${SDL2TTF_VERSION}" -B "$WORK/src/SDL2_ttf-build32" -G Ninja \
        -DCMAKE_INSTALL_PREFIX="$SYS" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_FLAGS=-m32 -DCMAKE_CXX_FLAGS=-m32 \
        -DCMAKE_EXE_LINKER_FLAGS=-m32 -DCMAKE_SHARED_LINKER_FLAGS=-m32 \
        -DCMAKE_PREFIX_PATH="$SYS" -DCMAKE_POLICY_VERSION_MINIMUM=3.5 \
        -DBUILD_SHARED_LIBS=OFF \
        -DSDL2TTF_VENDORED=ON -DSDL2TTF_HARFBUZZ=OFF \
        -DSDL2TTF_SAMPLES=OFF -DSDL2TTF_TESTS=OFF > "$WORK/ttf-configure.log" 2>&1
    cmake --build "$WORK/src/SDL2_ttf-build32" -j "${JOBS:-4}" > "$WORK/ttf-build.log" 2>&1
    cmake --install "$WORK/src/SDL2_ttf-build32" > "$WORK/ttf-install.log" 2>&1
    echo "$SDL2TTF_CONFIG" > "$SDL2TTF_STAMP"
fi

PC2_SEEDS='0x00504980u 0x00553C9Du 0x00555F68u'
needs_lift=0
[ -f "$GEN/recomp_dispatch.c" ] || needs_lift=1
for seed in $PC2_SEEDS; do
    grep -Fq "$seed" "$GEN/recomp_dispatch.c" 2>/dev/null || needs_lift=1
done
if [ "$needs_lift" -ne 0 ]; then
    (cd "$PC" && PCRECOMP_ROOT="$PC" "$VENV/bin/python" "$LIFT_DRIVER" \
        "$EXE" --all --output "$GEN") > "$WORK/lift.log" 2>&1
    tail -12 "$WORK/lift.log"
fi
for seed in $PC2_SEEDS; do
    grep -Fq "$seed" "$GEN/recomp_dispatch.c" || {
        echo "lift: seeded function missing from dispatch: $seed" >&2
        tail -20 "$WORK/lift.log" >&2
        exit 1
    }
done

python3 "$REPO_ROOT/tools/pcrecomp_pc2/trace_points.py" "$GEN"
python3 "$REPO_ROOT/tools/pcrecomp_pc2/movie_port.py" "$GEN"
if [ ! -f "$FFMPEG32/lib/libavcodec.a" ]; then
    echo "building 32-bit FFmpeg Bink decoder..."
    sh "$REPO_ROOT/tools/pcrecomp_pc2/build_ffmpeg32.sh" "$FFMPEG32" || exit 1
fi

CAPTURE=${PC2_CAPTURE_BUILD:-0}
BUILD_LOG="$WORK/host-build.log"
if [ "$CAPTURE" = 1 ]; then
    HOSTDIR="$WORK/pc2-capture"
    python3 "$REPO_ROOT/tools/pcrecomp_pc2/instrument_capture.py" \
        "$GEN" "$PC/runtime/win32hle/host_lite.c" "$HOSTDIR/gen"
    GEN="$HOSTDIR/gen"
    BUILD_LOG="$HOSTDIR/build.log"
fi

mkdir -p "$HOSTDIR"
if ! make -C "$REPO_ROOT/tools/pcrecomp_pc2" \
    PC="$PC" GEN="$GEN" SYS="$SYS" VULKAN="$VULKAN" FFMPEG32="$FFMPEG32" CAPTURE="$CAPTURE" \
    OUT="$HOSTDIR/pc2" OBJ_DIR="$HOSTDIR/obj" \
    -j "${JOBS:-4}" > "$BUILD_LOG" 2>&1; then
    tail -40 "$BUILD_LOG" >&2
    exit 1
fi
if [ "${PC2_BUILD_ONLY:-0}" = 1 ]; then
    echo "built $HOSTDIR/pc2"
    exit 0
fi

set +e
(cd "$REPO_ROOT/game" && \
    LD_LIBRARY_PATH="$SYS/lib" SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy \
    PC2_HEADLESS=1 HLE_FILETRACE=1 PC2_TRACE_FRAMES=1 \
    PC2_TRACE_DDBLT="$DDBLT_TRACE" PC2_FRAME_DUMP="$FRAME_DUMP" \
    timeout "${PC2_TIMEOUT:-75}" \
    "$HOSTDIR/pc2" fastfood2.exe) > "$WORK/trace.log" 2>&1
status=$?
set -e

if [ "$status" -ne 0 ] && [ "$status" -ne 124 ]; then
    echo "native run failed with status $status" >&2
    tail -40 "$WORK/trace.log" >&2
    exit 1
fi
echo "run status=$status (124 = still running at the timeout)"

grep -Fq "[trace] entered WinMain at 0x00403D90" "$WORK/trace.log" || {
    echo "trace: WinMain was not reached" >&2
    tail -40 "$WORK/trace.log" >&2
    exit 1
}
for asset in language.ldf 'resources\main.pak' 'resources\iso.pak' 'resources\update.pak'; do
    grep -Fq "$asset" "$WORK/trace.log" || {
        echo "trace: asset not opened: $asset" >&2
        exit 1
    }
done
for point in '[trace] Movie_Play return' '[trace] Map_LoadIsodata return' '[trace] GameMain enter' '[trace] Screen_MainMenu enter' '[trace] GameLoop pending=21'; do
    grep -Fq "$point" "$WORK/trace.log" || {
        echo "trace: startup point not reached: $point" >&2
        tail -40 "$WORK/trace.log" >&2
        exit 1
    }
done

if [ -n "$DDBLT_TRACE" ]; then
    grep -Fq '[trace] DDBLT clip before=' "$WORK/trace.log" || {
        echo "trace: DDBLT before/after clipping was not captured" >&2
        tail -40 "$WORK/trace.log" >&2
        exit 1
    }
    grep -Fq 'hr=0x00000000 DD_OK' "$WORK/trace.log" || {
        echo "trace: DDBLT HRESULT was not captured" >&2
        tail -40 "$WORK/trace.log" >&2
        exit 1
    }
    grep -Fq 'dstsum_after=' "$WORK/trace.log" || {
        echo "trace: DDBLT post-copy destination checksum was not captured" >&2
        tail -40 "$WORK/trace.log" >&2
        exit 1
    }
fi

if [ -n "$FRAME_DUMP" ]; then
    python3 - "$FRAME_DUMP" <<'PY'
import hashlib
import sys
from pathlib import Path

path = Path(sys.argv[1])
data = path.read_bytes()
lines = data.split(b"\n", 3)
if len(lines) != 4 or lines[0] != b"P6":
    raise SystemExit("frame dump is not a P6 PPM")
w, h = map(int, lines[1].split())
pixels = lines[3]
if (w, h) != (800, 600):
    raise SystemExit(f"frame dump is {w}x{h}, expected 800x600")
if len(pixels) != w * h * 3:
    raise SystemExit("frame dump pixel count mismatch")
colors = len({pixels[i:i + 3] for i in range(0, len(pixels), 3)})
digest = hashlib.sha256(pixels).hexdigest()
expected = "1abdbb3fffaa31003b9d17fbbea7d92a0d306762095ad7fb0d45b3bcea0a6e2b"
if colors < 2:
    raise SystemExit("frame dump is a single color")
if digest != expected:
    raise SystemExit(f"frame dump is not the verified main menu (sha256={digest})")
print(f"menu frame: {w}x{h}, {colors} colors, sha256={digest}")
PY
fi

echo "native bring-up: OK"
grep -E "\[host\]|\[trace\] (entered|Movie_Play|Map_LoadIsodata|GameMain|GameLoop pending|Screen_MainMenu)|\[file\].*(\.ldf|\.pak)" "$WORK/trace.log" > "$WORK/trace.summary" || true
sed -n '1,30p' "$WORK/trace.summary"
