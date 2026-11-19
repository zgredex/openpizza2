// rea decompile_all
// name: MapList_AddIniRecord
// address: 0x4cd8e0
// body: available
// range: 0x4cd8e0-0x4cd952 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
MapList_AddIniRecord
          (void *param_1,undefined4 param_2,undefined4 param_3,undefined *param_4,undefined4 param_5
          ,int param_6,undefined4 param_7,char *param_8,undefined4 param_9,int param_10,
          undefined4 param_11,char *param_12,undefined4 param_13,int param_14,undefined4 param_15,
          char *param_16,undefined4 param_17,int param_18,undefined4 param_19,char *param_20,
          undefined4 param_21,int param_22,undefined4 param_23,char *param_24,undefined4 param_25,
          int param_26,undefined4 param_27,char *param_28,undefined4 param_29,int param_30,
          undefined4 param_31,char *param_32,undefined4 param_33,int param_34,undefined4 param_35,
          char *param_36,undefined4 param_37,int param_38,undefined4 param_39,char *param_40,
          undefined4 param_41,int param_42,undefined4 param_43,char *param_44,undefined4 param_45,
          int param_46,undefined4 param_47,char *param_48,undefined4 param_49,int param_50,
          undefined4 param_51,undefined *param_52,undefined4 param_53,int param_54,
          undefined4 param_55,char *param_56,undefined4 param_57,int param_58,undefined4 param_59,
          undefined *param_60,undefined4 param_61,int param_62,undefined4 param_63,char *param_64,
          undefined4 param_65,int param_66,undefined4 param_67,char *param_68,undefined4 param_69,
          int param_70,undefined4 param_71,char *param_72,undefined4 param_73,int param_74,
          undefined4 param_75,char *param_76,undefined4 param_77,int param_78,undefined4 param_79,
          char *param_80,undefined4 param_81,int param_82,undefined4 param_83,char *param_84,
          undefined4 param_85,int param_86,undefined4 param_87,char *param_88,undefined4 param_89,
          int param_90,undefined4 param_91,char *param_92,undefined4 param_93,int param_94,
          undefined4 param_95,char *param_96,undefined4 param_97,int param_98,undefined4 param_99,
          char *param_100,undefined4 param_101,int param_102,undefined4 param_103,char *param_104,
          undefined4 param_105,int param_106,undefined4 param_107,char *param_108,
          undefined4 param_109,int param_110,undefined4 param_111,char *param_112,
          undefined4 param_113,int param_114,undefined4 param_115,char *param_116,
          undefined4 param_117,int param_118)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  void *this;
  undefined4 unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  int iVar5;
  undefined1 *unaff_EDI;
  undefined1 *unaff_retaddr;
  
                    /* Parses a map ini and appends it to the map list. */
  puVar2 = CityDefinition_ParseIni
                     (DAT_0057c5d8,param_2,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,unaff_retaddr,
                      param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                      param_10,param_11,param_12,param_13,param_14,param_15,param_16,param_17,
                      param_18,param_19,param_20,param_21,param_22,param_23,param_24,param_25,
                      param_26,param_27,param_28,param_29,param_30,param_31,param_32,param_33,
                      param_34,param_35,param_36,param_37,param_38,param_39,param_40,param_41,
                      param_42,param_43,param_44,param_45,param_46,param_47,param_48,param_49,
                      param_50,param_51,param_52,param_53,param_54,param_55,param_56,param_57,
                      param_58,param_59,param_60,param_61,param_62,param_63,param_64,param_65,
                      param_66,param_67,param_68,param_69,param_70,param_71,param_72,param_73,
                      param_74,param_75,param_76,param_77,param_78,param_79,param_80,param_81,
                      param_82,param_83,param_84,param_85,param_86,param_87,param_88,param_89,
                      param_90,param_91,param_92,param_93,param_94,param_95,param_96,param_97,
                      param_98,param_99,param_100,param_101,param_102,param_103,param_104,param_105,
                      param_106,param_107,param_108,param_109,param_110,param_111,param_112,
                      param_113,param_114,param_115,param_116,param_117,param_118);
  if (puVar2 != (undefined4 *)0x0) {
    iVar5 = 0;
    iVar1 = *(int *)((int)param_1 + 0x14);
    if (0 < iVar1) {
      do {
        iVar3 = FUN_004017f0(param_1,iVar5,(int *)0x0);
        uVar4 = FUN_005570c0(this,(byte *)(iVar3 + 0x40),(byte *)(puVar2 + 0x10));
        if (uVar4 == 0) {
          FUN_0054dd78(puVar2);
          return;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    FUN_004014b0(param_1,puVar2);
  }
  return;
}

