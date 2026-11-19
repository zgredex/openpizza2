// rea decompile_all
// name: FUN_004d8320
// address: 0x4d8320
// body: available
// range: 0x4d8320-0x4d846d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_004d8320(void *this,int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  iVar4 = param_2 * param_2 * 4;
  local_8 = 0;
  param_2 = iVar4;
  FUN_004f34f0(*(void **)((int)this + 0xfa8),*(int *)(param_1 + 0x24),&param_1,&local_4);
  iVar6 = *(int *)((int)this + 0xfc0);
  if (0 < iVar6) {
    do {
      iVar4 = IDMap_Lookup((void *)((int)this + 0xfac),iVar5,(int *)0x0);
      if (*(int *)(iVar4 + 0x48) != -1) {
        *(undefined4 *)(iVar4 + 0x98) = 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
    iVar4 = param_2;
  }
  iVar5 = 0;
  iVar6 = *(int *)(DAT_0057c670 + 0x50);
  if (0 < iVar6) {
    do {
      iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),iVar5,(int *)0x0);
      if (*(int *)(iVar1 + 0xa0) != 0) {
        piVar2 = (int *)(iVar1 + 0xd4);
        iVar1 = 8;
        do {
          iVar3 = *piVar2;
          piVar2 = piVar2 + 1;
          *(int *)(iVar3 + 0x98) = *(int *)(iVar3 + 0x98) + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar6);
  }
  param_2 = *(int *)((int)this + 0xfc0);
  iVar6 = 0;
  if (0 < param_2) {
    do {
      iVar5 = IDMap_Lookup((void *)((int)this + 0xfac),iVar6,(int *)0x0);
      if (*(int *)(iVar5 + 0x48) != -1) {
        iVar1 = FUN_004f0cc0(*(void **)((int)this + 0xfa8),1,*(int *)(iVar5 + 0x54));
        iVar3 = *(int *)(iVar1 + 0xc) - param_1;
        iVar1 = *(int *)(iVar1 + 0x10) - local_4;
        if (iVar3 * iVar3 + iVar1 * iVar1 * 4 < iVar4) {
          if (*(int *)(iVar5 + 4) == 0x20) {
            local_8 = local_8 + (*(int *)((int)this + 0x48) >> 3);
          }
          else {
            local_8 = local_8 + *(int *)(iVar5 + 0x98);
          }
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_2);
  }
  return local_8;
}

