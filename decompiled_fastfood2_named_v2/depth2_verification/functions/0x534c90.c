// rea decompile_all
// name: FUN_00534c90
// address: 0x534c90
// body: available
// range: 0x534c90-0x534d53 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall
FUN_00534c90(void *this,int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_48 [18];
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 0x48))) {
    in_EAX = *(uint *)((int)this + 0x4c);
    iVar3 = param_1 * 0x48;
    if (*(int *)(in_EAX + iVar3) != -1) {
      FUN_00401320(0x5842a0);
      puVar5 = (undefined4 *)(*(int *)((int)this + 0x4c) + iVar3);
      puVar4 = puVar5;
      puVar6 = local_48;
      for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      Record_AdvanceFrameSequence
                (this,param_1,param_2,(double *)(puVar5 + 2),(double *)(puVar5 + 4),param_5);
      iVar2 = *(int *)((int)this + 0x4c);
      *param_3 = *(undefined4 *)(iVar2 + 8 + iVar3);
      param_3[1] = *(undefined4 *)(iVar2 + 0xc + iVar3);
      iVar2 = *(int *)((int)this + 0x4c);
      *param_4 = *(undefined4 *)(iVar2 + 0x10 + iVar3);
      param_4[1] = *(undefined4 *)(iVar2 + 0x14 + iVar3);
      puVar5 = local_48;
      puVar4 = (undefined4 *)(*(int *)((int)this + 0x4c) + iVar3);
      for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar4 = puVar4 + 1;
      }
      uVar1 = FUN_00401340(0x5842a0);
      return uVar1 & 0xffffff00;
    }
  }
  return in_EAX & 0xffffff00;
}

