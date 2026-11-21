# batch02 part3 worklog

Toolchain: `/tmp/opencode/vc6-sp3-toolchain/VC98`, `wine CL.EXE` with
`/O2 /TP`. All 25 manifest records are byte matches, including the
`--strict-symbols` relocation checks.

Verification: `bash reconstructed/match/batch02/part3/verify_c.sh` from the
repository root. Last run: 25/25 candidates report `"match": true`.

## Matched (25)

| address | name | bytes | notes |
| --- | --- | --- | --- |
| 0x4dca70 | City_GetLocalizedName | 14 | `__fastcall`; global dword array indexed by field 0x10bc |
| 0x4ddcc0 | Game_GetPlayerCity | 17 | global pointer 0x57c670 plus 0x224 + index*4 |
| 0x4e4760 | Object_SetField0C | 10 | `__thiscall` member; stores dword at 0xc |
| 0x4f0e20 | Counter_IncrementShortBA | 15 | 16-bit `inc` then `mov ax` reload of field 0xba |
| 0x4f5c70 | Object_SetShort28 | 12 | `__thiscall` member; stores short at 0x28 |
| 0x4f5fc0 | Object_ClearField28 | 8 | dword zero at 0x28 |
| 0x501b70 | Player_AIState_Destroy | 14 | vtable store 0x55c664, tail jmp to List_Node_Destroy(this+0x68) |
| 0x508d40 | Object_ApplyPendingType | 16 | skips copy when type == 0x23; 0x30 = 0x78 |
| 0x509220 | Object_SetChildShort | 17 | null-checked child at 0xc8, word 0xffff at child+8 |
| 0x50e4a0 | Object_GetChildField2C | 17 | `if (child != 0) return ...; return 0;` layout |
| 0x50e540 | Object_IsState10 | 15 | field 0x108 == 10, `sete al` |
| 0x50e700 | Set_Field168 | 13 | `__thiscall` member; stores dword at 0x168 |
| 0x50e710 | Object_SetFlag104 | 13 | `__thiscall` member; stores byte at 0x104 |
| 0x50e720 | Object_SetFieldFC | 13 | `__thiscall` member; stores dword at 0xfc |
| 0x50e840 | Object_Reset108 | 16 | two -1 stores share `or eax,-1` |
| 0x50efb0 | Object_SetField8 | 10 | `__thiscall` member; stores dword at 8 |
| 0x513fe0 | Storage_Destroy | 14 | vtable store 0x55c700, tail jmp to List_Node_Destroy(this+0x44) |
| 0x514320 | Storage_GetCapacity | 11 | `field2c * 15 + 0x24`, two LEAs |
| 0x521380 | UI_RealizeSprite | 11 | thiscall call on field 0x60 with -1 |
| 0x521b30 | UI_ClipChildRect | 15 | thiscall ClipRect(field8, this+0x28, 1) |
| 0x522e60 | Atexit_RegisterListCritSectDtor | 12 | `_atexit(0x522e70)`; caller pops argument |
| 0x526cf0 | Set_Field228 | 13 | `__thiscall` member; stores dword at 0x228 |
| 0x526d00 | Clear_Field228 | 11 | dword zero at 0x228 |
| 0x5272c0 | UI_GetTextObject | 11 | tail jmp to Renderer_GetTextObject(field 0x244) |
| 0x527940 | UI_SetWindowProc | 13 | `__thiscall` member; stores dword at 0x8304 |

## Implementation notes

- VC6 rejects `__thiscall` on free functions in C++ (`error C4234`), so every
  `__thiscall` record is written as a member function of a padded struct.
  These are the `?Set...@Object@@QAEX...` entries above.
- `__fastcall` free functions compile to the `@@YI...` decorated names; the
  extern thiscall callees at 0x521380/0x521b30 are modelled as member
  functions (`Sprite::FillTransparentColor`, `Renderer::ClipRect`).
- Relocations are linker-resolved fields and are normalized from the original
  PE by the matcher. The addresses supplied to `verify_c.sh --symbol` are:
  DAT_00582fd8=0x582fd8, DAT_0057c670=0x57c670,
  PTR_Player_AIState_Delete_0055c664=0x55c664,
  PTR_Storage_Delete_0055c700=0x55c700, List_Node_Destroy=0x401480,
  FillTransparentColor=0x53d6c0, ClipRect=0x5321f0,
  dtor_00522e70=0x522e70, _atexit=0x54dea3,
  Renderer_GetTextObject=0x52e8e0.
- First iteration compiled 13/25 because the explicit `__thiscall` free
  functions were rejected (C4234). Rewriting them as member functions fixed
  all of them; 0x50e4a0 additionally needed the positive `if` form (the
  inverted form emitted `jne` where the original has `je`).
- No unresolved records; `nonmatching/` is empty.
