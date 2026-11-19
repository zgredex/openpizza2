// rea decompile_all
// name: City_RemovePersonAndMaintainPopulation
// address: 0x4d6c10
// body: available
// range: 0x4d6c10-0x4d6ca8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall City_RemovePersonAndMaintainPopulation(void *this,int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_8;
  
                    /* Removes a person and probabilistically spawns a replacement. */
  iVar3 = *(int *)((int)this + 0xfdc);
  iVar5 = 0;
  local_8 = 0;
  if (0 < iVar3) {
    do {
      piVar2 = (int *)FUN_004017f0((void *)((int)this + 0xfc8),iVar5,(int *)0x0);
      if (*piVar2 == param_1) {
        local_8 = FUN_00401790((void *)((int)this + 0xfc8),(int)piVar2);
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  bVar1 = *(byte *)(param_1 + 0x824);
  iVar3 = FUN_004d6ba0(this,(uint)bVar1);
  if ((iVar3 == 0) || (uVar4 = FUN_004034d0(0,99), (int)uVar4 < iVar3 * -0x1e + 100)) {
    City_SpawnPerson(this,(uint)bVar1);
  }
  return local_8;
}

