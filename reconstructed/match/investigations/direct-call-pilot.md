# Direct-call generator pilot

The pilot tested 24 previously unmatched functions across three groups.
The two tools translate named exports with shared call declarations and
check direct call sites and callee stack cleanup against the pinned PE.
VC6 produces candidate objects for the existing strict byte and relocation
checks. Run with Capstone 5.0.7 and the [pinned VC6 toolchain](../VC6_TOOLCHAIN.md).

```sh
python tools/verify_direct_call_pilot.py --out /tmp/pc2-direct-call-pilot --jobs 4
python tools/verify_serializer_pilot.py --out /tmp/pc2-serializer-pilot --verify --jobs 4
```

Use fresh output directories. Both commands save a report and individual
match receipts. Use `--address` to recheck one candidate.

| Group | Strict functions | Strict bytes | Candidate bytes |
| --- | ---: | ---: | ---: |
| UI updates | 0/8 | 0 | 2,398 |
| Other direct-call routines | 1/8 | 886 | 2,663 |
| Save/load serializers | 6/8 | 1,325 | 5,166 |
| Total | 7/24 | 2,211 | 10,227 |

The seven verified functions linked into a byte-identical scratch PE. The
886-byte `UI_LoadStringTable` passed with its repeated direct call sequence.
The [serializer pilot](serializer-pilot.md) matched the GamePlan, calendar,
and character pairs. The two largest serializer targets, `IsoMap_Save` and
`Branch_Save`, still differ.

All candidates compiled after enabling virtual data addresses, partial
global accesses, and the explicit call types needed by this sample. The
two nutrition-row functions first diverge at offset `+0x8` and each has 122
differing bytes. The pilot's **21.6% byte yield** measures these 24 candidates.
The sample favors routines with a small number of distinct callees, so its
yield provides a starting point for testing further shared corrections.
