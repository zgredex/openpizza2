# Gemma 0x53ef60 report

- target: 0x53ef60 RefCount_AddRef
- source: 0x53ef60.c
- entry: _RefCount_AddRef@4
- length: 16
- strict: yes
- candidate_length: 16
- difference_count: 0
- first_difference: none
- flags: /O2 /TP
- exact bytes: 8b 44 24 04 8b 48 04 41 89 48 04 8b c1 c2 04 00

The function extent is 16 bytes, not 14. A 14-byte check also
reports strict by splitting the `ret 4` immediate into an inline tail;
the helper recipe uses the true 16-byte extent.
