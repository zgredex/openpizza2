// rea decompile_all
// name: FUN_0054bb30
// address: 0x54bb30
// body: available
// range: 0x54bb30-0x54bc89 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_0054bb30(void *this,void *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  char local_104 [260];
  
  iVar2 = 9;
  puVar1 = (undefined4 *)((int)this + 0x244);
  do {
    puVar1[-0x22] = 0;
    *puVar1 = 0;
    puVar1[-0x20] = 0;
    puVar1[-1] = 0;
    puVar1 = puVar1 + 0x23;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)((int)this + 0x1ac) = 0;
  FUN_0054dd83(local_104,(byte *)s__s1_spr_005765d4,param_2);
  FUN_00527580(param_1,local_104,(undefined4 *)0x1,(undefined4 *)((int)this + 8));
  FUN_0054dd83(local_104,(byte *)s__s2_spr_005765cc,param_2);
  FUN_00527580(param_1,local_104,(undefined4 *)0x1,(undefined4 *)((int)this + 0x4c));
  FUN_0054dd83(local_104,(byte *)s__s3_spr_005765c4,param_2);
  FUN_00527580(param_1,local_104,(undefined4 *)0x1,(undefined4 *)((int)this + 0x90));
  FUN_0054dd83(local_104,(byte *)s__s1_spr_005765d4,param_3);
  FUN_00527580(param_1,local_104,(undefined4 *)0x1,(undefined4 *)((int)this + 0xd4));
  FUN_0054dd83(local_104,(byte *)s__s2_spr_005765cc,param_3);
  FUN_00527580(param_1,local_104,(undefined4 *)0x1,(undefined4 *)((int)this + 0x118));
  FUN_0054dd83(local_104,(byte *)s__s3_spr_005765c4,param_3);
  FUN_00527580(param_1,local_104,(undefined4 *)0x1,(undefined4 *)((int)this + 0x15c));
  *(void **)this = param_1;
  *(undefined4 *)((int)this + 0x1a0) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x1a8) = 0;
  *(undefined4 *)((int)this + 0x1a4) = 0;
  return this;
}

