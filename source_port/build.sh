#!/bin/sh
# Build the readable source port as a 32-bit Windows PE.
# Compilation proves structural integration, not behavioral equivalence.
# /force:unresolved is a temporary link scaffold for not-yet-recovered externals.
set -eu
cd "$(dirname "$0")"
OUT=${OUT:-build}
CC=${CC:-clang}
LINK=${LINK:-lld-link}
mkdir -p "$OUT"
for f in src/*.c src/*.cpp stubs/*.c; do
    [ -e "$f" ] || continue
    obj="$OUT/$(basename "$f" | sed 's/\.[^.]*$//').obj"
    "$CC" --target=i686-windows-gnu -x c -std=gnu99 -ffreestanding \
        -fno-stack-protector -fno-asynchronous-unwind-tables \
        -mno-stack-arg-probe -w -Wno-int-conversion \
        -Wno-implicit-function-declaration -Wno-incompatible-pointer-types -Wno-pointer-arith -Iinclude -c "$f" -o "$obj"
done
"$LINK" /entry:main /subsystem:console /nodefaultlib /force:unresolved /force:multiple \
    /out:"$OUT/pc2_port.exe" "$OUT"/*.obj
file "$OUT/pc2_port.exe"
