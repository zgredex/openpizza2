// rea decompile_all
// name: FUN_00525080
// address: 0x525080
// body: available
// range: 0x525080-0x52526c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00525080(void *this,undefined4 *param_1,int *param_2,void *param_3,undefined4 *param_4)

{
  void *this_00;
  int iVar1;
  int *piVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  
  this_00 = param_3;
  if ((param_3 != (void *)0x0) && (*(int *)((int)param_3 + 0x4c) != 0)) {
    iVar1 = FUN_0052ffa0(param_3,param_2);
    if (iVar1 != 0) {
      if ((*(void **)((int)this + 0x228) != (void *)0x0) &&
         (*(void **)((int)this + 0x228) != this_00)) {
        *(undefined4 *)((int)this + 0x82d4) = 0;
        return 1;
      }
      piVar2 = UI_HitTestChildAtPoint(this_00,param_2,&param_3);
      if (piVar2 != (int *)0x0) {
        if (*(int **)((int)this + 0x82dc) != piVar2) {
          *(void **)((int)this + 0x82d0) = this_00;
          *(int **)((int)this + 0x82dc) = piVar2;
          *(undefined4 *)((int)this + 0x82f0) = 0;
          DVar3 = timeGetTime();
          *(DWORD *)((int)this + 0x82e0) = DVar3 + *(int *)((int)this + 0x82f4);
          iVar1 = FUN_00520e00((int)piVar2);
          if (iVar1 != 0) {
            iVar1 = piVar2[1];
            iVar4 = FUN_00520e10((int)piVar2);
            FUN_005301c0(*(void **)((int)this + 0x82d0),iVar1,0xc,iVar4);
          }
          if (*(int *)((int)this + 0x82ec) == 0) {
            *(undefined4 *)((int)this + 0x82f0) = 1;
          }
        }
        if (piVar2[7] == 0) {
          uVar5 = (**(code **)(*piVar2 + 0xc))(param_1,0,param_2);
          *param_1 = uVar5;
          *(int **)((int)this + 0x82d4) = piVar2;
          return 1;
        }
        *param_4 = 0;
        *(int **)((int)this + 0x82d4) = piVar2;
        return 1;
      }
      if (*(int **)((int)this + 0x82dc) != (int *)0x0) {
        UI_RefreshChildRect(this);
        if (*(int *)((int)this + 0x82d0) != 0) {
          iVar1 = FUN_00520e00(*(int *)((int)this + 0x82dc));
          if (iVar1 != 0) {
            FUN_005301c0(*(void **)((int)this + 0x82d0),*(int *)(*(int *)((int)this + 0x82dc) + 4),
                         0xd,0);
          }
        }
        *(undefined4 *)((int)this + 0x82dc) = 0;
      }
      *(undefined4 *)((int)this + 0x82d4) = 0;
      if (param_3 != (void *)0x0) {
        if (param_1 == (undefined4 *)0x7) {
          _DAT_00584228 = *param_2;
          _DAT_0058422c = param_2[1];
          FUN_005301c0(this_00,-1,0x11,0x584228);
          return 1;
        }
        if (param_1 == (undefined4 *)0x9) {
          _DAT_00584228 = *param_2;
          _DAT_0058422c = param_2[1];
          FUN_005301c0(this_00,-1,0x16,0x584228);
        }
        return 1;
      }
    }
  }
  return 0;
}

