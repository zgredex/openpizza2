// rea decompile_all
// name: Sprite_TestCollision
// address: 0x53d720
// body: available
// range: 0x53d720-0x53d83b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Sprite_TestCollision(void *this,int param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
                    /* Scans a compressed 8bpp sprite stream against the collision buffer. */
  if (*(char *)((int)this + 0x39) == '\0') {
    Sprite_RealizeLazy(this);
  }
  bVar1 = *(byte *)((int)this + 4);
  if ((bVar1 & 4) == 0) {
    iVar5 = param_2;
  }
  else {
    param_1 = param_1 - *(short *)((int)this + 10);
    iVar5 = param_2 - *(short *)((int)this + 0xc);
  }
  if ((*(char *)((int)this + 5) == '\b') && ((bVar1 & 0x10) != 0)) {
    iVar6 = iVar5 * 800 + param_1 + param_3;
    pcVar3 = *(char **)((int)this + 0x30);
    if (pcVar3 == (char *)0x0) {
      param_2 = (int)*(short *)((int)this + 8);
      iVar4 = (int)*(short *)((int)this + 6);
      pcVar3 = *(char **)((int)this + 0x2c);
    }
    else if (*(char *)((int)this + 0x37) == '\0') {
      param_2 = (int)*(short *)((int)this + 8);
      iVar4 = (int)*(short *)((int)this + 6);
    }
    else {
      param_2 = (int)*(short *)((int)this + 6);
      iVar4 = (int)*(short *)((int)this + 8);
    }
    if ((((-1 < param_1) && (-1 < iVar5)) && (iVar4 + param_1 < 0x321)) && (iVar5 + param_2 < 0x259)
       ) {
      iVar5 = 0;
      if (0 < param_2) {
        do {
          iVar2 = 0;
          if (0 < iVar4) {
            do {
              if (*pcVar3 == '\0') {
                if ((bVar1 & 1) == 0) {
                  iVar2 = iVar2 + 1;
                }
                else {
                  iVar2 = iVar2 + (uint)(byte)pcVar3[1];
                }
              }
              else {
                if (*(char *)(iVar2 + iVar6) == '\0') {
                  return 0;
                }
                if (*(char *)(iVar2 + iVar6) == -1) {
                  return 0;
                }
                iVar2 = iVar2 + 1;
              }
              pcVar3 = pcVar3 + 2;
            } while (iVar2 < iVar4);
          }
          iVar6 = iVar6 + 800;
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_2);
      }
      return 1;
    }
  }
  return 0;
}

