// rea decompile_all
// name: FUN_00536160
// address: 0x536160
// body: available
// range: 0x536160-0x536340 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
FUN_00536160(void *this,undefined4 param_1,FILE *param_2,void *param_3,undefined *param_4)

{
  char **ppcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  FILE *pFVar7;
  char *pcVar8;
  int iVar9;
  short local_38 [9];
  undefined4 local_26;
  undefined4 local_22;
  short local_1c;
  int local_1a;
  
  uVar4 = 0xffffffff;
  pcVar2 = (char *)((int)this + 0x1c);
  do {
    pFVar7 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pFVar7 = (FILE *)((int)&param_2->_ptr + 1);
    ppcVar1 = &param_2->_ptr;
    param_2 = pFVar7;
  } while (*(char *)ppcVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = (char *)((int)pFVar7 - uVar4);
  pcVar8 = pcVar2;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar8 = pcVar8 + 1;
  }
  if (param_3 == (void *)0x0) {
    param_2 = (FILE *)FUN_0054dfe0(pcVar2,&DAT_00563184);
    if (param_2 == (FILE *)0x0) {
      return 0;
    }
    FUN_0054e978((char *)local_38,1,0x36,(int *)param_2);
  }
  else {
    param_2 = (FILE *)FUN_00402290(param_3,pcVar2,0);
    if (param_2 == (FILE *)0x0) {
      return 0;
    }
    FUN_00402750(param_3,(char *)local_38,0x36,(int)param_2);
  }
  if (local_38[0] != 0x4d42) {
    if (param_3 == (void *)0x0) {
      FUN_0054dee4(param_2);
    }
    else {
      FUN_00402990(param_3,(int)param_2);
    }
  }
  *(undefined4 *)((int)this + 4) = local_26;
  *(undefined4 *)((int)this + 8) = local_22;
  *(byte *)((int)this + 0x10) = (byte)local_1c;
  if ((byte)local_1c < 9) {
    *(undefined1 *)((int)this + 0x11) = 1;
  }
  else if ((byte)local_1c < 0x11) {
    *(undefined1 *)((int)this + 0x11) = 2;
  }
  else if ((byte)local_1c < 0x19) {
    *(undefined1 *)((int)this + 0x11) = 3;
  }
  else {
    *(undefined1 *)((int)this + 0x11) = 4;
  }
  if (param_4 != (undefined *)0x0) {
    (*(code *)param_4)(local_22);
  }
  uVar4 = (uint)*(byte *)((int)this + 0x11) * *(int *)((int)this + 8) * *(int *)((int)this + 4);
  *(uint *)((int)this + 0xc) = uVar4;
  pcVar2 = operator_new(uVar4);
  *(char **)((int)this + 0x18) = pcVar2;
  if ((local_1a == 0) && (local_1c == 0x18)) {
    if (param_3 == (void *)0x0) {
      FUN_0054e978(pcVar2,1,*(uint *)((int)this + 0xc),(int *)param_2);
      goto LAB_00536325;
    }
    iVar3 = *(int *)((int)this + 8);
    uVar4 = -(*(int *)((int)this + 4) * 3 & 3U) & 3;
    iVar9 = 0;
    if (0 < iVar3) {
      do {
        FUN_00402750(param_3,pcVar2 + ((iVar3 - iVar9) + -1) * *(int *)((int)this + 4) * 3,
                     *(int *)((int)this + 4) * 3,(int)param_2);
        if (uVar4 != 0) {
          Stream_Seek(uVar4,(int)param_2,1);
        }
        iVar3 = *(int *)((int)this + 8);
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar3);
    }
  }
  if (param_3 != (void *)0x0) {
    FUN_00402990(param_3,(int)param_2);
    return 1;
  }
LAB_00536325:
  FUN_0054dee4(param_2);
  return 1;
}

