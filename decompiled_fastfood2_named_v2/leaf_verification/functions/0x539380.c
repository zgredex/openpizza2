// rea decompile_all
// name: Gfx_Blit16Clipped
// address: 0x539380
// body: available
// range: 0x539380-0x539543 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Gfx_Blit16Clipped(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6
                 ,int param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  int local_18;
  int local_14;
  
                    /* Leaf reversal proposal batch 2. */
  iVar3 = param_3 + param_1;
  iVar4 = param_2 + param_4;
  local_18 = param_6;
  local_14 = param_7;
  iVar2 = *(int *)(param_5 + 4);
  if (param_6 < iVar2) {
    param_1 = (iVar2 - param_6) + param_1;
    local_18 = iVar2;
  }
  iVar2 = *(int *)(param_5 + 0xc);
  if (param_7 < iVar2) {
    param_2 = (iVar2 - param_7) + param_2;
    local_14 = iVar2;
  }
  if (*(int *)(param_5 + 8) < param_3 + param_6) {
    iVar3 = iVar3 + (*(int *)(param_5 + 8) - (param_3 + param_6));
  }
  if (*(int *)(param_5 + 0x10) < param_4 + param_7) {
    iVar4 = iVar4 + (*(int *)(param_5 + 0x10) - (param_4 + param_7));
  }
  if (param_1 < *(int *)((int)this + 4)) {
    local_18 = local_18 + (*(int *)((int)this + 4) - param_1);
    param_1 = *(int *)((int)this + 4);
  }
  if (param_2 < *(int *)((int)this + 0xc)) {
    local_14 = local_14 + (*(int *)((int)this + 0xc) - param_2);
    param_2 = *(int *)((int)this + 0xc);
  }
  if (*(int *)((int)this + 8) < iVar3) {
    iVar3 = *(int *)((int)this + 8);
  }
  if (*(int *)((int)this + 0x10) < iVar4) {
    iVar4 = *(int *)((int)this + 0x10);
  }
  uVar1 = iVar3 - param_1;
  iVar4 = iVar4 - param_2;
  if ((0 < (int)uVar1) && (0 < iVar4)) {
    iVar3 = *(int *)((int)this + 0x20) * 2;
    puVar9 = (undefined8 *)
             (*(int *)((int)this + 0x28) + (*(int *)((int)this + 0x20) * param_2 + param_1) * 2);
    iVar2 = *(int *)(param_5 + 0x20) * 2;
    puVar7 = (undefined8 *)
             (*(int *)(param_5 + 0x28) + (*(int *)(param_5 + 0x20) * local_14 + local_18) * 2);
    if (*(int *)(DAT_0057c5c8 + 0x74) != 0) {
      do {
        uVar5 = uVar1;
        puVar6 = puVar7;
        puVar10 = puVar9;
        do {
          puVar8 = puVar10;
          if ((uVar5 & 3) == 0) break;
          puVar8 = (undefined8 *)((int)puVar10 + 2);
          *(undefined2 *)puVar10 = *(undefined2 *)puVar6;
          puVar6 = (undefined8 *)((int)puVar6 + 2);
          uVar5 = (uVar5 & 3) - 1;
          puVar10 = puVar8;
        } while (uVar5 != 0);
        for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar8 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar7 = (undefined8 *)((int)puVar7 + iVar2);
        puVar9 = (undefined8 *)((int)puVar9 + iVar3);
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return;
        }
      } while( true );
    }
    do {
      puVar6 = puVar7;
      puVar10 = puVar9;
      if ((uVar1 & 1) != 0) {
        puVar10 = (undefined8 *)((int)puVar9 + 2);
        *(undefined2 *)puVar9 = *(undefined2 *)puVar7;
        puVar6 = (undefined8 *)((int)puVar7 + 2);
      }
      for (uVar5 = uVar1 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)puVar10 = *(undefined4 *)puVar6;
        puVar6 = (undefined8 *)((int)puVar6 + 4);
        puVar10 = (undefined8 *)((int)puVar10 + 4);
      }
      puVar7 = (undefined8 *)((int)puVar7 + iVar2);
      puVar9 = (undefined8 *)((int)puVar9 + iVar3);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

