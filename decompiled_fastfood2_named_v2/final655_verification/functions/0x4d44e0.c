// rea decompile_all
// name: City_ConstructFromName
// address: 0x4d44e0
// body: available
// range: 0x4d44e0-0x4d47d7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
City_ConstructFromName
          (void *this,char *param_1,undefined4 param_2,char *param_3,undefined4 param_4,int param_5,
          undefined4 param_6,char *param_7,undefined4 param_8,int param_9,undefined4 param_10,
          char *param_11,undefined4 param_12,int param_13,undefined4 param_14,char *param_15,
          undefined4 param_16,int param_17,undefined4 param_18,char *param_19,undefined4 param_20,
          int param_21,undefined4 param_22,char *param_23,undefined4 param_24,int param_25,
          undefined4 param_26,char *param_27,undefined4 param_28,int param_29,undefined4 param_30,
          char *param_31,undefined4 param_32,int param_33,undefined4 param_34,char *param_35,
          undefined4 param_36,int param_37,undefined4 param_38,char *param_39,undefined4 param_40,
          int param_41,undefined4 param_42,char *param_43,undefined4 param_44,int param_45)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *puVar6;
  uint *puVar7;
  undefined1 *unaff_EDI;
  char *pcVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 unaff_retaddr;
  char acStack_1bc [128];
  char *pcVar11;
  char *pcVar12;
  undefined4 in_stack_fffffee8;
  undefined *puVar13;
  undefined4 in_stack_fffffef0;
  int in_stack_fffffef4;
  undefined4 in_stack_fffffef8;
  char *in_stack_fffffefc;
  undefined4 in_stack_ffffff00;
  int in_stack_ffffff04;
  undefined4 in_stack_ffffff08;
  char *in_stack_ffffff0c;
  undefined4 in_stack_ffffff10;
  int in_stack_ffffff14;
  undefined4 in_stack_ffffff18;
  char *in_stack_ffffff1c;
  undefined4 in_stack_ffffff20;
  int in_stack_ffffff24;
  undefined4 in_stack_ffffff28;
  char *in_stack_ffffff2c;
  undefined4 in_stack_ffffff30;
  int in_stack_ffffff34;
  undefined4 in_stack_ffffff38;
  char *in_stack_ffffff3c;
  undefined4 in_stack_ffffff40;
  int in_stack_ffffff44;
  undefined4 in_stack_ffffff48;
  char *in_stack_ffffff4c;
  undefined4 in_stack_ffffff50;
  int in_stack_ffffff54;
  undefined4 in_stack_ffffff58;
  char *in_stack_ffffff5c;
  undefined4 in_stack_ffffff60;
  int in_stack_ffffff64;
  undefined4 in_stack_ffffff68;
  char *in_stack_ffffff6c;
  undefined4 in_stack_ffffff70;
  int in_stack_ffffff74;
  undefined4 in_stack_ffffff78;
  char *in_stack_ffffff7c;
  undefined4 in_stack_ffffff80;
  int in_stack_ffffff84;
  undefined4 in_stack_ffffff88;
  char *in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  int in_stack_ffffff94;
  undefined4 in_stack_ffffff98;
  char *in_stack_ffffff9c;
  undefined4 in_stack_ffffffa0;
  int in_stack_ffffffa4;
  undefined4 in_stack_ffffffa8;
  undefined *in_stack_ffffffac;
  undefined4 in_stack_ffffffb0;
  int in_stack_ffffffb4;
  undefined4 in_stack_ffffffb8;
  char *in_stack_ffffffbc;
  undefined4 in_stack_ffffffc0;
  int in_stack_ffffffc4;
  undefined4 in_stack_ffffffc8;
  undefined *in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  int in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  char *in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  int in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  char *in_stack_ffffffec;
  undefined4 in_stack_fffffff0;
  void *pvVar14;
  undefined1 *puVar15;
  undefined4 uVar16;
  char *pcVar17;
  
                    /* Constructs a city from its ini, map, and sprite resources. */
  puVar15 = &LAB_00558dfe;
  pvVar14 = ExceptionList;
  ExceptionList = (void *)((int)register0x00000010 + -0xc);
  puVar13 = this;
  FUN_004013a0((void *)((int)this + 0xfac),0);
  uVar16 = 0;
  FUN_004013a0((void *)((int)this + 0xfc8),0);
  uVar4 = 0xffffffff;
  *(undefined ***)this = &PTR_FUN_0055c500;
  pcVar17 = (char *)CONCAT31((int3)((uint)uVar16 >> 8),1);
  pcVar8 = param_1;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  for (iVar5 = ~uVar4 - 2; (-1 < iVar5 && (param_1[iVar5] < '!')); iVar5 = iVar5 + -1) {
    param_1[iVar5] = '\0';
  }
  pcVar8 = acStack_1bc + 0xac;
  pcVar11 = s__s_ini_0056b380;
  pcVar12 = param_1;
  FUN_0054dd83(pcVar8,(byte *)s__s_ini_0056b380,param_1);
  puVar2 = FUN_004db430(DAT_0057c5d8,acStack_1bc + 0xac,pcVar8,pcVar11,(int)pcVar12,unaff_ESI,
                        unaff_EDI,unaff_EBP,unaff_EBX,in_stack_fffffee8,puVar13,in_stack_fffffef0,
                        in_stack_fffffef4,in_stack_fffffef8,in_stack_fffffefc,in_stack_ffffff00,
                        in_stack_ffffff04,in_stack_ffffff08,in_stack_ffffff0c,in_stack_ffffff10,
                        in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c,in_stack_ffffff20,
                        in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,in_stack_ffffff30,
                        in_stack_ffffff34,in_stack_ffffff38,in_stack_ffffff3c,in_stack_ffffff40,
                        in_stack_ffffff44,in_stack_ffffff48,in_stack_ffffff4c,in_stack_ffffff50,
                        in_stack_ffffff54,in_stack_ffffff58,in_stack_ffffff5c,in_stack_ffffff60,
                        in_stack_ffffff64,in_stack_ffffff68,in_stack_ffffff6c,in_stack_ffffff70,
                        in_stack_ffffff74,in_stack_ffffff78,in_stack_ffffff7c,in_stack_ffffff80,
                        in_stack_ffffff84,in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,
                        in_stack_ffffff94,in_stack_ffffff98,in_stack_ffffff9c,in_stack_ffffffa0,
                        in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,in_stack_ffffffb0,
                        in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,
                        in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0,
                        in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,
                        in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,in_stack_fffffff0,
                        (int)pvVar14,puVar15,pcVar17,unaff_retaddr,(int)param_1,param_2,param_3,
                        param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11,param_12,
                        param_13,param_14,param_15,param_16,param_17,param_18,param_19,param_20,
                        param_21,param_22,param_23,param_24,param_25,param_26,param_27,param_28,
                        param_29,param_30,param_31,param_32,param_33,param_34,param_35,param_36,
                        param_37,param_38,param_39,param_40,param_41,param_42,param_43,param_44,
                        param_45);
  if (puVar2 != (undefined4 *)0x0) {
    if (this == (void *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9 = (undefined4 *)((int)this + 4);
    }
    puVar6 = puVar2;
    for (iVar5 = 0x306; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar9 = puVar9 + 1;
    }
  }
  FUN_0054dd78(puVar2);
  *(undefined4 *)((int)this + 0x10ac) = 0;
  *(undefined4 *)((int)this + 0x10b0) = 0;
  *(undefined4 *)((int)this + 0x10b4) = 0;
  *(undefined4 *)((int)this + 0x10b8) = 0;
  *(undefined4 *)((int)this + 0x10c4) = 0;
  uVar4 = FUN_004034d0(0x30,0xc0);
  *(uint *)((int)this + 0x10c8) = uVar4;
  uVar4 = FUN_004034d0(0x18,0x60);
  *(uint *)((int)this + 0x10cc) = uVar4;
  *(undefined4 *)((int)this + 0x1148) = 0;
  *(undefined4 *)((int)this + 0x114c) = 0;
  *(undefined4 *)((int)this + 0x1154) = 0;
  *(undefined4 *)((int)this + 0x1150) = 0;
  *(undefined4 *)((int)this + 0x10bc) = 0xffffffff;
  FUN_004dca00((int)this);
  *(undefined4 *)((int)this + 0xdc4) = 0;
  *(undefined4 *)((int)this + 0x10a4) = 0;
  puVar2 = (undefined4 *)((int)this + 0xcb0);
  puVar9 = (undefined4 *)((int)this + 0xc3c);
  iVar5 = 6;
  do {
    puVar9[-1] = 100;
    *puVar9 = 100;
    puVar9[1] = 100;
    puVar9[2] = 100;
    puVar2[-6] = 100;
    *puVar2 = 0;
    puVar2[6] = 0x3c;
    puVar2[0x24] = 100;
    puVar2 = puVar2 + 1;
    puVar9 = puVar9 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar2 = (undefined4 *)((int)this + 0xdac);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0xd58);
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0xd88);
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0xce0);
  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x10d4);
  iVar5 = 5;
  do {
    puVar2[-1] = 0xffffffff;
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[2] = 0;
    *(undefined1 *)(puVar2 + 4) = 0;
    *(undefined1 *)((int)puVar2 + 0x11) = 0;
    puVar2 = puVar2 + 6;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar7 = (uint *)((int)this + 0xfe4);
  iVar5 = 8;
  do {
    iVar10 = 6;
    do {
      uVar4 = FUN_004034d0(0,0x55);
      *puVar7 = uVar4;
      puVar7 = puVar7 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  puVar2 = (undefined4 *)((int)this + 0xc20);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  FUN_0054dd83(acStack_1bc + 0xac,(byte *)s__s_iso_0056cd0c,param_1);
  pvVar3 = operator_new(0x10178);
  if (pvVar3 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = IsoMap_Construct(pvVar3,(int)DAT_0057c5cc);
  }
  *(undefined4 **)((int)this + 0xfa8) = puVar2;
  FUN_004eac80(DAT_0057c5cc,puVar2,-1);
  if (DAT_0057ba10 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057ba10)(1);
  }
  FUN_0054dd83(acStack_1bc + 0xac,(byte *)s_names__s_txt_00568358,(int)this + 0x44);
  pvVar3 = operator_new(0x18);
  if (pvVar3 == (void *)0x0) {
    DAT_0057ba10 = (undefined4 *)0x0;
  }
  else {
    DAT_0057ba10 = FUN_00402cf0(pvVar3,DAT_0057c5d8,acStack_1bc + 0xac,(undefined4 *)0x0);
  }
  FUN_004d4880((int)this);
  ExceptionList = pvVar14;
  return this;
}

