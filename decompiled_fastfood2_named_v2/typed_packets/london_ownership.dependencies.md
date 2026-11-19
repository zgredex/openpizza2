# London ownership goal dependency packet

Executable SHA-256:
`18cfd32e0ac5d6d98162ec016e058a2b51808d9ca49ebee933ce3166ff9922fd`

Generated function batch: `london_ownership.md` / `london_ownership.json`
Machine-readable per-routine records: `london_ownership.routines.json`
Emulation result: `fixtures/london_ownership.result.json`
Verifier: `tools/verify_london_ownership.py`

## Path summary

The London branch goal is controlled by a **one-byte flag at branch `+0x16F4`**.

- `1` is the owned/bought path.
- `0` is the rented path.
- `Branch_Construct` initializes the flag to `1` at `0x476D54`.
- `Company_OpenStartingBranch` writes `1` at `0x4F8B4B` or `0` at `0x4F8B90`.
- `AI_Action_BuyOrRentBranch` writes `1` at `0x4F81C8` or `0` at `0x4F8189`.
- `Branch_Load` reads the byte from the save stream at `0x47B1C6`; `Branch_Save` writes it at `0x47BBA9`.
- `Mission_EvaluateGoals` compares it to `1` at `0x4F60F4` (goal 4) and `0x4F6760` (goal `0x1B`).
- `Game_CountRecordsWithFlag16F4` tests it as nonzero at `0x4DE734`.
- `Stats_Report_FillCompanyOverview` tests it as zero/nonzero at `0x4DED2C`.
- `BranchStats_UpdateRatingPage` tests it as zero/nonzero at `0x491D7F`.

The goal checks are not just `flag != 0`:

- goal 4: `flag == 1` and branch `+0x38 > 0`
- goal `0x1B`: `flag == 1` and branch `+0x38 > 1`

So testing only the flag write can pass while the branch level/capacity field is
wrong.

## Routine records

| Routine | Address | Callers | Reads | Writes | Key calls |
|---|---|---|---|---|---|
| `Branch_Construct` | `0x476B60` | `Branch_ConstructFromStream`, `Company_Load`, `Player_CreateBranch` | construction args | `+0x16F4 = 1` | branch/map/list/stats constructors |
| `AI_Action_BuyOrRentBranch` | `0x4F7ED0` | `Company_ExecuteAction` | site/trade offers, new branch | `+0x16F4 = 0/1`, `+0x14B0`, site `+0x3C` | `AI_FindBestBranchSite`, `Game_ComputeTradeOffers`, `Player_CreateBranch`, `IDMap_Lookup` |
| `Company_OpenStartingBranch` | `0x4F8A80` | `Company_PlaceScenarioBranches` | buy/rent selector, trade offers | `+0x16F4 = 0/1`, `+0x14B0`, site `+0x3C` | `Game_ComputeTradeOffers`, `Player_CreateBranch`, `Customer_VisitBranch` |
| `Mission_EvaluateGoals` | `0x4F5FD0` | `Game_WindowProc`, `Mission_TickGoalDeadline` | `+0x16F4`, `+0x38`, player stats | goal progress | `Game_CountRecordsWithFlag16F4`, player/stat helpers |
| `Game_CountRecordsWithFlag16F4` | `0x4DE710` | `Mission_EvaluateGoals` | `+0x16F4`, count `+0x15C`, ID map `+0x148` | return count | `IDMap_Lookup` |
| `Stats_Report_FillCompanyOverview` | `0x4DECF0` | `Company_RecordDailyStatistics` | `+0x16F4`, `+0x38`, `+0x15C` | report counters `+0x00/+0x04/+0x120` and later sections | `IDMap_Lookup`, city/building helpers |
| `Branch_Load` | `0x47B000` | `Branch_ConstructFromStream` | save-stream byte | `+0x16F4` | `CRT_Istream_Read`, branch constructors |
| `Branch_Save` | `0x47B9E0` | `CompanyData_Save` | `+0x16F4` | save-stream byte | `CRT_Ostream_Write` |
| `BranchStats_UpdateRatingPage` | `0x491D40` | `BuildingInfoMenu_Init` | `+0x16F4`, `+0x38`, `+0x14B0`, `+0x16F0` | rented/owned UI controls | `UI_ShowChildByID`, `Building_ComputeOperatingRevenue`, chart helpers |

## Every `+0x16F4` instruction site in the executable

Byte sites used by the ownership path:

