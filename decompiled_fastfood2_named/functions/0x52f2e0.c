// rea decompile_all
// name: FUN_0052f2e0
// address: 0x52f2e0
// body: available
// range: 0x52f2e0-0x52f5a4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0052f2e0(void *this,void *param_1)

{
  undefined4 *this_00;
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055aa8b;
  pvStack_c = ExceptionList;
  local_20 = 0;
  if ((*(int *)((int)this + 0xe0) != 0) ||
     (piVar5 = (int *)((int)this + 0x38), *(int *)((int)this + 0x13c) != 0)) {
    piVar5 = (int *)((int)this + 8);
  }
  if (*(code **)((int)this + 0x284) == (code *)0x0) {
    ExceptionList = &pvStack_c;
  }
  else {
    ExceptionList = &pvStack_c;
    local_20 = (**(code **)((int)this + 0x284))(param_1,piVar5,*(undefined4 *)((int)this + 0x288));
  }
  if ((*(int *)((int)this + 0x168) != 0) &&
     ((*(int *)((int)this + 0x164) != 0 || (*(int *)((int)this + 0x50) == 0)))) {
    *(undefined4 *)((int)this + 0x164) = 0;
    *(undefined4 *)((int)this + 0x16c) = 1;
    FUN_005301f0((int)this);
    *(undefined4 *)((int)this + 0x16c) = 0;
  }
  if ((local_20 & 2) == 0) {
    FUN_00539660(param_1,*piVar5,piVar5[1],piVar5[2],piVar5[3]);
    iStack_1c = *(int *)((int)this + 0xc);
    puVar3 = *(uint **)((int)this + 8);
    if (*(int *)((int)this + 0x13c) != 0) {
      puVar3 = (uint *)((int)puVar3 + *(int *)((int)this + 0x140));
      iStack_1c = iStack_1c + *(int *)((int)this + 0x144);
    }
    if (*(void **)((int)this + 0x50) == (void *)0x0) {
      if (*(void **)((int)this + 0x94) == (void *)0x0) {
        if (*(void **)((int)this + 0x138) != (void *)0x0) {
          FUN_005374e0(*(void **)((int)this + 0x138),(int)param_1,(int)puVar3,iStack_1c,-9999,-9999,
                       0,0);
        }
      }
      else {
        FUN_0053d100(*(void **)((int)this + 0x94),&iStack_14,&iStack_18);
        FUN_0053d570(*(void **)((int)this + 0x94),(int)param_1,(uint *)((int)puVar3 - iStack_14),
                     iStack_1c - iStack_18);
      }
    }
    else {
      FUN_0053d570(*(void **)((int)this + 0x50),(int)param_1,puVar3,iStack_1c);
    }
    if ((((*(int *)((int)this + 0x168) == 0) && (*(int *)((int)this + 0x50) == 0)) &&
        (*(int *)((int)this + 0x138) == 0)) && (*(int *)((int)this + 0x94) == 0)) {
      iVar6 = *(int *)((int)this + 0x10) - *(int *)((int)this + 8);
      iVar4 = *(int *)((int)this + 0x14) - *(int *)((int)this + 0xc);
      if ((0 < iVar6) && (0 < iVar4)) {
        pvStack_10 = operator_new(0x11c);
        uStack_4 = 0;
        if (pvStack_10 == (void *)0x0) {
          this_00 = (undefined4 *)0x0;
        }
        else {
          this_00 = Window_Construct(pvStack_10,iVar6,iVar4,2);
        }
        uStack_4 = 0xffffffff;
        *(undefined4 **)((int)this + 0x138) = this_00;
        FUN_00537390(this_00,(int)param_1,(int)puVar3,iStack_1c);
        *(undefined4 *)((int)this + 0x2c0) = 1;
      }
    }
  }
  if ((local_20 & 1) == 0) {
    if (*(int *)((int)this + 0xe0) == 0) {
      iVar4 = *(int *)((int)this + 0x44);
      if (*(int *)((int)this + 0x24) <= *(int *)((int)this + 0x44)) {
        iVar4 = *(int *)((int)this + 0x24);
      }
      iVar6 = *(int *)((int)this + 0x40);
      if (*(int *)((int)this + 0x20) <= *(int *)((int)this + 0x40)) {
        iVar6 = *(int *)((int)this + 0x20);
      }
      iVar2 = *(int *)((int)this + 0x3c);
      if (*(int *)((int)this + 0x3c) <= *(int *)((int)this + 0x1c)) {
        iVar2 = *(int *)((int)this + 0x1c);
      }
      iVar1 = *(int *)((int)this + 0x38);
      if (*(int *)((int)this + 0x38) <= *(int *)((int)this + 0x18)) {
        iVar1 = *(int *)((int)this + 0x18);
      }
    }
    else {
      iVar4 = *(int *)((int)this + 0x24);
      iVar6 = *(int *)((int)this + 0x20);
      iVar2 = *(int *)((int)this + 0x1c);
      iVar1 = *(int *)((int)this + 0x18);
    }
    FUN_00539660(param_1,iVar1,iVar2,iVar6,iVar4);
    iVar4 = 0;
    if (0 < *(int *)((int)this + 0xf0)) {
      do {
        piVar5 = *(int **)(*(int *)((int)this + 0xec) + iVar4 * 8);
        if ((piVar5 != (int *)0x0) && (piVar5[8] != 0)) {
          (**(code **)(*piVar5 + 4))
                    (param_1,*(undefined4 *)((int)this + 0x18),*(undefined4 *)((int)this + 0x1c));
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)((int)this + 0xf0));
    }
  }
  if (*(code **)((int)this + 0x27c) != (code *)0x0) {
    (**(code **)((int)this + 0x27c))(param_1,(int)this + 0x18,*(undefined4 *)((int)this + 0x280));
  }
  *(undefined4 *)((int)this + 0xe0) = 0;
  *(undefined4 *)((int)this + 0x38) = 0xfffffc19;
  ExceptionList = pvStack_c;
  return;
}

