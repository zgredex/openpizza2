// rea decompile_all
// name: FUN_0048cc10
// address: 0x48cc10
// body: available
// range: 0x48cc10-0x48cd3c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0048cc10(void *this,int *param_1,int *param_2)

{
  void *this_00;
  void *pvVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int local_8;
  int local_4;
  
  this_00 = *(void **)((int)this + *(int *)((int)this + 0x2ec) * 4 + 0x200);
  local_8 = 0;
  local_4 = 0;
  piVar6 = (int *)((int)this + 0x200);
  do {
    pvVar1 = (void *)*piVar6;
    if ((pvVar1 != (void *)0x0) && (pvVar1 != this_00)) {
      iVar2 = *(int *)((int)pvVar1 + 0x15c);
      iVar5 = 0;
      if (0 < iVar2) {
        do {
          iVar3 = FUN_004017f0((void *)(*piVar6 + 0x148),iVar5,(int *)0x0);
          uVar4 = FUN_004e2e40(this_00,*(int *)(iVar3 + 0x16f0));
          if ((char)uVar4 != '\0') {
            if (local_8 == 0) {
              *param_1 = iVar5;
              *param_2 = local_4;
            }
            local_8 = local_8 + 1;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar2);
      }
      iVar5 = 0;
      iVar2 = *(int *)(*piVar6 + 0x194);
      if (0 < iVar2) {
        do {
          iVar3 = FUN_004017f0((void *)(*piVar6 + 0x180),iVar5,(int *)0x0);
          uVar4 = FUN_004e2e40(this_00,*(int *)(iVar3 + 0x34));
          if ((char)uVar4 != '\0') {
            if (local_8 == 0) {
              *param_1 = iVar5 + 0x14;
              *param_2 = local_4;
            }
            local_8 = local_8 + 1;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar2);
      }
      uVar4 = FUN_004e2e40(this_00,*(int *)(*piVar6 + 0x1d8));
      if ((char)uVar4 != '\0') {
        if (local_8 == 0) {
          *param_1 = 0x28;
          *param_2 = local_4;
        }
        local_8 = local_8 + 1;
      }
    }
    piVar6 = piVar6 + 1;
    local_4 = local_4 + 1;
  } while (local_4 < 6);
  return local_8;
}

