// rea decompile_all
// name: FUN_004d2600
// address: 0x4d2600
// body: available
// range: 0x4d2600-0x4d2876 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d2600(int param_1)

{
  char cVar1;
  undefined4 *this;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  longlong lVar9;
  longlong lVar10;
  undefined4 *puVar11;
  int local_12c;
  void *local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  double local_110;
  double local_108;
  char local_100 [256];
  
  pvVar2 = (void *)FUN_00528040(DAT_0057c5e0,*(int *)((int)DAT_0057c670 + 0x2dac),(int *)0x0);
  if (pvVar2 != (void *)0x0) {
    iVar6 = *(int *)(param_1 + 4);
    if (*(int *)(param_1 + 0x54) == -1) {
      iVar6 = -1;
    }
    iVar5 = 0;
    local_128 = pvVar2;
    if (*(int *)(param_1 + 8) != -1) {
      local_124 = FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 8));
      iVar5 = FUN_004e2250(local_124);
    }
    if (iVar6 == 0x1a) {
      iVar6 = *(int *)(param_1 + 0x30);
    }
    switch(iVar6) {
    case 0xf:
      break;
    case 0x10:
      iVar5 = iVar5 + 8;
      break;
    case 0x11:
      iVar5 = 0x1a;
      break;
    default:
      iVar5 = -1;
      break;
    case 0x17:
      iVar5 = 0x18;
      break;
    case 0x19:
      iVar5 = 0x19;
      break;
    case 0x1c:
      iVar5 = iVar5 + 0x10;
    }
    iVar6 = FUN_0052ff20(pvVar2,*(int *)(param_1 + 0x54));
    if (iVar6 != 0) {
      FUN_005311a0(pvVar2,*(int *)(param_1 + 0x54));
    }
    if (iVar5 != -1) {
      iVar6 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)(param_1 + 0x28),(int *)0x0);
      FUN_004f5c20(*(void **)(iVar6 + 0xfa8),&local_120);
      local_108 = 128.0 / (double)(local_118 - local_120);
      local_110 = 128.0 / (double)(local_114 - local_11c);
      local_12c = FUN_004d2320(param_1);
      local_12c = local_12c - local_120;
      FUN_004d2360(param_1);
      lVar9 = __ftol();
      this = *(undefined4 **)((int)DAT_0057c670 + 0xa4);
      puVar11 = this;
      local_12c = (int)lVar9;
      lVar10 = __ftol();
      pvVar2 = local_128;
      iVar6 = FUN_005319c0(local_128,*(int *)(param_1 + 0x54),(int)lVar9,(int)lVar10,puVar11);
      if (iVar6 != 0) {
        FUN_00531b90(pvVar2,*(int *)(param_1 + 0x54),&local_12c);
        FUN_00531470(pvVar2,*(int *)(param_1 + 0x54),1);
        FUN_00534990(this,local_12c,iVar5);
        iVar6 = *(int *)(param_1 + 4);
        if (iVar6 == 0xf) {
          iVar6 = FUN_004017f0((void *)(local_124 + 0x148),*(int *)(param_1 + 0x2c),(int *)0x0);
          if (iVar6 == 0) {
            pcVar7 = s_Error_0056311c;
          }
          else {
            pcVar7 = (char *)(iVar6 + 4);
          }
          uVar3 = 0xffffffff;
          do {
            pcVar8 = pcVar7;
            if (uVar3 == 0) break;
            uVar3 = uVar3 - 1;
            pcVar8 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar8;
          } while (cVar1 != '\0');
          uVar3 = ~uVar3;
          pcVar7 = pcVar8 + -uVar3;
          pcVar8 = local_100;
          for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
            *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar8 = pcVar8 + 4;
          }
          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *pcVar8 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar8 = pcVar8 + 1;
          }
          pvVar2 = local_128;
        }
        else if (iVar6 == 0x1a) {
          FUN_0054dd83(local_100,(byte *)s__s___s__0056c954,
                       *(undefined4 *)(&DAT_005840d4 + *(int *)(param_1 + 0x30) * 4));
        }
        else {
          FUN_0054dd83(local_100,&DAT_005630d0,*(undefined4 *)(&DAT_005840d4 + iVar6 * 4));
        }
        FUN_00531f50(pvVar2,*(int *)(param_1 + 0x54),local_100);
      }
    }
  }
  return;
}

