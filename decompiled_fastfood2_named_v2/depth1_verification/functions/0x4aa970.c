// rea decompile_all
// name: FUN_004aa970
// address: 0x4aa970
// body: available
// range: 0x4aa970-0x4aaab8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004aa970(void *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float *local_2c;
  undefined1 local_28 [36];
  
  fVar1 = DAT_0057d574;
  iVar3 = *(int *)(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x15c);
  if (iVar3 < 9) {
    param_2 = 0;
  }
  else {
    iVar3 = 8;
  }
  FUN_0054dd83(local_28,(byte *)s__0_2f___005688b0,SUB84((double)DAT_0057d574,0));
  if (0.0 <= fVar1) {
    uVar5 = 0;
  }
  else {
    uVar5 = 0xff;
  }
  FUN_0052f910(param_1,0x3fb,uVar5);
  FUN_0052f9b0(param_1,0x3fb,local_28);
  iVar4 = 0;
  if (0 < iVar3) {
    local_2c = (float *)(&DAT_0057d578 + param_2);
    do {
      fVar1 = *local_2c;
      FUN_0054dd83(local_28,(byte *)s__0_2f___005688b0,SUB84((double)fVar1,0));
      if (0.0 <= fVar1) {
        iVar2 = (&DAT_0056939c)[iVar4];
        uVar5 = 0;
      }
      else {
        iVar2 = (&DAT_0056939c)[iVar4];
        uVar5 = 0xff;
      }
      FUN_0052f910(param_1,iVar2,uVar5);
      iVar2 = Array_GetField20ByKey(param_1,(&DAT_0056935c)[iVar4]);
      if (iVar2 != 0) {
        FUN_0052f9b0(param_1,(&DAT_0056939c)[iVar4],local_28);
      }
      iVar4 = iVar4 + 1;
      local_2c = local_2c + 1;
    } while (iVar4 < iVar3);
  }
  return;
}

