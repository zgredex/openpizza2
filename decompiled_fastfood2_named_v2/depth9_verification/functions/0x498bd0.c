// rea decompile_all
// name: FUN_00498bd0
// address: 0x498bd0
// body: available
// range: 0x498bd0-0x498e17 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __cdecl FUN_00498bd0(int param_1)

{
  byte bVar1;
  int iVar2;
  HANDLE pvVar3;
  int iVar4;
  void *pvVar5;
  int *this;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  int iVar10;
  bool bVar11;
  undefined4 *local_36c;
  byte local_364 [64];
  uint local_324 [5];
  undefined1 local_310 [260];
  undefined1 local_20c [512];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055862c;
  local_c = ExceptionList;
  iVar10 = 0;
  ExceptionList = &local_c;
  pvVar3 = CRT_FindFirst(s_save_piz___piz_005688d0,local_324);
  if (pvVar3 != (HANDLE)0xffffffff) {
    do {
      if (iVar10 == param_1) {
        FUN_0054dd83(local_20c,(byte *)s_save_piz__s_005688e0,local_310);
        break;
      }
      iVar10 = iVar10 + 1;
      iVar4 = CRT_FindNext(pvVar3,local_324);
    } while (iVar4 != -1);
    CRT_FindClose(pvVar3);
    pvVar5 = operator_new(0x5c);
    iVar10 = 0;
    local_4 = 0;
    if (pvVar5 == (void *)0x0) {
      this = (int *)0x0;
    }
    else {
      this = FUN_0054cc99();
    }
    local_4 = 0xffffffff;
    if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) == 0) {
      FUN_0054cbc1(this,&DAT_0057c668,4);
      if ((DAT_0057c668 < 0x2a) || (0x2e < DAT_0057c668)) {
        if (this != (int *)0x0) {
          (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
        }
      }
      else {
        pvVar5 = operator_new(0x330);
        local_4 = 1;
        if (pvVar5 == (void *)0x0) {
          local_36c = (undefined4 *)0x0;
        }
        else {
          local_36c = FUN_0050fc20(pvVar5,this,'\x01');
        }
        local_4 = 0xffffffff;
        puVar8 = (undefined4 *)(*(int *)(*this + 4) + (int)this);
        if ((*(byte *)(*(int *)(*this + 4) + 8 + (int)this) & 6) == 0) {
          if (this != (int *)0x0) {
            (**(code **)*puVar8)(1);
          }
          FUN_0054dd83(local_364,&DAT_005630d0,local_36c + 1);
          iVar4 = *(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
          iVar2 = *(int *)(iVar4 + 0x124);
          if (0 < iVar2) {
            do {
              iVar6 = FUN_004017f0((void *)(iVar4 + 0x110),iVar10,(int *)0x0);
              pbVar9 = local_364;
              pbVar7 = (byte *)(iVar6 + 4);
              do {
                bVar1 = *pbVar7;
                bVar11 = bVar1 < *pbVar9;
                if (bVar1 != *pbVar9) {
LAB_00498dba:
                  iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
                  goto LAB_00498dbf;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar7[1];
                bVar11 = bVar1 < pbVar9[1];
                if (bVar1 != pbVar9[1]) goto LAB_00498dba;
                pbVar7 = pbVar7 + 2;
                pbVar9 = pbVar9 + 2;
              } while (bVar1 != 0);
              iVar6 = 0;
LAB_00498dbf:
              if (iVar6 == 0) {
                ExceptionList = local_c;
                return 2;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < iVar2);
          }
          FUN_004014b0((void *)(iVar4 + 0x110),local_36c);
          ExceptionList = local_c;
          return 1;
        }
        if (this != (int *)0x0) {
          (**(code **)*puVar8)(1);
        }
      }
    }
    else if (this != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*this + 4) + (int)this))(1);
    }
  }
  ExceptionList = local_c;
  return 0;
}

