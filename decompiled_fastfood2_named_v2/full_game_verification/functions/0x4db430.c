// rea decompile_all
// name: CityDefinition_ParseIni
// address: 0x4db430
// body: available
// range: 0x4db430-0x4dbf3a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __cdecl
CityDefinition_ParseIni
          (undefined4 param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4,int param_5,
          undefined4 param_6,undefined1 *param_7,undefined4 param_8,int param_9,undefined4 param_10,
          undefined *param_11,undefined4 param_12,int param_13,undefined4 param_14,char *param_15,
          undefined4 param_16,int param_17,undefined4 param_18,char *param_19,undefined4 param_20,
          int param_21,undefined4 param_22,char *param_23,undefined4 param_24,int param_25,
          undefined4 param_26,char *param_27,undefined4 param_28,int param_29,undefined4 param_30,
          char *param_31,undefined4 param_32,int param_33,undefined4 param_34,char *param_35,
          undefined4 param_36,int param_37,undefined4 param_38,char *param_39,undefined4 param_40,
          int param_41,undefined4 param_42,char *param_43,undefined4 param_44,int param_45,
          undefined4 param_46,char *param_47,undefined4 param_48,int param_49,undefined4 param_50,
          char *param_51,undefined4 param_52,int param_53,undefined4 param_54,char *param_55,
          undefined4 param_56,int param_57,undefined4 param_58,undefined *param_59,
          undefined4 param_60,int param_61,undefined4 param_62,char *param_63,undefined4 param_64,
          int param_65,undefined4 param_66,undefined *param_67,undefined4 param_68,int param_69,
          undefined4 param_70,char *param_71,undefined4 param_72,int param_73,undefined4 param_74,
          char *param_75,undefined4 param_76,int param_77,undefined4 param_78,char *param_79,
          undefined4 param_80,int param_81,undefined4 param_82,char *param_83,undefined4 param_84,
          int param_85,undefined4 param_86,char *param_87,undefined4 param_88,int param_89,
          undefined4 param_90,char *param_91,undefined4 param_92,int param_93,undefined4 param_94,
          char *param_95,undefined4 param_96,int param_97,undefined4 param_98,char *param_99,
          undefined4 param_100,int param_101,undefined4 param_102,char *param_103,
          undefined4 param_104,int param_105,undefined4 param_106,char *param_107,
          undefined4 param_108,int param_109,undefined4 param_110,char *param_111,
          undefined4 param_112,int param_113,undefined4 param_114,char *param_115,
          undefined4 param_116,int param_117,undefined4 param_118,char *param_119,
          undefined4 param_120,int param_121,undefined4 param_122,char *param_123,
          undefined4 param_124,int param_125)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  int *piVar11;
  byte *pbVar12;
  char *pcVar13;
  undefined4 *puVar14;
  undefined1 **ppuVar15;
  char *pcVar16;
  undefined4 *puVar17;
  bool bVar18;
  undefined1 local_res0;
  byte in_stack_0000035c;
  char in_stack_0000035d;
  int in_stack_000006fc;
  void *in_stack_000017b8;
  char *in_stack_000017bc;
  byte abStack_7ffffffe [2];
  uint auStack_7ffffffc [536870899];
  
  __chkstk(local_res0);
  param_5 = (int)register0x00000010 + 0x39c;
  param_9 = (int)register0x00000010 + 0x3dc;
  param_13 = (int)register0x00000010 + 0x3bc;
  param_17 = (int)register0x00000010 + 0x424;
  param_21 = (int)register0x00000010 + 0x428;
  param_25 = (int)register0x00000010 + 0x42c;
  param_29 = (int)register0x00000010 + 0x430;
  param_33 = (int)register0x00000010 + 0x434;
  param_37 = (int)register0x00000010 + 0x438;
  param_41 = (int)register0x00000010 + 0x43c;
  param_45 = (int)register0x00000010 + 0x3e0;
  param_49 = (int)register0x00000010 + 0x44c;
  param_53 = (int)register0x00000010 + 0x450;
  param_57 = (int)register0x00000010 + 0x454;
  param_3 = &DAT_0056d034;
  param_4 = 0;
  param_6 = 1;
  param_7 = s_SHORT_0056d02c;
  param_8 = 0;
  param_10 = 1;
  param_11 = &DAT_0056d024;
  param_12 = 0;
  param_14 = 1;
  param_15 = s_MIETEN_0056d01c;
  param_16 = 1;
  param_18 = 1;
  param_19 = s_GEDULT_0056d014;
  param_20 = 1;
  param_22 = 1;
  param_23 = s_KAUFPREIS_0056d008;
  param_24 = 1;
  param_26 = 1;
  param_27 = s_EINKOMMEN_0056cffc;
  param_28 = 1;
  param_30 = 1;
  param_31 = s_QUALITAET_0056cff0;
  param_32 = 1;
  param_34 = 1;
  param_35 = s_KOMFORT_0056cfe8;
  param_36 = 1;
  param_38 = 1;
  param_39 = s_KLIMA_0056cfe0;
  param_40 = 2;
  param_42 = 4;
  param_43 = s_BEVOELKERUNG_0056cfd0;
  param_44 = 2;
  param_46 = 1;
  param_47 = s_RATTE_0056cfc8;
  param_48 = 2;
  param_50 = 1;
  param_51 = s_KAKERLAKE_0056cfbc;
  param_52 = 2;
  param_54 = 1;
  param_55 = s_STINKBOMBE_0056cfb0;
  param_56 = 2;
  param_58 = 1;
  param_59 = &DAT_0056cfa8;
  param_60 = 2;
  param_61 = (int)register0x00000010 + 0x458;
  param_69 = (int)register0x00000010 + 0x3e4;
  param_73 = (int)register0x00000010 + 0x404;
  param_81 = (int)register0x00000010 + 0x6d8;
  param_89 = (int)register0x00000010 + 0x6e0;
  param_97 = (int)register0x00000010 + 0x6e8;
  param_101 = (int)register0x00000010 + 0x6f4;
  param_105 = (int)register0x00000010 + 0x6f8;
  param_77 = (int)register0x00000010 + 0x460;
  param_109 = (int)register0x00000010 + 0x7a0;
  param_85 = (int)register0x00000010 + 0x6dc;
  param_113 = (int)register0x00000010 + 0x7a4;
  param_65 = (int)register0x00000010 + 0x45c;
  param_93 = (int)register0x00000010 + 0x6e4;
  param_117 = (int)register0x00000010 + 0x7ac;
  param_121 = (int)register0x00000010 + 0x7b0;
  param_62 = 1;
  param_63 = s_GRAFFITI_0056cf9c;
  param_64 = 2;
  param_66 = 1;
  param_67 = &DAT_0056cf94;
  param_68 = 2;
  param_70 = 8;
  param_71 = s_BESUCHER_0056cf88;
  param_72 = 2;
  param_74 = 8;
  param_75 = s_GESCHMACK_0056cf7c;
  param_76 = 2;
  param_78 = 6;
  param_79 = s_BESONDERHEIT_0056cf6c;
  param_80 = 2;
  param_82 = 1;
  param_83 = s_SCHWIERIGKEITGRAD_0056cf58;
  param_84 = 2;
  param_86 = 1;
  param_87 = s_POLIZEIANZAHL_0056cf48;
  param_88 = 2;
  param_90 = 1;
  param_91 = s_SPIELZEIT_0056cf3c;
  param_92 = 2;
  param_94 = 1;
  param_95 = s_ZIELE_0056cf34;
  param_96 = 2;
  param_98 = 3;
  param_99 = s_STARTHQ_0056cf2c;
  param_100 = 2;
  param_102 = 1;
  param_103 = s_MAXHQ_0056cf24;
  param_104 = 2;
  param_106 = 1;
  param_107 = s_STARTGELD_0056cf18;
  param_108 = 2;
  param_110 = 1;
  param_111 = s_GEGNERANZAHL_0056cf08;
  param_112 = 2;
  param_114 = 1;
  param_115 = s_GEGNER_STARTHQ_0056cef8;
  param_116 = 2;
  param_118 = 1;
  param_119 = s_GEGNER_MAXHQ_0056cee8;
  param_120 = 2;
  param_122 = 1;
  param_123 = s_SCHLAGER_0056cedc;
  param_125 = (int)register0x00000010 + 0x478;
  param_124 = 2;
  piVar3 = Resource_Open(in_stack_000017b8,in_stack_000017bc,0);
  if (piVar3 == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar14 = (undefined4 *)((int)register0x00000010 + 0x39c);
  for (iVar7 = 0x306; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  iVar7 = Resource_ReadLine(in_stack_000017b8,(undefined1 *)((int)register0x00000010 + 0xfb4),0x400,
                            (int)piVar3);
  do {
    if (iVar7 == -1) {
      Resource_Close(in_stack_000017b8,(int)piVar3);
      puVar6 = operator_new(0xc18);
      puVar14 = (undefined4 *)((int)register0x00000010 + 0x39c);
      puVar17 = puVar6;
      for (iVar7 = 0x306; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar17 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar17 = puVar17 + 1;
      }
      puVar6[0xd0] = (puVar6[0xd0] * 0xb) / 100;
      return puVar6;
    }
    Parse_ReadDelimitedToken
              ((int)register0x00000010 + 0xfb4,(int *)&local_res0,
               (undefined4 *)((int)register0x00000010 + 0x35c),0x40);
    if ((in_stack_0000035c != 0x5c) && (in_stack_0000035d != '/')) {
      iVar7 = -1;
      pcVar13 = (char *)((int)register0x00000010 + 0x35c);
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        cVar1 = *pcVar13;
        pcVar13 = pcVar13 + 1;
      } while (cVar1 != '\0');
      if (iVar7 != -2) {
        CRT_Strupr((uint *)((int)register0x00000010 + 0x35c));
        iVar7 = 0;
        pbVar12 = &DAT_0056d034;
        ppuVar15 = &param_3;
        do {
          pbVar4 = (byte *)((int)register0x00000010 + 0x35c);
          do {
            bVar2 = *pbVar4;
            bVar18 = bVar2 < *pbVar12;
            if (bVar2 != *pbVar12) {
LAB_004dbd1c:
              iVar5 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
              goto LAB_004dbd21;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar4[1];
            bVar18 = bVar2 < pbVar12[1];
            if (bVar2 != pbVar12[1]) goto LAB_004dbd1c;
            pbVar4 = pbVar4 + 2;
            pbVar12 = pbVar12 + 2;
          } while (bVar2 != 0);
          iVar5 = 0;
LAB_004dbd21:
          if (iVar5 == 0) break;
          pbVar12 = ppuVar15[4];
          ppuVar15 = ppuVar15 + 4;
          iVar7 = iVar7 + 1;
        } while (pbVar12 != (byte *)0x0);
        if ((&param_3)[iVar7 * 4] == (undefined1 *)0x0) {
          Debug_WarningMessageBox();
        }
        else {
          switch((&param_4)[iVar7 * 4]) {
          case 0:
            Parse_ReadDelimitedToken
                      ((int)register0x00000010 + 0xfb4,(int *)&local_res0,
                       (undefined4 *)((int)register0x00000010 + 0x13b4),0x400);
            uVar8 = 0xffffffff;
            pcVar13 = (char *)((int)register0x00000010 + 0x13b4);
            do {
              pcVar16 = pcVar13;
              if (uVar8 == 0) break;
              uVar8 = uVar8 - 1;
              pcVar16 = pcVar13 + 1;
              cVar1 = *pcVar13;
              pcVar13 = pcVar16;
            } while (cVar1 != '\0');
            uVar8 = ~uVar8;
            pcVar13 = pcVar16 + -uVar8;
            pcVar16 = (char *)(&param_5)[iVar7 * 4];
            for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar16 = *(undefined4 *)pcVar13;
              pcVar13 = pcVar13 + 4;
              pcVar16 = pcVar16 + 4;
            }
            for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pcVar16 = *pcVar13;
              pcVar13 = pcVar13 + 1;
              pcVar16 = pcVar16 + 1;
            }
            break;
          case 1:
            iVar5 = (&param_6)[iVar7 * 4];
            if (0 < iVar5) {
              pfVar10 = (float *)(&param_5)[iVar7 * 4];
              do {
                iVar7 = Parse_ReadIntToken((int)register0x00000010 + 0xfb4,(int *)&local_res0);
                iVar5 = iVar5 + -1;
                *pfVar10 = (float)iVar7 * 0.02;
                pfVar10 = pfVar10 + 1;
              } while (iVar5 != 0);
            }
            break;
          case 2:
            iVar5 = (&param_6)[iVar7 * 4];
            piVar11 = (int *)(&param_5)[iVar7 * 4];
            if (0 < iVar5) {
              do {
                iVar7 = Parse_ReadIntToken((int)register0x00000010 + 0xfb4,(int *)&local_res0);
                *piVar11 = iVar7;
                piVar11 = piVar11 + 1;
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            break;
          case 3:
            iVar5 = in_stack_000006fc * 0x10;
            iVar7 = Parse_ReadIntToken((int)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(int *)((int)register0x00000010 + iVar5 + 0x700) = iVar7;
            iVar7 = Parse_ReadIntToken((int)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(int *)((int)register0x00000010 + iVar5 + 0x704) = iVar7;
            iVar7 = Parse_ReadIntToken((int)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(int *)((int)register0x00000010 + iVar5 + 0x708) = iVar7;
            iVar7 = Parse_ReadIntToken((int)register0x00000010 + 0xfb4,(int *)&local_res0);
            *(uint *)((int)register0x00000010 + iVar5 + 0x70c) = (uint)(iVar7 == 1);
            in_stack_000006fc = in_stack_000006fc + 1;
          }
        }
      }
    }
    iVar7 = Resource_ReadLine(in_stack_000017b8,(undefined1 *)((int)register0x00000010 + 0xfb4),
                              0x400,(int)piVar3);
  } while( true );
}

