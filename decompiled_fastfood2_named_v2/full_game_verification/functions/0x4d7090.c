// rea decompile_all
// name: MapObjectList_Save
// address: 0x4d7090
// body: available
// range: 0x4d7090-0x4d73b8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall MapObjectList_Save(void *this,void *param_1)

{
  void *this_00;
  int *piVar1;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  local_14 = Game_RemoveIDMapEntry(DAT_0057c5cc,*(int *)((int)this + 0xfa8));
  CRT_Ostream_Write(param_1,&local_14,4);
  CRT_Ostream_Write(param_1,(int)this + 0xc1c,4);
  CRT_Ostream_Write(param_1,(int)this + 4U,0x20);
  CRT_Ostream_Write(param_1,(int)this + 0x44,4);
  CRT_Ostream_Write(param_1,(int)this + 0xc20,0x18);
  local_c = 0xc18;
  CRT_Ostream_Write(param_1,&local_c,4);
  CRT_Ostream_Write(param_1,-(uint)(this != (void *)0x0) & (int)this + 4U,local_c);
  CRT_Ostream_Write(param_1,(int)this + 0xdac,0x18);
  CRT_Ostream_Write(param_1,(int)this + 0xdc4,4);
  CRT_Ostream_Write(param_1,(int)this + 0xdc8,0x1e0);
  CRT_Ostream_Write(param_1,(int)this + 0xc38,0x60);
  CRT_Ostream_Write(param_1,(int)this + 0xc98,0x18);
  CRT_Ostream_Write(param_1,(int)this + 0xcc8,0x18);
  CRT_Ostream_Write(param_1,(int)this + 0xd40,0x18);
  CRT_Ostream_Write(param_1,(int)this + 0xd58,0x30);
  CRT_Ostream_Write(param_1,(int)this + 0xd88,0x24);
  CRT_Ostream_Write(param_1,(int)this + 0xce0,0x60);
  CRT_Ostream_Write(param_1,(int)this + 0xcb0,0x18);
  CRT_Ostream_Write(param_1,(int)this + 0xfe4,0xc0);
  CRT_Ostream_Write(param_1,(int)this + 0x10ac,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10b0,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10b4,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10b8,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10c4,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10d0,0x78);
  CRT_Ostream_Write(param_1,(int)this + 0x10c0,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10bc,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10cc,4);
  CRT_Ostream_Write(param_1,(int)this + 0x10c8,4);
  CRT_Ostream_Write(param_1,(int)this + 0x1148,4);
  CRT_Ostream_Write(param_1,(int)this + 0x114c,4);
  CRT_Ostream_Write(param_1,(int)this + 0x1150,4);
  CRT_Ostream_Write(param_1,(int)this + 0x1154,4);
  local_14 = *(int *)((int)this + 0xfc0);
  CRT_Ostream_Write(param_1,&local_14,4);
  local_14 = 0;
  if (0 < *(int *)((int)this + 0xfc0)) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((int)this + 0xfac),local_14,(int *)0x0);
      MapObject_Save(this_00,param_1);
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)((int)this + 0xfc0));
  }
  local_10 = *(int *)((int)this + 0xfdc);
  CRT_Ostream_Write(param_1,&local_10,4);
  local_14 = 0;
  if (0 < local_10) {
    do {
      piVar1 = (int *)IDMap_Lookup((void *)((int)this + 0xfc8),local_14,(int *)0x0);
      local_8 = piVar1[1];
      CRT_Ostream_Write(param_1,&local_8,4);
      local_4 = Map_LookupLinear((void *)(DAT_0057c670 + 0x20),*piVar1);
      CRT_Ostream_Write(param_1,&local_4,4);
      local_14 = local_14 + 1;
    } while (local_14 < local_10);
  }
  CRT_Ostream_Write(param_1,(int)this + 0x10a4,4);
  return;
}

