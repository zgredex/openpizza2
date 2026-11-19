// rea decompile_all
// name: FUN_00504a90
// address: 0x504a90
// body: available
// range: 0x504a90-0x504cfd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00504a90(void *this,undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  *(undefined4 *)((int)this + 0x44) = 0xffffffff;
  switch(param_1) {
  case 0:
    switch(*(undefined4 *)((int)this + 0x30)) {
    case 0:
      *(undefined4 *)((int)this + 0x44) = 0x78;
      break;
    case 1:
      *(undefined4 *)((int)this + 0x44) = 0x96;
      break;
    case 2:
      *(undefined4 *)((int)this + 0x44) = 0x66;
      break;
    case 3:
      *(undefined4 *)((int)this + 0x44) = 0x5a;
      break;
    case 4:
      *(undefined4 *)((int)this + 0x44) = 0x84;
      break;
    case 5:
    case 0xb:
    case 0xf:
      *(undefined4 *)((int)this + 0x44) = 0xa2;
      break;
    case 6:
      *(undefined4 *)((int)this + 0x44) = 0xb4;
      break;
    case 7:
      *(undefined4 *)((int)this + 0x44) = 0x3c;
    }
    uVar1 = Random_Range(0,0x14);
    iVar2 = *(int *)((int)this + 0x44) + (uVar1 - 10);
    *(int *)((int)this + 0x44) = iVar2;
    *(int *)((int)this + 0x48) = iVar2;
    return;
  case 1:
    switch(*(undefined4 *)((int)this + 0x30)) {
    case 0:
switchD_00504ac2_caseD_0:
      *(undefined4 *)((int)this + 0x44) = 0x6e;
      break;
    case 1:
switchD_00504ac2_caseD_1:
      *(undefined4 *)((int)this + 0x44) = 0x78;
      break;
    case 2:
switchD_00504ac2_caseD_2:
      *(undefined4 *)((int)this + 0x44) = 100;
      break;
    case 3:
switchD_00504ac2_caseD_3:
      *(undefined4 *)((int)this + 0x44) = 0x50;
      break;
    case 4:
switchD_00504ac2_caseD_4:
      *(undefined4 *)((int)this + 0x44) = 0x46;
      break;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
switchD_00504ac2_caseD_5:
      *(undefined4 *)((int)this + 0x44) = 0x82;
      break;
    case 6:
switchD_00504ac2_caseD_6:
      *(undefined4 *)((int)this + 0x44) = 0x8c;
      break;
    case 7:
switchD_00504ac2_caseD_7:
      *(undefined4 *)((int)this + 0x44) = 0x5a;
    default:
      break;
    }
    break;
  case 2:
  case 9:
    *(undefined4 *)((int)this + 0x48) = 5;
    *(undefined4 *)((int)this + 0x44) = 5;
    return;
  case 3:
    switch(*(undefined4 *)((int)this + 0x30)) {
    case 0:
      goto switchD_00504ac2_caseD_0;
    case 1:
      goto switchD_00504ac2_caseD_1;
    case 2:
      goto switchD_00504ac2_caseD_2;
    case 3:
      goto switchD_00504ac2_caseD_3;
    case 4:
      goto switchD_00504ac2_caseD_4;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
      goto switchD_00504ac2_caseD_5;
    case 6:
      goto switchD_00504ac2_caseD_6;
    case 7:
      goto switchD_00504ac2_caseD_7;
    default:
      break;
    }
  case 4:
    switch(*(undefined4 *)((int)this + 0x30)) {
    case 0:
      *(undefined4 *)((int)this + 0x44) = 0xdc;
      break;
    case 1:
      *(undefined4 *)((int)this + 0x44) = 0xf0;
      break;
    case 2:
      *(undefined4 *)((int)this + 0x44) = 200;
      break;
    case 3:
      *(undefined4 *)((int)this + 0x44) = 0xa0;
      break;
    case 4:
      *(undefined4 *)((int)this + 0x44) = 0x8c;
      break;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
      *(undefined4 *)((int)this + 0x44) = 0x104;
      break;
    case 6:
      *(undefined4 *)((int)this + 0x44) = 0x118;
      break;
    case 7:
      *(undefined4 *)((int)this + 0x44) = 0xb4;
    }
    uVar1 = Random_Range(0,0x14);
    iVar2 = *(int *)((int)this + 0x44) + (uVar1 - 10);
    *(int *)((int)this + 0x44) = iVar2;
    *(int *)((int)this + 0x48) = iVar2;
    return;
  default:
    *(undefined4 *)((int)this + 0x48) = 10;
    *(undefined4 *)((int)this + 0x44) = 10;
    return;
  case 6:
    if ((*(int *)((int)this + 0x30) == 0xf) || (*(int *)((int)this + 0x30) == 0x21)) {
      *(undefined4 *)((int)this + 0x48) = 0x50;
      *(undefined4 *)((int)this + 0x44) = 0x50;
      return;
    }
    *(undefined4 *)((int)this + 0x48) = 0x1e;
    *(undefined4 *)((int)this + 0x44) = 0x1e;
    return;
  case 8:
    switch(*(undefined4 *)((int)this + 0x30)) {
    case 0:
      *(undefined4 *)((int)this + 0x44) = 0x140;
      break;
    case 1:
      *(undefined4 *)((int)this + 0x44) = 0x154;
      break;
    case 2:
      *(undefined4 *)((int)this + 0x44) = 300;
      break;
    case 3:
      *(undefined4 *)((int)this + 0x44) = 0x104;
      break;
    case 4:
      *(undefined4 *)((int)this + 0x44) = 0xf0;
      break;
    case 5:
    case 0xb:
    case 0xf:
    case 0x21:
      *(undefined4 *)((int)this + 0x44) = 0x168;
      break;
    case 6:
      *(undefined4 *)((int)this + 0x44) = 0x17c;
      break;
    case 7:
      *(undefined4 *)((int)this + 0x44) = 0x118;
    }
    uVar1 = Random_Range(0,0x14);
    iVar2 = *(int *)((int)this + 0x44) + (uVar1 - 10);
    *(int *)((int)this + 0x44) = iVar2;
    *(int *)((int)this + 0x48) = iVar2;
    return;
  }
  uVar1 = Random_Range(0,0x14);
  iVar2 = *(int *)((int)this + 0x44) + (uVar1 - 10);
  *(int *)((int)this + 0x44) = iVar2;
  *(int *)((int)this + 0x48) = iVar2;
  return;
}

