// rea decompile_all
// name: PersonnelOverview_Refresh
// address: 0x4951f0
// body: available
// range: 0x4951f0-0x4954d4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl PersonnelOverview_Refresh(void *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_EDI;
  
                    /* Refreshes the personnel overview from the selected building. */
  iVar5 = *(int *)(DAT_0057c670 + 0x21c);
  if ((iVar5 != 0) && ((char)param_2 != '\0')) {
    iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x20),*(int *)(iVar5 + 0x50),(int *)0x0);
    switch(*(undefined1 *)(iVar2 + 0x824)) {
    case 0:
      param_2 = 0x11;
      break;
    case 1:
      param_2 = 0x12;
      break;
    case 2:
      param_2 = 0x13;
      break;
    case 3:
      param_2 = 0x14;
      break;
    default:
    }
    FUN_005499f0(DAT_0057ba0c,param_2,6,*(int *)(iVar5 + 0x24) == 0);
    switch(*(undefined1 *)(iVar2 + 0x824)) {
    case 0:
      DAT_0057c6d8 = 0;
      break;
    case 1:
      DAT_0057c6d8 = 1;
      break;
    case 2:
      DAT_0057c6d8 = 2;
      break;
    case 3:
      DAT_0057c6d8 = 3;
    }
  }
  FUN_00532310(param_1,&LAB_00494970,0);
  FUN_00532520((int)param_1);
  UI_Group_Create(param_1,0,5,0x1fa4);
  if (*(int *)(DAT_0057c670 + 0x290) == 4) {
    FUN_00531740(param_1,0x1f77);
    FUN_00531740(param_1,0x1f78);
    iVar2 = 0x1f79;
  }
  else {
    iVar2 = *(int *)(DAT_0057c670 + 0x9c);
    if ((iVar2 == 0) ||
       (iVar1 = *(int *)(iVar2 + 0x30), iVar6 = FUN_00482820(DAT_0057c670), iVar1 != iVar6)) {
      uVar3 = FUN_004017f0((void *)(*(int *)(DAT_0057c670 + 0x200 +
                                            *(int *)(DAT_0057c670 + 0x2ec) * 4) + 0x148),0,
                           (int *)0x0);
      *(undefined4 *)(DAT_0057c670 + 0x9c) = uVar3;
      FUN_00547e70(DAT_0057ba0c);
      iVar2 = *(int *)(DAT_0057c670 + 0x9c);
    }
    FUN_0052f080(param_1,0x1f78,(byte *)(iVar2 + 4),unaff_EDI);
    FUN_00531740(param_1,0x1f45);
    iVar2 = 0x1f76;
  }
  FUN_00531740(param_1,iVar2);
  iVar2 = FUN_004e2280(*(int *)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4));
  if ((iVar2 < 2) && (FUN_00531740(param_1,0x1f76), DAT_0057c6d8 == 4)) {
    DAT_0057c6d8 = 0;
  }
  FUN_00495500();
  if (iVar5 == 0) {
    iVar5 = DAT_0057c6d8;
  }
  else {
    iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x20),*(int *)(iVar5 + 0x50),(int *)0x0);
    DAT_0057c6dc = 0;
    param_2 = 0;
    iVar5 = DAT_0057c6d8;
    do {
      iVar6 = 0;
      iVar1 = *(int *)((&DAT_0057c6e0)[iVar5] + 0x14);
      if (0 < iVar1) {
        do {
          piVar4 = (int *)FUN_004017f0((void *)(&DAT_0057c6e0)[iVar5],iVar6,(int *)0x0);
          if (*piVar4 == iVar2) {
            param_2 = 5;
            DAT_0057c6d8 = iVar5;
            DAT_0057c6dc = iVar6;
            goto LAB_00495465;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar1);
        iVar5 = DAT_0057c6d8;
      }
LAB_00495465:
      param_2 = param_2 + 1;
    } while (param_2 < 4);
  }
  if (*(int *)((&DAT_0057c6e0)[iVar5] + 0x14) == 0) {
    iVar2 = 0;
    piVar4 = &DAT_0057c6e0;
    do {
      if (0 < *(int *)(*piVar4 + 0x14)) {
        DAT_0057c6dc = 0;
        iVar5 = iVar2;
        DAT_0057c6d8 = iVar2;
        break;
      }
      piVar4 = piVar4 + 1;
      iVar2 = iVar2 + 1;
    } while ((int)piVar4 < 0x57c6f0);
  }
  FUN_0052ff50(param_1,iVar5 + 0x1fa4,1);
  PersonnelPage_UpdateEmployee(param_1);
  return;
}

