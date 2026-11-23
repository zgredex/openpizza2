#!/bin/sh
# Build the readable source port as a 32-bit Windows PE.
# Compilation proves structural integration, not behavioral equivalence.
set -eu
cd "$(dirname "$0")"
OUT=${OUT:-build}
CXX=${CXX:-clang++}
LINK=${LINK:-lld-link}
mkdir -p "$OUT"
for f in src/*.cpp stubs/*.cpp; do
    obj="$OUT/$(basename "$f" .cpp).obj"
    "$CXX" --target=i686-windows-gnu -std=c++17 -ffreestanding \
        -fno-exceptions -fno-rtti -fno-stack-protector \
        -fno-asynchronous-unwind-tables -mno-stack-arg-probe -w \
        -Iinclude -c "$f" -o "$obj"
done
"$LINK" /entry:main /subsystem:console /nodefaultlib /out:"$OUT/pc2_port.exe" "$OUT"/*.obj
file "$OUT/pc2_port.exe"
