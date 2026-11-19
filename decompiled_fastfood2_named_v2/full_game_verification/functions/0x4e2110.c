// rea decompile_all
// name: Company_RemoveStaffMember
// address: 0x4e2110
// body: available
// range: 0x4e2110-0x4e21c7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Company_RemoveStaffMember(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  int *piVar3;
  
                    /* Unlinks a person from a company's staff map and reroutes it. */
  piVar3 = (int *)0x0;
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),param_1,(int *)0x0);
  if (this_00 != (void *)0x0) {
    *(undefined4 *)((int)this_00 + 0x110) = 0xffffffff;
    Object_SetBuildingRecordForAllCompanies(this_00,0x17,0);
    Object_SetFieldA4Locked(this_00,0xffffffff);
    *(undefined4 *)((int)this_00 + 0x10c) = 0xffffffff;
    if (*(int *)((int)this_00 + 0x74) == 0) {
      Object_SetDestinationAndTarget(this_00,5,*(int *)((int)this_00 + 0xcc));
    }
    else {
      *(undefined1 *)((int)this_00 + 0x81) = 1;
    }
    iVar1 = *(int *)((int)this + 0x1cc);
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        piVar3 = (int *)IDMap_Lookup((void *)((int)this + 0x1b8),iVar2,(int *)0x0);
        if (*piVar3 == param_1) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    IDMap_RemoveByKey((void *)((int)this + 0x1b8),(int)piVar3);
  }
  return;
}

