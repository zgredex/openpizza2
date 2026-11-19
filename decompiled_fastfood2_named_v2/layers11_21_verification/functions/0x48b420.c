// rea decompile_all
// name: Game_ReassignDestroyedObjectReferences
// address: 0x48b420
// body: available
// range: 0x48b420-0x48b4fa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_ReassignDestroyedObjectReferences(void *this,int param_1)

{
  int iVar1;
  void *this_00;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_c;
  
                    /* Repoints references to a destroyed object at a random same-type replacement.
                        */
  iVar1 = *(int *)((int)this + 0x50);
  this_00 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
  local_c = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_004017f0((void *)((int)this + 0x3c),local_c,(int *)0x0);
      if (*(int *)(iVar2 + 0x30) != 0x2e) {
        if (*(int *)(iVar2 + 0xcc) == param_1) {
          iVar3 = FUN_004d74c0(this_00,*(int *)(param_1 + 4),param_1,'\0');
          if (iVar3 == 0) {
            iVar3 = FUN_004d74c0(this_00,0,0,'\0');
          }
          *(int *)(iVar2 + 0xcc) = iVar3;
          piVar4 = (int *)(iVar2 + 0xd4);
          iVar2 = 8;
          do {
            if (*piVar4 == param_1) {
              *piVar4 = iVar3;
            }
            piVar4 = piVar4 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        else {
          piVar4 = (int *)(iVar2 + 0xd4);
          iVar2 = 8;
          do {
            if ((*piVar4 == param_1) &&
               (iVar3 = FUN_004d74c0(this_00,*(int *)(param_1 + 4),param_1,'\0'), iVar3 != 0)) {
              *piVar4 = iVar3;
            }
            piVar4 = piVar4 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
      local_c = local_c + 1;
    } while (local_c < iVar1);
  }
  return;
}

