// rea decompile_all
// name: Game_RedirectPersonDestination
// address: 0x48c6d0
// body: available
// range: 0x48c6d0-0x48c7a8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_RedirectPersonDestination(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  undefined4 *this_01;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_10;
  
                    /* Retargets one random person destination to a newly completed building. */
  iVar1 = *(int *)(param_1 + 0x30);
  this_00 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
  this_01 = FUN_004d59c0(this_00,iVar1,param_1,'\0');
  iVar1 = this_01[5];
  uVar2 = FUN_004034d0(1,iVar1 + 1);
  local_10 = 0;
  if (0 < *(int *)((int)this + 0x50)) {
    do {
      iVar3 = FUN_004017f0((void *)((int)this + 0x3c),local_10,(int *)0x0);
      iVar7 = 0;
      if (0 < iVar1) {
        do {
          iVar4 = FUN_004017f0(this_01,iVar7,(int *)0x0);
          iVar6 = 8;
          piVar5 = (int *)(iVar3 + 0xd4);
          do {
            if ((*piVar5 == iVar4) && (uVar2 = uVar2 - 1, uVar2 == 0)) {
              uVar2 = iVar1 + 1;
              *piVar5 = param_1;
            }
            piVar5 = piVar5 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar1);
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)((int)this + 0x50));
  }
  if (this_01 != (undefined4 *)0x0) {
    (**(code **)*this_01)(1);
  }
  return;
}

