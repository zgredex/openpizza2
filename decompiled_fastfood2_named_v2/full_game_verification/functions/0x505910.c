// rea decompile_all
// name: PersonAction_LoadState
// address: 0x505910
// body: available
// range: 0x505910-0x505dfa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall PersonAction_LoadState(void *this,void *param_1)

{
  void *this_00;
  undefined4 uVar1;
  void *this_01;
  int iVar2;
  undefined4 *puVar3;
  int local_10;
  int local_c;
  int local_8;
  uint local_4;
  
                    /* Deserializes a person action/task record and its lists. */
  this_00 = param_1;
  CRT_Istream_Read(param_1,(int)this + 4,0x20);
  CRT_Istream_Read(this_00,(int)this + 0x24,4);
  CRT_Istream_Read(this_00,(int *)((int)this + 0x28),4);
  CRT_Istream_Read(this_00,(int)this + 0x30,4);
  CRT_Istream_Read(this_00,(int)this + 0x34,4);
  CRT_Istream_Read(this_00,(int)this + 0x38,4);
  CRT_Istream_Read(this_00,(int)this + 0x3c,4);
  CRT_Istream_Read(this_00,(int)this + 0x40,2);
  CRT_Istream_Read(this_00,(int)this + 0x44,4);
  CRT_Istream_Read(this_00,(int)this + 0x48,4);
  CRT_Istream_Read(this_00,(int)this + 0x4c,4);
  CRT_Istream_Read(this_00,(int)this + 0x50,4);
  CRT_Istream_Read(this_00,(int)this + 0x54,4);
  CRT_Istream_Read(this_00,(int)this + 0x58,4);
  CRT_Istream_Read(this_00,(int)this + 0x5c,0x18);
  CRT_Istream_Read(this_00,(int *)((int)this + 0x74),4);
  CRT_Istream_Read(this_00,(int)this + 0x78,4);
  CRT_Istream_Read(this_00,(int)this + 0x7c,4);
  CRT_Istream_Read(this_00,(int)this + 0x80,1);
  CRT_Istream_Read(this_00,(int)this + 0x81,1);
  CRT_Istream_Read(this_00,(int)this + 0x84,4);
  CRT_Istream_Read(this_00,(int)this + 0x88,4);
  CRT_Istream_Read(this_00,(int)this + 0x8c,4);
  CRT_Istream_Read(this_00,(int)this + 0x90,4);
  CRT_Istream_Read(this_00,(int)this + 0x10c,4);
  CRT_Istream_Read(this_00,(int)this + 0x94,4);
  CRT_Istream_Read(this_00,(int)this + 0x98,4);
  CRT_Istream_Read(this_00,(int)this + 0x9c,4);
  CRT_Istream_Read(this_00,(int)this + 0x14c,0x18);
  CRT_Istream_Read(this_00,(int)this + 0xa0,4);
  CRT_Istream_Read(this_00,(int)this + 0xa4,4);
  CRT_Istream_Read(this_00,(int)this + 0xa8,4);
  CRT_Istream_Read(this_00,(int)this + 0x110,4);
  CRT_Istream_Read(this_00,(int)this + 0x104,1);
  CRT_Istream_Read(this_00,(int)this + 0x108,4);
  CRT_Istream_Read(this_00,(int)this + 0xac,0x18);
  CRT_Istream_Read(this_00,(int)this + 0x2c,4);
  CRT_Istream_Read(this_00,&param_1,4);
  uVar1 = Game_UpdateIDMapEntry(DAT_0057c5cc,(int)param_1);
  *(undefined4 *)((int)this + 0xc4) = uVar1;
  MapObject_ReadRenderRecord(this,(uint)(*(int *)((int)this + 0x74) != 0),this_00);
  this_01 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  CRT_Istream_Read(this_00,&param_1,4);
  if (param_1 == (void *)0x0) {
    *(undefined4 *)((int)this + 0xcc) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&param_1,4);
    uVar1 = Game_UpdateAndFetchMapEntryFAC(this_01,(int)param_1);
    *(undefined4 *)((int)this + 0xcc) = uVar1;
  }
  CRT_Istream_Read(this_00,&param_1,4);
  if (param_1 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    CRT_Istream_Read(this_00,&param_1,4);
    uVar1 = Game_UpdateAndFetchMapEntryFAC(this_01,(int)param_1);
  }
  Object_SetFieldFC(this,uVar1);
  CRT_Istream_Read(this_00,&param_1,4);
  if (param_1 == (void *)0x0) {
    *(undefined4 *)((int)this + 0x100) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&param_1,4);
    uVar1 = Game_UpdateAndFetchMapEntryFAC(this_01,(int)param_1);
    *(undefined4 *)((int)this + 0x100) = uVar1;
  }
  CRT_Istream_Read(this_00,&param_1,4);
  if (param_1 == (void *)0x0) {
    *(undefined4 *)((int)this + 0xd0) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&param_1,4);
    uVar1 = Game_UpdateAndFetchMapEntryFAC(this_01,(int)param_1);
    *(undefined4 *)((int)this + 0xd0) = uVar1;
  }
  puVar3 = (undefined4 *)((int)this + 0xd4);
  local_8 = 8;
  do {
    CRT_Istream_Read(this_00,&param_1,4);
    if (param_1 == (void *)0x0) {
      *puVar3 = 0;
    }
    else {
      CRT_Istream_Read(this_00,&param_1,4);
      uVar1 = Game_UpdateAndFetchMapEntryFAC(this_01,(int)param_1);
      *puVar3 = uVar1;
    }
    puVar3 = puVar3 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  CRT_Istream_Read(this_00,&param_1,4);
  if (param_1 == (void *)0x0) {
    *(undefined4 *)((int)this + 0xf4) = 0;
  }
  else {
    CRT_Istream_Read(this_00,&param_1,4);
    uVar1 = Game_UpdateAndFetchMapEntryFAC(this_01,(int)param_1);
    *(undefined4 *)((int)this + 0xf4) = uVar1;
  }
  CRT_Istream_Read(this_00,&param_1,4);
  *(undefined4 *)((int)this + 0xf8) = 0;
  if (param_1 != (void *)0x0) {
    CRT_Istream_Read(this_00,&local_4,2);
    if (*(void **)((int)this + 0xc4) != (void *)0x0) {
      iVar2 = Object_FindRecordByKey28(*(void **)((int)this + 0xc4),(int *)0x1,local_4 & 0xffff);
      *(int *)((int)this + 0xf8) = iVar2;
    }
  }
  CRT_Istream_Read(this_00,&local_10,4);
  param_1 = (void *)0x0;
  if (0 < local_10) {
    do {
      CRT_Istream_Read(this_00,&local_c,4);
      List_Add((void *)((int)this + 0x114),local_c);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_10);
  }
  CRT_Istream_Read(this_00,&local_10,4);
  param_1 = (void *)0x0;
  if (0 < local_10) {
    do {
      CRT_Istream_Read(this_00,&local_c,4);
      uVar1 = Game_UpdateAndFetchMapEntryFAC(this_01,local_c);
      List_Add((void *)((int)this + 0x130),uVar1);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_10);
  }
  return;
}

