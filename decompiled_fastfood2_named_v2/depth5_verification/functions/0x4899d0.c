// rea decompile_all
// name: FUN_004899d0
// address: 0x4899d0
// body: available
// range: 0x4899d0-0x489b0d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004899d0(void *this,undefined4 param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_10;
  int local_c;
  
  if (*(int *)((int)param_2 + 0xc) != 0x10) {
    local_10 = 0;
    do {
      iVar1 = FUN_00488be0(this,local_10);
      if ((iVar1 != 0) && (iVar1 = FUN_00488be0(this,local_10), *(int *)(iVar1 + 0x1e4) != 0)) {
        iVar1 = FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
        if (iVar1 == 0) {
          return;
        }
        local_c = 0;
        if (0 < *(int *)(iVar1 + 0xfc0)) {
          do {
            iVar2 = FUN_004017f0((void *)(iVar1 + 0xfac),local_c,(int *)0x0);
            if ((((*(int *)(iVar2 + 4) == 0x1b) || (*(int *)(iVar2 + 4) == 0xf)) &&
                (*(int *)(iVar2 + 0x28) == local_10)) &&
               ((*(int *)(iVar2 + 0x74) != 0 &&
                (iVar3 = FUN_004e4490(*(int *)(iVar2 + 0x74)), 0 < iVar3)))) {
              iVar3 = FUN_00488be0(this,*(int *)(iVar2 + 8));
              FUN_004e2250(iVar3);
              FUN_004d2320(iVar2);
              FUN_004d2360(iVar2);
              FUN_004f3510(param_2);
            }
            local_c = local_c + 1;
          } while (local_c < *(int *)(iVar1 + 0xfc0));
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < 6);
  }
  return;
}

