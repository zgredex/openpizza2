// rea decompile_all
// name: Palette_Expand
// address: 0x48ce70
// body: available
// range: 0x48ce70-0x48cf71 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Palette_Expand(ushort *param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  byte *pbVar7;
  ushort *puVar8;
  int local_8;
  
  puVar5 = param_1 + 2;
  puVar6 = (ushort *)((uint)puVar5 & 0xff);
  local_8 = 0x100;
  pbVar7 = (byte *)(*(int *)param_1 + 1);
  puVar8 = puVar5;
  param_1 = puVar5;
  do {
    puVar2 = (ushort *)(uint)pbVar7[-1];
    puVar3 = (ushort *)(uint)*pbVar7;
    puVar4 = (ushort *)(uint)pbVar7[1];
    switch(param_3) {
    case 0:
      puVar5 = puVar4;
      puVar6 = puVar2;
      puVar8 = puVar2;
      break;
    case 1:
      puVar5 = puVar4;
      puVar6 = puVar4;
      puVar8 = puVar2;
      break;
    case 2:
      puVar2 = puVar3;
      goto LAB_0048cf0a;
    case 3:
      puVar5 = puVar2;
      puVar6 = puVar4;
      puVar8 = puVar3;
      break;
    case 4:
      puVar4 = (ushort *)((int)puVar4 + (int)puVar3 >> 1);
      puVar2 = puVar4;
      goto LAB_0048cf0a;
    case 5:
      goto LAB_0048cf08;
    case 6:
      puVar5 = puVar4;
      puVar6 = puVar3;
      puVar8 = puVar2;
      break;
    case 7:
      puVar4 = (ushort *)((uint)((int)puVar4 + (int)puVar3) / 2);
LAB_0048cf08:
      puVar3 = puVar4;
LAB_0048cf0a:
      puVar5 = puVar2;
      puVar6 = puVar3;
      puVar8 = puVar4;
    }
    if (param_2 == 0) {
      uVar1 = (ushort)((((uint)puVar5 & 0xf8) << 5 | (uint)puVar6 & 0xf8) << 2);
    }
    else {
      uVar1 = (ushort)((((uint)puVar5 & 0xfff8) << 5 | (uint)puVar6 & 0xf8) << 3);
    }
    *param_1 = uVar1 | (ushort)((int)puVar8 >> 3);
    param_1 = param_1 + 1;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      return;
    }
    pbVar7 = pbVar7 + 3;
  } while( true );
}

