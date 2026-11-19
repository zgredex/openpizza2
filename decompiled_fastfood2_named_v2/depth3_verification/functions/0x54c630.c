// rea decompile_all
// name: ResourceCache_FreeEntryMaps
// address: 0x54c630
// body: available
// range: 0x54c630-0x54c7c4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall ResourceCache_FreeEntryMaps(int param_1)

{
  LPVOID pvVar1;
  void *pvVar2;
  int iVar3;
  
                    /* Depth-3 proposal batch 4. */
  pvVar2 = *(void **)(param_1 + 4);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)FUN_004017f0(pvVar2,iVar3,(int *)0x0);
        FUN_0054c7e0(pvVar1);
        pvVar2 = *(void **)(param_1 + 4);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    FUN_00401440(*(int *)(param_1 + 4));
  }
  pvVar2 = *(void **)(param_1 + 0xc);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)FUN_004017f0(pvVar2,iVar3,(int *)0x0);
        FUN_0054dd78(pvVar1);
        pvVar2 = *(void **)(param_1 + 0xc);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    FUN_00401440(*(int *)(param_1 + 0xc));
  }
  pvVar2 = *(void **)(param_1 + 0x10);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)FUN_004017f0(pvVar2,iVar3,(int *)0x0);
        FUN_0054dd78(pvVar1);
        pvVar2 = *(void **)(param_1 + 0x10);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    FUN_00401440(*(int *)(param_1 + 0x10));
  }
  pvVar2 = *(void **)(param_1 + 0x14);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)FUN_004017f0(pvVar2,iVar3,(int *)0x0);
        if (*(LPVOID *)((int)pvVar1 + 0xc) != (LPVOID)0x0) {
          FUN_0054dd78(*(LPVOID *)((int)pvVar1 + 0xc));
        }
        if (*(LPVOID *)((int)pvVar1 + 0x10) != (LPVOID)0x0) {
          FUN_0054dd78(*(LPVOID *)((int)pvVar1 + 0x10));
        }
        FUN_0054dd78(pvVar1);
        pvVar2 = *(void **)(param_1 + 0x14);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    FUN_00401440(*(int *)(param_1 + 0x14));
  }
  pvVar2 = *(void **)(param_1 + 8);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)FUN_004017f0(pvVar2,iVar3,(int *)0x0);
        if (pvVar1 != (LPVOID)0x0) {
          FUN_0054c7d0((int)pvVar1);
          FUN_0054dd78(pvVar1);
        }
        pvVar2 = *(void **)(param_1 + 8);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    FUN_00401440(*(int *)(param_1 + 8));
  }
  pvVar2 = *(void **)(param_1 + 0x28);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)FUN_004017f0(pvVar2,iVar3,(int *)0x0);
        FUN_0054dd78(pvVar1);
        pvVar2 = *(void **)(param_1 + 0x28);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    FUN_00401440(*(int *)(param_1 + 0x28));
  }
  pvVar2 = *(void **)(param_1 + 0x2c);
  if (pvVar2 != (void *)0x0) {
    iVar3 = 0;
    if (0 < *(int *)((int)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)FUN_004017f0(pvVar2,iVar3,(int *)0x0);
        FUN_0054dd78(pvVar1);
        pvVar2 = *(void **)(param_1 + 0x2c);
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)pvVar2 + 0x14));
    }
    FUN_00401440(*(int *)(param_1 + 0x2c));
  }
  return;
}

