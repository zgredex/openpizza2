// rea decompile_all
// name: Sprite_FillColor8
// address: 0x53dd90
// body: available
// range: 0x53dd90-0x53de5e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall Sprite_FillColor8(void *param_1)

{
  undefined1 uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int local_4;
  
                    /* Depth-1 proposal batch 3/4. */
  if (((*(byte *)((int)param_1 + 4) & 1) != 0) || (*(char *)((int)param_1 + 5) != '\b')) {
    return 0;
  }
  if (*(byte *)((int)param_1 + 0x36) == 0xffffffff) {
    FUN_0053d840(param_1,(undefined2 *)0x0);
  }
  if (*(byte *)((int)param_1 + 0x36) == 0xffffffff) {
    return 0;
  }
  iVar9 = *(int *)((int)param_1 + 0x30);
  if (*(char *)((int)param_1 + 0x37) == '\0') {
    sVar2 = *(short *)((int)param_1 + 8);
    sVar3 = *(short *)((int)param_1 + 6);
  }
  else {
    sVar2 = *(short *)((int)param_1 + 6);
    sVar3 = *(short *)((int)param_1 + 8);
  }
  local_4 = (int)sVar2;
  iVar8 = (int)sVar3;
  uVar1 = *(undefined1 *)((int)param_1 + 0x1c);
  uVar7 = 0;
  if (0 < local_4) {
    do {
      if ((*(byte *)((int)param_1 + 4) & 0x10) == 0) {
        for (uVar6 = uVar7 & 1; iVar4 = iVar8, (int)uVar6 < iVar8; uVar6 = uVar6 + 2) {
          *(undefined1 *)(uVar6 + iVar9) = uVar1;
        }
      }
      else {
        uVar6 = uVar7 & 1;
        if ((int)uVar6 < iVar8) {
          puVar5 = (undefined1 *)(iVar9 + uVar6 * 2);
          uVar6 = (iVar8 - uVar6) + 1 >> 1;
          do {
            *puVar5 = 0;
            puVar5[1] = 1;
            puVar5 = puVar5 + 4;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        iVar4 = iVar8 * 2;
      }
      iVar9 = iVar9 + iVar4;
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < local_4);
  }
  return 1;
}

