// rea decompile_all
// name: FUN_00537390
// address: 0x537390
// body: available
// range: 0x537390-0x5374ab inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00537390(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_4;
  
  iVar1 = param_3;
  if ((*(byte *)((int)this + 0x10) < 0x11) && (0xe < *(byte *)((int)this + 0x10))) {
    iVar4 = *(int *)((int)this + 8);
    local_4 = 0;
    if (param_3 < 0) {
      param_3 = 0;
      local_4 = -iVar1;
      iVar4 = iVar4 + iVar1;
    }
    iVar1 = param_3;
    if ((int)(uint)*(ushort *)(param_1 + 0x1c) <= iVar4 + param_3) {
      iVar4 = (uint)*(ushort *)(param_1 + 0x1c) - param_3;
    }
    if (0 < iVar4) {
      if (iVar4 < *(int *)((int)this + 8)) {
        uVar2 = *(int *)((int)this + 4) * *(int *)((int)this + 8);
        puVar5 = *(undefined4 **)((int)this + 0x18);
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar5 = 0;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      }
      param_3 = *(int *)((int)this + 4);
      puVar5 = (undefined4 *)(*(int *)((int)this + 0x18) + param_3 * local_4 * 2);
      if (param_2 < 0) {
        param_3 = param_3 + param_2 * -2;
        puVar5 = puVar5 + -param_2;
        param_2 = 0;
      }
      puVar6 = (undefined4 *)
               (*(int *)(param_1 + 0x28) + (*(int *)(param_1 + 0x20) * iVar1 + param_2) * 2);
      if (0 < iVar4) {
        iVar1 = *(int *)(param_1 + 0x20);
        param_1 = iVar4;
        do {
          FUN_00539770(puVar5,puVar6,param_3 * 2,1);
          puVar6 = (undefined4 *)((int)puVar6 + iVar1 * 2);
          puVar5 = (undefined4 *)((int)puVar5 + *(int *)((int)this + 4) * 2);
          param_1 = param_1 + -1;
        } while (param_1 != 0);
      }
      return 1;
    }
  }
  return 0;
}

