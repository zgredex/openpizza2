// rea decompile_all
// name: FUN_005406a0
// address: 0x5406a0
// body: available
// range: 0x5406a0-0x540887 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
FUN_005406a0(void *this,int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined2 uVar1;
  int iVar2;
  int *unaff_retaddr;
  void *local_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0055aed3;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined4 *)((int)this + 4) = 1;
  *(undefined ***)this = &PTR_LAB_0055c840;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = param_3;
  *(undefined4 *)((int)this + 0x14) = param_2[1];
  *(undefined4 *)((int)this + 0x18) = *param_2;
  *(undefined4 *)((int)this + 0x1c) = param_2[1];
  *(undefined4 *)((int)this + 0x20) = param_2[2];
  *(undefined4 *)((int)this + 0x24) = param_2[3];
  uVar1 = *(undefined2 *)(param_2 + 4);
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined2 *)((int)this + 0x28) = uVar1;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(byte *)((int)this + 0x34) = (byte)((uint)param_4 >> 1) & 1;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined ***)this = &PTR_LAB_0055c874;
  local_4 = 1;
  local_24 = this;
  (**(code **)(*param_1 + 8))();
  local_24 = (void *)0x14;
  uStack_1c = param_3;
  uStack_18 = 0;
  puStack_14 = param_2;
  if (((uint)param_4 & 0x10) == 0) {
    uStack_20 = (uint)param_4 | 0x80c0;
  }
  else {
    uStack_20 = (uint)param_4 | 0x28080;
  }
  do {
    iVar2 = (**(code **)(*unaff_retaddr + 0xc))
                      (unaff_retaddr,&local_24,(undefined4 *)((int)this + 0x48),0);
    if (-1 < iVar2) {
LAB_00540863:
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = param_2;
      }
      ExceptionList = pvStack_10;
      return this;
    }
    if (((uStack_20 & 4) == 0) ||
       ((((iVar2 != -0x7787fff6 && (iVar2 != -0x7ff8fff2)) && (iVar2 != -0x7787ffce)) &&
        (iVar2 != -0x7787ffe2)))) {
      FUN_0053f0a0(&DAT_00585578,s_creating_sound_buffer__00574f80,iVar2,param_1);
      if (iVar2 < -0x7ffbfeef) {
        if (iVar2 == -0x7ffbfef0) {
          param_2 = (undefined4 *)0x80040110;
        }
        else if (iVar2 == -0x7fffbfff) {
          param_2 = (undefined4 *)0x80004001;
        }
        else if (iVar2 == -0x7fffbffe) {
          param_2 = (undefined4 *)0x80004002;
        }
        else {
          if (iVar2 != -0x7fffbffb) goto LAB_00540841;
          param_2 = (undefined4 *)0x80004005;
        }
      }
      else if (iVar2 == -0x7ff8fff2) {
        param_2 = (undefined4 *)0x8007000e;
      }
      else if (iVar2 == -0x7ff8ffa9) {
        param_2 = (undefined4 *)0x80070057;
      }
      else {
LAB_00540841:
        param_2 = (undefined4 *)0x8000ffff;
      }
      *(undefined4 *)((int)this + 0x48) = 0;
      goto LAB_00540863;
    }
    uStack_20 = uStack_20 & 0xfffffffb | 8;
  } while( true );
}

