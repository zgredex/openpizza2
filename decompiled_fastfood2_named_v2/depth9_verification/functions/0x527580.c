// rea decompile_all
// name: FUN_00527580
// address: 0x527580
// body: available
// range: 0x527580-0x5277c0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00527580(void *this,char *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int local_54;
  void *local_50;
  uint local_4c [16];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pcVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a7db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  SpriteCache_MakeKey(param_1,local_4c);
  iVar2 = FUN_00527400(this,(byte *)local_4c,(int *)&param_1);
  if (iVar2 == 0) {
    local_50 = operator_new(0x50);
    local_4 = 0;
    if (local_50 == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_0053c7f0(local_50,DAT_0057c5c8,*(void **)((int)this + 0x10),pcVar1,&local_54,0,
                            (void *)0x0,0);
    }
    local_4 = 0xffffffff;
    if (local_54 != 0) {
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(1);
      }
      if (param_2 == (undefined4 *)0x0) {
        ExceptionList = local_c;
        return 0;
      }
      FUN_00526f20(this,5,(byte *)s_Unable_to_load_sprite___s____005742ac,pcVar1);
    }
    if (*(int *)((int)this + 0x8300) <= *(int *)((int)this + 0x82fc)) {
      param_2 = operator_new((*(int *)((int)this + 0x8300) * 9 + 900) * 8);
      if (0 < *(int *)((int)this + 0x82fc)) {
        puVar6 = *(undefined4 **)((int)this + 0x82f8);
        puVar9 = param_2;
        for (uVar4 = (uint)(*(int *)((int)this + 0x82fc) * 0x48) >> 2; uVar4 != 0; uVar4 = uVar4 - 1
            ) {
          *puVar9 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar9 = puVar9 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined1 *)puVar9 = *(undefined1 *)puVar6;
          puVar6 = (undefined4 *)((int)puVar6 + 1);
          puVar9 = (undefined4 *)((int)puVar9 + 1);
        }
        FUN_0054dd78(*(LPVOID *)((int)this + 0x82f8));
      }
      *(undefined4 **)((int)this + 0x82f8) = param_2;
      *(int *)((int)this + 0x8300) = *(int *)((int)this + 0x8300) + 100;
    }
    iVar2 = *(int *)((int)this + 0x82fc) - (int)param_1;
    if (0 < iVar2) {
      FUN_0054e230((undefined4 *)(*(int *)((int)this + 0x82f8) + ((int)param_1 * 9 + 9) * 8),
                   (undefined4 *)(*(int *)((int)this + 0x82f8) + (int)param_1 * 0x48),iVar2 * 0x48);
    }
    *(undefined4 *)(*(int *)((int)this + 0x82f8) + 0x44 + (int)param_1 * 0x48) = 1;
    *(undefined4 **)(*(int *)((int)this + 0x82f8) + 0x40 + (int)param_1 * 0x48) = puVar3;
    *(int *)((int)this + 0x82fc) = *(int *)((int)this + 0x82fc) + 1;
    uVar4 = 0xffffffff;
    puVar7 = local_4c;
    do {
      puVar8 = puVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      puVar8 = (uint *)((int)puVar7 + 1);
      uVar5 = *puVar7;
      puVar7 = puVar8;
    } while ((char)uVar5 != '\0');
    uVar4 = ~uVar4;
    puVar6 = (undefined4 *)((int)puVar8 - uVar4);
    puVar9 = (undefined4 *)(*(int *)((int)this + 0x82f8) + (int)param_1 * 0x48);
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar9 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    }
    param_3[0x10] = puVar3;
  }
  else {
    *(int *)(*(int *)((int)this + 0x82f8) + 0x44 + (int)param_1 * 0x48) =
         *(int *)(*(int *)((int)this + 0x82f8) + 0x44 + (int)param_1 * 0x48) + 1;
    param_3[0x10] = *(undefined4 *)(*(int *)((int)this + 0x82f8) + 0x40 + (int)param_1 * 0x48);
  }
  uVar4 = 0xffffffff;
  puVar7 = local_4c;
  do {
    puVar8 = puVar7;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    puVar8 = (uint *)((int)puVar7 + 1);
    uVar5 = *puVar7;
    puVar7 = puVar8;
  } while ((char)uVar5 != '\0');
  uVar4 = ~uVar4;
  puVar3 = (undefined4 *)((int)puVar8 - uVar4);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *param_3 = *puVar3;
    puVar3 = puVar3 + 1;
    param_3 = param_3 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)param_3 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    param_3 = (undefined4 *)((int)param_3 + 1);
  }
  ExceptionList = local_c;
  return 1;
}

