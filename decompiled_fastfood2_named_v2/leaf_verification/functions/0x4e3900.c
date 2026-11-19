// rea decompile_all
// name: FUN_004e3900
// address: 0x4e3900
// body: available
// range: 0x4e3900-0x4e3aa1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004e3900(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  void *this_00;
  int iVar6;
  
  iVar1 = FUN_004e1d40(this,-1);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    do {
      piVar2 = (int *)IDMap_Lookup((void *)((int)this + 0x1b8),iVar1,(int *)0x0);
      FUN_004e2110(this,*piVar2);
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  iVar1 = *(int *)((int)this + 0x140) + -1;
  if (-1 < iVar1) {
    do {
      puVar3 = (undefined4 *)IDMap_Lookup((void *)((int)this + 300),iVar1,(int *)0x0);
      FUN_004e3ab0(this,puVar3,0);
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  iVar1 = *(int *)((int)this + 0x15c);
  iVar6 = 0;
  if (0 < iVar1) {
    do {
      pvVar4 = (void *)IDMap_Lookup((void *)((int)this + 0x148),iVar6,(int *)0x0);
      if (*(int *)((int)pvVar4 + 0x14c4) != 0) {
        iVar5 = FUN_0047c370(pvVar4,*(int *)((int)pvVar4 + 0x14c4));
        piVar2 = (int *)IDMap_Lookup((void *)((int)pvVar4 + 0x1500),iVar5,(int *)0x0);
        FUN_0047a9d0(pvVar4,piVar2,0);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
  }
  this_00 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4)
                                 ,(int *)0x0);
  pvVar4 = *(void **)((int)this + 0x1d8);
  if (pvVar4 != (void *)0x0) {
    FUN_00486be0(DAT_0057c670,0);
    if (param_1 == 0) {
      FUN_004dc9a0(this_00,pvVar4,(void *)0x0);
    }
    else {
      FUN_004d77b0(this_00,pvVar4,7,-1,(void *)0x23,-1);
    }
    *(undefined4 *)((int)this_00 + *(int *)((int)this + 0x48) * 4 + 0xc20) = 0;
    *(undefined4 *)((int)this + 0x1d8) = 0;
    FUN_00486e00((int)DAT_0057c670);
  }
  if (param_1 != 0) {
    iVar1 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    if (*(int *)((int)this + 0x48) == iVar1) {
      iVar1 = 3;
      piVar2 = *(int **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
      do {
        piVar2 = piVar2 + 1;
        if (*piVar2 == 0x1c) {
          FUN_004f6b50();
        }
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  pvVar4 = *(void **)((int)DAT_0057c670 + 0x25c);
  if (pvVar4 != (void *)0x0) {
    FUN_005301c0(pvVar4,-0x18617,0x23,0);
    iVar1 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    if (*(int *)((int)this + 0x48) == iVar1) {
      FUN_005301c0(pvVar4,-0x18629,0x23,0);
    }
  }
  return;
}

