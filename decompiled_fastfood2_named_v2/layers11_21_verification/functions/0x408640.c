// rea decompile_all
// name: FUN_00408640
// address: 0x408640
// body: available
// range: 0x408640-0x4089f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00408640(void *this,void *param_1,void *param_2)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  undefined3 extraout_var;
  void *this_00;
  int iVar4;
  int iVar5;
  uint extraout_EDX;
  undefined1 unaff_SI;
  undefined4 unaff_EDI;
  bool bVar6;
  int iVar7;
  
  uVar2 = FUN_00505e00((int)param_2);
  if (CONCAT31(extraout_var,uVar2) == 0) {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 5:
      bVar6 = *(int *)((int)param_2 + 0x30) == 0x12;
      iVar4 = FUN_004f50d0(0,(uint)bVar6,(uint)bVar6,unaff_EDI,unaff_SI);
      if (iVar4 == 0) {
        iVar4 = FUN_00509ff0((int)param_2);
        FUN_00507d90(param_2,iVar4);
        FUN_0050e890(param_2,0x14);
        return;
      }
      _DAT_0057c610 = FUN_0050e6b0(param_2,iVar4);
      return;
    case 6:
      iVar4 = FUN_004f3ad0(*(int *)((int)param_2 + 0xc4));
      if (iVar4 != 0) {
        FUN_00507d90(param_2,iVar4);
        FUN_0050e890(param_2,7);
        return;
      }
      break;
    case 7:
      FUN_0050e850(param_2,0xffffffff);
      if (*(int *)((int)param_2 + 0x30) == 10) {
        *(undefined4 *)((int)param_2 + 0x108) = 0xffffffff;
        *(undefined1 *)(*(int *)((int)param_2 + 0x10c) + 0x1880 + (int)param_1) = 0;
      }
      FUN_005087c0(param_2);
      iVar4 = *(int *)((int)param_1 + 0x30);
      iVar5 = FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
      *(int *)(iVar5 + 0xce0 + iVar4 * 4) = *(int *)(iVar5 + 0xce0 + iVar4 * 4) + 1;
      if (*(int *)((int)param_2 + 0x30) == 0x12) {
        FUN_0050e2a0((int)param_2,extraout_EDX,(int)param_1,'\x01');
        return;
      }
      break;
    case 8:
      iVar4 = *(int *)((int)param_2 + 0x30);
      if (iVar4 == 10) {
        iVar4 = *(int *)((int)param_2 + 0x8c);
        iVar5 = *(int *)((int)param_2 + 0x108);
        iVar7 = *(int *)((int)param_2 + 0x10c);
        iVar1 = *(int *)((int)param_2 + 0x88);
        this_00 = (void *)FUN_004017f0((void *)((int)this + 4),*(int *)((int)param_2 + 0x28),
                                       (int *)0x0);
        FUN_004d9a10(this_00,iVar7,param_1,iVar5,iVar4);
        FUN_0050d200(param_2,0xc);
        FUN_00509060(param_2,iVar1 + 0x10);
        FUN_0050e890(param_2,0x1c);
        return;
      }
      if (iVar4 == 0x12) {
        iVar4 = *(int *)((int)param_2 + 0x88);
        FUN_0050d200(param_2,0xc);
        FUN_00509060(param_2,iVar4 + 0x10);
        FUN_0050e890(param_2,0x1c);
        return;
      }
      if (iVar4 == 0x18) {
        FUN_0050d200(param_2,5);
        FUN_00509060(param_2,9);
        FUN_0050e890(param_2,0x1c);
        return;
      }
      FUN_00509060(param_2,(int)param_1);
      FUN_0050e890(param_2,0x1c);
      return;
    default:
      FUN_0050e7d0(param_2);
      return;
    case 0x14:
    case 0x1e:
switchD_00408676_caseD_14:
      FUN_0050e890(param_2,6);
      return;
    case 0x25:
      if (*(int *)((int)param_2 + 0x30) == 0x12) {
        FUN_0050e890(param_2,6);
        FUN_00507550(param_2,0x1d);
        return;
      }
    }
  }
  else {
    switch(*(undefined4 *)((int)param_2 + 0x38)) {
    case 5:
      FUN_0050adf0(param_2);
      return;
    case 8:
      iVar4 = FUN_0050adf0(param_2);
      if (iVar4 == 0) {
        if (*(int *)((int)param_2 + 200) == 0) {
          *(undefined4 *)((int)param_2 + 0x88) = 0xffffffff;
          return;
        }
        *(undefined4 *)((int)param_2 + 0x88) = *(undefined4 *)(*(int *)((int)param_2 + 200) + 0xc);
        return;
      }
      break;
    case 0x1c:
      iVar4 = FUN_0050adf0(param_2);
      if (iVar4 == 0) {
        iVar4 = *(int *)((int)param_2 + 0x30);
        if (iVar4 == 10) {
          iVar4 = *(int *)((int)param_2 + 0x94) + -1;
          *(int *)((int)param_2 + 0x94) = iVar4;
          if (iVar4 != 0) {
            return;
          }
          FUN_0050d200(param_2,-1);
          FUN_005090e0((int)param_2);
          iVar4 = *(int *)((int)param_2 + 0x98) + -1;
          *(int *)((int)param_2 + 0x98) = iVar4;
          if (iVar4 == 0) goto switchD_00408676_caseD_14;
        }
        else {
          if (iVar4 != 0x12) {
            if (iVar4 != 0x18) {
              return;
            }
            iVar4 = *(int *)((int)param_2 + 0x94) + -1;
            *(int *)((int)param_2 + 0x94) = iVar4;
            if (iVar4 != 0) {
              return;
            }
            FUN_0050d200(param_2,-1);
            FUN_005090e0((int)param_2);
            cVar3 = Branch_StepStarRating(param_1);
            if (cVar3 == '\0') {
              FUN_0050e890(param_2,6);
            }
            else {
              FUN_0050e890(param_2,0x1e);
              FUN_00509060(param_2,0x19);
            }
            if (*(void **)((int)this + 0x25c) == (void *)0x0) {
              return;
            }
            FUN_005301c0(*(void **)((int)this + 0x25c),-0x18614,0x23,0);
            return;
          }
          iVar4 = *(int *)((int)param_2 + 0x94) + -1;
          *(int *)((int)param_2 + 0x94) = iVar4;
          if (iVar4 != 0) {
            return;
          }
          FUN_0050d200(param_2,-1);
          FUN_005090e0((int)param_2);
          *(int *)((int)param_2 + 0x98) = *(int *)((int)param_2 + 0x98) + -1;
        }
        FUN_0050e890(param_2,5);
      }
      break;
    case 0x25:
      if (*(int *)((int)param_2 + 0x30) == 0x12) {
        FUN_00507a80((int)param_2);
        return;
      }
    }
  }
  return;
}

