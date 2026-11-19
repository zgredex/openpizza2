// rea decompile_all
// name: FUN_004c2be0
// address: 0x4c2be0
// body: available
// range: 0x4c2be0-0x4c2ece inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c2be0(void *param_1)

{
  void *this;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  byte bVar5;
  int iVar6;
  int iVar7;
  int local_118;
  int local_114;
  int local_110;
  void *local_10c;
  int local_108;
  int local_104;
  char local_100 [256];
  
  pvVar4 = *(void **)((int)DAT_0057c670 + 0x9c);
  local_10c = pvVar4;
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar4 + 0x30));
  local_108 = FUN_004ddcc0(iVar2);
  this = *(void **)((int)DAT_0057c670 + 0x220);
  if (DAT_0056adec == 2) {
    uVar3 = FUN_00480bf0(pvVar4,(int)this);
    if ((char)uVar3 != '\0') {
      bVar5 = 1;
      goto LAB_004c2c35;
    }
  }
  bVar5 = 0;
LAB_004c2c35:
  uVar1 = (uint)bVar5;
  FUN_005316f0(param_1,0x1f46,uVar1);
  FUN_005316f0(param_1,0x589,uVar1);
  FUN_005316f0(param_1,0x58a,uVar1);
  FUN_005316f0(param_1,0x58b,uVar1);
  FUN_005316f0(param_1,0x58e,uVar1);
  FUN_005316f0(param_1,0x58f,uVar1);
  FUN_005316f0(param_1,0x590,uVar1);
  FUN_005316f0(param_1,0x591,uVar1);
  if (bVar5 != 0) {
    iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 0x74),*(int *)((int)this + 4),(int *)0x0);
    if ((*(int *)(iVar2 + 8) < 1) || (2 < *(int *)(iVar2 + 8))) {
      FUN_0054dd83(local_100,(byte *)s_Moebel__s_spr_00568450,iVar2 + 0x40);
    }
    else {
      FUN_0054dd83(local_100,(byte *)s_Moebel__s__c_spr_00568460,iVar2 + 0x40);
    }
    FUN_00531910(param_1,0x1f46,local_100);
    FUN_0052f9b0(param_1,0x589,iVar2 + 0x18);
    FUN_0052f9b0(param_1,0x58b,(&DAT_0058319c)[*(int *)(iVar2 + 0x10)]);
    iVar2 = FUN_004e5f40(this,local_108,&local_114);
    FUN_0052f080(param_1,0x58f,&DAT_005683a4,local_114 + iVar2);
    FUN_0052f080(param_1,0x591,&DAT_005683a4,local_114);
  }
  iVar2 = *(int *)((int)local_10c + 0x170c);
  local_104 = iVar2;
  FUN_0052f080(param_1,0x5c2,(byte *)s__d__s_00568324,iVar2);
  iVar7 = 0;
  iVar6 = 0;
  local_110 = 0;
  local_118 = 0;
  if (0 < iVar2) {
    do {
      pvVar4 = (void *)FUN_004017f0((void *)((int)local_10c + 0x16f8),iVar7,(int *)0x0);
      iVar2 = FUN_004e5f40(pvVar4,local_108,&local_114);
      local_110 = local_110 + iVar2;
      iVar6 = iVar6 + local_114;
      local_118 = local_118 + *(int *)((int)pvVar4 + 0xc);
      iVar7 = iVar7 + 1;
    } while (iVar7 < local_104);
    iVar2 = local_104;
  }
  FUN_0052f080(param_1,0x5c3,&DAT_005683a4,iVar6 + local_110);
  FUN_0052f080(param_1,0x5c4,&DAT_005683a4,iVar6);
  FUN_0052f080(param_1,0x5bc,&DAT_005683a4,local_110);
  pvVar4 = local_10c;
  iVar6 = FUN_004781b0((int)local_10c);
  FUN_0052fd70(param_1,0x1f49,iVar6,0);
  if (iVar2 == 0) {
    local_118 = 0;
  }
  else {
    local_118 = local_118 / iVar2;
  }
  FUN_0052fd70(param_1,0x5b9,local_118,0);
  iVar2 = 0;
  uVar3 = extraout_EDX;
  do {
    iVar6 = FUN_00478be0(pvVar4,uVar3,iVar2);
    FUN_004a80e0(param_1,0x559,iVar2,iVar6,DAT_00582320);
    iVar2 = iVar2 + 1;
    uVar3 = extraout_EDX_00;
  } while (iVar2 < 8);
  return;
}

