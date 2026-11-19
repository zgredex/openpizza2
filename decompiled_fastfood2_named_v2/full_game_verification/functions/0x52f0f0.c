// rea decompile_all
// name: Dialog_Destructor
// address: 0x52f0f0
// body: available
// range: 0x52f0f0-0x52f2d1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Dialog_Destructor(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0055aa6c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_Dialog_Delete_0055c808;
  local_4 = 1;
  if ((code *)param_1[0xa3] != (code *)0x0) {
    (*(code *)param_1[0xa3])(param_1[0xa4]);
  }
  UI_FreeObjectPairs((int)param_1);
  UI_Group_ClearAll((int)param_1);
  iVar3 = 0;
  if (0 < (int)param_1[0x3c]) {
    do {
      puVar2 = *(undefined4 **)(param_1[0x3a] + iVar3 * 8);
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[0x3c]);
  }
  if ((LPVOID)param_1[0x3a] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x3a]);
  }
  if ((LPVOID)param_1[0x3b] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x3b]);
  }
  if (param_1[0x58] != 0) {
    iVar3 = 0;
    if (0 < (int)param_1[0x5d]) {
      iVar4 = 0;
      do {
        iVar1 = param_1[0x58] + iVar4;
        if (*(char *)(iVar1 + 0x108) == '\0') {
          if (*(undefined4 **)(iVar1 + 0x148) != (undefined4 *)0x0) {
            (**(code **)**(undefined4 **)(iVar1 + 0x148))(1);
          }
        }
        else {
          UI_DecrementRowCounter((void *)param_1[0x4d],(byte *)(iVar1 + 0x108));
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x14c;
      } while (iVar3 < (int)param_1[0x5d]);
    }
    Mem_Free((LPVOID)param_1[0x58]);
  }
  if ((LPVOID)param_1[0x57] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x57]);
  }
  puVar2 = (undefined4 *)param_1[0x25];
  if (puVar2 != (undefined4 *)0x0) {
    if (*(char *)(param_1 + 0x15) == '\0') {
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)*puVar2)(1);
      }
    }
    else {
      UI_DecrementRowCounter((void *)param_1[0x4d],(byte *)(param_1 + 0x15));
    }
  }
  if ((undefined4 *)param_1[0x4e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x4e])(1);
  }
  if ((undefined4 *)param_1[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x14])(1);
  }
  if ((undefined4 *)param_1[0x37] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x37])(1);
  }
  if ((LPVOID)param_1[0x3e] != (LPVOID)0x0) {
    Mem_Free((LPVOID)param_1[0x3e]);
  }
  if (param_1[0x36] != 0) {
    UI_DecrementRowCounter((void *)param_1[0x4d],(byte *)(param_1 + 0x26));
  }
  local_4 = local_4 & 0xffffff00;
  Array_Destroy(param_1 + 0xaa);
  local_4 = 0xffffffff;
  Array_Destroy(param_1 + 0x52);
  ExceptionList = pvStack_c;
  return;
}

