# batch12 part2 nonmatching evidence

Matcher: `python3 tools/match_decomp.py <address> <source> --length <manifest
length> --strict --auto-symbols` (entry picked from the single COFF function
symbol; flags `/O2 /TP`). The JSON below is the helper's summary: candidate
length, strict flag, first differing byte, difference count, and strict issues.

## 0x5355f0 Font_MeasureText (91 bytes)

```json
{"entry": ["?MeasureText@Font@@QAEHPAD@Z"], "candidate_length": 91, "strict": false, "first": {"offset": 0, "original": 81, "candidate": 86}, "ndiff": 87, "issues": []}
```

## 0x53f020 SoundBuffer_DestructBase (91 bytes)

```json
{"entry": ["?DestructBase@SoundBuffer@@QAEXXZ"], "candidate_length": 48, "strict": false, "first": {"offset": 0, "original": 106, "candidate": 86}, "ndiff": 36, "issues": ["relocation at 0x8 resolves to 0x55c830, original has 0xa1", "relocation at 0x1d resolves to 0x55c2d8, original has 0xc83006c7", "relocation at 0x23 resolves to 0x55c840, original has 0xc708468b"]}
```

## 0x47c7d0 MapObject_SettlePendingAmount (94 bytes)

```json
{"entry": ["?SettlePendingAmount@MapObject@@QAEXXZ"], "candidate_length": 94, "strict": false, "first": {"offset": 0, "original": 86, "candidate": 81}, "ndiff": 75, "issues": ["relocation at 0x14 resolves to 0x55c2e4, original has 0x86d91574", "relocation at 0x2d resolves to 0xffffb63f, original has 0x171c", "relocation at 0x3d resolves to 0x55c2e4, original has 0x1c86d915", "relocation at 0x54 resolves to 0xffffb458, original has 0xe8ce8b00", "relocation at 0x5d resolves to 0xffffff7f, original has 0x569090c3", "candidate extent 112 bytes, expected 94 (extra=18 bytes does not match the original table/padding)"]}
```

## 0x54e230 _memmove (91 bytes)

```json
{"entry": ["?_memmove@@YAPAXPAXPBXI@Z"], "candidate_length": 80, "strict": false, "first": {"offset": 0, "original": 85, "candidate": 139}, "ndiff": 79, "issues": []}
```

## 0x550cd0 _memmove_2 (91 bytes)

```json
{"entry": ["?_memmove_2@@YAPAXPAXPBXI@Z"], "candidate_length": 80, "strict": false, "first": {"offset": 0, "original": 85, "candidate": 139}, "ndiff": 79, "issues": []}
```

