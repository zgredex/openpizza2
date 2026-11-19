// rea decompile_all
// name: Font_DrawGlyphPattern
// address: 0x500580
// body: available
// range: 0x500580-0x5007f0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __cdecl
Font_DrawGlyphPattern(int param_1,int *param_2,int *param_3,int param_4,int param_5,int *param_6)

{
  undefined1 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int local_4;
  
  local_4 = 0;
  uVar5 = 6;
  switch(param_5) {
  case 0:
  case 0x15:
    uVar5 = Random_Mod(3);
    piVar2 = (int *)(&PTR_s_ss_ss_tttt_ssttttss_ssttttss_ttt_00572214)[uVar5];
    uVar5 = 0xc;
    local_4 = 0xc;
    break;
  case 1:
    NoOp_Stub();
  case 2:
    uVar5 = 6;
    local_4 = 1;
    piVar2 = (int *)PTR_s__00572220;
    break;
  case 3:
    uVar5 = Random_Mod(1);
    piVar2 = (int *)(&PTR_s__00572224)[uVar5];
    uVar5 = 6;
    local_4 = 3;
    break;
  default:
    NoOp_Stub();
    piVar2 = param_3;
    break;
  case 6:
    uVar5 = Random_Mod(1);
    piVar2 = (int *)(&PTR_s__0057222c)[uVar5];
    uVar5 = 6;
    local_4 = 3;
    break;
  case 7:
    uVar5 = Random_Mod(1);
    piVar2 = (int *)(&PTR_s__00572230)[uVar5];
    uVar5 = 6;
    local_4 = 4;
    break;
  case 0x14:
    uVar5 = Random_Mod(1);
    piVar2 = (int *)(&PTR_s__00572228)[uVar5];
    local_4 = 2;
    uVar5 = 6;
  }
  if (param_4 == 2) {
    if (local_4 != 0) {
      param_5 = local_4;
      do {
        piVar6 = piVar2;
        piVar8 = (int *)(*param_2 * 0x50 + *param_3 + 0x28 + param_1);
        for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *piVar8 = *piVar6;
          piVar6 = piVar6 + 1;
          piVar8 = piVar8 + 1;
        }
        for (uVar3 = uVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(char *)piVar8 = (char)*piVar6;
          piVar6 = (int *)((int)piVar6 + 1);
          piVar8 = (int *)((int)piVar8 + 1);
        }
        param_5 = param_5 + -1;
        *param_2 = *param_2 + -1;
        piVar2 = (int *)((int)piVar2 + uVar5);
      } while (param_5 != 0);
    }
  }
  else if (param_4 == 3) {
    if (local_4 != 0) {
      param_5 = local_4;
      do {
        iVar7 = 0;
        if (uVar5 != 0) {
          do {
            iVar4 = *param_2 * 0x50 - iVar7;
            puVar1 = (undefined1 *)(iVar7 + (int)piVar2);
            iVar7 = iVar7 + 1;
            *(undefined1 *)(iVar4 + *param_3 + 0x28 + param_1) = *puVar1;
          } while (iVar7 < (int)uVar5);
        }
        piVar2 = (int *)((int)piVar2 + uVar5);
        param_5 = param_5 + -1;
        *param_2 = *param_2 + -1;
      } while (param_5 != 0);
    }
  }
  else if (param_4 == 0) {
    if (local_4 != 0) {
      param_5 = local_4;
      do {
        iVar7 = 0;
        if (uVar5 != 0) {
          do {
            iVar4 = *param_2 + iVar7;
            puVar1 = (undefined1 *)(iVar7 + (int)piVar2);
            iVar7 = iVar7 + 1;
            *(undefined1 *)(iVar4 * 0x50 + *param_3 + 0x28 + param_1) = *puVar1;
          } while (iVar7 < (int)uVar5);
        }
        piVar2 = (int *)((int)piVar2 + uVar5);
        param_5 = param_5 + -1;
        *param_3 = *param_3 + 1;
      } while (param_5 != 0);
    }
  }
  else if ((param_4 == 1) && (local_4 != 0)) {
    param_5 = local_4;
    do {
      iVar7 = 0;
      if (uVar5 != 0) {
        do {
          iVar4 = *param_2 - iVar7;
          puVar1 = (undefined1 *)(iVar7 + (int)piVar2);
          iVar7 = iVar7 + 1;
          *(undefined1 *)(iVar4 * 0x50 + *param_3 + 0x28 + param_1) = *puVar1;
        } while (iVar7 < (int)uVar5);
      }
      piVar2 = (int *)((int)piVar2 + uVar5);
      param_5 = param_5 + -1;
      *param_3 = *param_3 + -1;
    } while (param_5 != 0);
  }
  *param_6 = *param_6 - local_4;
  return uVar5;
}

