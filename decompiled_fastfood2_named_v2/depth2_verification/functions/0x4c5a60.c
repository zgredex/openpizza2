// rea decompile_all
// name: FUN_004c5a60
// address: 0x4c5a60
// body: available
// range: 0x4c5a60-0x4c5dfb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c5a60(void *param_1)

{
  uint uVar1;
  int iVar2;
  void *this;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char local_100 [256];
  
  FUN_00532310(param_1,&LAB_004c58d0,0);
  DAT_0057dcfc = *(int *)((int)DAT_0057c670 + 0x21c);
  Sound_ProcessEvent(DAT_0057ba0c,*(int *)(DAT_0057dcfc + 0x30),0,*(int *)(DAT_0057dcfc + 0x24) == 0
                    );
  FUN_0052f9b0(param_1,0x4bf,DAT_0057dcfc + 4);
  iVar4 = 0x4c0;
  do {
    FUN_0052fd00(param_1,iVar4,100,0,0);
    iVar4 = iVar4 + 2;
  } while (iVar4 < 0x4cc);
  iVar4 = *(int *)(DAT_0057dcfc + 0x30);
  if (iVar4 == 0xb) {
    uVar3 = DAT_005812a4;
LAB_004c5b24:
  }
  else {
    uVar3 = DAT_005820e8;
    if ((iVar4 != 0xf) && (iVar4 != 0x21)) {
      uVar3 = (&DAT_005834d4)[*(int *)(DAT_0057dcfc + 0x34)];
      goto LAB_004c5b24;
    }
  }
  FUN_0052f9b0(param_1,0x469,uVar3);
  FUN_004c58f0(param_1);
  uVar1 = FUN_00488d90((int)DAT_0057c670);
  iVar4 = uVar1 - 1;
  if (iVar4 < 0) {
    iVar4 = 7;
  }
  iVar4 = *(int *)(DAT_0057dcfc + 0xd4 + iVar4 * 4);
  if (iVar4 != 0) {
    FUN_004bf120(param_1,*(int *)(iVar4 + 0x20),2,0x1f4f,-1,iVar4);
  }
  uVar1 = FUN_00488d90((int)DAT_0057c670);
  iVar4 = *(int *)(DAT_0057dcfc + 0xd4 + uVar1 * 4);
  if (iVar4 != 0) {
    FUN_004bf120(param_1,*(int *)(iVar4 + 0x20),2,0x1f50,-1,iVar4);
  }
  iVar4 = *(int *)(DAT_0057dcfc + 0x30);
  if (iVar4 == 0xb) {
    pcVar6 = s_fatman_0056b090;
  }
  else if (iVar4 == 0xf) {
    pcVar6 = s_promi_0056b088;
  }
  else {
    if (iVar4 == 0x21) {
      FUN_0054dd83(local_100,(byte *)s_M__s_spr_0056b05c,s_wissenschaftler_0056b068);
      goto LAB_004c5c20;
    }
    pcVar6 = (&PTR_DAT_0056b000)[*(int *)(DAT_0057dcfc + 0x34)];
  }
  FUN_0054dd83(local_100,(byte *)s_M__s__s01_spr_0056b078,pcVar6);
LAB_004c5c20:
  FUN_00531910(param_1,0x1f51,local_100);
  iVar5 = 0;
  iVar4 = 0x4c1;
  do {
    iVar2 = FUN_00488be0(DAT_0057c670,iVar5);
    if (iVar2 == 0) {
      UI_RemoveObjectByKey(param_1,iVar5 + 0x1f49);
      UI_RemoveObjectByKey(param_1,iVar4 + -1);
      UI_RemoveObjectByKey(param_1,iVar4);
      UI_RemoveObjectByKey(param_1,(&DAT_0056afb8)[iVar5]);
      UI_RemoveObjectByKey(param_1,(&DAT_0056afd0)[iVar5]);
    }
    else {
      FUN_0054dd83(local_100,(byte *)s_LOGOS__0_d_spr_00568eb8,*(int *)(iVar2 + 0x1e0) + 1);
      FUN_00531910(param_1,iVar5 + 0x1f49,local_100);
    }
    iVar4 = iVar4 + 2;
    iVar5 = iVar5 + 1;
  } while (iVar4 < 0x4cd);
  if (*(int *)(DAT_0057dcfc + 0x74) == 0) {
    FUN_004a80e0(param_1,0x47a,-1,0,0);
    FUN_004a80e0(param_1,0x48b,-1,0,0);
    FUN_004a80e0(param_1,0x49c,-1,0,0);
    FUN_004a80e0(param_1,0x4ad,-1,0,0);
    return;
  }
  iVar4 = *(int *)(*(int *)(DAT_0057dcfc + 0xf4) + 0x2c);
  iVar5 = FUN_00488be0(DAT_0057c670,*(int *)(*(int *)(DAT_0057dcfc + 0xf4) + 8));
  this = (void *)FUN_004017f0((void *)(iVar5 + 0x148),iVar4,(int *)0x0);
  iVar4 = FUN_004787f0(this,*(int *)(DAT_0057dcfc + 0x34));
  FUN_004a80e0(param_1,0x47a,-1,iVar4,DAT_005826d8);
  iVar4 = FUN_00478be0(this,DAT_0057dcfc,*(int *)(DAT_0057dcfc + 0x34));
  FUN_004a80e0(param_1,0x48b,-1,iVar4,DAT_00582320);
  iVar4 = FUN_00478320(this,*(int *)(DAT_0057dcfc + 0x34));
  FUN_004a80e0(param_1,0x49c,-1,iVar4,DAT_0058271c);
  iVar4 = FUN_004783c0(this,*(int *)(DAT_0057dcfc + 0x34));
  FUN_004a80e0(param_1,0x4ad,-1,iVar4,DAT_005827b8);
  return;
}

