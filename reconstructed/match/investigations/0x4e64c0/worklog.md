# Game_Construct animation pilot at `0x4e64c0`

The 14,505-byte constructor includes 159 calls to `Anim_Load` at `0x532c40`. The generator validates each exported row against the original PE. It checks the preceding `0x98` allocation, ECX receiver, five stack arguments, exact asset address and filename, and destination offset. All rows pass mode `1` and a stack status output. The constructor callee confirms `ret 0x14`. One destination uses an ESI alias of the game object field at `+0x2c00c`.

```sh
python reconstructed/match/investigations/0x4e64c0/animation_pilot.py \
  --out /tmp/pc2-game-animation-compile --compile
```

Use Capstone 5.0.7 and the [pinned VC6 SP3 toolchain](../../VC6_TOOLCHAIN.md). Without `--compile`, the tool emits all 159 typed `new Animation` rows and the PE evidence in the scratch directory. The emitted rows mark 38 places where other startup code intervenes.

The first 16 contiguous rows compiled with `/O2 /GX /TP`. The resulting COFF has 1,260 reachable primary code bytes and preserves all 16 allocation, constructor and destination sequences in the 1,287-byte reference span `[0x4e67b0, 0x4e6cb7)`. The verifier resolves the COFF call, asset and graphics references to independently known addresses. This slice contributes zero strict bytes for the complete constructor.

The original EH handler at `0x559e3d` is independently bracketed by the handlers of `0x4e4930` and `0x4e9e30`. Its `FuncInfo` is at `0x55f108` with 163 states. States 4 through 162 correspond to these animation allocations. The 16-row slice has its own EH sections. Full-constructor code generation still needs the sprite setup, interleaved point and object updates, and the full EH state sequence. The final x87 block at `0x4e9d25` computes `(int)(2.0 * sqrt((double)(0x400000 - i*i)))` for `i` from 0 through 2,047 and writes the table at `this + 0x2c4f4`.
