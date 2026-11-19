// rea decompile_all
// name: FUN_0047d080
// address: 0x47d080
// body: available
// range: 0x47d080-0x47d148 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0047d080(void *this,int param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int local_7d4;
  int local_7d0 [500];
  
  iVar6 = 0;
  local_7d4 = 0;
  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x170c)) {
    piVar5 = local_7d0;
    do {
      iVar2 = FUN_004017f0((void *)((int)this + 0x16f8),iVar6,(int *)0x0);
      if (iVar2 != 0) {
        cVar1 = FUN_004e5df0(iVar2);
        if (((cVar1 == '\x01') && (*(int *)(iVar2 + 0x10) < 1)) && (0 < *(int *)(iVar2 + 0xc))) {
          iVar3 = Game_HasAdjacentOccupiedCell(this,iVar2);
          if (iVar3 != 0) {
            *piVar5 = iVar2;
            local_7d4 = local_7d4 + 1;
            piVar5 = piVar5 + 1;
          }
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)((int)this + 0x170c));
    iVar2 = local_7d4;
  }
  *param_3 = iVar2;
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    uVar4 = FUN_004034d0(0,iVar2 - 1);
    iVar2 = local_7d0[uVar4];
    if (param_2 != 0) {
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x164);
      return iVar2;
    }
  }
  return iVar2;
}

