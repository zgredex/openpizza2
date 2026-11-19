// rea decompile_all
// name: FUN_0047e750
// address: 0x47e750
// body: available
// range: 0x47e750-0x47e85b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_0047e750(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_1a8;
  int local_1a4;
  void *local_1a0;
  int *local_19c;
  int local_198;
  int local_194;
  int local_190 [100];
  
  iVar7 = 0;
  local_194 = *(int *)(param_1 + 0x19ac);
  iVar1 = *(int *)(param_1 + 0x1514);
  local_1a8 = 0;
  if (local_194 < 1) {
    return -1;
  }
  local_1a0 = (void *)(param_1 + 0x1998);
  local_19c = local_190;
  local_198 = param_1;
  do {
    iVar2 = local_198;
    iVar3 = IDMap_Lookup(local_1a0,iVar7,&local_1a4);
    if (*(int *)(iVar3 + 0x1c) == 0) {
      iVar3 = 0;
      if (0 < iVar1) {
        do {
          piVar4 = (int *)IDMap_Lookup((void *)(iVar2 + 0x1500),iVar3,(int *)0x0);
          iVar5 = *piVar4;
          if (((*(char *)(iVar5 + 0x824) == '\x03') && (*(char *)(iVar5 + 0x825) == '\x04')) &&
             (iVar5 = FUN_004d3910(iVar5), *(int *)(iVar5 + 0x88) == local_1a4)) {
            if (iVar3 < iVar1) goto LAB_0047e80c;
            break;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
      local_1a8 = local_1a8 + 1;
      *local_19c = iVar7;
      local_19c = local_19c + 1;
    }
LAB_0047e80c:
    iVar7 = iVar7 + 1;
    if (local_194 <= iVar7) {
      if (local_1a8 == 0) {
        return -1;
      }
      uVar6 = FUN_004034d0(0,local_1a8 - 1);
      IDMap_Lookup(local_1a0,local_190[uVar6],&local_1a4);
      return local_1a4;
    }
  } while( true );
}

