// rea decompile_all
// name: Gfx_BlitScaled16Rows
// address: 0x53a270
// body: available
// range: 0x53a270-0x53a3b6 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Gfx_BlitScaled16Rows(void *this,int param_1,undefined4 *param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_4;
  
  uVar4 = param_4;
  if ((((*(byte *)((int)this + 4) & 1) == 0) && (*(char *)((int)this + 5) == '\x10')) &&
     (*(int *)(param_1 + 0x28) != 0)) {
    puVar7 = (undefined4 *)(int)*(short *)((int)this + 8);
    local_4 = 0;
    puVar6 = puVar7;
    if ((int)param_4 < 0) {
      param_4 = 0;
      local_4 = -uVar4;
      puVar6 = (undefined4 *)((int)puVar7 + uVar4);
    }
    uVar4 = param_4;
    if ((int)(uint)*(ushort *)(param_1 + 0x1c) <= (int)((int)puVar6 + param_4)) {
      puVar6 = (undefined4 *)(*(ushort *)(param_1 + 0x1c) - param_4);
    }
    if ((int)puVar6 < 1) {
      uVar1 = *(undefined1 *)((int)this + 0x1c);
      uVar3 = (int)*(short *)((int)this + 6) * (int)puVar7;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *param_2 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
        param_2 = param_2 + 1;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)param_2 = uVar1;
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
      return;
    }
    if (puVar6 != puVar7) {
      uVar1 = *(undefined1 *)((int)this + 0x1c);
      uVar5 = (int)*(short *)((int)this + 6) * (int)puVar7;
      puVar7 = param_2;
      for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar7 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
        puVar7 = puVar7 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar7 = uVar1;
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
    }
    param_4 = (uint)*(short *)((int)this + 6);
    puVar7 = (undefined4 *)(param_4 * local_4 + (int)param_2);
    if (param_3 < 0) {
      param_4 = param_4 + param_3 * 2;
      puVar7 = (undefined4 *)((int)puVar7 + param_3 * -2);
      param_3 = 0;
    }
    iVar2 = *(int *)(param_1 + 0x20);
    puVar8 = (undefined4 *)(*(int *)(param_1 + 0x28) + (iVar2 * uVar4 + param_3) * 2);
    if (0 < (int)puVar6) {
      param_2 = puVar6;
      do {
        Memory_Fill16(puVar7,puVar8,param_4,1);
        puVar7 = (undefined4 *)((int)puVar7 + (int)*(short *)((int)this + 6));
        puVar8 = (undefined4 *)((int)puVar8 + iVar2 * 2);
        param_2 = (undefined4 *)((int)param_2 + -1);
      } while (param_2 != (undefined4 *)0x0);
    }
  }
  return;
}

