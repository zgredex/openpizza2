// rea decompile_all
// name: Game_ApplyAreaObjectEvent
// address: 0x50b460
// body: available
// range: 0x50b460-0x50b5da inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Game_ApplyAreaObjectEvent(void *this,int param_1)

{
  void *this_00;
  bool bVar1;
  void *this_01;
  void *this_02;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Depth-3 proposal batch 3. */
  piVar2 = *(int **)((int)this + 200);
  bVar1 = false;
  if (piVar2 != (int *)0x0) {
    iVar4 = *(int *)((int)this + 0x30);
    this_00 = *(void **)((int)this + 0xf4);
    FUN_00534370((void *)piVar2[0x16],*piVar2,&local_c,&local_4);
    local_1c = 0;
    if (0 < *(int *)((int)this_00 + 0x8c)) {
      do {
        this_01 = (void *)FUN_004d2a60(this_00,local_1c);
        if ((-1 < *(int *)((int)this_01 + 0x30)) && (*(int *)((int)this_01 + 0x30) < 8)) {
          piVar2 = *(int **)((int)this_01 + 200);
          if (piVar2 == (int *)0x0) {
            iVar3 = -1;
            this_02 = (void *)0x0;
          }
          else {
            iVar3 = *piVar2;
            this_02 = (void *)piVar2[0x16];
          }
          FUN_00534370(this_02,iVar3,&local_10,&local_8);
          if ((local_10 - local_c) * (local_10 - local_c) +
              (local_8 - local_4) * (local_8 - local_4) * 4 <
              (int)((-(uint)(iVar4 != 0x2d) & 0xffff3224) + 0xe100)) {
            if ((*(short *)((int)this_01 + 0x40) == 9) &&
               (piVar2 = (int *)FUN_0050ad00((int)this_01), piVar2 != (int *)0x0)) {
              FUN_004f5bb0(*(void **)((int)this + 0xc4),piVar2);
            }
            *(undefined1 *)((int)this_01 + 0x81) = 1;
            FUN_00507550(this_01,0x14);
            FUN_00504a90(this_01,7);
            FUN_005094a0(this_01,param_1,0);
            bVar1 = true;
            *(undefined4 *)((int)this + *(int *)(param_1 + 0x30) * 4 + 0xac) = 0;
          }
        }
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)((int)this_00 + 0x8c));
      if (bVar1) {
        if (*(int *)((int)this + 0x30) == 0x2d) {
          iVar4 = 0x26;
        }
        else {
          iVar4 = 0x27;
        }
        FUN_00548210(DAT_0057ba0c,param_1,iVar4);
      }
    }
  }
  return;
}

