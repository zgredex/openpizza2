# Game_Construct animation pilot at `0x4e64c0`

The 14,505-byte constructor includes 159 calls to `Anim_Load` at `0x532c40`. The generator validates each exported row against the original PE. It checks the preceding `0x98` allocation, ECX receiver, five stack arguments, exact asset address and filename, and destination offset. All rows pass mode `1` and a stack status output. The constructor callee confirms `ret 0x14`. One destination uses an ESI alias of the game object field at `+0x2c00c`.

```sh
python reconstructed/match/investigations/0x4e64c0/animation_pilot.py \
  --out /tmp/pc2-game-animation-compile --compile
```

Use Capstone 5.0.7 and the [pinned VC6 SP3 toolchain](../../VC6_TOOLCHAIN.md). Without `--compile`, the tool emits all 159 typed `new Animation` rows and the PE evidence in the scratch directory. The emitted rows mark 38 places where other startup code intervenes.

The first 16 contiguous rows compiled with `/O2 /GX /TP`. The resulting COFF has 1,260 reachable primary code bytes and preserves all 16 allocation, constructor and destination sequences in the 1,287-byte reference span `[0x4e67b0, 0x4e6cb7)`. The verifier resolves the COFF call, asset and graphics references to independently known addresses. This slice contributes zero strict bytes for the complete constructor.

The original EH handler at `0x559e3d` is independently bracketed by the handlers of `0x4e4930` and `0x4e9e30`. Its `FuncInfo` is at `0x55f108` with 163 states. States 4 through 162 correspond to these animation allocations. The 16-row slice has its own EH sections. The final x87 block at `0x4e9d25` computes `(int)(2.0 * sqrt((double)(0x400000 - i*i)))` for `i` from 0 through 2,047 and writes the table at `this + 0x2c4f4`.

## Full constructor candidate

The full candidate adds the startup sprite loads, table setup, 38 interleaved updates, final slot registration, and x87 calculation. The embedded list constructor and three sprite allocations account for EH states 0–3. The generator uses the same PE-verified 159 animation rows as the slice.

```sh
python reconstructed/match/investigations/0x4e64c0/game_construct.py \
  --out /tmp/pc2-game-construct-new --compile
```

Use a fresh output directory. Pass `--object /path/to/game_construct.obj` in place of `--compile` to check an existing COFF object without starting Wine. The generator writes the C++ source and three JSON reports. `report.json` summarizes both checks, `unwind.json` lists the state comparisons and linked EH bytes, and `strict.json` is the standard matcher receipt.

- The pinned VC6 SP3 build with `/O2 /GX /TP` emitted 14,464 primary bytes against 14,505 in the original. All 345 direct calls resolve in the original order, and the 159 animation rows match their allocation size, receiver, constructor arguments, and destination slots.
- All 163 EH predecessors and cleanup transfers match. After resolving COFF relocations, all 1,336 bytes of `.xdata$x` match. The 2,295-byte `.text$x` differs at one byte, `0x559552`, where the state 0 cleanup loads `this` from `[ebp-0x134]` instead of `[ebp-0x114]`. States 1–162 agree on the saved allocation at `[ebp-0x170]`.
- The first primary-code difference is at `0x4e64dd`. The candidate reserves `0x16c` stack bytes and the original reserves `0x164`. The next compiler experiment should target local lifetimes and stack-slot reuse around sprite names, point temporaries, and the saved receiver. The strict function match is still false.

## VC6 source-shape matrix

The first ten variants compiled with `/O2 /GX /TP`. They narrowed the sprite-name buffer scope, delayed the point temporaries or coordinate table, split the sprite and animation status locals, reordered declarations, used a typed archive member or graphics argument, and combined those changes. Nine produced byte-identical primary sections compared with the compiled baseline. Splitting status changed 26 raw primary bytes outside the measured animation spans.

All ten preserved the 345 ordered direct calls, 159 validated animation rows, and 163 unwind states. They retained the baseline's exact 1,336-byte unwind table and one differing cleanup byte. After aligning each animation span by its allocation and rebasing relocations, all candidates scored **151 equal-length spans, zero exact spans, and a median of 18 differing bytes** among the equal-length spans. Each reserved `0x16c` bytes and saved `this` at `[esp+0x50]` in the prologue. The original uses `0x164` and `[esp+0x68]` at the same point.

Two additional variants introduced block-local graphics, archive, and status-pointer variables immediately before each animation allocation. One evaluated graphics before archive and the other reversed the order. Both compiled with the same frame and unwind result. Both moved the graphics and archive loads ahead of `operator new`, whereas the original performs both reads after allocation in the non-null branch. The animation verifier rejected both variants at their first constructor call, offset `0x2ff`. The baseline remains the best verified source.


## Matcher pass: name-buffer and frame closure

Using the matching-decomp loop, the 260-byte `spriteName` buffer was tested
against the original frame. The original reserves `0x164` bytes; the baseline
generator reserved `0x16c`. A 256-byte name buffer reproduces the original
frame and moves the first primary difference from `0x4e64dd` to the saved
`this` home at `0x4e64e8`:

```text
original   sub esp,0x164   mov [esp+0x68],ebx   lea [esp+0x70],spriteName
candidate  sub esp,0x164   mov [esp+0x4c],ebx   lea [esp+0x74],spriteName
```

Primary differing bytes drop from 11,432 to 10,963. All 345 direct calls,
159 animation rows and 163 unwind states remain intact. Declaration-order
permutations of the four locals do not move the `this` home. The remaining
wall is the original's early coordinate-array materialization and its stack
slot ordering; the candidate sinks the coordinate stores to the later
`SetPointPairs` loop. The EH `.text$x` cleanup byte and `$L...` section
verification remain separate open items.
