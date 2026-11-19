// rea decompile_all
// name: FUN_004fca30
// address: 0x4fca30
// body: available
// range: 0x4fca30-0x4fcbfe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004fca30(void *this,void *param_1)

{
  DWORD DVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  
  iVar8 = *(int *)((int)param_1 + 0x48);
  iVar2 = *(int *)((int)param_1 + 0x4c);
  *(undefined4 *)((int)this + iVar2 * 0x168 + 0x198) = 1;
  DVar1 = GetCurrentThreadId();
  if (DVar1 == *(DWORD *)((int)this + 0x10)) {
    puVar3 = (undefined4 *)((int)this + iVar2 * 0x168 + 0x74);
    iVar6 = 10;
    do {
      puVar3[3] = 0;
      *puVar3 = 0xffffffff;
      puVar3 = puVar3 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    bVar7 = *(int *)((int)this + iVar2 * 0x168 + 300) != 0x18;
    *(undefined4 *)((int)this + iVar2 * 0x168 + 300) = 0x18;
  }
  else {
    iVar6 = *(int *)((int)this + 0xc);
    if (iVar6 == 0) {
      Thread_IsOwner((int)this);
    }
    puVar3 = (undefined4 *)((int)this + iVar2 * 0x168 + 0x74);
    iVar5 = 10;
    do {
      puVar3[3] = 0;
      *puVar3 = 0xffffffff;
      puVar3 = puVar3 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    bVar7 = *(int *)((int)this + iVar2 * 0x168 + 300) != 0x18;
    *(undefined4 *)((int)this + iVar2 * 0x168 + 300) = 0x18;
    if (iVar6 == 0) {
      Thread_Init((int)this);
    }
  }
  if (bVar7) {
    iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    if (iVar8 == iVar2) {
      iVar2 = 5;
      iVar8 = 0x2b;
    }
    else {
      iVar2 = 3;
      iVar8 = 0x31;
    }
    FUN_0048bf90((int)DAT_0057c670,iVar8,iVar2,-1,-1,0,DAT_00582dcc,DAT_00581fcc,(int)param_1 + 8);
  }
  iVar8 = *(int *)((int)param_1 + 0x194) + -1;
  if (-1 < iVar8) {
    do {
      puVar3 = (undefined4 *)IDMap_Lookup((void *)((int)param_1 + 0x180),iVar8,(int *)0x0);
      if (puVar3 != (undefined4 *)0x0) {
        FUN_004871a0(DAT_0057c670,puVar3);
      }
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
  }
  iVar8 = *(int *)((int)param_1 + 0x15c) + -1;
  if (-1 < iVar8) {
    do {
      pvVar4 = (void *)IDMap_Lookup((void *)((int)param_1 + 0x148),iVar8,(int *)0x0);
      if (pvVar4 != (void *)0x0) {
        FUN_004fc990(this,pvVar4,1);
      }
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
  }
  FUN_004e3900(param_1,0);
  *(undefined4 *)((int)param_1 + 0x108) = 0;
  *(undefined4 *)((int)param_1 + 0x10c) = 0;
  if (param_1 != *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200)) {
    pvVar4 = *(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
    Array_SearchSet(pvVar4,0x13);
    Array_SearchSet(pvVar4,0x19);
  }
  return;
}

