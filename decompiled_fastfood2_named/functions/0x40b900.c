// rea decompile_all
// name: FUN_0040b900
// address: 0x40b900
// body: available
// range: 0x40b900-0x40baae inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0040b900(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *this_00;
  int iVar5;
  int iVar6;
  int local_10;
  
  uVar1 = FUN_00488d90((int)this);
  if (*(int *)((int)this + 0x150c) != 0) {
    iVar5 = 0;
    if (0 < *(int *)((int)this + 0x50)) {
      do {
        iVar2 = IDMap_Lookup((void *)((int)this + 0x3c),iVar5,(int *)0x0);
        if (iVar2 != 0) {
          FUN_00508040(iVar2);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)((int)this + 0x50));
    }
    *(undefined4 *)((int)this + 0x150c) = 0;
  }
  iVar5 = FUN_00482720((int)this);
  local_10 = 0;
  if (0 < iVar5) {
    do {
      iVar3 = FUN_00488be0(this,local_10);
      iVar2 = *(int *)(iVar3 + 0x15c);
      iVar6 = 0;
      if (0 < iVar2) {
        do {
          iVar4 = IDMap_Lookup((void *)(iVar3 + 0x148),iVar6,(int *)0x0);
          if (iVar4 != 0) {
            FUN_00480740(iVar4);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar2);
      }
      local_10 = local_10 + 1;
    } while (local_10 < iVar5);
  }
  iVar5 = *(int *)((int)this + 0x50) + -1;
  if (-1 < iVar5) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((int)this + 0x3c),iVar5,(int *)0x0);
      if (((this_00 != (void *)0x0) && (*(int *)((int)this_00 + 200) != 0)) &&
         (*(int *)((int)this_00 + 0x38) != 0x2e)) {
        if (*(int *)((int)this_00 + 0x74) == 0) {
          if (param_1 == 0) {
            IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this_00 + 0x28),(int *)0x0);
            if (*(int *)((int)this_00 + 0xa0) == 0) {
              FUN_0040b400(this,this_00);
            }
            else {
              FUN_0040b110(this,this_00,uVar1);
            }
          }
        }
        else {
          FUN_00506d60(this_00,param_1);
          FUN_00406e90(this,this_00);
        }
      }
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  if (param_1 == 0) {
    if ((DAT_0057bb20 == '\0') &&
       (iVar5 = *(int *)(*(int *)((int)this + 0x224) + 0xac), *(int *)(iVar5 + 0xd0) == 0)) {
      FUN_005491c0(DAT_0057ba0c,*(int *)(iVar5 + 0xd4),'\x01',DAT_0057c5c0 == 0);
    }
    if ((*(int *)((int)this + 0x268) == 0) && (*(void **)((int)this + 0x264) != (void *)0x0)) {
      FUN_005301c0(*(void **)((int)this + 0x264),-0x18639,0x23,0);
    }
  }
  return;
}

