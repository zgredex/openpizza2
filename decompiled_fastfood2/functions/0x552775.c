// rea decompile_all
// name: FUN_00552775
// address: 0x552775
// body: available
// range: 0x552775-0x552920 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


bool __cdecl FUN_00552775(int *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (DAT_00576a34 != 0) {
    uVar6 = param_1[5];
    if ((uVar6 != DAT_00576ac8) || (uVar6 != DAT_00576ad8)) {
      if (DAT_00585670 == 0) {
        FUN_00552921(1,1,uVar6,4,1,0,0,2,0,0,0);
        FUN_00552921(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_00585710 != 0) {
          uVar7 = (uint)DAT_00585716;
          uVar4 = 0;
          uVar5 = 0;
        }
        else {
          uVar4 = (uint)DAT_00585714;
          uVar7 = 0;
          uVar5 = (uint)DAT_00585716;
        }
        FUN_00552921(1,(uint)(DAT_00585710 == 0),uVar6,(uint)DAT_00585712,uVar5,uVar4,uVar7,
                     (uint)DAT_00585718,(uint)DAT_0058571a,(uint)DAT_0058571c,(uint)DAT_0058571e);
        if (DAT_005856bc != 0) {
          uVar7 = (uint)DAT_005856c2;
          uVar4 = 0;
          uVar5 = 0;
          uVar6 = param_1[5];
        }
        else {
          uVar4 = (uint)DAT_005856c0;
          uVar7 = 0;
          uVar5 = (uint)DAT_005856c2;
          uVar6 = param_1[5];
        }
        FUN_00552921(0,(uint)(DAT_005856bc == 0),uVar6,(uint)DAT_005856be,uVar5,uVar4,uVar7,
                     (uint)DAT_005856c4,(uint)DAT_005856c6,(uint)DAT_005856c8,(uint)DAT_005856ca);
      }
    }
    iVar1 = param_1[7];
    if (DAT_00576acc < DAT_00576adc) {
      if ((DAT_00576acc <= iVar1) && (iVar1 <= DAT_00576adc)) {
        if ((DAT_00576acc < iVar1) && (iVar1 < DAT_00576adc)) {
          return true;
        }
LAB_005528ed:
        iVar3 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar1 == DAT_00576acc) {
          bVar2 = DAT_00576ad0 <= iVar3;
        }
        else {
          bVar2 = iVar3 < DAT_00576ae0;
        }
        return bVar2;
      }
    }
    else {
      if (iVar1 < DAT_00576adc) {
        return true;
      }
      if (DAT_00576acc < iVar1) {
        return true;
      }
      if ((iVar1 <= DAT_00576adc) || (DAT_00576acc <= iVar1)) goto LAB_005528ed;
    }
  }
  return false;
}

