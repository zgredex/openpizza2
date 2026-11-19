// rea decompile_all
// name: FUN_004a5bb0
// address: 0x4a5bb0
// body: available
// range: 0x4a5bb0-0x4a661b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004a5bb0(void *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  float *pfVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  float10 fVar22;
  float10 fVar23;
  float10 fVar24;
  float10 fVar25;
  float10 fVar26;
  float10 fVar27;
  float10 fVar28;
  float10 fVar29;
  float10 fVar30;
  float10 fVar31;
  float10 fVar32;
  float10 fVar33;
  float10 fVar34;
  undefined4 uVar35;
  float local_78;
  int local_74;
  int local_70;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined1 local_50 [32];
  float local_30 [4];
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar6 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 4);
  uVar7 = (uint)*(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  iVar2 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  iVar3 = *(int *)(iVar2 + 0x15c);
  pfVar8 = local_30;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar8 = 0.0;
    pfVar8 = pfVar8 + 1;
  }
  local_64 = 0.0;
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = 0.0;
  local_54 = 0.0;
  local_70 = 0;
  if (0 < iVar3) {
    do {
      iVar5 = IDMap_Lookup((void *)(iVar2 + 0x148),local_70,(int *)0x0);
      if (*(int *)(iVar5 + 0x34) == *(int *)(iVar4 + 0xc1c)) {
        fVar9 = FUN_00478090(iVar5,-1,uVar6,uVar7);
        local_30[0] = (float)(fVar9 + (float10)local_30[0]);
        fVar9 = FUN_00478090(iVar5,0xc,uVar6,uVar7);
        local_18 = (float)(fVar9 + (float10)local_18);
        fVar9 = FUN_00478090(iVar5,0xe,uVar6,uVar7);
        fVar10 = FUN_00478090(iVar5,0,uVar6,uVar7);
        local_30[1] = (float)(fVar10 + (float10)(float)fVar9 + (float10)local_30[1]);
        fVar9 = FUN_00478090(iVar5,1,uVar6,uVar7);
        local_30[2] = (float)(fVar9 + (float10)local_30[2]);
        fVar9 = FUN_00478090(iVar5,2,uVar6,uVar7);
        local_30[3] = (float)(fVar9 + (float10)local_30[3]);
        fVar9 = FUN_00478090(iVar5,4,uVar6,uVar7);
        local_20 = (float)(fVar9 + (float10)local_20);
        fVar9 = FUN_0047a670(iVar5,1,uVar7);
        local_1c = (float)(fVar9 + (float10)local_1c);
        fVar9 = FUN_0047a670(iVar5,3,uVar7);
        local_c = (float)(fVar9 + (float10)local_c);
        fVar9 = FUN_00478090(iVar5,5,uVar6,uVar7);
        fVar10 = FUN_00478090(iVar5,0x12,uVar6,uVar7);
        fVar11 = FUN_00478090(iVar5,9,uVar6,uVar7);
        local_14 = (float)(fVar11 + (float10)(float)(fVar10 + (float10)(float)fVar9) +
                          (float10)local_14);
        fVar9 = FUN_00478090(iVar5,0x13,uVar6,uVar7);
        local_10 = (float)(fVar9 + (float10)local_10);
        fVar9 = FUN_00478090(iVar5,0xb,uVar6,uVar7);
        local_4 = (float)(fVar9 + (float10)local_4);
        fVar9 = FUN_00477fe0(iVar5,-1,uVar6,uVar7);
        local_78 = 0.0;
        local_74 = 0;
        local_64 = (float)(fVar9 + (float10)local_64);
        do {
          fVar9 = FUN_00477fe0(iVar5,local_74,uVar6,uVar7);
          local_74 = local_74 + 1;
          local_78 = (float)(fVar9 + (float10)local_78);
        } while (local_74 < 8);
        local_60 = local_60 + local_78;
        fVar9 = FUN_00477fe0(iVar5,0x16,uVar6,uVar7);
        local_5c = (float)(fVar9 + (float10)local_5c);
        fVar9 = FUN_00477fe0(iVar5,0x17,uVar6,uVar7);
        local_58 = (float)(fVar9 + (float10)local_58);
        fVar9 = FUN_00477fe0(iVar5,0x15,uVar6,uVar7);
        local_54 = (float)(fVar9 + (float10)local_54);
      }
      local_70 = local_70 + 1;
    } while (local_70 < iVar3);
  }
  fVar9 = FUN_004e0aa0(iVar2,0x14,uVar6,uVar7);
  fVar10 = FUN_004e0aa0(iVar2,0x14,uVar6,uVar7);
  local_8 = (float)fVar10;
  fVar10 = FUN_004e0aa0(iVar2,0x15,uVar6,uVar7);
  fVar11 = FUN_004e0aa0(iVar2,0x15,uVar6,uVar7);
  local_8 = (float)(fVar11 + (float10)local_8);
  fVar11 = FUN_004e0aa0(iVar2,0xb,uVar6,uVar7);
  fVar12 = FUN_004e0aa0(iVar2,0xb,uVar6,uVar7);
  local_4 = (float)(fVar12 + (float10)local_4);
  fVar12 = FUN_004e0aa0(iVar2,0xc,uVar6,uVar7);
  fVar13 = FUN_004e0aa0(iVar2,0xc,uVar6,uVar7);
  local_18 = (float)(fVar13 + (float10)local_18);
  fVar13 = FUN_004e0aa0(iVar2,10,uVar6,uVar7);
  fVar14 = FUN_004e0aa0(iVar2,10,uVar6,uVar7);
  local_1c = (float)(fVar14 + (float10)local_1c);
  fVar14 = FUN_004e0aa0(iVar2,6,uVar6,uVar7);
  fVar15 = FUN_004e0aa0(iVar2,6,uVar6,uVar7);
  local_1c = (float)(fVar15 + (float10)local_1c);
  fVar15 = FUN_004e0aa0(iVar2,7,uVar6,uVar7);
  fVar16 = FUN_004e0aa0(iVar2,7,uVar6,uVar7);
  local_1c = (float)(fVar16 + (float10)local_1c);
  fVar16 = FUN_004e0aa0(iVar2,8,uVar6,uVar7);
  fVar17 = FUN_004e0aa0(iVar2,8,uVar6,uVar7);
  local_1c = (float)(fVar17 + (float10)local_1c);
  fVar17 = FUN_004e0aa0(iVar2,0xd,uVar6,uVar7);
  fVar18 = FUN_004e0aa0(iVar2,0xd,uVar6,uVar7);
  local_1c = (float)(fVar18 + (float10)local_1c);
  fVar18 = FUN_004e0aa0(iVar2,3,uVar6,uVar7);
  fVar19 = FUN_004e0aa0(iVar2,3,uVar6,uVar7);
  local_30[2] = (float)(fVar19 + (float10)local_30[2]);
  fVar19 = FUN_004e0aa0(iVar2,1,uVar6,uVar7);
  fVar20 = FUN_004e0aa0(iVar2,1,uVar6,uVar7);
  local_30[2] = (float)(fVar20 + (float10)local_30[2]);
  fVar20 = FUN_004e0aa0(iVar2,2,uVar6,uVar7);
  fVar21 = FUN_004e0aa0(iVar2,2,uVar6,uVar7);
  local_30[3] = (float)(fVar21 + (float10)local_30[3]);
  fVar21 = FUN_004e0aa0(iVar2,0,uVar6,uVar7);
  fVar22 = FUN_004e0aa0(iVar2,0,uVar6,uVar7);
  local_30[1] = (float)(fVar22 + (float10)local_30[1]);
  fVar22 = FUN_004e0aa0(iVar2,0xe,uVar6,uVar7);
  fVar23 = FUN_004e0aa0(iVar2,0xe,uVar6,uVar7);
  local_30[1] = (float)(fVar23 + (float10)local_30[1]);
  fVar23 = FUN_004e0aa0(iVar2,4,uVar6,uVar7);
  fVar24 = FUN_004e0aa0(iVar2,4,uVar6,uVar7);
  local_20 = (float)(fVar24 + (float10)local_20);
  fVar24 = FUN_004e0aa0(iVar2,0x13,uVar6,uVar7);
  fVar25 = FUN_004e0aa0(iVar2,0x13,uVar6,uVar7);
  local_10 = (float)(fVar25 + (float10)local_10);
  fVar25 = FUN_004e0aa0(iVar2,0xf,uVar6,uVar7);
  fVar26 = FUN_004e0aa0(iVar2,0xf,uVar6,uVar7);
  local_c = (float)(fVar26 + (float10)local_c);
  fVar26 = FUN_004e0aa0(iVar2,0x11,uVar6,uVar7);
  fVar27 = FUN_004e0aa0(iVar2,0x11,uVar6,uVar7);
  local_c = (float)(fVar27 + (float10)local_c);
  fVar27 = FUN_004e0aa0(iVar2,0x10,uVar6,uVar7);
  fVar28 = FUN_004e0aa0(iVar2,0x10,uVar6,uVar7);
  local_c = (float)(fVar28 + (float10)local_c);
  fVar28 = FUN_004e0aa0(iVar2,9,uVar6,uVar7);
  fVar29 = FUN_004e0aa0(iVar2,9,uVar6,uVar7);
  local_14 = (float)(fVar29 + (float10)local_14);
  fVar29 = FUN_004e0aa0(iVar2,5,uVar6,uVar7);
  fVar30 = FUN_004e0aa0(iVar2,9,uVar6,uVar7);
  local_14 = (float)(fVar30 + (float10)local_14);
  fVar30 = FUN_004e0aa0(iVar2,0x18,uVar6,uVar7);
  fVar31 = FUN_004e0aa0(iVar2,0x18,uVar6,uVar7);
  local_14 = (float)(fVar31 + (float10)local_14);
  fVar31 = FUN_004e0aa0(iVar2,0x12,uVar6,uVar7);
  fVar32 = FUN_004e0aa0(iVar2,0x12,uVar6,uVar7);
  local_14 = (float)(fVar32 + (float10)local_14);
  fVar32 = FUN_004e0aa0(iVar2,0x17,uVar6,uVar7);
  fVar33 = FUN_004e0aa0(iVar2,0x17,uVar6,uVar7);
  local_14 = (float)(fVar33 + (float10)local_14);
  fVar33 = FUN_004e0aa0(iVar2,0x16,uVar6,uVar7);
  fVar34 = FUN_004e0aa0(iVar2,0x16,uVar6,uVar7);
  local_14 = (float)(fVar34 + (float10)local_14);
  local_30[0] = local_30[0] +
                (float)(fVar33 + (float10)(float)(fVar32 + (float10)(float)(fVar31 + (float10)(float
                                                  )(fVar30 + (float10)(float)(fVar29 + (float10)(
                                                  float)(fVar28 + (float10)(float)(fVar27 + (float10
                                                  )(float)(fVar26 + (float10)(float)(fVar25 + (
                                                  float10)(float)(fVar24 + (float10)(float)(fVar23 +
                                                                                           (float10)
                                                  (float)(fVar22 + (float10)(float)(fVar21 + (
                                                  float10)(float)(fVar20 + (float10)(float)(fVar19 +
                                                                                           (float10)
                                                  (float)(fVar18 + (float10)(float)(fVar17 + (
                                                  float10)(float)(fVar16 + (float10)(float)(fVar15 +
                                                                                           (float10)
                                                  (float)(fVar14 + (float10)(float)(fVar13 + (
                                                  float10)(float)(fVar12 + (float10)(float)(fVar11 +
                                                                                           (float10)
                                                  (float)(fVar10 + (float10)(float)fVar9))))))))))))
                                                  ))))))))))));
  fVar9 = FUN_004e09e0(iVar2,0x15,uVar6,uVar7);
  fVar10 = FUN_004e09e0(iVar2,0x18,uVar6,uVar7);
  fVar11 = FUN_004e09e0(iVar2,0x19,uVar6,uVar7);
  fVar12 = FUN_004e09e0(iVar2,0x14,uVar6,uVar7);
  fVar12 = fVar12 + (float10)(float)(fVar11 + (float10)(float)(fVar10 + (float10)(float)fVar9));
  fVar1 = (float)((float10)local_64 + fVar12);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_30[0],0));
  FUN_0052f9b0(param_1,0x457,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_30[1],0));
  FUN_0052f9b0(param_1,0x459,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_30[2],0));
  FUN_0052f9b0(param_1,0x458,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_30[3],0));
  FUN_0052f9b0(param_1,0x46a,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_20,0));
  FUN_0052f9b0(param_1,0x469,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_1c,0));
  FUN_0052f9b0(param_1,0x46e,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_18,0));
  FUN_0052f9b0(param_1,0x46d,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_14,0));
  FUN_0052f9b0(param_1,0x472,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_10,0));
  FUN_0052f9b0(param_1,0x471,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_c,0));
  FUN_0052f9b0(param_1,0x476,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_8,0));
  FUN_0052f9b0(param_1,0x475,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_4,0));
  FUN_0052f9b0(param_1,0x1f42,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)fVar1,0));
  FUN_0052f9b0(param_1,0x462,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_60,0));
  FUN_0052f9b0(param_1,0x463,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_5c,0));
  FUN_0052f9b0(param_1,0x464,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)local_58,0));
  FUN_0052f9b0(param_1,0x478,local_50);
  String_Format(local_50,(byte *)s___2f___005683d4,
                SUB84((double)(float)((float10)local_54 + fVar12),0));
  FUN_0052f9b0(param_1,0x465,local_50);
  if (fVar1 < local_30[0]) {
    FUN_0052f910(param_1,0x43c,0xff);
    FUN_0052f9b0(param_1,0x43c,DAT_00582554);
    String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)(local_30[0] - fVar1),0));
    uVar35 = 0xff;
  }
  else {
    FUN_0052f910(param_1,0x43c,0xa000);
    FUN_0052f9b0(param_1,0x43c,DAT_00582d8c);
    String_Format(local_50,(byte *)s___2f___005683d4,SUB84((double)(fVar1 - local_30[0]),0));
    uVar35 = 0xa000;
  }
  FUN_0052f910(param_1,0x466,uVar35);
  FUN_0052f9b0(param_1,0x466,local_50);
  return;
}

