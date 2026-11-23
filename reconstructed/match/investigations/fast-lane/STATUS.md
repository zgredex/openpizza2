# Fast-lane status

## 2026-11-23 session

Baseline: HEAD after the UI-strict fix; executable SHA-256
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`.

New strict, non-overlapping functions:

| address | bytes | family | source |
|---|---:|---|---|
| 0x541660 | 195 | destructor chain | `destructor-family/generated/0x00541660.cpp` |
| 0x541790 | 225 | destructor chain | `destructor-family/generated/0x00541790.cpp` |
| 0x477f50 | 131 | `call:0x4017f0` | `batch16/part4/0x477f50.c` |
| 0x477fe0 | 166 | `call:0x4017f0` | `batch16/part4/0x477fe0.c` |
| 0x478090 | 166 | `call:0x4017f0` | `batch16/part4/0x478090.c` |
| 0x49a040 | 150 | `call:0x4017f0` | `batch16/part1/0x49a040.c` |

Total: **1,033 new strict bytes**, 6 functions, 0.073 percentage points of
the 1,419,964-byte `.text` section. The destructor family is 8/8 strict
(1,250 bytes); the `0x4017f0` family is 76/78 (5,576 bytes).

## Inventory correction

The first queue run omitted `--ui-scan`, so the already-strict 120 UI builders
(259,523 indexed bytes) appeared as the top Lane B gap. `build_family_registry.py`
now counts a UI report with `status: "strict"` as strict. The rebuilt queue has
206,492 pending indexed bytes, not 643,959.

## Walls recorded

- `0x478eb0` (168 B): six source shapes still differ in pointer
  strength-reduction (`add eax,0x220` / `lea edi,0x20(eax)` vs
  `lea edi,[eax+0x220]`). Parked.
- `0x5448c0` (210 B): free `__stdcall` ABI and RAII guard are now correct; the
  remaining 30 bytes are an ESI/EDI swap for `self` vs the lock pointer.
- `0x544620` (211 B): ABI and guard are correct; the compiler hoists the
  `field53` load above the `field54` store and keeps `this` instead of reusing
  ESI for the object pointer.

## Next opportunity

Lane A/B: `call:0x488be0` end-results pages (28 functions, 8,728 indexed
bytes, 12 strict; four missing siblings of 487/487/680/639 bytes). Pilot the
two 487-byte siblings as a generator candidate. The remaining `0x4017f0`
residue is 322 bytes (`0x478eb0`, `0x4e1fe0`).
