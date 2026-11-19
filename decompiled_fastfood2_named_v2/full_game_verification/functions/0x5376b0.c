// rea decompile_all
// name: Sprite_Blit24BitClipped
// address: 0x5376b0
// body: available
// range: 0x5376b0-0x5377cb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Sprite_Blit24BitClipped
          (void *this,int param_1,uint *param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  undefined2 *puVar13;
  uint *local_1c;
  int local_10;
  int local_c;
  int local_8;
  
  iVar5 = param_3;
  Object_GetPair4(param_2,&local_8,&local_10);
  iVar7 = *(int *)((int)this + 4) - param_3;
  param_3 = local_8;
  if (iVar7 <= local_8) {
    param_3 = iVar7;
  }
  iVar8 = *(int *)((int)this + 8) - param_4;
  iVar7 = local_10;
  if (iVar8 <= local_10) {
    iVar7 = iVar8;
  }
  iVar5 = *(int *)((int)this + 4) * param_4 + *(int *)((int)this + 0x18) + iVar5;
  iVar9 = param_6 * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28) + param_5 * 3;
  param_2 = (uint *)Object_GetPair10(param_2,&local_c);
  uVar4 = (undefined1)DAT_00585518;
  iVar8 = *(int *)(param_1 + 0x20);
  iVar2 = *(int *)((int)this + 4);
  iVar3 = *(int *)((int)this + 0x14);
  do {
    local_1c = param_2;
    param_2 = (uint *)((int)param_2 + local_c * 2);
    while( true ) {
      uVar10 = *local_1c;
      local_1c = local_1c + 1;
      uVar6 = uVar10 & 0xffff;
      if (uVar6 == 0xffff) break;
      pbVar12 = (byte *)(iVar5 + uVar6);
      puVar13 = (undefined2 *)(iVar9 + uVar6 * 3);
      uVar10 = uVar10 >> 0x10;
      if (param_3 < (int)uVar10) {
        iVar11 = param_3 - uVar6;
        if (iVar11 == 0 || param_3 < (int)uVar6) break;
      }
      else {
        iVar11 = uVar10 - uVar6;
      }
      do {
        bVar1 = *pbVar12;
        *(undefined1 *)(puVar13 + 1) = uVar4;
        *puVar13 = *(undefined2 *)(iVar3 + 4 + (uint)bVar1 * 2);
        iVar11 = iVar11 + -1;
        pbVar12 = pbVar12 + 1;
        puVar13 = (undefined2 *)((int)puVar13 + 3);
      } while (iVar11 != 0);
    }
    iVar9 = iVar9 + iVar8;
    iVar5 = iVar5 + iVar2;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      return;
    }
  } while( true );
}

