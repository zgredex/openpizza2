// rea decompile_all
// name: FUN_0051ef80
// address: 0x51ef80
// body: available
// range: 0x51ef80-0x51f20a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_0051ef80(void *this,undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
            char *param_6,undefined4 *param_7)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  void *this_00;
  char *pcVar9;
  int local_240;
  int local_23c;
  int local_238;
  int local_234;
  int local_230;
  int local_22c;
  int local_228;
  int local_21c;
  void *local_218;
  char local_214 [260];
  char local_110 [260];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a53b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_218 = this;
  FUN_00520a80(this,param_1,param_3,param_4,param_5);
  *(undefined ***)this = &PTR_FUN_0055c704;
  pvVar2 = *(void **)(param_5 + 0x134);
  local_4 = 0;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  uVar6 = 0xffffffff;
  do {
    pcVar4 = param_6;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar4 = param_6 + 1;
    cVar1 = *param_6;
    param_6 = pcVar4;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  pcVar4 = pcVar4 + -uVar6;
  pcVar9 = local_214;
  for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar9 = pcVar9 + 4;
  }
  puVar3 = (undefined4 *)((int)this + 0x94);
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar9 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar9 = pcVar9 + 1;
  }
  *(undefined4 *)((int)this + 0x164) = 0;
  *(undefined4 *)((int)this + 0x168) = 0;
  *(undefined4 *)((int)this + 0x170) = 0;
  *(int *)((int)this + 0x16c) = param_2;
  iVar8 = 4;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 0x11;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(undefined4 *)((int)this + 0x40) = 1;
  pcVar4 = _strrchr(local_214,0x5f);
  if (pcVar4 != (char *)0x0) {
    FUN_0054e157(this_00,(byte *)(pcVar4 + 1));
    *pcVar4 = '\0';
  }
  local_21c = (param_2 != 0) + 3;
  iVar8 = 0;
  if (local_21c != 0) {
    puVar3 = (undefined4 *)((int)this + 0x54);
    do {
      FUN_0054dd83(local_110,(byte *)s__s__02d_spr_00573b9c,local_214);
      iVar5 = FUN_00527580(pvVar2,local_110,(undefined4 *)(uint)(iVar8 < 2),puVar3);
      if ((iVar5 == 0) && (iVar8 < 2)) {
        *param_7 = 2;
        ExceptionList = local_c;
        return this;
      }
      iVar8 = iVar8 + 1;
      puVar3 = puVar3 + 0x11;
    } while (iVar8 < local_21c);
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  local_22c = *(int *)((int)this + 0x28);
  local_228 = *(int *)((int)this + 0x2c);
  iVar8 = *(int *)((int)this + 0x30);
  iVar5 = *(int *)((int)this + 0x34);
  local_240 = 0;
  do {
    pvVar2 = *(void **)((int)this + local_240 * 0x44 + 0x94);
    if (pvVar2 != (void *)0x0) {
      Sprite_GetHotspot(pvVar2,&local_234,&local_230);
      Sprite_GetSize(*(void **)((int)this + local_240 * 0x44 + 0x94),&local_238,&local_23c);
      if (local_240 == 0) {
        local_22c = local_234;
        local_228 = local_230;
        iVar8 = local_238 + local_234;
        iVar5 = local_23c + local_230;
      }
      else {
        if (local_234 < local_22c) {
          local_22c = local_234;
        }
        if (local_230 < local_228) {
          local_228 = local_230;
        }
        if (iVar8 < local_234 + local_238) {
          iVar8 = local_234 + local_238;
        }
        if (iVar5 < local_23c + local_230) {
          iVar5 = local_23c + local_230;
        }
      }
    }
    local_240 = local_240 + 1;
  } while (local_240 < 4);
  *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + local_22c;
  *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + local_228;
  UI_SetAbsolutePosition(this,iVar8 - local_22c,iVar5 - local_228);
  ExceptionList = local_c;
  return this;
}

