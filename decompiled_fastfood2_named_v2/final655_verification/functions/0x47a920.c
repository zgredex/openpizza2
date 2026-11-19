// rea decompile_all
// name: Branch_ApplyStatsToOwner
// address: 0x47a920
// body: available
// range: 0x47a920-0x47a9cf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Branch_ApplyStatsToOwner(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  float10 fVar6;
  
                    /* Applies branch statistics to the owner and releases staff. */
  this = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x30));
  iVar1 = FUN_004ddce0(this,(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
  iVar2 = FUN_00477c20(param_1,-1);
  if (iVar2 != 0) {
    iVar5 = 0x19;
    pfVar4 = (float *)(iVar1 + 0x78);
    do {
      iVar5 = iVar5 + -1;
      *pfVar4 = *(float *)((iVar2 - iVar1) + (int)pfVar4) + *pfVar4;
      pfVar4 = pfVar4 + 1;
    } while (iVar5 != 0);
  }
  fVar6 = FUN_00477fe0((int)param_1,-1,-1,(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10)
                      );
  *(float *)(iVar1 + 0x60) = (float)(fVar6 + (float10)*(float *)(iVar1 + 0x60));
  if (0 < *(int *)((int)param_1 + 0x1514)) {
    do {
      iVar1 = 0;
      piVar3 = (int *)FUN_004017f0((void *)((int)param_1 + 0x1500),0,(int *)0x0);
      Branch_RemoveStaffMember(param_1,piVar3,iVar1);
    } while (0 < *(int *)((int)param_1 + 0x1514));
  }
  return;
}

