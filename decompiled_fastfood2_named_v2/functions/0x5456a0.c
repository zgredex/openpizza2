// rea decompile_all
// name: FUN_005456a0
// address: 0x5456a0
// body: available
// range: 0x5456a0-0x545a0b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_005456a0(uint param_1,char *param_2,int *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar1;
  char *this;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined **appuStack_58 [2];
  int *piStack_50;
  int iStack_4c;
  LPVOID pvStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  undefined4 uStack_30;
  LPVOID pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  uVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b62b;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &pvStack_c;
  EnterCriticalSection(lpCriticalSection);
  uVar5 = *(uint *)(uVar1 + 0x98);
  local_4 = 0;
  param_1 = 0;
  if (-1 < (int)uVar5) {
    *param_3 = 0;
    (**(code **)**(undefined4 **)(uVar1 + 0x9c))(*(undefined4 **)(uVar1 + 0x9c));
    FUN_0053f460(appuStack_58,*(void **)(uVar1 + 0x9c),param_2,(int *)&param_1);
    uVar5 = param_1;
    local_4._0_1_ = 1;
    if ((int)param_1 < 0) {
      appuStack_58[0] = &PTR_LAB_0055c850;
      local_4 = CONCAT31(local_4._1_3_,2);
      if (pvStack_1c != (LPVOID)0x0) {
        Mem_Free(pvStack_1c);
      }
      if (iStack_4c != 0) {
        FUN_00540260(piStack_50,iStack_4c);
      }
      if (pvStack_48 != (LPVOID)0x0) {
        Mem_Free(pvStack_48);
      }
      if (piStack_50 != (int *)0x0) {
        (**(code **)(*piStack_50 + 4))(piStack_50);
        appuStack_58[0] = &PTR_LAB_0055c840;
        goto LAB_005459ee;
      }
    }
    else {
      if (iStack_4c != 0) {
        uStack_68 = uStack_40;
        uStack_64 = uStack_3c;
        uStack_6c = uStack_44;
        uStack_60 = uStack_38;
        uStack_5c = uStack_34;
        if ((short)uStack_44 != 1) {
          FUN_0053f840((undefined2 *)&uStack_6c);
        }
      }
      this = operator_new(0xb4);
      local_4._0_1_ = 3;
      param_2 = this;
      if (this == (char *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        iVar4 = *(int *)(uVar1 + 0x94);
        if (((iVar4 == 0) || (iVar4 == 1)) || (uVar5 = 8, iVar4 == 2)) {
          uVar5 = 4;
        }
        piVar2 = *(int **)(uVar1 + 0xc);
        if (piVar2 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          (**(code **)(*piVar2 + 4))(piVar2);
          piVar2 = *(int **)(uVar1 + 0xc);
        }
        piVar2 = FUN_00541520(this,piVar2,&uStack_6c,uStack_30,uVar5 | 2,&param_1);
      }
      local_4._0_1_ = 1;
      if (piVar2 == (int *)0x0) {
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(local_4._1_3_,4);
        if (pvStack_1c != (LPVOID)0x0) {
          Mem_Free(pvStack_1c);
        }
        if (iStack_4c != 0) {
          FUN_00540260(piStack_50,iStack_4c);
        }
        if (pvStack_48 != (LPVOID)0x0) {
          Mem_Free(pvStack_48);
        }
        if (piStack_50 != (int *)0x0) {
          (**(code **)(*piStack_50 + 4))(piStack_50);
        }
        appuStack_58[0] = &PTR_LAB_0055c840;
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = pvStack_c;
        return 0x8007000e;
      }
      if ((int)param_1 < 0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        uVar5 = param_1;
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(local_4._1_3_,5);
        if (pvStack_1c != (LPVOID)0x0) {
          Mem_Free(pvStack_1c);
        }
        if (iStack_4c != 0) {
          FUN_00540260(piStack_50,iStack_4c);
        }
      }
      else {
        param_1 = FUN_00540a30(piVar2,appuStack_58);
        if (-1 < (int)param_1) {
          puVar3 = operator_new(0xc);
          if (puVar3 != (undefined4 *)0x0) {
            *puVar3 = piVar2;
            iVar4 = FUN_00546f00((void *)(uVar1 + 0x54),(int)puVar3,'\0');
            uVar5 = param_1;
            if (iVar4 != 0) {
              local_4 = (uint)local_4._1_3_ << 8;
              *param_3 = iVar4;
              FUN_0053f5d0(appuStack_58);
              goto LAB_005459ee;
            }
          }
          (**(code **)(*piVar2 + 4))(piVar2);
          local_4 = (uint)local_4._1_3_ << 8;
          FUN_0053f5d0(appuStack_58);
          LeaveCriticalSection(lpCriticalSection);
          ExceptionList = pvStack_c;
          return 0x8007000e;
        }
        (**(code **)(*piVar2 + 4))(piVar2);
        uVar5 = param_1;
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(local_4._1_3_,6);
        if (pvStack_1c != (LPVOID)0x0) {
          Mem_Free(pvStack_1c);
        }
        if (iStack_4c != 0) {
          FUN_00540260(piStack_50,iStack_4c);
        }
      }
      if (pvStack_48 != (LPVOID)0x0) {
        Mem_Free(pvStack_48);
      }
      if (piStack_50 != (int *)0x0) {
        (**(code **)(*piStack_50 + 4))(piStack_50);
      }
    }
    appuStack_58[0] = &PTR_LAB_0055c840;
  }
LAB_005459ee:
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return uVar5;
}

