// rea decompile_all
// name: FUN_004fb660
// address: 0x4fb660
// body: available
// range: 0x4fb660-0x4fba83 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_004fb660(int param_1,int param_2,void *param_3,int param_4,int param_5,undefined4 *param_6,
                int param_7,int param_8)

{
  int iVar1;
  int extraout_ECX;
  undefined4 unaff_EBX;
  uint uVar2;
  char *unaff_EBP;
  char *unaff_ESI;
  char *unaff_EDI;
  bool bVar3;
  undefined1 unaff_retaddr;
  int iVar4;
  int iStack00000024;
  uint uStack00000028;
  uint uStack0000002c;
  uint uStack00000030;
  int in_stack_00001938;
  void *in_stack_0000193c;
  int in_stack_00001940;
  int in_stack_00001944;
  int in_stack_00001948;
  uint in_stack_0000194c;
  char cVar5;
  
  __chkstk(unaff_retaddr);
  if ((*(int *)((int)in_stack_0000193c + 0x2c) != 0) &&
     (*(int *)((int)in_stack_0000193c + 0x2c) != 3)) {
    return 1;
  }
  if (*(int *)(*(int *)((int)in_stack_0000193c + 0x16f0) + 0x38) != 0) {
    return 3;
  }
  if (0 < *(int *)(*(int *)((int)in_stack_0000193c + 0x16f0) + 0x8c)) {
    FUN_0047f420(in_stack_0000193c,3);
    return 1;
  }
  if (0 < *(int *)((int)in_stack_0000193c + 0x170c)) {
    if (((*(byte *)((int)in_stack_0000193c + 0x28) & 4) == 0) &&
       (6 < *(int *)((int)in_stack_0000193c + 0x170c))) {
      return 1;
    }
    FUN_0047c5e0(in_stack_0000193c,0);
    FUN_0047c7d0(in_stack_0000193c);
  }
  uVar2 = 0;
  uStack00000030 = in_stack_0000194c;
  if (in_stack_00001940 == -1) {
    if (*(int *)(extraout_ECX + 0x134 + in_stack_00001938 * 0x168) < 80000) {
      *(undefined4 *)((int)in_stack_0000193c + 0x24) = 0;
      in_stack_00001940 = 0;
    }
    else {
      FUN_004f7320((int)in_stack_0000193c);
      in_stack_00001940 = *(int *)((int)in_stack_0000193c + 0x24);
      uStack00000030 = in_stack_0000194c;
    }
  }
  else {
    bVar3 = in_stack_00001940 == 4;
    if (bVar3) {
      in_stack_00001940 = 0;
    }
    uVar2 = (uint)bVar3;
    *(int *)((int)in_stack_0000193c + 0x24) = in_stack_00001940;
  }
  param_4 = *(int *)((int)in_stack_0000193c + 0x38);
  iVar4 = *(int *)((int)in_stack_0000193c + 0x30);
  param_5 = 1;
  param_6 = (undefined4 *)0x0;
  param_8 = in_stack_00001944;
  if (in_stack_00001944 == -1) {
    param_8 = 2;
  }
  iStack00000024 = param_8;
  if (in_stack_00001948 != -1) {
    iStack00000024 = in_stack_00001948;
  }
  param_3 = in_stack_0000193c;
  uStack00000028 = uVar2;
  if (uStack00000030 == 0xffffffff) {
    uStack0000002c = _rand();
    uStack0000002c = uStack0000002c & 1;
    uStack00000030 = _rand();
    uStack00000030 = uStack00000030 & 1;
  }
  else {
    uStack0000002c = uStack00000030;
  }
  iVar1 = FUN_004fb170(&param_3,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,iVar4,param_1,param_2,
                       (int)param_3,param_4,param_5,(int)param_6,param_7,param_8);
  if (iVar1 != 1) {
    FUN_004fc0b0(param_6);
    return iVar1;
  }
  FUN_004fb600(param_6,&param_2,&param_1);
  if (uVar2 == 0) {
    if (*(int *)(extraout_ECX + 0x114 + in_stack_00001938 * 0x168) == 0) {
      uVar2 = FUN_00477e40(in_stack_0000193c,4,(float)param_1,'\x01',-1);
      uVar2 = uVar2 & 0xff;
      if (uVar2 == 0) {
        uVar2 = FUN_00477e40(in_stack_0000193c,4,(float)param_2,'\x01',-1);
        uVar2 = uVar2 & 0xff;
        if (uVar2 == 0) goto LAB_004fb8b9;
        cVar5 = '\0';
      }
      else {
        cVar5 = '\x01';
      }
      FUN_004fbee0((int *)&param_3,cVar5);
    }
    else {
      FUN_00477e40(in_stack_0000193c,4,(float)param_1,'\x01',-1);
      FUN_004fbee0((int *)&param_3,'\x01');
      uVar2 = 1;
    }
  }
  else {
    FUN_004fbee0((int *)&param_3,'\0');
    *(undefined4 *)((int)in_stack_0000193c + 0x24) = 4;
    uVar2 = 1;
  }
LAB_004fb8b9:
  Array_ClearStride34((int)in_stack_0000193c);
  if (uVar2 == 0) {
    FUN_0048bf90(DAT_0057c670,0x29,5,4,7,*(int *)((int)in_stack_0000193c + 0x16f0),DAT_005828c0,
                 DAT_00582ea0,(int)in_stack_0000193c + 4);
    return 2;
  }
  FUN_0047f100(in_stack_0000193c);
  FUN_004f3200(*(void **)((int)in_stack_0000193c + 0x14e0),(int)in_stack_0000193c);
  FUN_00478db0();
  if ((*(int *)(extraout_ECX + 0x114 + in_stack_00001938 * 0x168) != 0) ||
     (iVar1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670), iVar4 != iVar1)) {
    FUN_004fccb0((int)in_stack_0000193c,0);
    FUN_004ff6e0(in_stack_0000193c);
    return 1;
  }
  iVar4 = in_stack_00001948 + 5 + in_stack_00001940 * 4;
  iVar1 = iVar4 * 0xfa;
  if (in_stack_00001944 == 0) {
    iVar1 = (iVar4 * 2000) / 10;
  }
  else if (in_stack_00001944 == 2) {
    iVar1 = (int)(iVar4 * 0x9c4 + (iVar4 * 0x9c4 >> 0x1f & 7U)) >> 3;
  }
  iVar4 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar4 + 0xd4) == 0) {
    if (*(int *)(iVar4 + 0x1b8) != 0) {
      iVar1 = (iVar1 * 0xf) / 10;
    }
  }
  else {
    iVar1 = 0;
  }
  FUN_00477e40(in_stack_0000193c,9,(float)iVar1,'\0',-1);
  iVar4 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar4 + 0xd4) != 0) {
    *(int *)(iVar4 + 0xd4) = *(int *)(iVar4 + 0xd4) + -1;
    return 1;
  }
  if (*(int *)(iVar4 + 0x1b8) == 0) {
    return 1;
  }
  *(int *)(iVar4 + 0x1b8) = *(int *)(iVar4 + 0x1b8) + -1;
  return 1;
}

