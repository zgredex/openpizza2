// rea decompile_all
// name: FUN_004cdac0
// address: 0x4cdac0
// body: available
// range: 0x4cdac0-0x4cdca1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
FUN_004cdac0(char *param_1,undefined4 param_2,int param_3,undefined4 param_4,char *param_5,
            undefined4 param_6,int param_7,undefined4 param_8,char *param_9,undefined4 param_10,
            int param_11,undefined4 param_12,char *param_13,undefined4 param_14,int param_15,
            undefined4 param_16,char *param_17,undefined4 param_18,int param_19,undefined4 param_20,
            char *param_21,undefined4 param_22,int param_23,undefined4 param_24,char *param_25,
            undefined4 param_26,int param_27,undefined4 param_28,char *param_29,undefined4 param_30,
            int param_31,undefined4 param_32,undefined *param_33,undefined4 param_34,int param_35,
            undefined4 param_36,char *param_37,undefined4 param_38,int param_39,undefined4 param_40,
            undefined *param_41,undefined4 param_42,int param_43,undefined4 param_44,char *param_45,
            undefined4 param_46,int param_47,undefined4 param_48,char *param_49,undefined4 param_50,
            int param_51,undefined4 param_52,char *param_53,undefined4 param_54,int param_55,
            undefined4 param_56,char *param_57,undefined4 param_58,int param_59,undefined4 param_60,
            char *param_61,undefined4 param_62,int param_63,undefined4 param_64,char *param_65,
            undefined4 param_66,int param_67,undefined4 param_68,char *param_69,undefined4 param_70,
            int param_71,undefined4 param_72,char *param_73,undefined4 param_74,int param_75,
            undefined4 param_76,char *param_77,undefined4 param_78,int param_79,undefined4 param_80,
            char *param_81,undefined4 param_82,int param_83,undefined4 param_84,char *param_85,
            undefined4 param_86,int param_87,undefined4 param_88,char *param_89,undefined4 param_90,
            int param_91,undefined4 param_92,char *param_93,undefined4 param_94,int param_95,
            undefined4 param_96,char *param_97,undefined4 param_98,int param_99)

{
  char *this;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_EBX;
  undefined1 *unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  undefined4 auStack_264 [128];
  char *pcVar5;
  int in_stack_ffffffbc;
  undefined4 in_stack_ffffffc0;
  undefined *in_stack_ffffffc4;
  undefined4 in_stack_ffffffc8;
  int in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  char *in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  int in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  char *in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  int in_stack_ffffffec;
  undefined4 in_stack_fffffff0;
  char *in_stack_fffffff4;
  undefined4 in_stack_fffffff8;
  int in_stack_fffffffc;
  
  this = param_1;
  if (DAT_0057c5c0 != 0) {
    FUN_0052f830(param_1,0x433,DAT_0058280c);
  }
  if (DAT_0057c5c0 == 7) {
    FUN_0052f830(this,0x433,DAT_00581bfc);
  }
  iVar1 = IDMap_Lookup(&DAT_0057c590,DAT_0057bb40,(int *)0x0);
  puVar2 = auStack_264 + 0x89;
  pcVar5 = s__s_ini_0056b380;
  FUN_0054dd83((undefined1 *)puVar2,(byte *)s__s_ini_0056b380,iVar1);
  puVar2 = FUN_004db430(DAT_0057c5d8,auStack_264 + 0x89,(undefined1 *)puVar2,pcVar5,iVar1,unaff_EDI,
                        unaff_ESI,unaff_EBX,in_stack_ffffffbc,in_stack_ffffffc0,in_stack_ffffffc4,
                        in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0,in_stack_ffffffd4,
                        in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,in_stack_ffffffe4,
                        in_stack_ffffffe8,in_stack_ffffffec,in_stack_fffffff0,in_stack_fffffff4,
                        in_stack_fffffff8,in_stack_fffffffc,unaff_retaddr,param_1,param_2,param_3,
                        param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
                        param_13,param_14,param_15,param_16,param_17,param_18,param_19,param_20,
                        param_21,param_22,param_23,param_24,param_25,param_26,param_27,param_28,
                        param_29,param_30,param_31,param_32,param_33,param_34,param_35,param_36,
                        param_37,param_38,param_39,param_40,param_41,param_42,param_43,param_44,
                        param_45,param_46,param_47,param_48,param_49,param_50,param_51,param_52,
                        param_53,param_54,param_55,param_56,param_57,param_58,param_59,param_60,
                        param_61,param_62,param_63,param_64,param_65,param_66,param_67,param_68,
                        param_69,param_70,param_71,param_72,param_73,param_74,param_75,param_76,
                        param_77,param_78,param_79,param_80,param_81,param_82,param_83,param_84,
                        param_85,param_86,param_87,param_88,param_89,param_90,param_91,param_92,
                        param_93,param_94,param_95,param_96,param_97,param_98,param_99);
  FUN_0052f9b0(this,0x42c,puVar2 + 0x106);
  FUN_0052f9b0(this,0x42d,puVar2);
  FUN_0054dd83((undefined1 *)(auStack_264 + 0x89),(byte *)s_maps__s_spr_0056b330,puVar2 + 0x10);
  FUN_005314a0(this,0x435,auStack_264 + 0x88,&param_1);
  FUN_00531850(this,200000,in_stack_ffffffbc,(int)param_1,(char *)(auStack_264 + 0x89));
  iVar1 = FUN_0052f950(this,0x42c);
  iVar3 = FUN_0052f970(this,0x42c);
  iVar4 = FUN_0052f930(this,0x42c);
  iVar3 = iVar3 / *(int *)(iVar4 + 0x9b0);
  if (iVar3 < iVar1) {
    FUN_005316b0(this,0x42e);
    FUN_0052fd00(this,0x42e,0,(iVar1 - iVar3) * 100,1);
    FUN_0052fd70(this,0x42e,0,0);
    FUN_0052fce0(this,0x42e,1);
  }
  else {
    FUN_00531740(this,0x42e);
    FUN_0052f990(this,0x42c,0);
  }
  FUN_00531fb0(this,200000,1,(char *)0x0);
  FUN_00531fb0(this,0x42e,1,(char *)0x0);
  FUN_00531fb0(this,0x433,1,(char *)0x0);
  FUN_00531fb0(this,0x434,1,(char *)0x0);
  FUN_0052f9b0(this,0x429,DAT_00582e4c);
  FUN_00549070(DAT_0057ba0c,DAT_0057bb40,'\0');
  return;
}

