// rea decompile_all
// name: FUN_004f5990
// address: 0x4f5990
// body: available
// range: 0x4f5990-0x4f5aa1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f5990(void *this,int *param_1,int *param_2)

{
  int *piVar1;
  void *this_00;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int *local_8;
  int local_4;
  
  piVar1 = param_1;
  if ((param_1 != (int *)0x0) && (param_1[2] != 0)) {
    this_00 = (void *)SparseMap_Lookup48(*(void **)((int)this + 4),*(int *)(param_1[2] + 0x10));
    if (this_00 == (void *)0x0) {
      UI_ComputeCenteredRect(this,piVar1,(int *)&param_1,&local_24);
      local_c = local_24 + -0x40;
      local_10 = param_1 + -0x10;
      local_4 = local_24 + 0x40;
      local_8 = param_1 + 0x10;
    }
    else {
      FUN_004ed780(this,piVar1,this_00,(int *)&param_1,&local_24);
      Sprite_GetHotspot(this_00,&local_20,&local_1c);
      Sprite_GetSize(this_00,&local_18,&local_14);
      local_10 = (int *)(local_20 + (int)param_1);
      local_c = local_24 + local_1c;
      local_8 = (int *)(local_18 + (int)local_10);
      local_4 = local_14 + local_c;
    }
    if (param_2 != (int *)0x0) {
      *param_2 = (int)local_10 + -0x32;
      param_2[1] = local_c + -0x32;
      param_2[2] = (int)local_8 + 0x32;
      param_2[3] = local_4 + 0x32;
      return;
    }
    FUN_00534e20(DAT_0058072c,(uint *)&local_10);
  }
  return;
}

