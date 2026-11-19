// rea decompile_all
// name: FUN_004ac460
// address: 0x4ac460
// body: available
// range: 0x4ac460-0x4ac5db inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ac460(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *local_34;
  int local_30;
  undefined1 local_28 [36];
  
  iVar1 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  local_30 = *(int *)(iVar1 + 0x15c);
  if (local_30 < 6) {
    param_2 = 0;
  }
  else {
    local_30 = 5;
  }
  FUN_0052ff50(param_1,0x3e9,(uint)(DAT_0056951c == -1));
  FUN_0052f9b0(param_1,0x3f8,DAT_005819f8);
  String_Format(local_28,(byte *)s__0_2f___005688b0,SUB84((double)DAT_0057d5d8,0));
  FUN_0052f9b0(param_1,0x3fb,local_28);
  FUN_005316f0(param_1,0x4b2,(uint)(DAT_0056951c != -1));
  iVar3 = 0;
  if (0 < local_30) {
    local_34 = (float *)(&DAT_0057d5dc + param_2);
    do {
      if (param_2 != DAT_0056951c) {
        iVar2 = (&DAT_00569570)[iVar3];
      }
      else {
        iVar2 = (&DAT_00569570)[iVar3];
      }
      FUN_0052ff50(param_1,iVar2,(uint)(param_2 == DAT_0056951c));
      iVar2 = IDMap_Lookup((void *)(iVar1 + 0x148),param_2,(int *)0x0);
      FUN_0052f9b0(param_1,(&DAT_00569584)[iVar3],iVar2 + 4);
      String_Format(local_28,(byte *)s__0_2f___005688b0,SUB84((double)*local_34,0));
      FUN_0052f9b0(param_1,(&DAT_00569598)[iVar3],local_28);
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
      local_34 = local_34 + 1;
    } while (iVar3 < local_30);
  }
  return;
}

