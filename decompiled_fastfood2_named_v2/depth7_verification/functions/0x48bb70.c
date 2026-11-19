// rea decompile_all
// name: FUN_0048bb70
// address: 0x48bb70
// body: available
// range: 0x48bb70-0x48bd9f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0048bb70(void *this,uint *param_1)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  void *this_00;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  char *pcVar8;
  uint *puVar9;
  undefined4 *local_68;
  int local_64;
  int local_5c;
  char *local_54;
  void *local_50;
  uint local_4c [15];
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005583d6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_50 = operator_new(0x1c);
  local_4 = 0;
  if (local_50 == (void *)0x0) {
    local_68 = (undefined4 *)0x0;
  }
  else {
    local_68 = List_Construct(local_50,0);
  }
  local_4 = 0xffffffff;
  FUN_0054f775(param_1);
  local_5c = 0;
  iVar2 = FUN_00486910(this,-1);
  local_64 = 0;
  if (0 < iVar2) {
    do {
      pvVar3 = (void *)FUN_004017f0((void *)((int)this + 0x3c),local_64,(int *)0x0);
      uVar5 = 0xffffffff;
      pcVar4 = (char *)((int)pvVar3 + 4);
      do {
        pcVar8 = pcVar4;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      puVar7 = (uint *)(pcVar8 + -uVar5);
      puVar9 = local_4c;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)puVar9 = (char)*puVar7;
        puVar7 = (uint *)((int)puVar7 + 1);
        puVar9 = (uint *)((int)puVar9 + 1);
      }
      FUN_0054f775(local_4c);
      pcVar4 = _strstr((char *)local_4c,(char *)param_1);
      if (pcVar4 != (char *)0x0) {
        local_5c = local_5c + 1;
        this_00 = operator_new(0x58);
        local_4 = 1;
        if (this_00 == (void *)0x0) {
          local_54 = (char *)0x0;
        }
        else {
          local_54 = FUN_00403370(this_00,(char *)((int)pvVar3 + 4),local_64);
        }
        local_4 = 0xffffffff;
        FUN_004014b0(local_68,local_54);
        local_50 = pvVar3;
      }
      local_64 = local_64 + 1;
    } while (local_64 < iVar2);
    if (local_5c != 0) {
      if (local_5c != 1) {
        FUN_0054ea8f((int *)local_68[1],(undefined4 *)local_68[5],4,&LAB_0048bb20);
        FUN_00483210(this,0xfffe79e7,DAT_00582ab4,DAT_00582420,(int)local_68,0,0);
        *(undefined4 *)((int)this + 0x278) = 0;
        ExceptionList = local_c;
        return;
      }
      if (local_54 != (char *)0x0) {
        (*(code *)**(undefined4 **)local_54)(1);
      }
      if (local_68 != (undefined4 *)0x0) {
        (**(code **)*local_68)(1);
      }
      FUN_0048bef0(this,(int)local_50);
      ExceptionList = local_c;
      return;
    }
  }
  FUN_00482b70(this,0xffffffff,DAT_00582ab4,DAT_005828dc,0);
  if (local_68 == (undefined4 *)0x0) {
    ExceptionList = local_c;
    return;
  }
  (**(code **)*local_68)(1);
  ExceptionList = pvStack_10;
  return;
}

