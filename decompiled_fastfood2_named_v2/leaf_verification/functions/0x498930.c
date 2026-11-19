// rea decompile_all
// name: FUN_00498930
// address: 0x498930
// body: available
// range: 0x498930-0x498a66 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __cdecl FUN_00498930(void *param_1)

{
  int *this;
  bool bVar1;
  float10 fVar2;
  undefined4 local_94;
  void *local_90;
  undefined1 local_8c [64];
  undefined1 auStack_4c [64];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005585ce;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined1 *)((int)param_1 + 0x1dd) = 0;
  FUN_0054dd83(local_8c,(byte *)s_save_piz__s_piz_005688c0,(int)param_1 + 4);
  local_90 = operator_new(0x58);
  this = (int *)0x0;
  local_4 = 0;
  if (local_90 != (void *)0x0) {
    this = FUN_0054d140();
  }
  local_4 = 0xffffffff;
  if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) == 0) {
    local_94 = 0x2e;
    FUN_0054cc2b(this,&local_94,4);
    FUN_00510640(param_1,this,'\0');
    bVar1 = (*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) == 0;
    if (this != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))();
    }
    fVar2 = Game_GetPlayerWeightedStat((int)param_1);
    FUN_0054dd83(auStack_4c,(byte *)s__0_2f__005688b8,SUB84((double)fVar2,0));
    if (*(void **)(DAT_0057c670 + 0x264) != (void *)0x0) {
      FUN_0052f9b0(*(void **)(DAT_0057c670 + 0x264),0x4f9,auStack_4c);
    }
  }
  else {
    if (this != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))();
    }
    bVar1 = false;
  }
  ExceptionList = pvStack_c;
  return bVar1;
}

