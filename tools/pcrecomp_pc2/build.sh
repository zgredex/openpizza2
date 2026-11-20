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

EXE_SHA256=18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd
PCRECOMP_REPO=https://github.com/sp00nznet/pcrecomp.git
PCRECOMP_COMMIT=621860a9d22c9b25ae2be4575b956596f4ddaeeb

SDL2_VERSION=2.30.9
SDL2_URL="https://github.com/libsdl-org/SDL/releases/download/release-${SDL2_VERSION}/SDL2-${SDL2_VERSION}.tar.gz"
SDL2_SHA256=24b574f71c87a763f50704bbb630cbe38298d544a1f890f099a4696b1d6beba4

SDL2TTF_VERSION=2.22.0
SDL2TTF_URL="https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL2TTF_VERSION}/SDL2_ttf-${SDL2TTF_VERSION}.tar.gz"
SDL2TTF_SHA256=d48cbd1ce475b9e178206bf3b72d56b66d84d44f64ac05803328396234d67723

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

actual=$(sha256sum "$EXE" | cut -d' ' -f1)
if [ "$actual" != "$EXE_SHA256" ]; then
    echo "fastfood2.exe SHA-256 mismatch: $actual" >&2
    exit 1
fi

mkdir -p "$WORK/src" "$WORK/sysroot32"

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

if [ ! -f "$SYS/lib/libSDL2.a" ]; then
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
        -DSDL_X11=ON -DSDL_WAYLAND=OFF \
        -DSDL_ALSA=OFF -DSDL_PULSEAUDIO=OFF -DSDL_JACK=OFF -DSDL_ESD=OFF -DSDL_NAS=OFF \
        -DSDL_PIPEWIRE=OFF -DSDL_SNDIO=OFF -DSDL_DSP=OFF \
        -DSDL_DISKAUDIO=ON -DSDL_DUMMYAUDIO=ON \
        -DSDL_DBUS=OFF -DSDL_IBUS=OFF -DSDL_LIBUDEV=OFF \
        -DSDL_OPENGL=OFF -DSDL_VULKAN=OFF -DSDL_RPATH=OFF > "$WORK/sdl2-configure.log" 2>&1
    cmake --build "$WORK/src/SDL2-build32" -j "${JOBS:-4}" > "$WORK/sdl2-build.log" 2>&1
    cmake --install "$WORK/src/SDL2-build32" > "$WORK/sdl2-install.log" 2>&1
fi

if [ ! -f "$SYS/lib/libSDL2_ttf.so" ]; then
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
        -DSDL2TTF_VENDORED=ON -DSDL2TTF_HARFBUZZ=OFF \
        -DSDL2TTF_SAMPLES=OFF -DSDL2TTF_TESTS=OFF > "$WORK/ttf-configure.log" 2>&1
    cmake --build "$WORK/src/SDL2_ttf-build32" -j "${JOBS:-4}" > "$WORK/ttf-build.log" 2>&1
    cmake --install "$WORK/src/SDL2_ttf-build32" > "$WORK/ttf-install.log" 2>&1
fi

if [ ! -f "$GEN/recomp_dispatch.c" ]; then
    (cd "$PC" && "$VENV/bin/python" -m tools "$EXE" --all --output "$GEN") > "$WORK/lift.log" 2>&1
    tail -8 "$WORK/lift.log"
fi

mkdir -p "$HOSTDIR"
make -C "$REPO_ROOT/tools/pcrecomp_pc2" \
    PC="$PC" GEN="$GEN" SYS="$SYS" \
    OUT="$HOSTDIR/pc2" OBJ_DIR="$HOSTDIR/obj" \
    -j "${JOBS:-4}" > "$WORK/host-build.log" 2>&1

set +e
(cd "$REPO_ROOT/game" && \
    LD_LIBRARY_PATH="$SYS/lib" SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy \
    PC2_HEADLESS=1 HLE_FILETRACE=1 timeout "${PC2_TIMEOUT:-15}" \
    "$HOSTDIR/pc2" fastfood2.exe) > "$WORK/trace.log" 2>&1
status=$?
set -e

if [ "$status" -ne 0 ] && [ "$status" -ne 124 ]; then
    echo "native run failed with status $status" >&2
    tail -40 "$WORK/trace.log" >&2
    exit 1
fi

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

echo "native bring-up: OK"
grep -E "\[host\]|\[trace\]|\[file\].*(\.ldf|\.pak)" "$WORK/trace.log" | head -20
