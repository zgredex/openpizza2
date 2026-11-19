// rea decompile_all
// name: Stats_Report_FillCompanyOverview
// address: 0x4decf0
// body: available
// range: 0x4decf0-0x4defca inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Stats_Report_FillCompanyOverview(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *this_00;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int local_c;
  int local_4;
  
  piVar2 = param_1;
  iVar7 = 0;
  *(undefined4 *)*param_1 = 0;
  *(undefined4 *)(*param_1 + 4) = 0;
  *(undefined4 *)(*param_1 + 0x120) = 0;
  if (0 < *(int *)((int)this + 0x15c)) {
    do {
      iVar3 = IDMap_Lookup((void *)((int)this + 0x148),iVar7,(int *)0x0);
      piVar1 = (int *)*param_1;
      if (*(char *)(iVar3 + 0x16f4) == '\0') {
        piVar1[1] = piVar1[1] + 1;
        *(int *)(*param_1 + 0x120) = *(int *)(*param_1 + 0x120) + (*(int *)(iVar3 + 0x38) + 1) * 600
        ;
      }
      else {
        *piVar1 = *piVar1 + 1;
        *(int *)(*param_1 + 0x120) =
             *(int *)(*param_1 + 0x120) + (*(int *)(iVar3 + 0x38) + 1) * 0x5dc;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)((int)this + 0x15c));
  }
  iVar7 = 0;
  *(undefined4 *)(*param_1 + 8) = 0;
  *(undefined4 *)(*param_1 + 0xc) = 0;
  *(undefined4 *)(*param_1 + 0x124) = 0;
  if (0 < *(int *)((int)this + 0x194)) {
    do {
      iVar3 = IDMap_Lookup((void *)((int)this + 0x180),iVar7,(int *)0x0);
      if (*(char *)(iVar3 + 0x3c) == '\0') {
        *(int *)(*param_1 + 0xc) = *(int *)(*param_1 + 0xc) + 1;
        iVar5 = *param_1;
        iVar3 = Get_Field2C(iVar3);
        *(int *)(iVar5 + 0x124) = *(int *)(iVar5 + 0x124) + (iVar3 + 1) * 600;
      }
      else {
        *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + 1;
        iVar5 = *param_1;
        iVar3 = Get_Field2C(iVar3);
        *(int *)(iVar5 + 0x124) = *(int *)(iVar5 + 0x124) + (iVar3 + 1) * 0x5dc;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)((int)this + 0x194));
  }
  *(undefined4 *)(*param_1 + 0x10) = 0;
  pvVar4 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
  this_00 = City_CollectBuildingsByType(pvVar4,0x11,0,'\0');
  iVar7 = 0;
  if (0 < (int)this_00[5]) {
    do {
      iVar3 = IDMap_Lookup(this_00,iVar7,(int *)0x0);
      if (*(int *)(iVar3 + 8) == *(int *)((int)this + 0x48)) {
        *(int *)(*param_1 + 0x10) = *(int *)(*param_1 + 0x10) + 1;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)this_00[5]);
  }
  iVar7 = 0;
  param_1 = (int *)0x6;
  local_c = 0;
  do {
    pvVar4 = (void *)Game_GetPlayerBySlot(DAT_0057c670,local_c);
    if (pvVar4 != (void *)0x0) {
      iVar3 = *(int *)((int)pvVar4 + 0x48);
      iVar5 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      iVar7 = iVar7 + *(int *)(iVar5 + 0xcb0 + iVar3 * 4);
      if (pvVar4 == this) {
        iVar3 = *(int *)((int)pvVar4 + 0x48);
        iVar5 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                             (int *)0x0);
        local_4 = *(int *)(iVar5 + 0xcb0 + iVar3 * 4);
      }
      else {
        iVar3 = Game_GetPlayerFieldC20((int)pvVar4);
        iVar5 = Game_GetPlayerFieldC20((int)this);
        if (iVar5 < iVar3) {
          param_1 = (int *)((int)param_1 + -1);
        }
        iVar3 = Game_GetPlayerFieldC20((int)pvVar4);
        iVar5 = Game_GetPlayerFieldC20((int)this);
        if ((iVar3 == iVar5) && (*(int *)((int)pvVar4 + 0x60) < *(int *)((int)this + 0x60))) {
          param_1 = (int *)((int)param_1 + -1);
        }
      }
    }
    local_c = local_c + 1;
  } while (local_c < 6);
  *(int *)(*piVar2 + 0x14) = local_4;
  if (iVar7 < 1) {
    *(undefined4 *)(*piVar2 + 0x128) = 0;
  }
  else {
    *(int *)(*piVar2 + 0x128) = ((local_4 * 100) / iVar7) * 100;
  }
  uVar6 = Game_GetPlayerFieldC20((int)this);
  *(undefined4 *)(*piVar2 + 0x18) = uVar6;
  *(undefined4 *)(*piVar2 + 0x1c) = *(undefined4 *)((int)this + 0x60);
  iVar7 = Game_GetPlayerFieldC20((int)this);
  *(int *)(*piVar2 + 300) = ((int)param_1 + iVar7 * 2) * 1000;
  return;
}

