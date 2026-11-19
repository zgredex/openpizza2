// rea decompile_all
// name: SoundSystem_Destroy
// address: 0x544ba0
// body: available
// range: 0x544ba0-0x544d89 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall SoundSystem_Destroy(undefined4 *param_1)

{
  int iVar1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  int *piVar4;
  undefined4 *puVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
                    /* Destroys the DirectSound system, mixer thread, buffers, and base child. */
  puStack_8 = &LAB_0055b51d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  param_1[-1] = &PTR_LAB_0055c8f8;
  *param_1 = &PTR_LAB_0055c9f8;
  param_1[4] = &PTR_LAB_0055c8f4;
  param_1[6] = &PTR_LAB_0055c9f4;
  puVar5 = (undefined4 *)param_1[0x14];
  local_4 = 6;
  param_1[0x16] = puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    param_1[0x16] = puVar5[1];
    while( true ) {
      (**(code **)(*(int *)*puVar5 + 4))((int *)*puVar5);
      puVar5 = (undefined4 *)param_1[0x16];
      if (puVar5 == (undefined4 *)0x0) break;
      param_1[0x16] = puVar5[1];
    }
  }
  piVar4 = (int *)param_1[0x18];
  param_1[0x1a] = piVar4;
  if (piVar4 != (int *)0x0) {
    param_1[0x1a] = piVar4[1];
    while( true ) {
      iVar1 = *piVar4;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      *(undefined4 *)(iVar1 + 0x24) = 0;
      (**(code **)(*(int *)*piVar4 + 4))((int *)*piVar4);
      piVar4 = (int *)param_1[0x1a];
      if (piVar4 == (int *)0x0) break;
      param_1[0x1a] = piVar4[1];
    }
  }
  puVar5 = (undefined4 *)param_1[0x1c];
  param_1[0x1e] = puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    param_1[0x1e] = puVar5[1];
    while( true ) {
      (**(code **)(*(int *)*puVar5 + 4))((int *)*puVar5);
      puVar5 = (undefined4 *)param_1[0x1e];
      if (puVar5 == (undefined4 *)0x0) break;
      param_1[0x1e] = puVar5[1];
    }
  }
  piVar4 = (int *)param_1[0x26];
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 4))(piVar4);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x27));
  local_4._0_1_ = 4;
  puVar5 = (undefined4 *)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)(param_1 + 0x1c));
  pvVar3 = (LPVOID)*puVar5;
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((int)pvVar3 + 4);
    FUN_0054dd78(pvVar3);
    pvVar3 = pvVar2;
  }
  *puVar5 = 0;
  puVar5[2] = 0;
  puVar5[3] = 0;
  local_4._0_1_ = 3;
  puVar5 = (undefined4 *)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)(param_1 + 0x18));
  pvVar3 = (LPVOID)*puVar5;
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((int)pvVar3 + 4);
    FUN_0054dd78(pvVar3);
    pvVar3 = pvVar2;
  }
  *puVar5 = 0;
  puVar5[2] = 0;
  puVar5[3] = 0;
  local_4._0_1_ = 2;
  puVar5 = (undefined4 *)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)(param_1 + 0x14));
  pvVar3 = (LPVOID)*puVar5;
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((int)pvVar3 + 4);
    FUN_0054dd78(pvVar3);
    pvVar3 = pvVar2;
  }
  *puVar5 = 0;
  puVar5[2] = 0;
  puVar5[3] = 0;
  local_4._0_1_ = 1;
  FUN_005427e0((undefined4 *)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)(param_1 + 6)));
  local_4 = (uint)local_4._1_3_ << 8;
  puVar5 = (undefined4 *)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)(param_1 + 4));
  *puVar5 = &PTR_FUN_0055c860;
  piVar4 = (int *)puVar5[1];
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  local_4 = 0xffffffff;
  FUN_0053f020((undefined4 *)(-(uint)(param_1 != (undefined4 *)0x4) & (uint)param_1));
  ExceptionList = pvStack_c;
  return;
}

