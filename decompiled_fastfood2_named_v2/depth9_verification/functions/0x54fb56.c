// rea decompile_all
// name: CRT_Fwrite
// address: 0x54fb56
// body: available
// range: 0x54fb56-0x54fc5f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl CRT_Fwrite(char *param_1,uint param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
                    /* Writes items through a stdio buffer and returns complete items written. */
  piVar1 = param_4;
  piVar6 = (int *)(param_2 * param_3);
  if (piVar6 == (int *)0x0) {
    param_3 = 0;
  }
  else {
    piVar5 = piVar6;
    if ((*(ushort *)(param_4 + 3) & 0x10c) == 0) {
      param_4 = (int *)0x1000;
    }
    else {
      param_4 = (int *)param_4[6];
    }
    do {
      if (((piVar1[3] & 0x108U) == 0) || (piVar7 = (int *)piVar1[1], piVar7 == (int *)0x0)) {
        if (param_4 <= piVar5) {
          if (((piVar1[3] & 0x108U) != 0) && (iVar2 = FUN_005506b2(piVar1), iVar2 != 0)) {
LAB_0054fc57:
            return (uint)((int)piVar6 - (int)piVar5) / param_2;
          }
          if (param_4 == (int *)0x0) {
            piVar7 = piVar5;
          }
          else {
            piVar7 = (int *)((int)piVar5 - (uint)piVar5 % (uint)param_4);
          }
          piVar3 = (int *)FUN_0054ff6b(piVar1[4],param_1,(DWORD)piVar7);
          if ((piVar3 == (int *)0xffffffff) ||
             (piVar5 = (int *)((int)piVar5 - (int)piVar3), piVar3 < piVar7)) {
            piVar1[3] = piVar1[3] | 0x20;
            goto LAB_0054fc57;
          }
          goto LAB_0054fc0e;
        }
        uVar4 = FUN_0055104d((int)*param_1,piVar1);
        if (uVar4 == 0xffffffff) goto LAB_0054fc57;
        param_1 = param_1 + 1;
        param_4 = (int *)piVar1[6];
        piVar5 = (int *)((int)piVar5 - 1);
        if ((int)param_4 < 1) {
          param_4 = (int *)0x1;
        }
      }
      else {
        piVar3 = piVar5;
        if (piVar7 <= piVar5) {
          piVar3 = piVar7;
        }
        FUN_00550cd0((undefined4 *)*piVar1,(undefined4 *)param_1,(uint)piVar3);
        piVar1[1] = piVar1[1] - (int)piVar3;
        *piVar1 = *piVar1 + (int)piVar3;
        piVar5 = (int *)((int)piVar5 - (int)piVar3);
LAB_0054fc0e:
        param_1 = param_1 + (int)piVar3;
      }
    } while (piVar5 != (int *)0x0);
  }
  return param_3;
}

