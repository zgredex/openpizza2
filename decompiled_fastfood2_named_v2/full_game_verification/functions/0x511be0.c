// rea decompile_all
// name: Recipe_StreamConstruct
// address: 0x511be0
// body: available
// range: 0x511be0-0x511e50 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall
Recipe_StreamConstruct
          (void *param_1,undefined4 param_2,int param_3,int param_4,int param_5,byte param_6,
          int param_7)

{
  undefined1 uVar1;
  short sVar2;
  void **ppvVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  int iVar9;
  short local_a8;
  short local_a6;
  uint local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  void *local_90;
  byte local_8c [128];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a49e;
  local_c = ExceptionList;
  local_a4 = CONCAT31(local_a4._1_3_,(char)*(undefined4 *)(param_4 + 0xd0) + -1);
  local_9c = *(int *)(param_4 + 0xac + (uint)param_6 * 4);
  local_a0 = *(int *)(param_3 * 0x140 + 0x388 + DAT_0057c670) << 1;
  local_98 = local_a0 / param_7;
  pbVar8 = local_8c;
  for (iVar6 = 0x20; iVar6 != 0; iVar6 = iVar6 + -1) {
    pbVar8[0] = 0;
    pbVar8[1] = 0;
    pbVar8[2] = 0;
    pbVar8[3] = 0;
    pbVar8 = pbVar8 + 4;
  }
  if (param_7 == 1) {
    ExceptionList = &local_c;
    uVar5 = Random_RangeFast(0,7);
    local_8c[0] = (byte)uVar5;
  }
  else {
    iVar9 = 0;
    iVar6 = param_7 / 2;
    ExceptionList = &local_c;
    ppvVar3 = &local_c;
    if (0 < iVar6) {
      do {
        ExceptionList = ppvVar3;
        uVar5 = Random_RangeFast(0,7);
        bVar4 = (byte)uVar5;
        local_8c[iVar9] = bVar4;
        if (bVar4 < 4) {
          local_8c[iVar6 + iVar9] = bVar4 + 4;
        }
        else {
          local_8c[iVar6 + iVar9] = bVar4 - 4;
        }
        iVar9 = iVar9 + 1;
        ppvVar3 = ExceptionList;
      } while (iVar9 < iVar6);
    }
  }
  iVar6 = 0;
  if (0 < param_7) {
    local_94 = (local_a4 & 0xff) << 2;
    do {
      local_90 = operator_new(0x1c);
      puVar7 = (undefined4 *)0x0;
      local_4 = 0;
      if (local_90 != (void *)0x0) {
        puVar7 = RecipeTopping_StreamConstruct(local_90,(void *)0x0);
      }
      *(undefined1 *)(puVar7 + 1) = (undefined1)local_a4;
      uVar1 = *(undefined1 *)(param_4 + 0xa8);
      *(byte *)(puVar7 + 4) = local_8c[iVar6];
      local_4 = 0xffffffff;
      *(undefined1 *)((int)puVar7 + 5) = uVar1;
      *(byte *)((int)puVar7 + 6) = param_6;
      List_Add((void *)((int)param_1 + 0x48),puVar7);
      param_5 = param_5 + local_98;
      if (local_a0 < param_5) {
        param_5 = param_5 - local_a0;
      }
      Stream_Seek(((param_3 +
                   ((uint)*(byte *)(puVar7 + 4) + ((uint)*(byte *)((int)puVar7 + 6) + local_94) * 8)
                   * 0xd) * 0x20 + param_5) * 4 + -0x84,*(int *)((int)param_1 + 0x310),0);
      Resource_Read(DAT_0057c5d8,(char *)&local_a6,2,*(int *)((int)param_1 + 0x310));
      Resource_Read(DAT_0057c5d8,(char *)&local_a8,2,*(int *)((int)param_1 + 0x310));
      puVar7[2] = (int)local_a6;
      puVar7[3] = (int)local_a8;
      iVar9 = (uint)*(byte *)(puVar7 + 4) + (uint)*(byte *)((int)puVar7 + 6) * 8;
      sVar2 = *(short *)(param_4 + 0x48 + iVar9 * 2);
      puVar7[5] = ((int)*(short *)(param_4 + 8 + iVar9 * 2) >> 1) + puVar7[2];
      puVar7[6] = ((int)sVar2 >> 1) + puVar7[3];
      Screen_AccumulateColorHistogram
                (param_1,(int)puVar7,*(int *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18));
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_7);
  }
  ExceptionList = local_c;
  return (float10)local_9c * (float10)param_7;
}

