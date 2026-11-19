// rea decompile_all
// name: FUN_00545290
// address: 0x545290
// body: available
// range: 0x545290-0x545643 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00545290(int param_1,char *param_2,int *param_3)

{
  int *this;
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined1 uStack00000000;
  int local_74;
  LPCRITICAL_SECTION local_70;
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
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b5db;
  pvStack_c = ExceptionList;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  ExceptionList = &pvStack_c;
  local_70 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  iVar3 = *(int *)(param_1 + 0x98);
  local_4 = 0;
  local_74 = 0;
  if (-1 < iVar3) {
    *param_3 = 0;
    (**(code **)**(undefined4 **)(param_1 + 0x9c))(*(undefined4 **)(param_1 + 0x9c));
    FUN_0053f460(appuStack_58,*(void **)(param_1 + 0x9c),param_2,&local_74);
    iVar3 = local_74;
    local_4._0_1_ = 1;
    if (local_74 < 0) {
      appuStack_58[0] = &PTR_LAB_0055c850;
      local_4 = CONCAT31(local_4._1_3_,2);
      if (pvStack_1c != (LPVOID)0x0) {
        FUN_0054dd78(pvStack_1c);
      }
      if (iStack_4c != 0) {
        FUN_00540260(piStack_50,iStack_4c);
      }
      if (pvStack_48 != (LPVOID)0x0) {
        FUN_0054dd78(pvStack_48);
      }
      if (piStack_50 != (int *)0x0) {
        (**(code **)(*piStack_50 + 4))(piStack_50);
      }
      appuStack_58[0] = &PTR_LAB_0055c840;
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
      this = operator_new(0xac);
      local_4._0_1_ = 3;
      if (this == (int *)0x0) {
        this = (int *)0x0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x94);
        if ((iVar3 == 0) || ((iVar3 != 1 && (iVar3 != 2)))) {
          uVar5 = 8;
        }
        else {
          uVar5 = 4;
        }
        piVar1 = *(int **)(param_1 + 0xc);
        if (piVar1 == (int *)0x0) {
          piVar1 = (int *)0x0;
        }
        else {
          (**(code **)(*piVar1 + 4))(piVar1);
          piVar1 = *(int **)(param_1 + 0xc);
        }
        SoundBuffer_CreateDSBuffer(this,piVar1,&uStack_6c,uStack_30,(undefined4 *)(uVar5 | 0x12));
        local_4._0_1_ = 4;
        FUN_00545650(this + 0x13);
        piVar1 = this + 0x17;
        *(undefined1 *)(this + 0x28) = 0;
        *(undefined1 *)((int)this + 0xa1) = 0;
        *piVar1 = 0;
        DVar2 = timeGetTime();
        this[0x29] = DVar2;
        this[0x2a] = DVar2;
        *this = (int)&PTR_LAB_0055c8c8;
        if (-1 < local_74) {
          iVar3 = (*(code *)**(undefined4 **)this[0x12])
                            ((undefined4 *)this[0x12],&DAT_0055cb88,piVar1);
          if (iVar3 < 0) {
            *piVar1 = 0;
          }
          else {
            FUN_00545660((int)this);
          }
          this[0x14] = this[0x14] | 3;
          if (&uStack00000000 != (undefined1 *)0x74) {
            local_74 = iVar3;
          }
        }
        lpCriticalSection = local_70;
      }
      local_4._0_1_ = 1;
      if (this == (int *)0x0) {
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(local_4._1_3_,5);
        if (pvStack_1c != (LPVOID)0x0) {
          FUN_0054dd78(pvStack_1c);
        }
        if (iStack_4c != 0) {
          FUN_00540260(piStack_50,iStack_4c);
        }
        if (pvStack_48 != (LPVOID)0x0) {
          FUN_0054dd78(pvStack_48);
        }
        if (piStack_50 != (int *)0x0) {
          (**(code **)(*piStack_50 + 4))(piStack_50);
        }
        appuStack_58[0] = &PTR_LAB_0055c840;
        LeaveCriticalSection(lpCriticalSection);
        ExceptionList = pvStack_c;
        return -0x7ff8fff2;
      }
      if (local_74 < 0) {
        (**(code **)(*this + 4))(this);
        iVar3 = local_74;
        appuStack_58[0] = &PTR_LAB_0055c850;
        local_4 = CONCAT31(local_4._1_3_,6);
        if (pvStack_1c != (LPVOID)0x0) {
          FUN_0054dd78(pvStack_1c);
        }
        if (iStack_4c != 0) {
          FUN_00540260(piStack_50,iStack_4c);
        }
        if (pvStack_48 != (LPVOID)0x0) {
          FUN_0054dd78(pvStack_48);
        }
        if (piStack_50 != (int *)0x0) {
          (**(code **)(*piStack_50 + 4))(piStack_50);
        }
        appuStack_58[0] = &PTR_LAB_0055c840;
      }
      else {
        local_74 = FUN_00540a30(this,appuStack_58);
        if (local_74 < 0) {
          (**(code **)(*this + 4))(this);
        }
        else {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
LAB_005455e3:
            (**(code **)(*this + 4))(this);
            local_4 = (uint)local_4._1_3_ << 8;
            SoundSample_Destruct(appuStack_58);
            LeaveCriticalSection(lpCriticalSection);
            ExceptionList = pvStack_c;
            return -0x7ff8fff2;
          }
          *puVar4 = this;
          iVar3 = FUN_00546f00((void *)(param_1 + 0x54),(int)puVar4,'\0');
          if (iVar3 == 0) goto LAB_005455e3;
          *param_3 = iVar3;
        }
        iVar3 = local_74;
        local_4 = (uint)local_4._1_3_ << 8;
        SoundSample_Destruct(appuStack_58);
      }
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = pvStack_c;
  return iVar3;
}

