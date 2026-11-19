// rea decompile_all
// name: FUN_004d1da0
// address: 0x4d1da0
// body: available
// range: 0x4d1da0-0x4d1fd7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d1da0(void *this,void *param_1)

{
  void *this_00;
  undefined4 *puVar1;
  int iVar2;
  int local_18;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  this_00 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558d2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CRT_Istream_Read(param_1,(int)this + 4,4);
  CRT_Istream_Read(this_00,(int)this + 8,4);
  CRT_Istream_Read(this_00,(int)this + 0x4c,4);
  CRT_Istream_Read(this_00,(int)this + 0x50,4);
  CRT_Istream_Read(this_00,(int)this + 0x2c,4);
  CRT_Istream_Read(this_00,(int)this + 0x30,4);
  CRT_Istream_Read(this_00,(int)this + 0x34,4);
  CRT_Istream_Read(this_00,(int)this + 0x38,4);
  CRT_Istream_Read(this_00,(int)this + 0xc,4);
  CRT_Istream_Read(this_00,(int)this + 0x3c,4);
  CRT_Istream_Read(this_00,(int)this + 0x94,4);
  CRT_Istream_Read(this_00,(int)this + 0x10,0x10);
  CRT_Istream_Read(this_00,(int)this + 0x20,4);
  CRT_Istream_Read(this_00,(int)this + 0x24,4);
  CRT_Istream_Read(this_00,(int)this + 0x40,8);
  CRT_Istream_Read(this_00,(int)this + 0x48,4);
  CRT_Istream_Read(this_00,(int)this + 0x54,4);
  CRT_Istream_Read(this_00,(int *)((int)this + 0x28),4);
  if (*(int *)((int)this + 0x28) == -1) {
    FUN_0048e0a0();
  }
  CRT_Istream_Read(this_00,&param_1,4);
  FUN_004eacd0(DAT_0057c5cc,(int)param_1);
  CRT_Istream_Read(this_00,&local_18,4);
  iVar2 = 0;
  if (0 < local_18) {
    do {
      CRT_Istream_Read(this_00,&param_1,4);
      FUN_004014b0((void *)((int)this + 0x58),param_1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < local_18);
  }
  CRT_Istream_Read(this_00,&param_1,4);
  if (param_1 == (void *)0x1) {
    local_10 = operator_new(0x20);
    local_4 = 0;
    if (local_10 == (void *)0x0) {
      local_4 = 0xffffffff;
      *(undefined4 *)((int)this + 0x74) = 0;
    }
    else {
      puVar1 = FUN_004e4370(local_10,this_00);
      local_4 = 0xffffffff;
      *(undefined4 **)((int)this + 0x74) = puVar1;
    }
  }
  else {
    *(undefined4 *)((int)this + 0x74) = 0;
  }
  CRT_Istream_Read(this_00,&local_18,4);
  param_1 = (void *)0x0;
  if (0 < local_18) {
    do {
      CRT_Istream_Read(this_00,&local_14,4);
      FUN_004014b0((void *)((int)this + 0x78),local_14);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_18);
  }
  ExceptionList = local_c;
  return;
}

