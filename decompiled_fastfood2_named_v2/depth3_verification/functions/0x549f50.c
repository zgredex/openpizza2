// rea decompile_all
// name: Sound_PlayWeaponPageEvent
// address: 0x549f50
// body: available
// range: 0x549f50-0x54a225 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sound_PlayWeaponPageEvent(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
                    /* Depth-3 proposal batch 4. */
  if (*(char *)((int)this + 0xfc) != '\0') {
    bVar2 = param_2 == 0;
    switch(param_1) {
    case 0:
      FUN_005499f0(this,0,0,bVar2);
      return;
    case 1:
      FUN_005499f0(this,1,0,bVar2);
      return;
    case 2:
      FUN_005499f0(this,2,0,bVar2);
      return;
    case 3:
      FUN_005499f0(this,3,0,bVar2);
      return;
    case 4:
      FUN_005499f0(this,4,0,bVar2);
      return;
    case 6:
      FUN_005499f0(this,6,0,bVar2);
      return;
    case 7:
      FUN_005499f0(this,7,0,bVar2);
      return;
    case 8:
      iVar1 = 0x21;
      if (bVar2) goto LAB_0054a1ed;
    case 5:
      FUN_005499f0(this,5,0,bVar2);
      return;
    case 9:
      FUN_005499f0(this,0xb,0,bVar2);
      return;
    case 10:
      FUN_005499f0(this,0x14,0,bVar2);
      return;
    case 0xb:
      FUN_005499f0(this,0x13,0,bVar2);
      return;
    case 0xc:
      FUN_005499f0(this,0x11,0,bVar2);
      return;
    case 0xd:
      FUN_005499f0(this,0x12,0,bVar2);
      return;
    case 0xe:
      FUN_005499f0(this,0x13,6,bVar2);
      return;
    case 0xf:
      FUN_005499f0(this,0x17,0,'\x01');
      return;
    case 0x10:
      FUN_005499f0(this,0x16,0,bVar2);
      return;
    case 0x11:
      FUN_005499f0(this,0x1f,0,bVar2);
      return;
    case 0x12:
      FUN_005499f0(this,0x1e,0,'\x01');
      return;
    case 0x13:
      FUN_005499f0(this,0x1d,0,'\x01');
      return;
    case 0x14:
      FUN_005499f0(this,0xd,0,'\x01');
      return;
    case 0x15:
      FUN_005499f0(this,10,0,bVar2);
      return;
    case 0x16:
      FUN_005499f0(this,0x18,0,bVar2);
      return;
    case 0x17:
      FUN_005499f0(this,0x22,0,'\x01');
      return;
    case 0x18:
      FUN_005499f0(this,0x14,7,'\x01');
      return;
    case 0x19:
      FUN_005499f0(this,0xe,0,bVar2);
      return;
    case 0x1a:
      iVar1 = 0x20;
LAB_0054a1ed:
      FUN_005499f0(this,iVar1,0,bVar2);
      return;
    case 0x1b:
      FUN_005482e0(this,0x2c);
      return;
    case 0x1c:
      FUN_005482e0(this,0x21);
      return;
    case 0x1d:
      FUN_005482e0(this,0x22);
    }
  }
  return;
}

