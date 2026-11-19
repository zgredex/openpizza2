// rea decompile_all
// name: FUN_00486590
// address: 0x486590
// body: available
// range: 0x486590-0x4867dc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00486590(void *param_1)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar6 = (uint)*(byte *)(*(int *)((int)param_1 + 0x94) + 7);
  cVar1 = *(char *)(*(int *)((int)param_1 + 0x94) + 8);
  FUN_00486be0(param_1,0);
  iVar8 = 0;
  *(int *)(*(int *)((int)param_1 + 0x94) + 0xc) = *(int *)(*(int *)((int)param_1 + 0x94) + 0xc) + 1;
  iVar7 = *(int *)((int)param_1 + 0x34);
  if (0 < iVar7) {
    do {
      iVar2 = FUN_004017f0((void *)((int)param_1 + 0x20),iVar8,(int *)0x0);
      if (iVar2 != 0) {
        FUN_004d4170(iVar2);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar7);
  }
  iVar7 = *(int *)((int)param_1 + 0x18);
  iVar8 = 0;
  if (0 < iVar7) {
    do {
      pvVar3 = (void *)FUN_004017f0((void *)((int)param_1 + 4),iVar8,(int *)0x0);
      if (pvVar3 != (void *)0x0) {
        FUN_004d8d50(pvVar3,uVar6);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar7);
  }
  puVar4 = (undefined4 *)((int)param_1 + 0x224);
  iVar7 = 6;
  do {
    if ((void *)*puVar4 != (void *)0x0) {
      FUN_0050efe0((void *)*puVar4,uVar6);
    }
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  puVar4 = (undefined4 *)((int)param_1 + 0x200);
  iVar7 = 6;
  do {
    if ((void *)*puVar4 != (void *)0x0) {
      FUN_004e0200((void *)*puVar4,uVar6);
    }
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = *(int *)((int)param_1 + 0x50);
  while (iVar7 = iVar7 + -1, -1 < iVar7) {
    puVar4 = (undefined4 *)FUN_004017f0((void *)((int)param_1 + 0x3c),iVar7,(int *)0x0);
    if ((puVar4 != (undefined4 *)0x0) && (iVar8 = Object_CanDetach(puVar4), iVar8 != 0)) {
      puVar5 = (undefined4 *)FUN_004017f0((void *)((int)param_1 + 0x20),puVar4[0x14],(int *)0x0);
      if (puVar5 != (undefined4 *)0x0) {
        FUN_00401790((void *)((int)param_1 + 0x20),(int)puVar5);
        (**(code **)*puVar5)(1);
      }
      pvVar3 = (void *)FUN_004017f0((void *)((int)param_1 + 4),*(int *)((int)param_1 + 0x2f4),
                                    (int *)0x0);
      FUN_004dd050(pvVar3,puVar4);
      FUN_00401790((void *)((int)param_1 + 0x3c),(int)puVar4);
      puVar4[0x59] = 0xffffffff;
      if (*(undefined4 **)((int)param_1 + 0x21c) == puVar4) {
        *(undefined4 *)((int)param_1 + 0x21c) = 0;
        *(undefined4 *)((int)param_1 + 0x2da8) = 1;
        FUN_005301c0(*(void **)((int)param_1 + 0x25c),-0x18624,0x23,0);
      }
      (**(code **)*puVar4)(1);
    }
  }
  FUN_004fc560(*(int *)((int)param_1 + 0x90));
  if (uVar6 == 0) {
    FUN_004867e0(param_1,(char *)(uint)(cVar1 == '\0'));
  }
  FUN_0054a660(DAT_0057c1e0,0xff,(byte *)s_EndofHour__d___0056812c,uVar6);
  if (*(void **)((int)param_1 + 0x264) != (void *)0x0) {
    FUN_005301c0(*(void **)((int)param_1 + 0x264),-0x1863b,0x23,0);
  }
  if (*(void **)((int)param_1 + 0x25c) != (void *)0x0) {
    FUN_005301c0(*(void **)((int)param_1 + 0x25c),-0x1863b,0x23,0);
  }
  if (uVar6 % 3 == 0) {
    *(undefined4 *)((int)param_1 + 0x340) = 0;
  }
  FUN_00486e00((int)param_1);
  FUN_004dd4d0(*(int *)((int)param_1 + 0x94));
  return;
}

