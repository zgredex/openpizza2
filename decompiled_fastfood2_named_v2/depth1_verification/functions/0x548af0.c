// rea decompile_all
// name: FUN_00548af0
// address: 0x548af0
// body: available
// range: 0x548af0-0x548d68 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00548af0(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  longlong lVar10;
  float local_24;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  int local_4;
  
  local_4 = (int)param_1 + 0x178;
  FUN_00401320(local_4);
  if (*(char *)((int)param_1 + 0x169) != '\0') {
    iVar5 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    local_24 = 0.0;
    this = *(void **)(DAT_0057c5cc + 0x2c3d4);
    iVar1 = *(int *)(*(int *)(iVar5 + 0xfa8) + 0xe8);
    local_c = *(int *)(DAT_0057c670 + 0x2da0);
    iVar5 = *(int *)(*(int *)(iVar5 + 0xfa8) + 0xec);
    local_10 = 0x2c41c;
    iVar8 = local_c * 0xc;
    iVar2 = *(int *)(&DAT_005752d8 + iVar8);
    iVar3 = *(int *)(&DAT_005752dc + iVar8);
    do {
      iVar6 = *(int *)(local_10 + DAT_0057c5cc);
      if (((-1 < iVar6) && (iVar6 < *(int *)((int)this + 0x48))) &&
         (*(char *)(*(int *)((int)this + 0x4c) + 0x3e + iVar6 * 0x48) != '\0')) {
        local_18 = 0;
        local_14 = 0;
        uVar9 = Record_GetTwoFloats48(this,iVar6,&local_18,&local_14);
        if ((int)uVar9 != 0) {
          iVar7 = (local_14 + 0x100) - (iVar3 + iVar5);
          iVar6 = (local_18 + 0x100) - (iVar2 + iVar1);
          local_14 = iVar7 * iVar7 + iVar6 * iVar6;
          lVar10 = __ftol();
          local_14 = (int)lVar10;
          local_18 = *(int *)(&DAT_005752e0 + iVar8);
          if (local_14 <= local_18) {
            local_24 = (0.33333334 - ((float)local_14 / (float)local_18) * 0.33333334) + local_24;
          }
        }
      }
      local_10 = local_10 + 4;
    } while (local_10 < 0x2c434);
    if (0.0 < local_24) {
      if (*(char *)((int)param_1 + 0x140) == '\0') {
        Sound_SetPosition(param_1,*(undefined4 *)((int)param_1 + 0x80));
        *(undefined1 *)((int)param_1 + 0x140) = 1;
        FUN_00401340(local_4);
        return;
      }
      local_c = *(undefined4 *)((int)param_1 + 0x1d0);
      uStack_8 = 0;
      piVar4 = *(int **)((int)param_1 + 8);
      iVar1 = *piVar4;
      lVar10 = __ftol();
      (**(code **)(iVar1 + 0x7c))(piVar4,*(undefined4 *)((int)param_1 + 0x80),(int)lVar10);
      FUN_00401340(local_10);
      return;
    }
    if (*(char *)((int)param_1 + 0x140) != '\0') {
      (**(code **)(**(int **)((int)param_1 + 8) + 0x68))
                (*(int **)((int)param_1 + 8),*(undefined4 *)((int)param_1 + 0x80));
      *(undefined1 *)((int)param_1 + 0x140) = 0;
    }
  }
  FUN_00401340(local_4);
  return;
}

