// rea decompile_all
// name: Object_SetFacadeAndLogoVariant
// address: 0x4dc540
// body: available
// range: 0x4dc540-0x4dc65d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Object_SetFacadeAndLogoVariant(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  
                    /* Selects FARBANIM and LOGO variants on an object's children. */
  CS_Enter(*(int *)(DAT_0057c670 + 0x248));
  iVar1 = *(int *)(*(int *)((int)this + 0xfa8) + 0x4c) + *(int *)(param_2 + 0x24) * 0xc;
  iVar4 = Game_FindCityIndex(param_3);
  iVar2 = *(int *)(param_3 + 0x1e0);
  iVar5 = *(int *)(iVar1 + 8);
  iVar8 = 0;
  param_2 = 0;
  if (0 < *(int *)(iVar5 + 0x14)) {
    do {
      piVar6 = (int *)(*(int *)(iVar5 + 0x18) + iVar8);
      pcVar3 = (char *)piVar6[2];
      iVar5 = *piVar6;
      if (*pcVar3 == '\x02') {
        pcVar7 = _strstr(pcVar3 + 4,s_FARBANIM_0056d05c);
        if (pcVar7 != (char *)0x0) {
          *(int *)(*(int *)(*(int *)(iVar1 + 8) + 0x18) + 4 + iVar8) = param_1;
          if (param_1 == 0) {
            Record_ClearFlags48(*(void **)(pcVar3 + 0x48),iVar5);
          }
          else {
            Record_SelectVariant(*(void **)(pcVar3 + 0x48),iVar5,iVar4);
          }
        }
        pcVar7 = _strstr(pcVar3 + 4,&DAT_0056d054);
        if (pcVar7 != (char *)0x0) {
          *(int *)(*(int *)(*(int *)(iVar1 + 8) + 0x18) + 4 + iVar8) = param_1;
          if (param_1 == 0) {
            Record_ClearFlags48(*(void **)(pcVar3 + 0x48),iVar5);
          }
          else {
            Record_SelectVariant(*(void **)(pcVar3 + 0x48),iVar5,iVar2);
          }
        }
      }
      iVar5 = *(int *)(iVar1 + 8);
      param_2 = param_2 + 1;
      iVar8 = iVar8 + 0xc;
    } while (param_2 < *(int *)(iVar5 + 0x14));
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x248));
  return;
}

