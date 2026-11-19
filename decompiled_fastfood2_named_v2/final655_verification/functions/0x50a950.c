// rea decompile_all
// name: Person_OnArriveAtDestination
// address: 0x50a950
// body: available
// range: 0x50a950-0x50aae2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Person_OnArriveAtDestination(void *param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
                    /* Handles a person arriving at its movement destination. */
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 0xd:
    pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    iVar1 = *(int *)((int)param_1 + 0x58);
    iVar3 = *(int *)((int)pvVar2 + iVar1 * 0x18 + 0x10e0) + 1;
    *(int *)((int)pvVar2 + iVar1 * 0x18 + 0x10e0) = iVar3;
    if (*(int *)((int)pvVar2 + iVar1 * 0x18 + 0x10dc) + iVar3 ==
        *(int *)((int)pvVar2 + iVar1 * 0x18 + 0x10d8)) {
      FUN_004dc330(pvVar2,2,*(int *)((int)param_1 + 0x58));
    }
  case 0x22:
    FUN_0050e890(param_1,0x2e);
    *(undefined4 *)((int)DAT_0057c670 + 0x368) = 1;
    break;
  case 0x16:
  case 0x1e:
  case 0x1f:
    if ((*(int *)(*(int *)((int)param_1 + 0xcc) + 4) == 0x11) &&
       (*(int *)((int)param_1 + 0x108) == 6)) {
      iVar1 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      *(int *)(iVar1 + 0x10b0) = *(int *)(iVar1 + 0x10b0) + 1;
      FUN_005086e0((int)param_1);
      pvVar2 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
      if (pvVar2 != (void *)0x0) {
        Company_RemoveStaffMember(pvVar2,*(int *)((int)param_1 + 0x164));
        *(undefined4 *)((int)param_1 + 0x110) = 0xffffffff;
      }
      *(undefined4 *)((int)param_1 + 0x108) = 0xffffffff;
      FUN_00506330(param_1,-1);
      pvVar2 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                    *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
      pvVar2 = (void *)FUN_004d74c0(pvVar2,0x17,0,'\0');
      iVar1 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      iVar1 = FUN_004f0cc0(*(void **)(iVar1 + 0xfa8),1,*(int *)((int)pvVar2 + 0x54));
      FUN_00505e60(param_1,0,iVar1);
      FUN_0050e4c0(param_1,0);
      FUN_00506c00(param_1);
      FUN_005090e0((int)param_1);
      FUN_0050ab30(param_1,pvVar2);
      return;
    }
  }
  FUN_0050ab30(param_1,*(void **)((int)param_1 + 0xfc));
  return;
}

