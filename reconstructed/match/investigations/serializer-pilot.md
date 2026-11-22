# VC6 serializer pilot

`tools/verify_serializer_pilot.py` generates scratch C++ from eight named exports using a shared stream and collaborator ABI. The generator checks the ordered direct calls and callee cleanup against the pinned PE before compiling. It keeps the source, object, and strict matcher receipt for each attempted function in the chosen scratch directory.

```sh
python tools/verify_serializer_pilot.py --out /tmp/pc2-serializer-pilot --verify --jobs 4
```

Use Capstone 5.0.7 and the [pinned VC6 SP3 toolchain](../VC6_TOOLCHAIN.md). The test fixes the flags at `/O2 /TP`. Omit `--verify` to validate the extraction and generate sources without Wine. Repeat `--address` to run a subset of the eight recipes.

The GamePlan, calendar, and character pairs test repeated fixed-field transfers. Calendar load adds a save-version gate. `IsoMap_Save` adds repeated records and compressed cells. `Branch_Save` adds record lookups and dependent serializers. Together they cover 5,166 candidate bytes. `report.json` gives the strict byte count and the earliest difference for any compiled miss. Only strict receipts contribute to the count.

## Measured result

Six of eight functions passed the strict verifier, for **1,325 code bytes**. The initial calendar load compiled the version fallback before the stream read. Rendering the equivalent signed guard with the read arm first matched the original's `cmp 45; jle fallback` and recovered the full 190-byte function. The other generated sources remained byte-identical.

| Functions | Strict bytes | First obstacle |
| --- | ---: | --- |
| GamePlan save/load | 312 | |
| Calendar save/load | 347 | |
| Character load/save | 666 | |
| `IsoMap_Save` | 0 | `+0x8` in the prologue, 823 compared-byte differences and an extent mismatch |
| `Branch_Save` | 0 | `+0x24` in the setup for the first field write, 972 compared-byte differences |
