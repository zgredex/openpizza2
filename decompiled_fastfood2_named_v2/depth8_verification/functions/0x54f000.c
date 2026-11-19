// rea decompile_all
// name: _strcmp
// address: 0x54f000
// body: available
// range: 0x54f000-0x54f042 inclusive
// range: 0x54f044-0x54f049 inclusive
// range: 0x54f04c-0x54f083 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  bool bVar4;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar3 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar4 = bVar3 < (byte)*_Str2;
      if (bVar3 != *_Str2) goto LAB_0054f044;
      _Str2 = _Str2 + 1;
      if (bVar3 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_0054f010;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar3 = (byte)uVar1;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) goto LAB_0054f044;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((ushort)uVar1 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) goto LAB_0054f044;
    if (bVar3 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_0054f010:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar3 = (byte)uVar2;
    bVar4 = bVar3 < (byte)*_Str2;
    if (bVar3 != *_Str2) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 8);
    bVar4 = bVar3 < (byte)_Str2[1];
    if (bVar3 != _Str2[1]) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 0x10);
    bVar4 = bVar3 < (byte)_Str2[2];
    if (bVar3 != _Str2[2]) break;
    if (bVar3 == 0) {
      return 0;
    }
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    bVar4 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_0054f044:
  return (uint)bVar4 * -2 + 1;
}

