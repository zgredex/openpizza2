// rea decompile_all
// name: FUN_004962e0
// address: 0x4962e0
// body: available
// range: 0x4962e0-0x496670 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004962e0(void *param_1,char param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float10 fVar6;
  undefined1 *puVar7;
  undefined1 local_40 [64];
  
  if (param_2 != '\0') {
    FUN_00532330(param_1,0,4,0x4f8);
  }
  FUN_0052ff50(param_1,DAT_0057c708 + 0x4f8,1);
  iVar3 = 0;
  FUN_00532310(param_1,&LAB_00495f80,0);
  pvVar1 = *(void **)(DAT_0057c670 + 0x9c);
  DAT_0057c700 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  DAT_0057c6f8 = 0;
  DAT_0057c704 = FUN_004ddde0((int)DAT_0057c700);
  DAT_0057c70c = -1;
  FUN_00496930();
  iVar5 = *(int *)(DAT_0057c670 + 0x98);
  if ((iVar5 != 0) && (*(char *)(iVar5 + 0x1dc) == '\x01')) {
    DAT_0057c70c = FUN_004ddeb0(DAT_0057c700,iVar5);
  }
  piVar4 = &DAT_005687dc;
  iVar5 = 0x512;
  do {
    FUN_005316b0(param_1,iVar3 + 0x502);
    FUN_005316b0(param_1,iVar5);
    FUN_005316b0(param_1,*piVar4);
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + -1;
    piVar4 = piVar4 + 1;
  } while (0x50c < iVar5);
  FUN_005316b0(param_1,0x428);
  uVar2 = *(undefined4 *)((int)pvVar1 + 0x14a8);
  FUN_0052fd00(param_1,0x42c,0,500,0);
  FUN_0052fd70(param_1,0x42c,uVar2,0);
  FUN_0052fce0(param_1,0x42c,1);
  FUN_0054dd83(local_40,(byte *)s____d____005687f4,uVar2);
  FUN_0052f9b0(param_1,0x4f1,local_40);
  FUN_0054dd83(local_40,&DAT_005683a4,*(undefined4 *)((int)pvVar1 + 0x14ac));
  FUN_0052f9b0(param_1,0x1f43,local_40);
  FUN_0052ff80(param_1,0x1f42);
  FUN_0052ff80(param_1,0x1f44);
  iVar5 = *(int *)((int)pvVar1 + 0x14dc);
  if (iVar5 == 0) {
    FUN_0052f830(param_1,0x4f7,DAT_005822cc);
    puVar7 = DAT_00582e4c;
  }
  else {
    FUN_0052f830(param_1,0x4f7,iVar5 + 4);
    fVar6 = FUN_00513bf0(iVar5,(int)pvVar1,-999);
    FUN_0054dd83(local_40,(byte *)s__0_2f_005685f4,SUB84((double)fVar6,0));
    puVar7 = local_40;
  }
  FUN_0052f9b0(param_1,0x51d,puVar7);
  if (DAT_0057c704 == 0) {
    iVar5 = 0;
    piVar4 = &DAT_005687dc;
    iVar3 = 0x512;
    do {
      UI_RemoveObjectByKey(param_1,iVar5 + 0x502);
      UI_RemoveObjectByKey(param_1,iVar3);
      UI_RemoveObjectByKey(param_1,*piVar4);
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + -1;
      piVar4 = piVar4 + 1;
    } while (0x50c < iVar3);
    UI_RemoveObjectByKey(param_1,0x428);
    iVar5 = 0;
    do {
      FUN_004a80e0(param_1,0x4e8,iVar5,0,0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 8);
    return;
  }
  if (DAT_0057c704 < 7) {
    UI_RemoveObjectByKey(param_1,0x428);
    iVar5 = 0;
    if (0 < 6 - DAT_0057c704) {
      iVar3 = 0x507;
      piVar4 = &DAT_005687f0;
      do {
        UI_RemoveObjectByKey(param_1,*piVar4);
        UI_RemoveObjectByKey(param_1,iVar5 + 0x50d);
        UI_RemoveObjectByKey(param_1,iVar3);
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + -1;
        iVar3 = iVar3 + -1;
      } while (iVar5 < 6 - DAT_0057c704);
    }
  }
  else {
    if (DAT_0057c70c != -1) {
      DAT_0057c6f8 = FUN_00496900(DAT_0057c70c);
    }
    if (DAT_0057c704 < DAT_0057c6f8 + 6) {
      DAT_0057c6f8 = DAT_0057c704 + -6;
    }
    FUN_0052fd00(param_1,0x428,0,(DAT_0057c704 * 5 + -0x1e) * 0x14,0);
    FUN_0052fd70(param_1,0x428,DAT_0057c6f8 * 100,0);
    FUN_0052fce0(param_1,0x428,1);
  }
  FUN_00496680(param_1,DAT_0057c6f8,1000);
  FUN_004962a0(param_1,pvVar1);
  return;
}

