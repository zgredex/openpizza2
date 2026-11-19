// rea decompile_all
// name: LoadingWindow_Create
// address: 0x474b90
// body: available
// range: 0x474b90-0x474c6f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __cdecl LoadingWindow_Create(int *param_1)

{
  int iVar1;
  void *this;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* Creates the modal loading/progress window. */
  iVar1 = FUN_00523bb0(DAT_0057c5e0,0xbb,0xf8,s_PE_RQ_LOADING_spr_00566d34,FUN_0048e0a0);
  *param_1 = iVar1;
  this = (void *)FUN_00528040(DAT_0057c5e0,iVar1,(int *)0x0);
  if (this == (void *)0x0) {
    return (void *)0x0;
  }
  iVar1 = UI_CreateSlider(this,0x3f7,0x13,0x46,400,s_SC_00_spr_00564324,1,0);
  if (iVar1 != 0) {
    local_10 = 0xff;
    local_c = 0xffff;
    local_8 = 0xff00;
    local_4 = 0;
    FUN_0052fcc0(this,0x3f7,&local_10);
  }
  iVar1 = FUN_0052f850(this,0x3e9,0x10,0x17,s_VERDANA16_fnt_00565788,DAT_005828f0);
  if (iVar1 != 0) {
    FUN_0052f910(this,0x3e9,0);
    FUN_0052f9d0(this,0x3e9,2,400,0,0);
  }
  return this;
}

