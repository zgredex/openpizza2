// rea decompile_all
// name: FUN_00500070
// address: 0x500070
// body: available
// range: 0x500070-0x5001e3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00500070(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  void *pvVar7;
  int iVar8;
  int local_24;
  int local_1c;
  
  iVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  iVar3 = FUN_004e2280(iVar1);
  if (1 < iVar3) {
    iVar3 = *(int *)(iVar1 + 0x15c);
    local_1c = 0;
    if (0 < iVar3) {
      do {
        iVar4 = IDMap_Lookup((void *)(iVar1 + 0x148),local_1c,(int *)0x0);
        iVar5 = *(int *)(*(int *)(iVar4 + 0x16f0) + 0x74);
        if (iVar5 == 0) {
          local_24 = -1;
        }
        else {
          local_24 = FUN_004e4490(iVar5);
        }
        iVar5 = FUN_00481140(iVar4);
        iVar8 = 0;
        if (0 < iVar5) {
          do {
            piVar6 = (int *)IDMap_Lookup(*(void **)(iVar4 + 0x1a28),iVar8,(int *)0x0);
            pvVar7 = (void *)IDMap_Lookup((void *)(iVar2 + 0xfac),*piVar6,(int *)0x0);
            if (*(int *)((int)pvVar7 + 4) == 0x1b) {
              if (((double)piVar6[1] < (double)(local_24 + 0x4b) * 0.8) &&
                 (-1 < *(int *)((int)pvVar7 + 8))) {
                FUN_005001f0(this,param_1,pvVar7,*(undefined4 *)(iVar4 + 0x3c));
              }
              if (((double)piVar6[1] < (double)(local_24 + 0x4b) * 0.9) &&
                 (*(int *)((int)pvVar7 + 8) == -1)) {
                FUN_005001f0(this,param_1,pvVar7,*(undefined4 *)(iVar4 + 0x3c));
              }
            }
            iVar8 = iVar8 + 1;
          } while (iVar8 < iVar5);
        }
        local_1c = local_1c + 1;
      } while (local_1c < iVar3);
    }
  }
  return;
}

