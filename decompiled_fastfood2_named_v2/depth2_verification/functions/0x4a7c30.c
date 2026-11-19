// rea decompile_all
// name: FUN_004a7c30
// address: 0x4a7c30
// body: available
// range: 0x4a7c30-0x4a7f75 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a7c30(int *param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int *this;
  int iVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  undefined4 uVar7;
  int local_8;
  int local_4;
  
  this = param_1;
  iVar3 = 0;
  piVar2 = *(int **)(*(int *)(DAT_0057c670 + 0x224) + 0xac);
  local_8 = 0;
  local_4 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (local_4 == 0) {
    local_4 = 0;
  }
  else {
    local_4 = local_4 + 4;
  }
  iVar4 = 0x1f44;
  do {
    FUN_0052f9b0(param_1,iVar4,DAT_00582adc);
    FUN_0052f910(param_1,iVar4,0);
    FUN_0052f910(param_1,iVar4 + 3,0);
    iVar1 = iVar4 + -0x1f43;
    iVar4 = iVar4 + 1;
  } while (iVar1 < 3);
  iVar4 = 0x1f44;
  param_1 = piVar2;
  do {
    param_1 = param_1 + 1;
    iVar1 = *param_1;
    if (iVar1 < 0) {
      local_8 = local_8 + 1;
    }
    else {
      if (*(int *)(&DAT_00571e0c + iVar1 * 4) == 0) {
        if (*(char *)((int)piVar2 + iVar3 + 0xc4) == '\0') {
          FUN_0052f910(this,iVar4 + 3,0xff);
          uVar7 = 0xff;
          iVar6 = iVar4;
        }
        else {
          FUN_0052f910(this,iVar4,0xa000);
          uVar7 = 0xa000;
          iVar6 = iVar4 + 3;
        }
LAB_004a7d7b:
        FUN_0052f910(this,iVar6,uVar7);
        if ((iVar1 == 0) && (DAT_0057bb20 == '\0')) {
          FUN_0052f9b0(this,iVar4,DAT_00580de8);
          iVar4 = iVar4 + 1;
          goto LAB_004a7da5;
        }
      }
      else {
        if (iVar1 != 0xf) {
          FUN_0052f910(this,iVar4,0xa000);
          iVar6 = iVar4 + 3;
          uVar7 = 0xa000;
          goto LAB_004a7d7b;
        }
        if (piVar2[0x13] < 2) {
          FUN_0052f910(this,iVar4,0xa000);
          uVar7 = 0xa000;
        }
        else {
          FUN_0052f910(this,iVar4,0xff);
          uVar7 = 0xff;
        }
        FUN_0052f910(this,iVar4 + 3,uVar7);
      }
      FUN_0052f9b0(this,iVar4,*(undefined4 *)(&DAT_00583384 + iVar1 * 4));
      iVar4 = iVar4 + 1;
    }
LAB_004a7da5:
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  if (local_8 == 3) {
    FUN_0052f9b0(this,0x1f43,DAT_005818e0);
    iVar3 = 0x1f44;
    do {
      UI_RemoveObjectByKey(this,iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x1f4a);
LAB_004a7de9:
    UI_RemoveObjectByKey(this,0x1f4b);
    FUN_0052f9b0(this,0x1f4a,DAT_00582b28);
  }
  else {
    if (DAT_0057bb2c == 0xb) goto LAB_004a7de9;
    FUN_0052f080(this,0x1f4b,(byte *)s__d__s_00568324,piVar2[0x30]);
  }
  if (DAT_0057bb20 == '\0') {
    if ((char)piVar2[0x33] != '\0') {
      FUN_0052f9b0(this,0x42b,local_4 + 0x818);
      if (param_2 != '\0') {
        FUN_00549070(DAT_0057ba0c,DAT_0057bb40,'\x01');
      }
      goto LAB_004a7eae;
    }
    local_4 = local_4 + 0x418;
  }
  else if ((char)piVar2[0x33] == '\0') {
    local_4 = DAT_005811dc;
  }
  else {
    local_4 = DAT_005818f8;
  }
  FUN_0052f9b0(this,0x42b,local_4);
LAB_004a7eae:
  iVar3 = 0x1f42;
  if ((char)piVar2[0x33] != '\0') {
    FUN_005316b0(this,0x1f42);
    FUN_0052f830(this,0x1f42,DAT_00582e70);
    UI_RemoveObjectByKey(this,0x1f43);
    UI_RemoveObjectByKey(this,0x1f4a);
    iVar3 = 0x1f4b;
  }
  UI_RemoveObjectByKey(this,iVar3);
  if (DAT_0057bb40 == 8) {
    FUN_005316b0(this,0x1f4c);
    FUN_005316b0(this,0x1f4d);
    FUN_004e09e0(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4),0x19,-1,-1);
    lVar5 = __ftol();
    FUN_0052f080(this,0x1f4d,&DAT_005683a4,(int)lVar5);
    return;
  }
  UI_RemoveObjectByKey(this,0x1f4c);
  UI_RemoveObjectByKey(this,0x1f4d);
  return;
}

