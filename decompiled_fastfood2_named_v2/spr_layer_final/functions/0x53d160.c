// rea decompile_all
// name: Sprite_Serialize
// address: 0x53d160
// body: available
// range: 0x53d160-0x53d413 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sprite_Serialize(void *this,int param_1,int *param_2,void *param_3)

{
  byte *pbVar1;
  uint *puVar2;
  byte *pbVar3;
  ushort uVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  int local_c;
  ushort *local_8;
  int local_4;
  
                    /* Writes a sprite header/palette/pixels to a stream. */
  local_4 = 0;
  pbVar1 = (byte *)((int)this + 5);
  if (*(char *)((int)this + 5) == '\b') {
    local_4 = 1;
    if (1 < *(byte *)((int)this + 0x34)) {
      *pbVar1 = *(byte *)((int)this + 0x34) | 0x80;
    }
    if ((param_3 != (void *)0x0) && (*pbVar1 == 8)) {
      *pbVar1 = 0x48;
    }
  }
  if (*(char *)((int)this + 0x39) == '\0') {
    Sprite_RealizeLazy(this);
  }
  local_8 = *(ushort **)((int)this + 0x1c);
  if ((*(char *)(param_1 + 0x18) != '\0') && (8 < *pbVar1)) {
    *(uint *)((int)this + 0x1c) = (int)local_8 >> 1 & 0x7fe0U | (uint)local_8 & 0x1f;
  }
  puVar2 = (uint *)((int)this + 0x18);
  FUN_0054fb27((char *)puVar2,1,4,param_2);
  FUN_0054fb27((char *)pbVar1,1,1,param_2);
  pbVar3 = (byte *)((int)this + 4);
  FUN_0054fb27((char *)pbVar3,1,0x1c,param_2);
  *(ushort **)((int)this + 0x1c) = local_8;
  if (((*(char *)(param_1 + 0x18) == '\0') || (*pbVar1 < 9)) || ((*pbVar3 & 0x10) != 0)) {
    FUN_0054fb27(*(char **)((int)this + 0x2c),1,*puVar2,param_2);
  }
  else {
    local_8 = *(ushort **)((int)this + 0x2c);
    puVar5 = operator_new(((int)*puVar2 >> 1) << 1);
    if ((*pbVar3 & 1) == 0) {
      iVar8 = 0;
      if (0 < (int)(*puVar2 & 0xfffffffe)) {
        puVar6 = local_8;
        do {
          uVar4 = *puVar6;
          puVar6 = puVar6 + 1;
          iVar8 = iVar8 + 1;
          *(ushort *)((int)puVar5 + (-2 - (int)local_8) + (int)puVar6) =
               uVar4 >> 1 & 0x7fe0 | uVar4 & 0x1f;
        } while (iVar8 < (int)*puVar2 >> 1);
      }
    }
    else {
      iVar8 = 0;
      if (0 < (int)(*puVar2 & 0xfffffffe)) {
        puVar6 = puVar5;
        puVar7 = local_8;
        do {
          uVar4 = *puVar7;
          if ((uint)uVar4 == *(uint *)((int)this + 0x1c)) {
            puVar7 = puVar7 + 1;
            *puVar6 = uVar4 >> 1 & 0x7fe0 | uVar4 & 0x1f;
            iVar8 = iVar8 + 1;
            puVar6 = puVar6 + 1;
            *puVar6 = *puVar7;
          }
          else {
            *puVar6 = uVar4 >> 1 & 0x7fe0 | uVar4 & 0x1f;
          }
          iVar8 = iVar8 + 1;
          puVar7 = puVar7 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar8 < (int)*puVar2 >> 1);
      }
    }
    FUN_0054fb27((char *)puVar5,1,*puVar2,param_2);
    FUN_0054dd78(puVar5);
  }
  if (local_4 != 0) {
    if (*(byte *)((int)this + 0x34) < 2) {
      if ((*pbVar1 & 0x40) == 0) {
        FUN_00535e20(*(void **)((int)this + 0x20),param_2);
        *pbVar1 = 8;
        return;
      }
      local_c = FUN_00535cb0(param_3,*(undefined4 **)((int)this + 0x20));
      if (local_c == -1) {
        FUN_0048e0a0();
      }
      FUN_0054fb27((char *)&local_c,1,4,param_2);
      *pbVar1 = 8;
      return;
    }
    iVar8 = 0;
    if (*(byte *)((int)this + 0x34) != 0) {
      do {
        if ((*pbVar1 & 0x40) == 0) {
          FUN_00535e20(*(void **)(*(int *)((int)this + 0x24) + iVar8 * 4),param_2);
        }
        else {
          local_c = FUN_00535cb0(param_3,*(undefined4 **)(*(int *)((int)this + 0x24) + iVar8 * 4));
          if (local_c == -1) {
            FUN_0048e0a0();
          }
          FUN_0054fb27((char *)&local_c,1,4,param_2);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)*(byte *)((int)this + 0x34));
    }
    *pbVar1 = 8;
  }
  return;
}

