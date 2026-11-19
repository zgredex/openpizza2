// rea decompile_all
// name: Map_CountNearbyObjects
// address: 0x4d5cf0
// body: available
// range: 0x4d5cf0-0x4d5dc4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Map_CountNearbyObjects(void *this,int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  
  iVar1 = *(int *)((int)this + 0xfc0);
  *param_3 = 0;
  *param_2 = 0;
  *param_4 = 0;
  iVar2 = Game_GetObjectCenterY(param_1);
  iVar3 = Game_GetObjectBottom(param_1);
  iVar8 = 0;
  if (0 < iVar1) {
    do {
      iVar4 = IDMap_Lookup((void *)((int)this + 0xfac),iVar8,(int *)0x0);
      iVar5 = Game_GetObjectCenterY(iVar4);
      iVar6 = Game_GetObjectBottom(iVar4);
      if ((iVar2 - iVar5) * (iVar2 - iVar5) + (iVar3 - iVar6) * (iVar3 - iVar6) * 4 < 360000) {
        if (*(int *)(iVar4 + 4) == 0) {
          piVar7 = param_2;
LAB_004d5db0:
          *piVar7 = *piVar7 + 1;
        }
        else if (*(int *)(iVar4 + 4) == 0x20) {
          *param_4 = 1;
        }
        else if (*(int *)(iVar4 + 0x48) != -1) {
          piVar7 = param_3;
          goto LAB_004d5db0;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar1);
  }
  return;
}

