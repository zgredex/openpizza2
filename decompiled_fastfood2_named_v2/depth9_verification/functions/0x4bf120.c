// rea decompile_all
// name: FUN_004bf120
// address: 0x4bf120
// body: available
// range: 0x4bf120-0x4bf3c1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bf120(void *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  void *this;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  byte local_244 [64];
  void *local_204;
  char local_200 [256];
  char local_100 [256];
  
  switch(*(undefined4 *)(param_6 + 4)) {
  case 5:
    FUN_0054dd83(local_200,&DAT_005630d0,s_Kletterhaus_0056ac60);
    break;
  default:
    pcVar2 = (char *)(DAT_0057c5cc + 0x25 + param_2 * 0x48);
LAB_004bf209:
    uVar4 = 0xffffffff;
    do {
      pcVar6 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar6 + -uVar4;
    pcVar6 = local_200;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar6 = pcVar6 + 1;
    }
    pcVar2 = _strchr(local_200,0x2e);
    pcVar2[-1] = '\0';
    break;
  case 0xb:
    pcVar2 = (char *)(DAT_0057c5cc + 0x25 + param_2 * 0x48);
    if (*(int *)(param_6 + 0x48) != -1) goto LAB_004bf209;
    uVar4 = 0xffffffff;
    do {
      pcVar6 = pcVar2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar6 = pcVar2 + 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar6;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar2 = pcVar6 + -uVar4;
    pcVar6 = local_200;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar2;
      pcVar2 = pcVar2 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      pcVar6 = pcVar6 + 1;
    }
    pcVar2 = _strchr(local_200,0x2e);
    pcVar2[-1] = '\0';
    pcVar2[-2] = '\0';
    break;
  case 0x18:
    FUN_0054dd83(local_200,&DAT_005630d0,s_H_STADION_0056ac54);
    break;
  case 0x22:
    FUN_0054dd83(local_200,&DAT_005630d0,s_H_BAHNHOF_0056ac48);
  }
  if (param_3 == 1) {
    if (-1 < param_5) {
      FUN_0054dd83(local_100,(byte *)s_buildings_MG__s_d_spr_0056ac00,local_200);
      goto LAB_004bf2c3;
    }
    pcVar2 = s_buildings_MG__s_spr_0056abec;
  }
  else {
    if (param_3 != 2) goto LAB_004bf2c3;
    if (-1 < param_5) {
      FUN_0054dd83(local_100,(byte *)s_buildings_M__s_d_0_spr_0056ac30,local_200);
      goto LAB_004bf2c3;
    }
    pcVar2 = s_buildings_M__s_0_spr_0056ac18;
  }
  FUN_0054dd83(local_100,(byte *)pcVar2,local_200);
LAB_004bf2c3:
  iVar3 = FUN_0052ff30(param_1,param_4);
  if (iVar3 == 6) {
    iVar3 = FUN_00531910(param_1,param_4,local_100);
    if (iVar3 == 0) {
      DebugConsole_Printf(DAT_0057c1e0,0xffff,(byte *)s_Not_found___s_0056abdc,local_100);
      return;
    }
  }
  else if (iVar3 == 7) {
    this = (void *)FUN_00531cf0(param_1,param_4);
    FUN_00521380((int)this);
    iVar3 = FUN_00527580(DAT_0057c5e0,local_100,(undefined4 *)0x0,(undefined4 *)local_244);
    if (iVar3 != 0) {
      FUN_00521ae0(this,&local_24c,&local_250);
      uVar4 = FUN_00521b10((int)this);
      FUN_0053d090(local_204,&local_254,&local_248);
      FUN_0053d570(local_204,uVar4,(uint *)(local_24c - local_254 >> 1),local_250 - local_248 >> 1);
      FUN_005277d0(DAT_0057c5e0,local_244);
    }
  }
  return;
}

