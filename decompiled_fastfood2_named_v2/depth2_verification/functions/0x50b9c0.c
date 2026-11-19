// rea decompile_all
// name: FUN_0050b9c0
// address: 0x50b9c0
// body: available
// range: 0x50b9c0-0x50bb90 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0050b9c0(void *this,void *param_1)

{
  void *this_00;
  int *piVar1;
  int *this_01;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  if (*(int *)((int)this + 200) != 0) {
    local_14 = *(int *)((int)this + 0x10c);
    this_00 = *(void **)((int)param_1 + 0x16f0);
    local_18 = 0;
    if (0 < *(int *)((int)this_00 + 0x8c)) {
      do {
        iVar4 = local_18;
        this_01 = (int *)FUN_004d2a60(this_00,local_18);
        if (this_01[0x59] == local_14) {
          FUN_00534370((void *)(*(int **)((int)this + 200))[0x16],**(int **)((int)this + 200),
                       &local_24,&local_28);
          local_24 = local_24 + *(int *)(*(int *)((int)this + 0xc4) + 0xf8);
          local_28 = local_28 + *(int *)(*(int *)((int)this + 0xc4) + 0xfc);
          piVar1 = (int *)this_01[0x32];
          if (piVar1 == (int *)0x0) {
            iVar4 = -1;
            pvVar2 = (void *)0x0;
          }
          else {
            iVar4 = *piVar1;
            pvVar2 = (void *)piVar1[0x16];
          }
          FUN_00534370(pvVar2,iVar4,&local_20,&local_1c);
          pvVar2 = *(void **)((int)this + 0xc4);
          local_20 = local_20 + *(int *)((int)pvVar2 + 0xf8);
          local_1c = local_1c + *(int *)((int)pvVar2 + 0xfc);
          Map_ScreenToGridCell(pvVar2,local_20,local_1c,&local_8,&local_10,(int *)0x1);
          Map_ScreenToGridCell
                    (*(void **)((int)this + 0xc4),local_24,local_28,&local_4,&local_c,(int *)0x1);
          uVar5 = local_10 - local_c >> 0x1f;
          if ((int)((local_10 - local_c ^ uVar5) - uVar5) < 5) {
            iVar4 = *(int *)((int)this + 0x110);
            iVar3 = FUN_00482820(DAT_0057c670);
            if (iVar4 == iVar3) {
              FUN_00502f10(*(void **)(*(int *)(DAT_0057c670 + 0x224) + 0xa8),10,this_01[0x59],-1);
            }
            FUN_0050e890(this_01,0x25);
            this_01[0x42] = 1;
            FUN_004ffef0(*(void **)(DAT_0057c670 + 0x90),param_1,this_01);
            this_01[0x43] = *(int *)((int)this + 0x164);
            return 1;
          }
          iVar4 = local_18;
        }
        local_18 = iVar4 + 1;
      } while (local_18 < *(int *)((int)this_00 + 0x8c));
    }
  }
  return 0;
}

