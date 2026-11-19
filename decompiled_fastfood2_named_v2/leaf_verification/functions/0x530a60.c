// rea decompile_all
// name: FUN_00530a60
// address: 0x530a60
// body: available
// range: 0x530a60-0x530f7b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00530a60(int param_1)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  double local_c0;
  int local_b4;
  int local_b0;
  uint local_ac;
  double local_a8;
  double local_a0;
  char local_94 [16];
  uint local_84;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  local_94[1] = 0xfe;
  local_94[4] = 0xfe;
  local_94[6] = 0xfd;
  local_94[0xe] = 0xfd;
  local_94[5] = 2;
  local_94[8] = 2;
  local_94[2] = 1;
  local_94[10] = 1;
  local_94[0] = '\0';
  local_94[3] = 0xff;
  local_94[7] = 3;
  local_94[9] = 0;
  local_94[0xb] = 0xff;
  local_94[0xc] = 0xfc;
  local_94[0xd] = 4;
  local_94[0xf] = 3;
  Sprite_GetSize(*(void **)(param_1 + 0x50),&local_b0,&local_b4);
  if (*(int *)(param_1 + 0x100) == -0x1000000) {
    *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + 0xfc);
  }
  uVar8 = *(uint *)(param_1 + 0x100);
  local_a8 = (double)CONCAT44(local_a8._4_4_,uVar8);
  if ((uVar8 != 0xff000000) &&
     ((*(int *)(param_1 + 0x104) == -0x1000000 || (*(int *)(param_1 + 0x108) == -0x1000000)))) {
    uVar7 = *(uint *)(param_1 + 0xfc);
    *(undefined4 *)(param_1 + 0x10c) = 4;
    local_84 = uVar7 & 0xff;
    iVar4 = (uVar8 & 0xff) - local_84;
    local_a8 = (double)CONCAT44(local_a8._4_4_,iVar4);
    uVar3 = uVar7 >> 8 & 0xff;
    uVar7 = uVar7 >> 0x10 & 0xff;
    local_ac = (uVar8 >> 8 & 0xff) - uVar3;
    iVar2 = (uVar8 >> 0x10 & 0xff) - uVar7;
    if (*(int *)(param_1 + 0x104) == -0x1000000) {
      iVar6 = local_b0 + local_b4;
      iVar5 = ((iVar2 * local_b0) / iVar6 + uVar7) * 0x100;
      local_a0 = (double)CONCAT44(local_a0._4_4_,iVar5);
      *(uint *)(param_1 + 0x104) =
           (iVar4 * local_b0) / iVar6 +
           local_84 + ((int)(local_ac * local_b0) / iVar6 + uVar3 + iVar5) * 0x100;
    }
    if (*(int *)(param_1 + 0x108) == -0x1000000) {
      iVar6 = local_b0 + local_b4;
      *(uint *)(param_1 + 0x108) =
           (iVar4 * local_b4) / iVar6 +
           local_84 +
           ((int)(local_ac * local_b4) / iVar6 +
           uVar3 + ((iVar2 * local_b4) / iVar6 + uVar7) * 0x100) * 0x100;
    }
  }
  local_84 = FUN_0053d480(*(void **)(param_1 + 0x50));
  uVar8 = *(uint *)(param_1 + 0xfc);
  local_c0 = (double)(ulonglong)(uVar8 >> 0x10 & 0xff);
  local_a0 = (double)(longlong)local_c0;
  local_c0 = (double)(ulonglong)(uVar8 >> 8 & 0xff);
  local_a8 = (double)(longlong)local_c0;
  uVar7 = *(uint *)(param_1 + 0x108);
  local_c0 = (double)(ulonglong)(uVar8 & 0xff);
  local_80 = (double)(longlong)local_c0;
  dVar1 = (double)local_b4;
  local_50 = ((double)(uVar7 >> 0x10 & 0xff) - local_a0) / dVar1;
  uVar8 = *(uint *)(param_1 + 0x104);
  uVar3 = *(uint *)(param_1 + 0x100);
  local_c0 = (double)(ulonglong)(uVar8 >> 0x10 & 0xff);
  local_18 = ((double)(uVar7 >> 8 & 0xff) - local_a8) / dVar1;
  local_48 = ((double)(uVar7 & 0xff) - local_80) / dVar1;
  local_78 = (double)(longlong)local_c0;
  local_c0 = (double)(ulonglong)(uVar8 >> 8 & 0xff);
  local_70 = (double)(longlong)local_c0;
  local_c0 = (double)(ulonglong)(uVar8 & 0xff);
  local_c0 = (double)(longlong)local_c0;
  local_40 = ((double)(uVar3 >> 0x10 & 0xff) - local_78) / dVar1;
  local_ac = 0;
  local_30 = ((double)(uVar3 >> 8 & 0xff) - local_70) / dVar1;
  local_20 = ((double)(uVar3 & 0xff) - local_c0) / dVar1;
  if (0 < local_b4) {
    iVar2 = local_b0;
    do {
      uVar8 = 0;
      dVar1 = (double)local_b0;
      local_58 = local_a0;
      local_68 = local_a8;
      local_60 = local_80;
      local_38 = (local_78 - local_a0) / dVar1;
      local_10 = (local_70 - local_a8) / dVar1;
      local_28 = (local_c0 - local_80) / dVar1;
      if (0 < iVar2) {
        uVar7 = local_ac & 3;
        do {
          iVar2 = (int)local_94[(uVar8 & 3) + uVar7 * 4];
          lVar9 = __ftol();
          uVar3 = (int)lVar9 + iVar2;
          if ((int)uVar3 < 0) {
            uVar3 = 0;
          }
          else if (0xff < (int)uVar3) {
            uVar3 = 0xff;
          }
          lVar9 = __ftol();
          iVar4 = (int)lVar9 + iVar2;
          if (iVar4 < 0) {
            iVar4 = 0;
          }
          else if (0xff < iVar4) {
            iVar4 = 0xff;
          }
          lVar9 = __ftol();
          iVar2 = (int)lVar9 + iVar2;
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          else if (0xff < iVar2) {
            iVar2 = 0xff;
          }
          uVar3 = Color_RGBTo16(DAT_0057c5c8,(byte)iVar2,(byte)iVar4,uVar3);
          local_58 = local_38 + local_58;
          local_68 = local_10 + local_68;
          iVar2 = local_ac * local_b0 + uVar8;
          uVar8 = uVar8 + 1;
          *(short *)(local_84 + iVar2 * 2) = (short)uVar3;
          local_60 = local_28 + local_60;
        } while ((int)uVar8 < local_b0);
        iVar2 = local_b0;
      }
      local_a0 = local_50 + local_a0;
      local_ac = local_ac + 1;
      local_a8 = local_18 + local_a8;
      local_80 = local_48 + local_80;
      local_78 = local_40 + local_78;
      local_70 = local_30 + local_70;
      local_c0 = local_20 + local_c0;
    } while ((int)local_ac < local_b4);
  }
  return;
}

