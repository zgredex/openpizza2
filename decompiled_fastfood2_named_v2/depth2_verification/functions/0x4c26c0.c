// rea decompile_all
// name: FUN_004c26c0
// address: 0x4c26c0
// body: available
// range: 0x4c26c0-0x4c281f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c26c0(int *param_1)

{
  int iVar1;
  int *this;
  void *this_00;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_20;
  undefined1 local_14 [20];
  
  this = param_1;
  this_00 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4)
                                 ,(int *)0x0);
  iVar2 = FUN_004da630(this_00,DAT_0057d730);
  iVar5 = 0;
  FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)(*(int *)((int)DAT_0057c670 + 0x218) + 0x28),
               (int *)0x0);
  iVar4 = 6;
  piVar6 = (int *)(iVar2 + 0x2c);
  do {
    iVar1 = *piVar6;
    piVar6 = piVar6 + 1;
    iVar5 = iVar5 + iVar1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  piVar6 = &DAT_0056ada8;
  do {
    FUN_0052f9b0(param_1,*piVar6,DAT_00582e4c);
    FUN_0052f9b0(param_1,*piVar6 + 1,DAT_00582e4c);
    piVar6 = piVar6 + 1;
  } while ((int)piVar6 < 0x56adc0);
  piVar6 = &DAT_0056ada8;
  local_20 = 0;
  param_1 = (int *)(iVar2 + 0x2c);
  do {
    iVar2 = FUN_00488be0(DAT_0057c670,local_20);
    if (iVar2 != 0) {
      uVar3 = FUN_004da6b0(DAT_0057d730,*(int *)(iVar2 + 0x48));
      if ((char)uVar3 != '\0') {
        if (iVar5 < 1) {
          iVar4 = 0;
        }
        else {
          iVar4 = (*param_1 * 100) / iVar5;
        }
        FUN_0052f910(this,*piVar6,*(undefined4 *)(iVar2 + 0x1dc));
        FUN_0052f9b0(this,*piVar6,iVar2 + 8);
        FUN_0054dd83(local_14,(byte *)s__d____00568834,iVar4);
        FUN_0052f9b0(this,*piVar6 + 1,local_14);
        piVar6 = piVar6 + 1;
      }
    }
    local_20 = local_20 + 1;
    param_1 = param_1 + 1;
  } while (local_20 < 6);
  return;
}

