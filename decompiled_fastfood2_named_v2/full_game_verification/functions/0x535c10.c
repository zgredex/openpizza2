// rea decompile_all
// name: Font_WrapText
// address: 0x535c10
// body: available
// range: 0x535c10-0x535caa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Font_WrapText(void *this,char *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  char *in_EAX;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_4;
  
  if (*param_1 != '\0') {
    in_EAX = param_1;
    do {
      if (*in_EAX == '\n') {
        *in_EAX = ' ';
      }
      pcVar1 = in_EAX + 1;
      in_EAX = in_EAX + 1;
    } while (*pcVar1 != '\0');
  }
  cVar2 = *param_1;
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),cVar2);
  iVar6 = 0;
  iVar7 = 0;
  iVar8 = -1;
  while (cVar2 != '\0') {
    cVar2 = param_1[iVar6];
    uVar5 = CONCAT31((int3)(uVar5 >> 8),cVar2);
    if (cVar2 == ' ') {
      iVar8 = iVar6;
      local_4 = iVar7;
    }
    if (cVar2 == '\r') {
      iVar7 = 0;
      iVar8 = -1;
    }
    else {
      uVar3 = Font_GetCharWidth(this,uVar5);
      uVar5 = iVar7 + CONCAT31(extraout_var,uVar3);
      if ((param_2 < (int)uVar5) && (iVar8 != -1)) {
        param_1[iVar8] = '\n';
        uVar4 = Font_GetCharWidth(this,0x20);
        uVar5 = CONCAT31(extraout_var_00,uVar4) + local_4;
        iVar7 = iVar7 - uVar5;
        iVar8 = -1;
      }
      iVar7 = iVar7 + CONCAT31(extraout_var,uVar3);
    }
    iVar6 = iVar6 + 1;
    cVar2 = param_1[iVar6];
  }
  return;
}

