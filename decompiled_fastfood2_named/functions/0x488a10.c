// rea decompile_all
// name: FUN_00488a10
// address: 0x488a10
// body: available
// range: 0x488a10-0x488b2f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00488a10(void *this,void *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_40 [32];
  undefined1 local_20 [32];
  
  if ((param_1 != (void *)0x0) || (param_1 = *(void **)((int)this + 0x25c), param_1 != (void *)0x0))
  {
    if (*(int *)((int)this + 0x1508) == 0) {
      String_Format(local_40,(byte *)s__02d__02d_005682f8,
                    (uint)*(byte *)(*(int *)((int)this + 0x94) + 7));
    }
    else {
      uVar3 = 0xffffffff;
      pcVar5 = DAT_00582a68;
      do {
        pcVar6 = pcVar5;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar6 = pcVar5 + 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar6;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar5 = pcVar6 + -uVar3;
      pcVar6 = local_40;
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar5 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      }
    }
    String_Format(local_20,(byte *)s__d__s__02d_005682ec,
                  *(byte *)(*(int *)((int)this + 0x94) + 8) + 1);
    CS_Enter(*(int *)(DAT_0057c5e0 + 0x1c8));
    iVar2 = FUN_0052ff20(param_1,0x410);
    if (iVar2 != 0) {
      FUN_0052f9b0(param_1,0x410,local_40);
    }
    iVar2 = FUN_0052ff20(param_1,0x1f41);
    if (iVar2 != 0) {
      FUN_0052f9b0(param_1,0x1f41,local_20);
    }
    CS_Leave(*(int *)(DAT_0057c5e0 + 0x1c8));
  }
  return;
}

