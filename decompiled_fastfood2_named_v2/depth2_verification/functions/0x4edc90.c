// rea decompile_all
// name: FUN_004edc90
// address: 0x4edc90
// body: available
// range: 0x4edc90-0x4ede82 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004edc90(void *this,int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  uint local_18;
  int *local_14;
  int *local_10;
  LPCRITICAL_SECTION local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 0xc0);
  local_c = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  FUN_004f0850(this,param_1,(int *)&local_14,(int *)&local_10,&local_4,&local_8);
  iVar3 = *(int *)((int)this + 0xb4);
  if (iVar3 != 0) {
    iVar1 = *(int *)((int)this + 0xb0);
    if (*(int *)((int)this + 0xac) == 0xffff) {
      FUN_0053de60(*(int *)((int)this + 8),*(int *)(iVar3 + 0xc) - *(int *)((int)this + 0x24),
                   *(int *)(iVar3 + 0x10) - *(int *)((int)this + 0x28),*(int *)(iVar1 + 0xc),
                   *(int *)(iVar1 + 0x10),0xffff,'\x01');
    }
    else {
      FUN_0053e1e0(*(int *)((int)this + 8),*(int *)(iVar3 + 0xc) - *(int *)((int)this + 0x24),
                   *(int *)(iVar3 + 0x10) - *(int *)((int)this + 0x28),*(int *)(iVar1 + 0xc),
                   *(int *)(iVar1 + 0x10),0xa000,0xff,'\x01');
    }
  }
  local_18 = 0;
  if (0 < *local_10) {
    iVar3 = 0;
    do {
      Map_DrawRecordLinkSprites(this,param_1,*local_14 + iVar3);
      uVar4 = 0xffffff;
      if ((*(int *)((int)this + 0xc) == 0x40) &&
         ((((*(int *)(DAT_0057c670 + 0x21c) != 0 &&
            (iVar1 = *(int *)(*(int *)(DAT_0057c670 + 0x21c) + 200), iVar1 != 0)) &&
           (iVar1 = *(int *)(iVar1 + 0x20), iVar1 != 0)) ||
          ((*(int *)(DAT_0057c670 + 0x218) != 0 &&
           (iVar1 = FUN_004f0cc0(this,1,*(int *)(*(int *)(DAT_0057c670 + 0x218) + 0x54)), iVar1 != 0
           )))))) {
        if (local_18 == *(ushort *)(iVar1 + 4)) {
          uVar4 = 0xff00;
        }
        else {
          psVar2 = (short *)(iVar1 + 0x14);
          iVar1 = 8;
          do {
            if ((int)*psVar2 == local_18) {
              uVar4 = 0xff;
            }
            psVar2 = psVar2 + 1;
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
      }
      if (*(int *)((int)this + 0xc) == 0x10) {
        iVar1 = *(int *)(*(int *)(*(int *)((int)this + 0x4c) + 8 +
                                 *(int *)(*local_14 + 8 + iVar3) * 0xc) + 0x10);
        if (iVar1 == -2) {
          uVar4 = 0xff;
        }
        else {
          uVar4 = (-(uint)(iVar1 != -1) & 0xffffa001) + 0xffff;
        }
        if (*(char *)(*local_14 + iVar3) != '\0') {
          uVar4 = 0xff0000;
        }
      }
      Map_DrawTileCursorDiamond
                (this,*(int *)(*local_14 + iVar3 + 0xc) - *(int *)((int)this + 0x24),
                 *(int *)(*local_14 + 0x10 + iVar3) - *(int *)((int)this + 0x28),0,1,0,uVar4);
      local_18 = local_18 + 1;
      iVar3 = iVar3 + 0x28;
    } while ((int)local_18 < *local_10);
    lpCriticalSection = local_c;
  }
  LeaveCriticalSection(lpCriticalSection);
  return;
}

