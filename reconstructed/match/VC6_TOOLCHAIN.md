# Pinned MSVC 6.0 SP3 toolchain

PC2 uses the [VC6 SP3 checkout at `1524047fc7e0bd9f94ff3f6b23aa1269e88cbea0`](https://github.com/zach2good/vc6-sp3-toolchain/tree/1524047fc7e0bd9f94ff3f6b23aa1269e88cbea0).
This tree has `CL.EXE` 12.00.8168, `C1.DLL` and `C1XX.DLL` 12.00.8472, `C2.DLL`
12.00.8447, and `LINK.EXE` 6.00.8447. Use the commit and checksums below when
restoring the tree for byte matching.

## Restore and verify

Run the following from the repository root with Git, Python 3, and `sha256sum`.
The install directory is under your persistent user data directory. The clone
runs only when the directory is missing. If an existing directory fails the
checks, move it aside and run this block again.

```sh
vc6_root="${XDG_DATA_HOME:-$HOME/.local/share}/pc2/vc6-sp3-toolchain"
vc6_revision=1524047fc7e0bd9f94ff3f6b23aa1269e88cbea0
(
  set -eu
  if [ ! -e "$vc6_root" ]; then
    mkdir -p "$(dirname "$vc6_root")"
    git -c core.autocrlf=false clone --depth 1 --revision="$vc6_revision" \
      https://github.com/zach2good/vc6-sp3-toolchain.git "$vc6_root"
  fi
  test "$(git -C "$vc6_root" rev-parse HEAD)" = "$vc6_revision"
  cd "$vc6_root"
  sha256sum --check <<'SHA256'
67743d7275a83c90159c4b9f916541d1fb857acac943d78b464d32691c0035d4  MANIFEST.sha256
06c503d58d5a51361042c7fefc52e198329f2c327dde76ef47a8e9587ecae5e0  tools/verify.py
SHA256
  python3 -B tools/verify.py --all
)
```

Expect `2595 of 2595 files agree with the manifest`. This checks the binaries,
headers, and libraries. The clone uses `--revision` (Git 2.49 or newer).
With older Git, initialize the directory with `git init "$vc6_root"`, then
fetch and check out the same revision before running the verification block.

```sh
git -C "$vc6_root" fetch --depth 1 \
  https://github.com/zach2good/vc6-sp3-toolchain.git "$vc6_revision"
git -C "$vc6_root" -c core.autocrlf=false checkout --detach "$vc6_revision"
```

## Instructions for coding agents

1. Verify a new or restored tree with the block above. Matching tools default to
   `$vc6_root/VC98` when `PC2_VC6` is unset. If using another verified location,
   export `PC2_VC6` as its absolute `VC98` directory (the one containing `BIN`,
   `INCLUDE`, and `LIB`). `match_decomp.py --vc6` overrides the environment for
   one invocation.
2. From the PC2 repository root, run `sh reconstructed/match/runtime01/verify_strict.sh`.
   It needs Wine with 32-bit Windows support and the original `game/fastfood2.exe`.
   Expect `strict matches: 6/6`. If Wine cannot start inside the sandbox, retry
   the smoke command with permission to run outside it. Fix setup failures
   before changing candidates or compiler flags.
3. Reuse the recorded address, C/C++ entry symbol, length, and flags for each
   function. Use `tools/match_decomp.py --strict --auto-symbols` as shown below.
   Count a result once it reports `"strict_match": true`.
4. For stock CRT recovery, run `python3 tools/match_crt_archive.py --stock`.
   It checks the six archive SHA-256 pins and runs without Wine. Expect 71
   verified addresses with the project's original executable.

```sh
python3 tools/match_decomp.py 0x551944 reconstructed/match/runtime01/0x551944.c \
  --length 13 --entry _CRT_GetVaArg --flags /O1 --strict --auto-symbols
```

Keep toolchain files in the user data directory and commit PC2 source and
matching evidence to the project repository.
