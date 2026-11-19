// rea decompile_all
// name: FUN_0048b600
// address: 0x48b600
// body: available
// range: 0x48b600-0x48b898 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0048b600(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  void *pvVar5;
  void *this_00;
  int iVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  int local_50;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar4 = FUN_004017f0((void *)((int)param_1 + 4),*(int *)((int)param_1 + 0x2f4),(int *)0x0);
  this = *(void **)(iVar4 + 0xfa8);
  pvVar5 = (void *)FUN_00528040(DAT_0057c5e0,*(int *)((int)param_1 + 0x2dac),(int *)0x0);
  if (((pvVar5 != (void *)0x0) && (this != (void *)0x0)) &&
     (pvVar5 = (void *)FUN_00531cf0(pvVar5,99999), pvVar5 != (void *)0x0)) {
    iVar4 = FUN_004017f0((void *)((int)param_1 + 4),*(int *)((int)param_1 + 0x2f4),(int *)0x0);
    if (iVar4 == 0) {
      FUN_00521380((int)pvVar5);
      return;
    }
    this_00 = (void *)FUN_00521b10((int)pvVar5);
    if ((*(int *)((int)param_1 + 0x2e18) == 0) && (*(void **)(iVar4 + 0x10a8) != (void *)0x0)) {
      FUN_0053d570(*(void **)(iVar4 + 0x10a8),(int)this_00,(uint *)0x0,0);
    }
    else {
      SetRect(&local_28,0,0,0x80,0x80);
      Surface_FillClippedRect(this_00,&local_28.left,0,1);
    }
    FUN_004f5c20(this,&local_18);
    local_28._0_8_ = 128.0 / (double)(local_10 - local_18);
    iVar1 = *(int *)(iVar4 + 0xfc0);
    local_50 = 0;
    if (0 < iVar1) {
      do {
        iVar6 = FUN_004017f0((void *)(iVar4 + 0xfac),local_50,(int *)0x0);
        if (((iVar6 != 0) && (iVar2 = *(int *)(iVar6 + 8), iVar2 != -1)) &&
           ((*(int *)(iVar6 + 0x74) != 0 &&
            (iVar7 = FUN_004e4490(*(int *)(iVar6 + 0x74)), 0 < iVar7)))) {
          FUN_004d2320(iVar6);
          lVar8 = __ftol();
          FUN_004d2360(iVar6);
          lVar9 = __ftol();
          iVar6 = FUN_00488be0(param_1,iVar2);
          if (iVar6 != 0) {
            uVar3 = FUN_00539840(this_00,*(uint *)(iVar6 + 0x1dc));
            lVar10 = __ftol();
            FUN_0053e5a0((int)this_00,(int)lVar8,(uint)lVar9,(int)lVar10,uVar3);
          }
        }
        local_50 = local_50 + 1;
      } while (local_50 < iVar1);
    }
    FUN_00521a50(pvVar5,(uint *)(((*(int *)((int)this + 0xe8) - local_18) * 0x80) /
                                (local_10 - local_18)),
                 ((*(int *)((int)this + 0xec) - local_14) * 0x80) / (local_c - local_14),
                 (uint *)((((DAT_00571950 - local_18) + *(int *)((int)this + 0xe8)) * 0x80) /
                         (local_10 - local_18)),
                 (((DAT_00571954 - local_14) + *(int *)((int)this + 0xec)) * 0x80) /
                 (local_c - local_14),0xffffff);
    FUN_00521b30((int)pvVar5);
  }
  return;
}

