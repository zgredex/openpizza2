// rea decompile_all
// name: FUN_004d2420
// address: 0x4d2420
// body: available
// range: 0x4d2420-0x4d25f1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d2420(void *this,int param_1,int param_2)

{
  int *piVar1;
  void *this_00;
  int iVar2;
  void *pvVar3;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)this + 0x28),(int *)0x0);
  this_00 = *(void **)(iVar2 + 0xfa8);
  if (this_00 != (void *)0x0) {
    if ((*(int *)((int)this + 4) == 0xf) && (param_1 != 0xf)) {
      iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 8));
      if (iVar2 != 0) {
        pvVar3 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                      *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
        FUN_004dc420(pvVar3,0,(int)this,iVar2);
      }
    }
    Map_ClearObjectFlags(this,this_00,0xffffffff);
    *(int *)((int)this + 0x20) = param_2;
    *(int *)((int)this + 4) = param_1;
    piVar1 = (int *)(*(int *)((int)this_00 + 0x4c) + *(int *)((int)this + 0x24) * 0xc);
    if (piVar1 != (int *)0x0) {
      FUN_00401320(*(int *)((int)DAT_0057c670 + 0x240));
      FUN_004eeef0(piVar1[2] + 0x10);
      FUN_004f5990(this_00,piVar1,&local_10);
      local_10 = local_10 + *(int *)((int)this_00 + 0x24);
      local_8 = local_8 + *(int *)((int)this_00 + 0x24);
      local_c = local_c + *(int *)((int)this_00 + 0x28);
      local_4 = local_4 + *(int *)((int)this_00 + 0x28);
      *(int *)(piVar1[2] + 0x10) = param_2;
      FUN_004f43c0(this_00,&local_10);
      FUN_004eef40(this_00,param_2,piVar1[2] + 0x10);
      if (*(int *)((int)this + 4) == 0xf) {
        iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 8));
        if (iVar2 != 0) {
          pvVar3 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),
                                        *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
          FUN_004dc420(pvVar3,1,(int)this,iVar2);
        }
      }
      pvVar3 = FUN_004ed880(this_00,(uint)piVar1,&local_14,&local_18);
      FUN_004ed780(this_00,piVar1,pvVar3,&local_20,&local_1c);
      local_20 = local_20 + *(int *)((int)this_00 + 0x24);
      local_1c = local_1c + *(int *)((int)this_00 + 0x28);
      SetRect((LPRECT)((int)this + 0x10),local_20,local_1c,local_14 + local_20,local_18 + local_1c);
      FUN_00401340(*(int *)((int)DAT_0057c670 + 0x240));
    }
    FUN_004d2600((int)this);
  }
  return;
}

