// rea decompile_all
// name: FUN_004b4280
// address: 0x4b4280
// body: available
// range: 0x4b4280-0x4b43e2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004b4280(void *this,void *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_005589bb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (DAT_0057d6a0 != (LPVOID)0x0) {
    ExceptionList = &pvStack_c;
    Mem_Free(DAT_0057d6a0);
    DAT_0057d6a0 = (LPVOID)0x0;
  }
  if (DAT_0057d6a4 != (undefined4 *)0x0) {
    (**(code **)*DAT_0057d6a4)(1,this);
    DAT_0057d6a4 = (undefined4 *)0x0;
  }
  pvVar2 = operator_new(0x1c);
  uStack_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057d6a4 = (undefined4 *)0x0;
  }
  else {
    DAT_0057d6a4 = FUN_004013a0(pvVar2,0);
  }
  uStack_4 = 0xffffffff;
  pvVar2 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  iVar3 = FUN_004ddde0((int)pvVar2);
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      iVar4 = FUN_004dde30(pvVar2,iVar5);
      List_Add(DAT_0057d6a4,iVar4);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  if (DAT_0056a7d4 != -1) {
    iVar3 = IDMap_Lookup((void *)((int)pvVar2 + 0x148),DAT_0056a7d4,(int *)0x0);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x14dc) != 0)) {
      List_Add(DAT_0057d6a4,*(int *)(iVar3 + 0x14dc));
    }
  }
  puVar1 = (undefined4 *)DAT_0057d6a4[5];
  if (0 < (int)puVar1) {
    DAT_0057d6a0 = operator_new((int)puVar1 * 4);
  }
  FUN_004b43f0(puVar1);
  iVar3 = 0;
  do {
    if (iVar3 < (int)puVar1) {
      FUN_0052ff50(param_1,iVar3 + 0x1f41,
                   (uint)(*(int *)(&DAT_0056a760 + *(int *)((int)DAT_0057d6a0 + iVar3 * 4) * 4) == 1
                         ));
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  ExceptionList = pvStack_c;
  return;
}

