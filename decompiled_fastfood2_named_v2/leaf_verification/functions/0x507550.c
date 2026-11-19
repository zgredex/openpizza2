// rea decompile_all
// name: FUN_00507550
// address: 0x507550
// body: available
// range: 0x507550-0x50780b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00507550(void *this,undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)((int)this + 200);
  if (iVar1 != 0) {
    *(undefined2 *)((int)this + 0x40) = param_1;
    switch(param_1) {
    case 0:
      *(undefined2 *)(iVar1 + 8) = 0x19;
      return;
    case 1:
      *(undefined2 *)(iVar1 + 8) = 0x29;
      return;
    case 2:
      *(undefined2 *)(iVar1 + 8) = 0x3f;
      return;
    case 3:
      *(undefined2 *)(iVar1 + 8) = 0x4f;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 4:
    case 0x18:
      *(undefined2 *)(iVar1 + 8) = 0x7e;
      return;
    case 5:
      *(undefined2 *)(iVar1 + 8) = 0x50;
      return;
    case 6:
      *(undefined2 *)(iVar1 + 8) = 0x60;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 7:
      *(undefined2 *)(iVar1 + 8) = 0x87;
      return;
    case 8:
      *(short *)(iVar1 + 8) = (short)*(undefined4 *)((int)this + 0x9c);
      return;
    case 10:
      *(undefined2 *)(iVar1 + 8) = 0x79;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0xc:
      *(undefined2 *)(iVar1 + 8) = 100;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0xd:
      *(undefined2 *)(iVar1 + 8) = 0x12;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0xe:
      *(undefined2 *)(iVar1 + 8) = 0x11;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0xf:
      *(undefined2 *)(iVar1 + 8) = 0x6c;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0x10:
      *(undefined2 *)(iVar1 + 8) = 0x2b;
      return;
    case 0x11:
      *(undefined2 *)(iVar1 + 8) = 0x2a;
      return;
    case 0x12:
      *(undefined2 *)(iVar1 + 8) = 0x7a;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0x13:
      *(undefined2 *)(iVar1 + 8) = 0x7b;
      return;
    case 0x14:
      *(undefined2 *)(iVar1 + 8) = 0x61;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0x15:
      *(undefined2 *)(iVar1 + 8) = 0x2f;
      return;
    case 0x16:
      *(undefined2 *)(iVar1 + 8) = 0x10;
      return;
    case 0x17:
      *(undefined2 *)(iVar1 + 8) = 0x7f;
      return;
    case 0x19:
      *(undefined2 *)(iVar1 + 8) = 0x7d;
      return;
    case 0x1a:
      *(undefined2 *)(iVar1 + 8) = 0x82;
      return;
    case 0x1b:
      *(undefined2 *)(iVar1 + 8) = 0x81;
      return;
    case 0x1c:
      *(undefined2 *)(iVar1 + 8) = 0x80;
      return;
    case 0x1d:
      *(undefined2 *)(iVar1 + 8) = 0x86;
      return;
    case 0x1e:
      *(undefined2 *)(iVar1 + 8) = 0x62;
      return;
    case 0x1f:
      *(undefined2 *)(iVar1 + 8) = 0x6a;
      return;
    case 0x20:
      *(undefined2 *)(iVar1 + 8) = 99;
      return;
    case 0x21:
      *(undefined2 *)(iVar1 + 8) = 0x76;
      return;
    case 0x22:
      *(undefined2 *)(iVar1 + 8) = 0x18;
      return;
    case 0x23:
      *(undefined2 *)(iVar1 + 8) = 0x9a;
      *(undefined2 *)((int)this + 0x40) = 0xb;
      return;
    case 0x24:
      *(undefined2 *)(iVar1 + 8) = 0x75;
      return;
    case 0x25:
      *(undefined2 *)(iVar1 + 8) = 0x78;
      return;
    case 0x26:
switchD_00507578_caseD_26:
      *(undefined2 *)(iVar1 + 8) = 0x74;
      return;
    case 0x27:
      *(undefined2 *)(iVar1 + 8) = 0x77;
      break;
    case 0xffff:
      iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)((int)this + 0x50),(int *)0x0);
      if ((iVar1 != 0) && (*(char *)((int)this + 0x104) != '\0')) {
        uVar2 = State_IsNegative(iVar1);
        if ((char)uVar2 != '\0') {
          *(undefined2 *)(*(int *)((int)this + 200) + 8) = 0x78;
          return;
        }
        iVar3 = Rating_AdjustB(iVar1);
        if (iVar3 < 0x14) {
          *(undefined2 *)(*(int *)((int)this + 200) + 8) = 0x75;
          return;
        }
        if (*(int *)(iVar1 + 0xc) < 0x14) {
          iVar1 = *(int *)((int)this + 200);
          goto switchD_00507578_caseD_26;
        }
        uVar2 = State_HasFlags(iVar1);
        if ((char)uVar2 != '\0') {
          *(undefined2 *)(*(int *)((int)this + 200) + 8) = 0x76;
          return;
        }
        uVar2 = State_HasPositive(iVar1);
        if ((char)uVar2 != '\0') {
          *(undefined2 *)(*(int *)((int)this + 200) + 8) = 0x77;
          return;
        }
      }
      iVar1 = *(int *)((int)this + 200);
    case 9:
      *(undefined2 *)(iVar1 + 8) = 0xffff;
      return;
    }
  }
  return;
}

