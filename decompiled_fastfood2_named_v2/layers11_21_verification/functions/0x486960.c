// rea decompile_all
// name: FUN_00486960
// address: 0x486960
// body: available
// range: 0x486960-0x486b72 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00486960(int param_1)

{
  int *piVar1;
  void *this;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  byte *pbVar6;
  int local_108;
  byte local_100 [256];
  
  FUN_004017f0((void *)(param_1 + 4),*(int *)(param_1 + 0x2f4),(int *)0x0);
  local_108 = 0;
  if (0 < *(int *)(param_1 + 0x50)) {
    do {
      this = (void *)FUN_004017f0((void *)(param_1 + 0x3c),local_108,(int *)0x0);
      iVar3 = *(int *)((int)this + 0x30);
      if (iVar3 == 0xb) {
        if (((*(int *)((int)this + 0x74) == 0) &&
            (pvVar4 = Game_FindBestCompositeRatedBranch(-1), pvVar4 != (void *)0x0)) &&
           (*(int *)((int)pvVar4 + 0x16f0) != 0)) {
          FUN_00507e20(this,1,*(int *)((int)pvVar4 + 0x16f0));
        }
      }
      else if (iVar3 == 0xf) {
        uVar2 = FUN_004034d0(0,2);
        if (((uVar2 == 0) && (*(int *)((int)this + 0x74) == 0)) &&
           ((pvVar4 = Game_FindBestCompositeRatedBranch(5), pvVar4 != (void *)0x0 &&
            (*(int *)((int)pvVar4 + 0x16f0) != 0)))) {
          FUN_0054a660(DAT_0057c1e0,0xa000,(byte *)s_Prommi_geht_nach__s_00568150,(int)pvVar4 + 4);
          FUN_00507e20(this,1,*(int *)((int)pvVar4 + 0x16f0));
          iVar3 = *(int *)((int)pvVar4 + 0x30);
          iVar5 = FUN_00482820(param_1);
          if (iVar3 == iVar5) {
            pbVar6 = local_100;
            FUN_0054dd83(pbVar6,DAT_005825d8,(int)pvVar4 + 4);
            FUN_0054a980((void *)(param_1 + 0x304),-1,0,4,1,*(int *)((int)pvVar4 + 0x16f0),
                         DAT_00582a6c,local_100,pbVar6);
            FUN_00503250(*(void **)(*(int *)(param_1 + 0x224) + 0xa8),7,-1);
            FUN_00503250(*(void **)(*(int *)(param_1 + 0x224) + 0xa8),0x12,-1);
          }
        }
      }
      else if ((iVar3 == 0x21) && (*(int *)(*(int *)(*(int *)(param_1 + 0x224) + 0xa8) + 0xb8) != 0)
              ) {
        if (*(int *)((int)this + 0x74) == 0) {
          iVar3 = *(int *)(param_1 + 0x200 + *(int *)(param_1 + 0x2ec) * 4);
          iVar5 = *(int *)(iVar3 + 0x15c);
          if (iVar5 == 0) goto LAB_00486b54;
          uVar2 = FUN_004034d0(0,iVar5 - 1);
          iVar3 = FUN_004017f0((void *)(iVar3 + 0x148),uVar2,(int *)0x0);
          if (iVar3 != 0) {
            FUN_00507e20(this,1,*(int *)(iVar3 + 0x16f0));
          }
        }
        piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x224) + 0xa8) + 0xb8);
        *piVar1 = *piVar1 + -1;
      }
LAB_00486b54:
      local_108 = local_108 + 1;
    } while (local_108 < *(int *)(param_1 + 0x50));
  }
  return;
}

