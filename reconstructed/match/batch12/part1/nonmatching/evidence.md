# batch12 part1 nonmatching evidence

Matcher: `python3 tools/match_decomp.py <address> <source> --length <manifest
length> --strict --auto-symbols` (entry picked from the single COFF function
symbol; flags `/O2 /TP`). The JSON below is the helper's summary: candidate
length, strict flag, first differing byte, difference count, and strict issues.

## 0x4aec60 Glossary_FillCityBuildingList (89 bytes)

```json
{"entry": ["?Glossary_FillCityBuildingList@@YAXPAUWindow@@H@Z"], "candidate_length": 89, "strict": false, "first": {"offset": 1, "original": 85, "candidate": 139}, "ndiff": 65, "issues": ["relocation at 0xf resolves to 0x58404c, original has 0x1c8d0000", "relocation at 0x34 resolves to 0x812b8, original has 0x8b000812", "relocation at 0x3f resolves to 0x80d0d, original has 0xd0be8cf"]}
```

## 0x4af5c0 Glossary_FillPeopleNameList (89 bytes)

```json
{"entry": ["?Glossary_FillPeopleNameList@@YAXPAUWindow@@H@Z"], "candidate_length": 89, "strict": false, "first": {"offset": 1, "original": 85, "candidate": 139}, "ndiff": 63, "issues": ["relocation at 0xf resolves to 0x583434, original has 0x1c8d0000", "relocation at 0x31 resolves to 0x8095b, original has 0x959e8cf", "relocation at 0x3f resolves to 0x803ad, original has 0x3abe8cf"]}
```

## 0x4d22c0 Map_ApplyRandomTileVariant (89 bytes)

```json
{"entry": ["@Map_ApplyRandomTileVariant@4"], "candidate_length": 89, "strict": false, "first": {"offset": 38, "original": 70, "candidate": 86}, "ndiff": 7, "issues": []}
```

## 0x4de300 Stats_GetMaxObjectMatrixValue (89 bytes)

```json
{"entry": ["?GetMaxObjectMatrixValue@Stats@@QAEMH@Z"], "candidate_length": 89, "strict": false, "first": {"offset": 1, "original": 83, "candidate": 139}, "ndiff": 73, "issues": ["relocation at 0x15 resolves to 0xfff9c307, original has 0x33ff3357", "relocation at 0x2b resolves to 0xffffff51, original has 0x7541c4f6"]}
```

## 0x52e4b0 Tooltip_Construct (89 bytes)

```json
{"entry": ["?Construct@Tooltip@@QAEPAU1@PAXH@Z"], "candidate_length": 89, "strict": false, "first": {"offset": 3, "original": 185, "candidate": 139}, "ndiff": 26, "issues": ["relocation at 0x18 resolves to 0x55c804, original has 0x4e890055"]}
```

## 0x4872b0 UI_ClearActiveRecordSlots (91 bytes)

```json
{"entry": ["@UI_ClearActiveRecordSlots@4"], "candidate_length": 91, "strict": false, "first": {"offset": 6, "original": 85, "candidate": 86}, "ndiff": 76, "issues": ["relocation at 0x17 resolves to 0x57c5cc, original has 0x57c5cc0d", "relocation at 0x38 resolves to 0xac784, original has 0xe8cf8b50"]}
```

## 0x50d790 AI_WanderToRandomRoadTile (91 bytes)

```json
{"entry": ["@AI_WanderToRandomRoadTile@4"], "candidate_length": 91, "strict": false, "first": {"offset": 30, "original": 80, "candidate": 139}, "ndiff": 6, "issues": []}
```

