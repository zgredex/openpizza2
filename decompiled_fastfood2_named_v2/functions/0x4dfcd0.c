// rea decompile_all
// name: FUN_004dfcd0
// address: 0x4dfcd0
// body: available
// range: 0x4dfcd0-0x4dfe32 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004dfcd0(void *this,int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_10;
  
  iVar6 = 1;
  iVar1 = *(int *)((int)this + 0x70);
  iVar2 = *(int *)((int)this + 0x74);
  iVar3 = *(int *)((int)this + 0x8c);
  iVar8 = 1;
  iVar7 = 1;
  local_10 = 0;
  do {
    iVar5 = FUN_00488be0(DAT_0057c670,local_10);
    if (iVar5 != 0) {
      if (iVar1 < *(int *)(iVar5 + 0x70)) {
        iVar6 = 0;
      }
      if (iVar2 < *(int *)(iVar5 + 0x74)) {
        iVar8 = 0;
      }
      if (*(int *)(iVar5 + 0x8c) < iVar3) {
        iVar7 = 0;
      }
    }
    local_10 = local_10 + 1;
  } while (local_10 < 6);
  if (iVar1 == 0) {
    iVar6 = 0;
  }
  if (iVar2 == 0) {
    iVar8 = 0;
  }
  if (iVar3 == 0) {
    iVar7 = 0;
  }
  *(int *)(*param_1 + 0xbc) = iVar1;
  *(int *)(*param_1 + 0xc0) = iVar6;
  *(int *)(*param_1 + 0x180) = (iVar1 + iVar6 * 0x32) * 100;
  *(int *)(*param_1 + 0xc4) = iVar2;
  *(int *)(*param_1 + 200) = iVar8;
  *(int *)(*param_1 + 0x184) = (iVar2 + iVar8 * 0x32) * 100;
  *(int *)(*param_1 + 0xcc) = iVar3;
  *(int *)(*param_1 + 0xd0) = iVar7;
  *(int *)(*param_1 + 0x188) = (iVar3 + iVar7 * 0x32) * 100;
  iVar1 = *(int *)((int)this + 0x88);
  uVar4 = *(undefined4 *)((int)this + 0x90);
  *(int *)(*param_1 + 0xd4) = iVar1;
  *(undefined4 *)(*param_1 + 0xd8) = uVar4;
  *(int *)(*param_1 + 0x18c) = iVar1 * 10000;
  return;
}

