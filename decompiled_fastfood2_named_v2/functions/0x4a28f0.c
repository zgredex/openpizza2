// rea decompile_all
// name: FUN_004a28f0
// address: 0x4a28f0
// body: available
// range: 0x4a28f0-0x4a2a05 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a28f0(void *param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  int local_110;
  int *local_10c;
  int local_108;
  int local_104;
  char local_100 [256];
  
  local_110 = 0;
  local_10c = &DAT_00568e14;
  do {
    iVar1 = FUN_00488be0(DAT_0057c670,local_110);
    if (iVar1 == 0) {
      FUN_00531740(param_1,*local_10c);
    }
    else {
      iVar2 = FUN_004e2280(iVar1);
      FUN_005316b0(param_1,*local_10c);
      String_Format(local_100,(byte *)s_LOGOS__0_d_spr_00568eb8,*(int *)(iVar1 + 0x1e0) + 1);
      FUN_00531910(param_1,*local_10c,local_100);
      if (0 < iVar2) {
        this = (void *)FUN_00531cf0(param_1,local_110 + 0x45a);
        FUN_00521380((int)this);
        FUN_00521ae0(this,&local_104,&local_108);
        FUN_005219a0(this,0,(local_108 - (local_108 * iVar2) / 6) + -1,local_104,local_108,
                     *(uint *)(iVar1 + 0x1dc));
        FUN_00521b30((int)this);
      }
    }
    local_10c = local_10c + 1;
    local_110 = local_110 + 1;
  } while ((int)local_10c < 0x568e2c);
  return;
}

