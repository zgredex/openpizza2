#!/bin/sh
# Build a minimal 32-bit FFmpeg with only the Bink video path, for the
# 32-bit recovered-game host. The 64-bit system FFmpeg cannot be linked into
# the i686 ELF, so the movie decoder needs its own private build.
set -eu

PREFIX=${1:-${PC2_WORK:-/tmp/opencode/pcrecomp-pc2}/ffmpeg32}
WORK=${PC2_WORK:-/tmp/opencode/pcrecomp-pc2}
VERSION=7.1
TARBALL="$WORK/ffmpeg-$VERSION.tar.xz"
SOURCE="$WORK/ffmpeg-$VERSION"
URL="https://ffmpeg.org/releases/ffmpeg-$VERSION.tar.xz"
SHA256=40973d44970dbc83ef302b0609f2e74982be2d85916dd2ee7472d30678a7abe6

if [ -f "$PREFIX/lib/libavcodec.a" ]; then
    exit 0
fi

mkdir -p "$WORK"
if [ ! -f "$TARBALL" ]; then
    command -v curl >/dev/null 2>&1 || { echo "missing curl" >&2; exit 1; }
    curl -fL "$URL" -o "$TARBALL"
fi
echo "$SHA256  $TARBALL" | sha256sum -c -
if [ ! -d "$SOURCE" ]; then
    tar -C "$WORK" -xf "$TARBALL"
fi

cd "$SOURCE"
./configure --prefix="$PREFIX" \
    --arch=x86 --target-os=linux \
    --cc='gcc -m32' --cxx='g++ -m32' --ld='gcc -m32' \
    --disable-x86asm --disable-everything --disable-programs --disable-doc \
    --disable-network --disable-autodetect --disable-zlib --disable-bzlib \
    --disable-lzma --disable-iconv --disable-sdl2 --disable-xlib \
    --disable-vaapi --disable-vdpau --disable-vulkan \
    --enable-static --disable-shared \
    --enable-protocol=file --enable-demuxer=bink --enable-decoder=bink \
    > "$WORK/ffmpeg32-configure.log" 2>&1
make -j "${JOBS:-$(nproc)}" > "$WORK/ffmpeg32-build.log" 2>&1
make install > "$WORK/ffmpeg32-install.log" 2>&1
echo "built 32-bit FFmpeg Bink decoder in $PREFIX"
