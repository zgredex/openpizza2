// rea decompile_all
// name: Map_DrawTileCursorDiamond
// address: 0x4f03f0
// body: available
// range: 0x4f03f0-0x4f0842 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
Map_DrawTileCursorDiamond
          (void *this,int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
          uint param_6)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  tagRECT local_10;
  
  uVar1 = Color_RGBTo16FromDword(*(void **)((int)this + 8),param_6);
  SetRect(&local_10,0,0,DAT_00571950,DAT_00571954);
  if ((DAT_005719b8 != 0xffffffff) && (param_4 == 0)) {
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40,DAT_00580a44 + -2,(short)DAT_005719b8);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40,DAT_00580a44 + -1,DAT_005719bc);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + 1,DAT_00580a44,DAT_005719c0);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + 2,DAT_00580a44,DAT_005719c4);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40,DAT_00580a44 + 1,DAT_005719c8);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40,DAT_00580a44 + 2,DAT_005719cc);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + -1,DAT_00580a44,DAT_005719d0);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + -2,DAT_00580a44,DAT_005719d4);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + 1,DAT_00580a44 + -1,DAT_005719d8);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + 1,DAT_00580a44 + 1,DAT_005719dc);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + -1,DAT_00580a44 + -1,DAT_005719e0);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40 + -1,DAT_00580a44 + 1,DAT_005719e4);
    Surface_SetPixel(*(int *)((int)this + 8),DAT_00580a40,DAT_00580a44,DAT_005719e8);
  }
  if (param_3 == 0) {
    uVar2 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1,param_2 + -2);
    DAT_005719b8 = uVar2 & 0xffff;
    _DAT_005719bc = Tilemap_GetCell(*(uint *)((int)this + 8),param_1,param_2 + -1);
    _DAT_005719bc = _DAT_005719bc & 0xffff;
    _DAT_005719c0 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + 1,param_2);
    _DAT_005719c0 = _DAT_005719c0 & 0xffff;
    _DAT_005719c4 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + 2,param_2);
    _DAT_005719c4 = _DAT_005719c4 & 0xffff;
    _DAT_005719c8 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1,param_2 + 1);
    _DAT_005719c8 = _DAT_005719c8 & 0xffff;
    _DAT_005719cc = Tilemap_GetCell(*(uint *)((int)this + 8),param_1,param_2 + 2);
    _DAT_005719cc = _DAT_005719cc & 0xffff;
    _DAT_005719d0 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + -1,param_2);
    _DAT_005719d0 = _DAT_005719d0 & 0xffff;
    _DAT_005719d4 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + -2,param_2);
    _DAT_005719d4 = _DAT_005719d4 & 0xffff;
    _DAT_005719d8 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + 1,param_2 + -1);
    _DAT_005719d8 = _DAT_005719d8 & 0xffff;
    _DAT_005719dc = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + 1,param_2 + 1);
    _DAT_005719dc = _DAT_005719dc & 0xffff;
    _DAT_005719e0 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + -1,param_2 + -1);
    _DAT_005719e0 = _DAT_005719e0 & 0xffff;
    _DAT_005719e4 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1 + -1,param_2 + 1);
    _DAT_005719e4 = _DAT_005719e4 & 0xffff;
    _DAT_005719e8 = Tilemap_GetCell(*(uint *)((int)this + 8),param_1,param_2);
    _DAT_005719e8 = _DAT_005719e8 & 0xffff;
    Surface_SetPixel(*(int *)((int)this + 8),param_1,param_2 + -2,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1,param_2 + -1,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + 1,param_2,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + 2,param_2,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1,param_2 + 1,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1,param_2 + 2,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + -1,param_2,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + -2,param_2,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + 1,param_2 + -1,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + 1,param_2 + 1,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + -1,param_2 + -1,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1 + -1,param_2 + 1,uVar1);
    Surface_SetPixel(*(int *)((int)this + 8),param_1,param_2,uVar1);
    if (param_4 == 0) {
      DAT_00580a40 = param_1;
      DAT_00580a44 = param_2;
      return;
    }
  }
  puVar4 = &DAT_005719b8;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xffffffff;
    puVar4 = puVar4 + 1;
  }
  DAT_00580a40 = param_1;
  DAT_00580a44 = param_2;
  return;
}

