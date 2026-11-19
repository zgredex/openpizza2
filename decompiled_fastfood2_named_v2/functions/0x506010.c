// rea decompile_all
// name: FUN_00506010
// address: 0x506010
// body: available
// range: 0x506010-0x50632f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall
FUN_00506010(void *this,uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,
            uint param_6,uint param_7,uint param_8)

{
  byte bVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  char cVar15;
  uint local_80;
  byte local_64 [100];
  
  uVar5 = param_6 & 0xff;
  uVar8 = param_8 & 0xff;
  uVar6 = param_7 & 0xff;
  uVar2 = param_5 & 0xff;
  uVar12 = param_4 & 0xff;
  uVar9 = param_3 & 0xff;
  uVar10 = param_2 & 0xff;
  uVar11 = param_1 & 0xff;
  if (uVar8 + uVar6 + uVar5 + uVar2 + uVar12 + uVar9 + uVar10 + uVar11 != 100) {
    FUN_0048e0a0();
  }
  local_80 = 0;
  if (((char)param_1 != '\0') && (uVar11 != 0)) {
    pbVar13 = local_64;
    for (uVar7 = uVar11 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580ac8,DAT_00580ac8),CONCAT11(DAT_00580ac8,DAT_00580ac8));
      pbVar13 = pbVar13 + 4;
    }
    for (uVar7 = param_1 & 3; local_80 = uVar11, uVar7 != 0; uVar7 = uVar7 - 1) {
      *pbVar13 = DAT_00580ac8;
      pbVar13 = pbVar13 + 1;
    }
  }
  if (((char)param_2 != '\0') && (uVar10 != 0)) {
    pbVar13 = local_64 + local_80;
    for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580ac9,DAT_00580ac9),CONCAT11(DAT_00580ac9,DAT_00580ac9));
      pbVar13 = pbVar13 + 4;
    }
    local_80 = local_80 + uVar10;
    for (uVar10 = param_2 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pbVar13 = DAT_00580ac9;
      pbVar13 = pbVar13 + 1;
    }
  }
  if (((char)param_3 != '\0') && (uVar9 != 0)) {
    pbVar13 = local_64 + local_80;
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580aca,DAT_00580aca),CONCAT11(DAT_00580aca,DAT_00580aca));
      pbVar13 = pbVar13 + 4;
    }
    local_80 = local_80 + uVar9;
    for (uVar9 = param_3 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pbVar13 = DAT_00580aca;
      pbVar13 = pbVar13 + 1;
    }
  }
  if (((char)param_4 != '\0') && (uVar12 != 0)) {
    pbVar13 = local_64 + local_80;
    for (uVar9 = uVar12 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580acb,DAT_00580acb),CONCAT11(DAT_00580acb,DAT_00580acb));
      pbVar13 = pbVar13 + 4;
    }
    for (uVar9 = param_4 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pbVar13 = DAT_00580acb;
      pbVar13 = pbVar13 + 1;
    }
    local_80 = local_80 + uVar12;
  }
  if (((char)param_5 != '\0') && (uVar2 != 0)) {
    pbVar13 = local_64 + local_80;
    for (uVar9 = uVar2 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580acc,DAT_00580acc),CONCAT11(DAT_00580acc,DAT_00580acc));
      pbVar13 = pbVar13 + 4;
    }
    for (uVar9 = param_5 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pbVar13 = DAT_00580acc;
      pbVar13 = pbVar13 + 1;
    }
    local_80 = local_80 + uVar2;
  }
  if (((char)param_6 != '\0') && (uVar5 != 0)) {
    pbVar13 = local_64 + local_80;
    for (uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580acd,DAT_00580acd),CONCAT11(DAT_00580acd,DAT_00580acd));
      pbVar13 = pbVar13 + 4;
    }
    for (uVar2 = param_6 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pbVar13 = DAT_00580acd;
      pbVar13 = pbVar13 + 1;
    }
    local_80 = local_80 + uVar5;
  }
  if (((char)param_7 != '\0') && (uVar6 != 0)) {
    pbVar13 = local_64 + local_80;
    for (uVar2 = uVar6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580ace,DAT_00580ace),CONCAT11(DAT_00580ace,DAT_00580ace));
      pbVar13 = pbVar13 + 4;
    }
    for (uVar2 = param_7 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pbVar13 = DAT_00580ace;
      pbVar13 = pbVar13 + 1;
    }
    local_80 = local_80 + uVar6;
  }
  if (((char)param_8 != '\0') && (uVar8 != 0)) {
    pbVar13 = local_64 + local_80;
    for (uVar8 = uVar8 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(uint *)pbVar13 =
           CONCAT22(CONCAT11(DAT_00580acf,DAT_00580acf),CONCAT11(DAT_00580acf,DAT_00580acf));
      pbVar13 = pbVar13 + 4;
    }
    for (uVar2 = param_8 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pbVar13 = DAT_00580acf;
      pbVar13 = pbVar13 + 1;
    }
  }
  uVar2 = Random_Range(0,99);
  bVar1 = local_64[uVar2];
  if (bVar1 == 0) {
    return *(int *)((int)this + 0xcc);
  }
  pvVar3 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  iVar4 = FUN_004d74c0(pvVar3,(uint)bVar1,0,'\0');
  if (iVar4 == 0) {
    cVar15 = '\0';
    iVar14 = 0;
    iVar4 = 0;
    pvVar3 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
    iVar4 = FUN_004d74c0(pvVar3,iVar4,iVar14,cVar15);
  }
  return iVar4;
}

