// rea decompile_all
// name: FUN_004f2e50
// address: 0x4f2e50
// body: available
// range: 0x4f2e50-0x4f2fba inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f2e50(void *this,int param_1)

{
  short sVar1;
  char cVar2;
  void *this_00;
  int iVar3;
  undefined4 *this_01;
  int iVar4;
  int iVar5;
  int local_4;
  
  iVar5 = 0;
  if (0 < *(int *)((int)this + 0x1c) * *(int *)((int)this + 0x20)) {
    iVar4 = 0;
    do {
      iVar3 = *(int *)(iVar4 + 8 + *(int *)((int)this + 0x4c));
      if ((iVar3 != 0) && (*(int *)(iVar3 + 0x10) == -2)) {
        *(undefined4 *)(iVar3 + 0x10) = 0xffffffff;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar5 < *(int *)((int)this + 0x1c) * *(int *)((int)this + 0x20));
  }
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0x170c)) {
    do {
      iVar5 = IDMap_Lookup((void *)(param_1 + 0x16f8),local_4,(int *)0x0);
      if (((iVar5 != 0) &&
          (this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(iVar5 + 4),
                                          (int *)0x0), this_00 != (void *)0x0)) &&
         (iVar4 = FUN_004ef4b0(this,*(int *)(iVar5 + 0x18),*(int *)(iVar5 + 0x1c)), iVar4 != 0)) {
        cVar2 = FUN_004e5df0(iVar5);
        if (cVar2 == '\x01') {
          iVar3 = FUN_004e42c0(this_00,*(int *)(*(int *)(iVar4 + 8) + 0x10),*(int *)(iVar5 + 8));
          if (iVar3 == 2) {
            sVar1 = *(short *)((int)this_00 + *(int *)(iVar5 + 8) * 0xc + 0x80);
          }
          else {
            if (iVar3 != 3) {
              *(undefined4 *)(*(int *)(iVar4 + 8) + 0x1c) = 0xffffffff;
              goto LAB_004f2f49;
            }
            sVar1 = *(short *)((int)this_00 + *(int *)(iVar5 + 8) * 0xc + 0x82);
          }
          *(int *)(*(int *)(iVar4 + 8) + 0x1c) = (int)sVar1;
        }
LAB_004f2f49:
        this_01 = FUN_004f2b60(this,iVar5);
        iVar5 = 0;
        if (0 < (int)this_01[5]) {
          do {
            iVar4 = IDMap_Lookup(this_01,iVar5,(int *)0x0);
            if (*(int *)(*(int *)(iVar4 + 8) + 0x10) == -1) {
              *(undefined4 *)(*(int *)(iVar4 + 8) + 0x10) = 0xfffffffe;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)this_01[5]);
        }
        FUN_00401440((int)this_01);
        if (this_01 != (undefined4 *)0x0) {
          (**(code **)*this_01)(1);
        }
      }
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(param_1 + 0x170c));
  }
  return;
}

