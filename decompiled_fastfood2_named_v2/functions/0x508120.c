// rea decompile_all
// name: FUN_00508120
// address: 0x508120
// body: available
// range: 0x508120-0x5082fa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00508120(void *param_1)

{
  bool bVar1;
  void *pvVar2;
  undefined4 *this;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int local_c;
  int local_8;
  void *local_4;
  
  pvVar2 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_1 + 0x28),
                                (int *)0x0);
  local_4 = pvVar2;
  FUN_00505ef0(param_1,(uint)(*(int *)((int)param_1 + 0x74) != 0),&local_8,&local_c);
  this = FUN_004d7ed0(pvVar2,*(int *)((int)param_1 + 0x34),local_8,local_c);
  iVar7 = 0;
  iVar5 = this[5];
  if (0 < iVar5) {
    do {
      iVar3 = IDMap_Lookup(this,iVar7,(int *)0x0);
      iVar4 = FUN_00401930((void *)((int)param_1 + 0x130),iVar3);
      if (iVar4 == -1) {
        List_Add((void *)((int)param_1 + 0x130),iVar3);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar5);
  }
  if (iVar5 == 0) {
    if (this != (undefined4 *)0x0) {
      (**(code **)*this)(1);
    }
  }
  else if (iVar5 == 1) {
    if (((((*(int *)((int)param_1 + 0x54) == 0) &&
          (iVar5 = IDMap_Lookup(this,0,(int *)0x0), *(int *)(iVar5 + 4) == 0xf)) &&
         (iVar7 = FUN_00488be0(DAT_0057c670,*(int *)(iVar5 + 8)), iVar7 != 0)) &&
        ((pvVar2 = (void *)IDMap_Lookup((void *)(iVar7 + 0x148),*(int *)(iVar5 + 0x2c),(int *)0x0),
         pvVar2 != (void *)0x0 && (bVar1 = FUN_005080f0(param_1,pvVar2), bVar1)))) &&
       ((*(int *)((int)param_1 + 0x58) == -1 ||
        (*(int *)((int)param_1 + 0x58) == *(int *)(iVar5 + 8))))) {
      *(undefined4 *)((int)param_1 + 0x54) = 1;
      *(int *)((int)param_1 + 0xf4) = iVar5;
      FUN_00507e20(param_1,1,iVar5);
    }
    if (this != (undefined4 *)0x0) {
      (**(code **)*this)(1);
      return;
    }
  }
  else {
    pvVar2 = FUN_004d82b0((int)param_1,this);
    iVar5 = FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar2 + 8));
    pvVar6 = (void *)IDMap_Lookup((void *)(iVar5 + 0x148),*(int *)((int)pvVar2 + 0x2c),(int *)0x0);
    bVar1 = FUN_005080f0(param_1,pvVar6);
    if (((bVar1) &&
        ((*(int *)((int)param_1 + 0x54) == 0 ||
         ((*(void **)((int)param_1 + 0xf4) != pvVar2 &&
          ((*(int *)((int)param_1 + 0x54) == 0 ||
           (*(int *)((int)*(void **)((int)param_1 + 0xf4) + 8) != *(int *)((int)pvVar2 + 8)))))))))
       && ((*(int *)((int)param_1 + 0x58) == -1 ||
           (*(int *)((int)param_1 + 0x58) == *(int *)((int)pvVar2 + 8))))) {
      *(undefined4 *)((int)param_1 + 0x54) = 1;
      *(void **)((int)param_1 + 0xf4) = pvVar2;
      FUN_00507e20(param_1,1,(int)pvVar2);
    }
    if (this != (undefined4 *)0x0) {
      (**(code **)*this)(1);
      return;
    }
  }
  return;
}

