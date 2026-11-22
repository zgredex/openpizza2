# Language_MapStrings (0x5146d0)

`game/language.ldf` contains 2,361 NUL-terminated strings. `Language_LoadLDF`
(`0x5145a0`) parses them into a pointer table at `DAT_00580ad4`; this function
copies all 2,361 pointers into the UI globals in LDF index order.

The shipped body is straight-line, unoptimized code:

```text
55 8b ec
a1 d4 0a 58 00     mov eax,[DAT_00580ad4]
8b 08              mov ecx,[eax]
89 0d ...          mov [global_0],ecx
8b 15 ...          mov edx,[DAT_00580ad4]
8b 42 04           mov eax,[edx+4]
a3 ...             mov [global_1],eax
...
5d c3              pop ebp; ret
```

It is 40,832 bytes and ends immediately before the next function at
`0x51e650`. The 2,361 destinations are unique globals; source offsets are
`0 .. 0x24e0` in steps of four.

The C source is generated directly from that assignment sequence:

```c
extern char **DAT_00580ad4;
extern char *DAT_00582530;
...
DAT_00582530 = DAT_00580ad4[0];
...
DAT_0058215c = DAT_00580ad4[2360];
```

Build and verify with the pinned VC6 SP3 toolchain:

```sh
sh reconstructed/match/investigations/0x5146d0/verify_strict.sh
```

Result:

```text
strict_match: true
difference_count: 0
candidate_length: 40832
```

The function was compiled `/Od`: the frame pointer and per-assignment reload of
`DAT_00580ad4` are the unoptimized code shape. Matching it recovers about 3.3%
of the indexed code bytes in one function.

The audited link path also accepts this `/Od` recipe. It verifies and links
all 40,832 bytes into a byte-identical scratch PE, and the second run reuses
the compiled object with `--cache-only`.