| Address | Access | Width | Routine | Evidence |
|---|---|---|---|---|
| `0x476D54` | write 1 | 1 | `Branch_Construct` | `mov BYTE PTR [esi+0x16f4],0x1` |
| `0x47B1C6` | stream read | 1 | `Branch_Load` | `lea edx,[edi+0x16f4]` then one-byte `CRT_Istream_Read` |
| `0x47BBA9` | stream write | 1 | `Branch_Save` | `lea ecx,[edi+0x16f4]` then one-byte `CRT_Ostream_Write` |
| `0x491D7F` | read | 1 | `BranchStats_UpdateRatingPage` | `mov al,BYTE PTR [ebx+0x16f4]` |
| `0x4DE734` | read | 1 | `Game_CountRecordsWithFlag16F4` | `mov cl,BYTE PTR [eax+0x16f4]` |
| `0x4DED2C` | read | 1 | `Stats_Report_FillCompanyOverview` | `mov cl,BYTE PTR [eax+0x16f4]` |
| `0x4F60F4` | compare 1 | 1 | `Mission_EvaluateGoals` | `cmp BYTE PTR [eax+0x16f4],0x1` |
| `0x4F6760` | compare 1 | 1 | `Mission_EvaluateGoals` | `cmp BYTE PTR [eax+0x16f4],0x1` |
| `0x4F8189` | write 0 | 1 | `AI_Action_BuyOrRentBranch` | `mov BYTE PTR [esi+0x16f4],0x0` |
| `0x4F81C8` | write 1 | 1 | `AI_Action_BuyOrRentBranch` | `mov BYTE PTR [esi+0x16f4],0x1` |
| `0x4F8B4B` | write 1 | 1 | `Company_OpenStartingBranch` | `mov BYTE PTR [esi+0x16f4],0x1` |
| `0x4F8B90` | write 0 | 1 | `Company_OpenStartingBranch` | `mov BYTE PTR [esi+0x16f4],0x0` |

Unresolved byte sites:

| Address | Access | Evidence | Status |
|---|---|---|---|
| `0x491FD2` | read byte | `mov al,BYTE PTR [esi+0x16f4]` | unnamed UI command handler; no retained procedure entry |
| `0x4920C7` | read byte | `mov dl,BYTE PTR [eax+0x16f4]` | same unnamed handler as `0x491FD2` |
| `0x4A7694` | write 0 | `mov BYTE PTR [esi+0x16f4],0x0` | unnamed writer; caller path unresolved |

Excluded overlapping-offset sites (different record families):

| Address | Access | Width | Routine | Reason |
|---|---|---|---|---|
| `0x4019D0` | address | 4 | `ResourceManager_Construct` | resource-manager object, not a branch |
| `0x402262` | read | 4 | `ResourceHandle_Alloc` | 20-slot resource-handle pool with stride `0x24` |
| `0x40227F` | write 1 | 4 | `ResourceHandle_Alloc` | marks a free resource-handle slot |
| `0x51A9EE` | read | 4 | `Language_MapStrings` | language string-table field |

## Initialization and overwrite order

1. `Branch_Construct` sets the record to owned by default at `0x476D54`.
2. `Branch_Load` replaces the byte from the save stream at `0x47B1C6`.
3. Starting branches call `Company_OpenStartingBranch`, which writes buy/rent at `0x4F8B4B` / `0x4F8B90`.
4. Later AI expansion calls `AI_Action_BuyOrRentBranch`, which writes buy/rent at `0x4F81C8` / `0x4F8189`.
5. `Branch_Save` persists the current byte at `0x47BBA9`.

## Fixture evidence

`tools/emulate_mission_goals.py` was run against the original executable and
produced 9/9 matching cases:

- goal 2 remains incomplete when the flagged-record count is 0
- goal 2 completes when the flagged-record count is 1
- all three goals complete with progress=1, C20=3, flag_count=1

Command:

```sh
python3 tools/emulate_mission_goals.py \
  --json-out decompiled_fastfood2_named_v2/typed_packets/fixtures/london_ownership.result.json
```

Result: `case_count: 9`, `matches: 9`, `first_mismatch: null`.

## Assumptions and open questions

- `+0x16F4` is a **byte** flag; every ownership-path instruction above accesses
  exactly one byte.
- `1 = owned`, `0 = rented` is inferred from the buy/rent writer branches and
  from the branch stats UI paths.
- `+0x38` is treated as the branch level/upgrade count; the evaluator compares
  it at `>0` and `>1`.
- The two unnamed byte readers at `0x491FD2` and `0x4920C7` and the unnamed
  writer at `0x4A7694` need their function boundaries and callers recovered.
- `0x40227F` and `0x51A9EE` are 32-bit accesses in different record families;
  they are excluded rather than treated as ownership writes.
- The AI and starting-branch writers are statically traced but not yet covered
  by a Unicorn fixture; only `Mission_EvaluateGoals` has the 9-case emulation
  fixture.
