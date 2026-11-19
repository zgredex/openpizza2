// rea decompile_all
// name: FUN_0052e570
// address: 0x52e570
// body: available
// range: 0x52e570-0x52e824 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_0052e570(void *this,int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  char cVar1;
  void *this_00;
  undefined2 uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  undefined2 *puVar14;
  char *pcVar15;
  uint local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a94b;
  local_c = ExceptionList;
  if (*(int *)((int)this + 0x18) != 0) {
    ExceptionList = &local_c;
    *(undefined4 *)((int)this + 0x34) = 0;
    if (*(LPVOID *)((int)this + 0x30) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)((int)this + 0x30));
    }
    uVar12 = 0xffffffff;
    pcVar3 = param_5;
    do {
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = operator_new(~uVar12);
    uVar12 = 0xffffffff;
    *(char **)((int)this + 0x30) = pcVar3;
    do {
      pcVar4 = param_5;
      if (uVar12 == 0) break;
      uVar12 = uVar12 - 1;
      pcVar4 = param_5 + 1;
      cVar1 = *param_5;
      param_5 = pcVar4;
    } while (cVar1 != '\0');
    uVar12 = ~uVar12;
    pcVar4 = pcVar4 + -uVar12;
    for (uVar13 = uVar12 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar3 = pcVar3 + 4;
    }
    for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      *pcVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar3 = pcVar3 + 1;
    }
    iVar6 = 0;
    pcVar3 = *(char **)((int)this + 0x30);
    while (pcVar3 != (char *)0x0) {
      *(int *)((int)this + 0x34) = *(int *)((int)this + 0x34) + 1;
      pcVar4 = _strchr(pcVar3,10);
      if (pcVar4 == (char *)0x0) {
        pcVar15 = (char *)0x0;
      }
      else {
        pcVar15 = pcVar4 + 1;
        *pcVar4 = '\0';
      }
      iVar5 = FUN_005355f0(*(void **)((int)this + 0x18),pcVar3);
      pcVar3 = pcVar15;
      if (iVar6 < iVar5) {
        iVar6 = iVar5;
      }
    }
    *(undefined4 *)((int)this + 0x14) = 1;
    uVar12 = iVar6 + 8;
    iVar6 = *(int *)(*(int *)((int)this + 0x18) + 0x9b0) * *(int *)((int)this + 0x34);
    uVar13 = iVar6 + 4;
    *(int *)((int)this + 0x10) = param_2;
    *(int *)((int)this + 0xc) = param_1;
    if (param_3 < (int)(uVar12 + param_1)) {
      *(uint *)((int)this + 0xc) = param_3 - uVar12;
    }
    if (param_4 < (int)(param_2 + uVar13)) {
      *(uint *)((int)this + 0x10) = param_4 - uVar13;
    }
    if (*(int *)((int)this + 0xc) < 0) {
      *(undefined4 *)((int)this + 0xc) = 0;
    }
    if (*(int *)((int)this + 0x10) < 0) {
      *(undefined4 *)((int)this + 0x10) = 0;
    }
    if (*(void **)((int)this + 0x20) != (void *)0x0) {
      FUN_0053d040(*(void **)((int)this + 0x20),&local_14,&local_10);
      local_14 = (int)local_14 / 2;
      if ((local_14 != uVar12) || (local_10 != uVar13)) {
        if (*(undefined4 **)((int)this + 0x20) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)((int)this + 0x20))(1);
        }
        *(undefined4 *)((int)this + 0x20) = 0;
      }
    }
    *(uint *)((int)this + 4) = uVar12;
    *(uint *)((int)this + 8) = uVar13;
    if (*(int *)((int)this + 0x20) == 0) {
      pvVar7 = operator_new(0x50);
      uStack_4 = 0;
      if (pvVar7 == (void *)0x0) {
        puVar8 = (undefined4 *)0x0;
      }
      else {
        puVar8 = FUN_0053c710(pvVar7,uVar12,uVar13,0,0x10,0);
      }
      uStack_4 = 0xffffffff;
      *(undefined4 **)((int)this + 0x20) = puVar8;
    }
    pvVar7 = *(void **)((int)this + 0x20);
    this_00 = *(void **)((int)this + 0x1c);
    if (*(char *)((int)pvVar7 + 0x39) == '\0') {
      FUN_0053cea0(pvVar7);
    }
    FUN_00539280(this_00,*(undefined4 *)((int)pvVar7 + 0x2c),
                 (ushort)((int)*(short *)((int)pvVar7 + 6) >> 1),*(ushort *)((int)pvVar7 + 8),
                 (int)*(short *)((int)pvVar7 + 6));
    iVar5 = FUN_00539840(*(void **)((int)this + 0x1c),*(uint *)((int)this + 0x28));
    FUN_0053d6c0(*(void **)((int)this + 0x20),iVar5);
    uVar2 = FUN_00539840(*(void **)((int)this + 0x1c),*(uint *)((int)this + 0x2c));
    puVar9 = (undefined2 *)FUN_0053d480(*(void **)((int)this + 0x20));
    if (0 < (int)uVar12) {
      puVar10 = puVar9 + (iVar6 + 3) * uVar12;
      puVar14 = puVar9;
      uVar13 = uVar12;
      do {
        *puVar14 = uVar2;
        *puVar10 = uVar2;
        puVar14 = puVar14 + 1;
        puVar10 = puVar10 + 1;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    if (1 < iVar6 + 3) {
      puVar10 = puVar9 + uVar12 * 2 + -1;
      iVar6 = iVar6 + 2;
      do {
        puVar9 = puVar9 + uVar12;
        *puVar9 = uVar2;
        *puVar10 = uVar2;
        puVar10 = puVar10 + uVar12;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    uVar11 = FUN_00539840(*(void **)((int)this + 0x1c),*(uint *)((int)this + 0x24));
    FUN_00535500(*(void **)((int)this + 0x18),uVar11);
    pcVar3 = *(char **)((int)this + 0x30);
    iVar6 = 0;
    if (0 < *(int *)((int)this + 0x34)) {
      do {
        FUN_00535570(*(void **)((int)this + 0x18),4,
                     *(int *)((int)*(void **)((int)this + 0x18) + 0x9b0) * iVar6 + 2,0);
        FUN_00535740(*(void **)((int)this + 0x18),*(void **)((int)this + 0x1c),(int)pcVar3);
        uVar12 = 0xffffffff;
        pcVar4 = pcVar3;
        do {
          if (uVar12 == 0) break;
          uVar12 = uVar12 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        iVar6 = iVar6 + 1;
        pcVar3 = pcVar3 + ~uVar12;
      } while (iVar6 < *(int *)((int)this + 0x34));
    }
    *(undefined4 *)((int)this + 0x3c) = 1;
  }
  ExceptionList = local_c;
  return;
}

