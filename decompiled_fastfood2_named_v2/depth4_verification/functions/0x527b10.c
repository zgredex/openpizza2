// rea decompile_all
// name: UI_UpdateScene
// address: 0x527b10
// body: available
// range: 0x527b10-0x527c5d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall UI_UpdateScene(void *param_1)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Updates the active UI scene. */
  iVar6 = 0;
  iVar7 = *(int *)((int)param_1 + 0x8334);
  local_4 = iVar7;
  if (*(int *)((int)param_1 + 0x83a8) != 0) {
    FUN_0053d090(*(void **)((int)param_1 + 0x839c),&local_8,&local_c);
    iVar1 = *(int *)((int)param_1 + 0x83a0);
    if (iVar1 != -9999) {
      FUN_00526d30(param_1,iVar1,*(int *)((int)param_1 + 0x83a4),local_8 + iVar1,
                   local_c + *(int *)((int)param_1 + 0x83a4));
    }
    iVar1 = *(int *)((int)param_1 + 0x24c);
    iVar2 = *(int *)((int)param_1 + 0x248);
    *(int *)((int)param_1 + 0x83a4) = iVar1;
    *(int *)((int)param_1 + 0x83a0) = iVar2;
    FUN_00526d30(param_1,iVar2,iVar1,local_8 + iVar2,local_c + iVar1);
  }
  DVar3 = timeGetTime();
  if (DAT_00573ddc == 0) {
    uVar5 = DVar3 - DAT_005841f4;
    if (10000 < uVar5) {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
    DAT_00573ddc = 0;
  }
  DAT_005841f4 = DVar3;
  if (0 < iVar7) {
    do {
      piVar4 = (int *)FUN_005230b0((void *)((int)param_1 + 0x8324),iVar6);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x18))(uVar5);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < local_4);
  }
  if (*(int **)((int)param_1 + 0x833c) != (int *)0x0) {
    iVar7 = *(int *)((int)param_1 + 0x8348) - uVar5;
    *(int *)((int)param_1 + 0x8348) = iVar7;
    if (iVar7 < 1) {
      *(int *)((int)param_1 + 0x8348) = *(int *)((int)param_1 + 0x8344) + iVar7;
      (**(code **)(**(int **)((int)param_1 + 0x833c) + 0xc))(0x3c,0,0);
    }
  }
  iVar7 = 0;
  if (0 < *(int *)((int)param_1 + 0x23c)) {
    puVar8 = (undefined4 *)((int)param_1 + 0x14);
    do {
      if ((void *)*puVar8 != (void *)0x0) {
        FUN_005328e0((void *)*puVar8,uVar5);
      }
      iVar7 = iVar7 + 1;
      puVar8 = puVar8 + 1;
    } while (iVar7 < *(int *)((int)param_1 + 0x23c));
  }
  return;
}

