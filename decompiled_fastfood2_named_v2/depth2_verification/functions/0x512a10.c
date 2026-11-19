// rea decompile_all
// name: FUN_00512a10
// address: 0x512a10
// body: available
// range: 0x512a10-0x512c25 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char * FUN_00512a10(char *param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char local_58 [28];
  char local_3c [60];
  
  local_58[0] = '\t';
  local_58[2] = 0x26;
  local_3c[0x1d] = 9;
  local_3c[0x2b] = 0x26;
  local_58[1] = 0x11;
  local_58[3] = 0x35;
  local_58[4] = 0x3b;
  local_58[5] = 0x3e;
  local_58[6] = 0x41;
  local_58[7] = 0xff;
  local_3c[0x18] = 0;
  local_3c[0x19] = 1;
  local_3c[0x1a] = 2;
  local_3c[0x1b] = 3;
  local_3c[0x1c] = 7;
  local_3c[0x1e] = 10;
  local_3c[0x1f] = 0xd;
  local_3c[0x20] = 0x11;
  local_3c[0x21] = 0x12;
  local_3c[0x22] = 0x13;
  local_3c[0x23] = 0x14;
  local_3c[0x24] = 0x15;
  local_3c[0x25] = 0x18;
  local_3c[0x26] = 0x1b;
  local_3c[0x27] = 0x20;
  local_3c[0x28] = 0x22;
  local_3c[0x29] = 0x23;
  local_3c[0x2a] = 0x25;
  local_3c[0x2c] = 0x28;
  local_3c[0x2d] = 0x2d;
  local_3c[0x2e] = 0x30;
  local_3c[0x2f] = 0x31;
  local_3c[0x30] = 0x33;
  local_3c[0x31] = 0x36;
  local_3c[0x32] = 0x37;
  local_3c[0x33] = 0x38;
  local_3c[0x34] = 0x39;
  local_3c[0x35] = 0x3a;
  local_3c[0x36] = 0x3c;
  local_3c[0x37] = 0x3d;
  local_3c[0x38] = 0x41;
  local_3c[0x39] = 0xff;
  local_3c[0] = '\0';
  local_3c[1] = 8;
  local_3c[2] = 10;
  local_3c[3] = 0xd;
  local_3c[4] = 0xe;
  local_3c[5] = 0xf;
  local_3c[6] = 0x10;
  local_3c[7] = 0x16;
  local_3c[8] = 0x1c;
  local_3c[9] = 0x24;
  local_3c[10] = 0x27;
  local_3c[0xb] = 0x2b;
  local_3c[0xc] = 0x2c;
  local_3c[0xd] = 0x2d;
  local_3c[0xe] = 0x30;
  local_3c[0xf] = 0x33;
  local_3c[0x10] = 0x35;
  local_3c[0x11] = 0x36;
  local_3c[0x12] = 0x37;
  local_3c[0x13] = 0x3b;
  local_3c[0x14] = 0x3c;
  local_3c[0x15] = 0x3e;
  local_3c[0x16] = 0x3f;
  local_3c[0x17] = 0xff;
  local_58[8] = 0;
  local_58[9] = 0x11;
  local_58[10] = 0x1c;
  local_58[0xb] = 0x1e;
  local_58[0xc] = 0x24;
  local_58[0x12] = 0x30;
  local_58[0xd] = 0x27;
  local_58[0xe] = 0x2a;
  local_58[0xf] = 0x2b;
  local_58[0x10] = 0x2c;
  local_58[0x11] = 0x2d;
  local_58[0x13] = 0x31;
  local_58[0x14] = 0x39;
  local_58[0x15] = 0x3a;
  local_58[0x16] = 0x3b;
  local_58[0x17] = 0x41;
  local_58[0x18] = 0xff;
  switch(param_1[6]) {
  case '\0':
    pcVar4 = local_58 + 8;
    pcVar3 = (char *)0x0;
    break;
  case '\x01':
    pcVar4 = local_3c;
    pcVar3 = (char *)0x0;
    break;
  case '\x02':
    pcVar4 = local_3c + 0x18;
    pcVar3 = (char *)0x1;
    break;
  case '\x03':
    pcVar4 = local_58;
    pcVar3 = (char *)0x1;
    break;
  default:
    pcVar3 = param_1;
    pcVar4 = param_1;
  }
  cVar2 = *pcVar4;
  pcVar1 = (char *)(uint)(pcVar3 == (char *)0x0);
  if (cVar2 != -1) {
    while (cVar2 != param_1[4]) {
      cVar2 = pcVar4[1];
      pcVar4 = pcVar4 + 1;
      if (cVar2 == -1) {
        return (char *)(uint)(pcVar3 == (char *)0x0);
      }
    }
    pcVar1 = pcVar3;
  }
  return pcVar1;
}

