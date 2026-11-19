// rea decompile_all
// name: FUN_004b0300
// address: 0x4b0300
// body: available
// range: 0x4b0300-0x4b06dd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b0300(void *param_1)

{
  uint *puVar1;
  uint *puVar2;
  ushort uVar3;
  void *this;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  int local_38;
  int local_34;
  float local_30;
  float local_2c;
  int local_28;
  uint local_24;
  void *local_20;
  float local_1c;
  int local_18;
  float local_14;
  float local_10;
  int local_c;
  int local_8;
  int *local_4;
  
  uVar3 = *(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10);
  uVar6 = (uint)uVar3;
  local_24 = uVar6;
  this = (void *)FUN_00531cf0(param_1,0x413);
  local_20 = this;
  FUN_00521380((int)this);
  if (uVar3 == 0) {
    FUN_00521ae0(this,&local_34,&local_38);
    pvVar4 = (void *)FUN_00521b10((int)this);
    FUN_00535520(DAT_0057d684,local_34 / 2,local_38 / 2,2);
    FUN_00535500(DAT_0057d684,0);
    FUN_00535740(DAT_0057d684,pvVar4,DAT_00581444);
    FUN_00521b30((int)this);
    return;
  }
  local_4 = FUN_00521bc0(this,0,3);
  FUN_00521ae0(this,&local_34,&local_38);
  local_34 = local_34 + -3;
  local_38 = local_38 + -3;
  local_14 = (float)local_34 / (float)(int)local_24;
  iVar5 = FUN_004b0710();
  FUN_0052f080(param_1,0x414,(byte *)s__0_0f_0056a690,SUB84((double)iVar5,0));
  if ((float)iVar5 <= 0.0) {
    local_1c = 0.0;
  }
  else {
    local_1c = (float)local_38 / (float)iVar5;
  }
  FUN_0052f080(param_1,0x415,(byte *)s__d__d_00568ef8,
               (uint)*(byte *)(*(int *)((int)DAT_0057c670 + 0x94) + 8));
  local_c = 0;
  do {
    iVar5 = local_c;
    local_10 = (float)local_38;
    local_2c = 0.0;
    local_30 = 0.0;
    local_18 = FUN_00488be0(DAT_0057c670,local_c);
    if (((local_18 != 0) && ((&DAT_0056a644)[iVar5] == '\x01')) && (local_28 = 0, 0 < (int)uVar6)) {
      do {
        IDMap_Lookup((void *)(local_18 + 0x19c),local_28,(int *)0x0);
        local_30 = local_30 + local_14;
        switch(DAT_0056a68c) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 0xffffffff:
        }
        lVar7 = __ftol();
        iVar5 = local_38 - (int)lVar7;
        local_8 = iVar5;
        lVar7 = __ftol();
        puVar1 = (uint *)((int)lVar7 + 1);
        lVar7 = __ftol();
        lVar8 = __ftol();
        puVar2 = (uint *)((int)lVar8 + 1);
        FUN_00521740(local_20,puVar2,(int)lVar7 + 2,puVar1,iVar5 + 2,0);
        FUN_00521740(local_20,puVar2,(int)lVar7 + 1,puVar1,iVar5 + 1,*(uint *)(local_18 + 0x1dc));
        local_2c = local_2c + local_14;
        local_28 = local_28 + 1;
        local_10 = (float)local_8;
      } while (local_28 < (int)local_24);
      uVar6 = local_24;
      this = local_20;
      iVar5 = local_c;
    }
    local_c = iVar5 + 1;
  } while (local_c < 6);
  FUN_00521b30((int)this);
  FUN_00521da0(local_4);
  return;
}

