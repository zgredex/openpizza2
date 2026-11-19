// rea decompile_all
// name: FUN_004fd520
// address: 0x4fd520
// body: available
// range: 0x4fd520-0x4fd60f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004fd520(void *this,int param_1)

{
  int *piVar1;
  void *this_00;
  void *pvVar2;
  void *this_01;
  int iVar3;
  int iVar4;
  int local_c;
  
  local_c = 0;
  piVar1 = (int *)((int)this + param_1 * 0x168 + 0x70);
  if (0 < *(int *)(*piVar1 + 0x15c)) {
    do {
      pvVar2 = (void *)FUN_00500e80(this,param_1,local_c,1);
      if (pvVar2 != (void *)0x0) {
        this_01 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)pvVar2 + 0x34),
                                       (int *)0x0);
        iVar3 = Game_CountFreeResidentialBuildings((int)pvVar2);
        iVar4 = *piVar1;
        if (0 < iVar3) {
          this_00 = *(void **)((int)pvVar2 + 0x16f0);
          iVar3 = FUN_004d2ae0(this_00,0x20);
          if (iVar3 < 1) {
            if (*(double *)(iVar4 + 0x108) <= 30000.0) {
              iVar4 = FUN_0048a130(DAT_0057c670,1,0x20,(int)this_00,-1);
              if (iVar4 < 1) {
                iVar4 = 1;
                goto LAB_004fd5e4;
              }
            }
            else {
              iVar4 = FUN_0048a130(DAT_0057c670,2,0x20,(int)this_00,-1);
              if (iVar4 < 1) {
                iVar4 = 2;
LAB_004fd5e4:
                FUN_004d5250(this_01,iVar4,pvVar2);
              }
            }
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < *(int *)(*piVar1 + 0x15c));
  }
  return;
}

