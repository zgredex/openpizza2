// rea decompile_all
// name: FUN_0052ae20
// address: 0x52ae20
// body: available
// range: 0x52ae20-0x52b1f2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_0052ae20(void *this,int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5,
            char *param_6,undefined4 param_7,int param_8)

{
  char cVar1;
  void *this_00;
  void *pvVar2;
  int *piVar3;
  HANDLE pvVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  char *pcVar14;
  longlong lVar15;
  undefined4 local_2c [2];
  undefined4 local_24 [2];
  undefined4 local_1c [2];
  undefined4 local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  iVar7 = param_8;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a893;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00520a80(this,param_1,param_2,param_3,param_8);
  pcVar12 = param_6;
  *(undefined ***)this = &PTR_MovieWindow_Delete_0055c7b0;
  this_00 = *(void **)(iVar7 + 0x134);
  *(undefined4 *)((int)this + 0xac) = param_7;
  puVar13 = (undefined4 *)((int)this + 0x54);
  uVar9 = 0xffffffff;
  local_4 = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xa0) = 0;
  *(undefined4 *)((int)this + 0xb0) = 1;
  *(undefined4 *)((int)this + 0x9c) = 0xffffffff;
  *(undefined4 *)((int)this + 0xb4) = 0;
  *puVar13 = 0;
  *(undefined4 *)((int)this + 0xb8) = 0;
  *(undefined4 *)((int)this + 0x40) = 6;
  *(undefined4 *)((int)this + 0xa4) = param_4;
  switch(param_4) {
  case 0:
    puVar6 = param_5;
    for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar13 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar13 = puVar13 + 1;
    }
    FUN_0053d090(*(void **)((int)this + 0x94),&param_3,&param_8);
    FUN_0053d100(*(void **)((int)this + 0x94),&param_2,&param_1);
    break;
  case 1:
    if (*param_6 != '\0') {
      pcVar8 = param_6;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      pcVar8 = operator_new(~uVar9);
      uVar9 = 0xffffffff;
      *(char **)((int)this + 0xa0) = pcVar8;
      do {
        pcVar14 = pcVar12;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar14 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar14;
      } while (cVar1 != '\0');
      uVar9 = ~uVar9;
      pcVar12 = pcVar14 + -uVar9;
      for (uVar11 = uVar9 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar8 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
    *puVar13 = param_5;
    iVar7 = FUN_005338c0(param_5,-1);
    *(int *)((int)this + 0x98) = iVar7;
    FUN_005336f0((void *)*puVar13,&param_3,&param_8,&param_2,&param_1);
    FUN_00534ac0((void *)*puVar13,0,local_2c,local_24,local_14,local_1c);
    lVar15 = __ftol();
    param_2 = param_2 + (int)lVar15;
    lVar15 = __ftol();
    param_1 = param_1 + (int)lVar15;
    break;
  case 2:
    if (*param_6 != '\0') {
      pcVar8 = param_6;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      pcVar8 = operator_new(~uVar9);
      uVar9 = 0xffffffff;
      *(char **)((int)this + 0xa0) = pcVar8;
      do {
        pcVar14 = pcVar12;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar14 = pcVar12 + 1;
        cVar1 = *pcVar12;
        pcVar12 = pcVar14;
      } while (cVar1 != '\0');
      uVar9 = ~uVar9;
      pcVar12 = pcVar14 + -uVar9;
      for (uVar11 = uVar9 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar8 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar8 = pcVar8 + 1;
      }
    }
    *puVar13 = param_5;
    param_3 = param_5[1];
    param_8 = param_5[2];
    param_1 = 0;
    param_2 = 0;
    break;
  case 3:
    pvVar2 = operator_new(0x1c);
    *(void **)((int)this + 0xb8) = pvVar2;
    *(undefined4 *)((int)pvVar2 + 0x14) = 0;
    *(undefined4 *)(*(int *)((int)this + 0xb8) + 0xc) = 0;
    *(undefined4 *)(*(int *)((int)this + 0xb8) + 0x10) = 0;
    if (*param_6 != '\0') {
      puVar6 = *(undefined4 **)((int)this + 0xb8);
      for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      piVar3 = FUN_0054a5d0(DAT_0057ba0c);
      *(int **)(*(int *)((int)this + 0xb8) + 4) = piVar3;
      iVar10 = *(int *)(*(int *)((int)this + 0xb8) + 4);
      if (iVar10 != 0) {
        _BinkSetSoundSystem_8(_BinkOpenDirectSound_4_exref,iVar10);
      }
      *(undefined4 **)(*(int *)((int)this + 0xb8) + 0x18) = param_5;
      *(undefined4 *)(*(int *)((int)this + 0xb8) + 0xc) = 1;
      pvVar4 = FUN_004025e0(*(void **)(*(int *)(iVar7 + 0x134) + 0x10),param_6);
      uVar5 = _BinkOpen_8(pvVar4,0x800000);
      **(undefined4 **)((int)this + 0xb8) = uVar5;
      *(undefined4 *)((int)this + 0xac) = 1;
      if (**(int **)((int)this + 0xb8) == 0) {
        param_8 = 0;
        param_3 = 0;
        *(undefined4 *)((int)this + 0xa4) = 2;
        param_1 = 0;
        param_2 = 0;
      }
      else {
        (*(int **)((int)this + 0xb8))[3] = 1;
        piVar3 = *(int **)((int)this + 0xb8);
        param_3 = *(int *)*piVar3;
        param_8 = *(int *)(*piVar3 + 4);
        if (piVar3[6] != 0) {
          param_3 = param_3 << 1;
          param_8 = param_8 << 1;
        }
        param_6 = operator_new(0x11c);
        local_4._0_1_ = 1;
        if (param_6 == (char *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          puVar6 = FUN_00537230(param_6,param_3,param_8,0x10);
        }
        *puVar13 = puVar6;
        local_4 = (uint)local_4._1_3_ << 8;
        FUN_0052bbc0(this,*(int *)(*(int *)(iVar7 + 0x134) + 0xc));
        param_1 = 0;
        param_2 = 0;
      }
    }
  }
  *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + param_2;
  *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + param_1;
  FUN_00520b40(this,param_3,param_8);
  if ((*(int *)((int)this + 0xa4) == 1) || (*(int *)((int)this + 0xa4) == 3)) {
    FUN_00527c60(this_00,this);
  }
  ExceptionList = pvStack_c;
  return this;
}

