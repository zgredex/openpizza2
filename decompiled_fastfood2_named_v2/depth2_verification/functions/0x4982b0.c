// rea decompile_all
// name: FUN_004982b0
// address: 0x4982b0
// body: available
// range: 0x4982b0-0x49836d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004982b0(void *param_1)

{
  void *this;
  int iVar1;
  float10 fVar2;
  longlong lVar3;
  undefined1 local_80 [128];
  
  this = *(void **)(DAT_0057c670 + 0x98);
  if (this != (void *)0x0) {
    fVar2 = FUN_0050fe70((int)this);
    FUN_0054dd83(local_80,(byte *)s__0_2f__005688b8,SUB84((double)fVar2,0));
    FUN_0052f9b0(param_1,0x4f9,local_80);
    Stats_GetMaxCategoryValue((int)this,-1);
    lVar3 = __ftol();
    FUN_0054dd83(local_80,&DAT_005683a4,(int)lVar3);
    FUN_0052f9b0(param_1,0x4fa,local_80);
    iVar1 = FUN_005101d0(this,-1,0,-1);
    FUN_0054dd83(local_80,&DAT_005686f4,iVar1);
    FUN_0052f9b0(param_1,0x4fb,local_80);
  }
  return;
}

