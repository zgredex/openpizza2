# Runtime utility matches

Six of eight candidates matched, covering 121 bytes of the shipped PE32 image. The verifier uses MSVC 6.0 SP3 and requires `strict_match: true` with exact function extents and original relocation targets.

```sh
sh reconstructed/match/runtime01/verify_strict.sh
```

| PE address | Routine | Bytes | Compiler flag |
| --- | --- | ---: | --- |
| `0x54c4d0` | `Memory_FreeAndClear` | 26 | `/O2` |
| `0x54f0d5` | `CRT_Srand` | 13 | `/O2` |
| `0x551944` | `CRT_GetVaArg` | 13 | `/O1` |
| `0x551961` | `CRT_ReadArg16` | 14 | `/O1` |
| `0x5558b1` | `CRT_BitSetClear` | 12 | `/O1` |
| `0x5577aa` | `CRT_Strnlen` | 43 | `/O1` |

## Unmatched candidates

- `0x555896` (`CRT_BitSetCopy`) had 11 differing bytes at `/O1`, starting with the register selection for the first stack argument load. `/O2` also had a 32-byte extent against the original 27.
- `0x5558bd` (`CRT_BitSetIsZero`) had 21 differing bytes at `/O1`. The first difference was at offset 6, where the original compares a memory operand directly and the candidate begins with a load. The `/O1` and `/O2` extents were 28 and 32 bytes against the original 27.
