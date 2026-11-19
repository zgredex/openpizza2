// rea decompile_all
// name: Game_GetBestObject
// address: 0x47f2e0
// body: available
// range: 0x47f2e0-0x47f3fa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Game_GetBestObject(void *this,int param_1,int param_2,float *param_3)

{
  bool bVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  float10 fVar4;
  float local_8;
  
                    /* Finds the best object under a threshold. */
  iVar3 = 0;
  local_8 = 0.0;
  bVar1 = false;
  if (0 < *(int *)((int)this + 0x170c)) {
    do {
      iVar2 = FUN_004017f0((void *)((int)this + 0x16f8),iVar3,(int *)0x0);
      if (*(int *)(iVar2 + 0xc) < param_2) {
        fVar4 = FUN_0047f230((int)this,iVar2,(float *)0x0);
        local_8 = (float)(fVar4 + (float10)local_8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)((int)this + 0x170c));
  }
  *param_3 = local_8;
  if (param_1 == 0) {
    if (local_8 <= 0.0) {
      return 0;
    }
  }
  else {
    FUN_00477e40(this,5,local_8,'\0',-1);
    iVar3 = 0;
    if (0 < *(int *)((int)this + 0x170c)) {
      do {
        this_00 = (void *)FUN_004017f0((void *)((int)this + 0x16f8),iVar3,(int *)0x0);
        if (*(int *)((int)this_00 + 0xc) < param_2) {
          if (*(int *)((int)this_00 + 0xc) == 0) {
            FUN_004e6020(this_00,*(void **)((int)this + 0x14e0));
            bVar1 = true;
          }
          else {
            FUN_004e6300(this_00,100);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)this + 0x170c));
      if (bVar1) {
        FUN_004ffeb0(*(void **)(DAT_0057c670 + 0x90),*(int *)((int)this + 0x30),5);
      }
    }
  }
  return 1;
}

