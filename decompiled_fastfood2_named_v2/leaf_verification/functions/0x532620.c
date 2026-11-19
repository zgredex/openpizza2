// rea decompile_all
// name: FUN_00532620
// address: 0x532620
// body: available
// range: 0x532620-0x532844 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00532620(void *this,int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int iStack_4;
  
  iVar1 = param_2;
joined_r0x0053263c:
  do {
    while( true ) {
      if (iVar1 != -1) {
        iVar4 = *param_1;
        if ((iVar4 == 0) || (iVar4 == 1)) {
          piVar3 = (int *)FUN_0052fef0(this,iVar1);
          iVar4 = (**(code **)(*piVar3 + 0xc))(2,0,0);
          if (iVar4 == 0) {
            UI_ClearPendingCommand(piVar3);
            return;
          }
          iVar4 = param_1[5];
          iStack_4 = 0;
          if (0 < iVar4) {
            do {
              iVar5 = Array_GetPtr(param_1 + 1,iStack_4);
              piVar3 = (int *)FUN_0052fef0(this,iVar5);
              if (iVar5 == iVar1) {
                if (unaff_ESI != 0) {
                  Object_EnsureInit(piVar3);
                }
              }
              else {
                (**(code **)(*piVar3 + 0xc))(2,0,0);
                (**(code **)(*piVar3 + 0xc))(0,0,0);
                if (unaff_ESI != 0) {
                  UI_ClearPendingCommand(piVar3);
                }
              }
              iStack_4 = iStack_4 + 1;
            } while (iStack_4 < iVar4);
          }
        }
        else {
          if (iVar4 != 2) {
            return;
          }
          iVar4 = param_1[5];
          param_2 = 0;
          if (0 < iVar4) {
            do {
              iVar5 = Array_GetPtr(param_1 + 1,param_2);
              iVar2 = FUN_0052fef0(this,iVar5);
              if (iVar5 != iVar1) {
                FUN_00520e60(iVar2);
              }
              param_2 = param_2 + 1;
            } while (param_2 < iVar4);
          }
        }
        *(undefined4 *)(*(int *)((int)this + 0x134) + 0x1b8) = 1;
        return;
      }
      if (*param_1 == 0) break;
      if (*param_1 != 2) {
        return;
      }
      iVar4 = param_1[5];
      iVar5 = 0;
      while( true ) {
        if (iVar4 <= iVar5) {
          iVar1 = Array_GetPtr(param_1 + 1,0);
          iVar1 = FUN_0052fef0(this,iVar1);
          FUN_00520e30(iVar1);
          return;
        }
        iVar1 = Array_GetPtr(param_1 + 1,iVar5);
        iVar2 = FUN_0052fef0(this,iVar1);
        if (*(int *)(iVar2 + 0x20) != 0) break;
        iVar5 = iVar5 + 1;
      }
    }
    iVar4 = param_1[5];
    iVar5 = 0;
    if (0 < iVar4) {
      do {
        iVar1 = Array_GetPtr(param_1 + 1,iVar5);
        piVar3 = (int *)FUN_0052fef0(this,iVar1);
        iVar2 = (**(code **)(*piVar3 + 0xc))(2,0,0);
        if (iVar2 == 1) goto joined_r0x0053263c;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
    }
    iVar1 = Array_GetPtr(param_1 + 1,0);
    piVar3 = (int *)FUN_0052fef0(this,iVar1);
    (**(code **)(*piVar3 + 0xc))(0,1,0);
  } while( true );
}

