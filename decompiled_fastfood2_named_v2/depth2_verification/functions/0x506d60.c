// rea decompile_all
// name: FUN_00506d60
// address: 0x506d60
// body: available
// range: 0x506d60-0x50712c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00506d60(void *this,int param_1)

{
  undefined1 uVar1;
  void *this_00;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  
  this_00 = (void *)FUN_00489820(DAT_0057c670,*(int *)(*(int *)((int)this + 0xf4) + 8),
                                 *(int *)(*(int *)((int)this + 0xf4) + 0x2c));
  if ((param_1 % 10 == 0) && (0 < *(int *)((int)this + 0x44))) {
    *(int *)((int)this + 0x44) = *(int *)((int)this + 0x44) + -1;
  }
  iVar5 = *(int *)((int)this + 0x30);
  if ((((-1 < iVar5) && (iVar5 < 8)) || (iVar5 == 0xb)) || ((iVar5 == 0xf || (iVar5 == 0x21)))) {
    switch(*(undefined2 *)((int)this + 0x40)) {
    case 2:
      if (*(int *)((int)this + 0x44) == 0) {
        FUN_00507550(this,3);
        *(short *)((int)this_00 + 0x16d2) = *(short *)((int)this_00 + 0x16d2) + 1;
        FUN_00504a90(this,7);
        FUN_0050e890(this,9);
        FUN_005090e0((int)this);
        FUN_005094a0(this,(int)this_00,0x14);
        *(undefined4 *)((int)this + *(int *)((int)this_00 + 0x30) * 4 + 0xac) = 0x14;
        iVar5 = *(int *)((int)this_00 + 0x30);
        iVar3 = FUN_00482820((int)DAT_0057c670);
        if (iVar5 == iVar3) {
          FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,1);
          FUN_00503180(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,0x14);
          return;
        }
      }
      else {
        lVar6 = FUN_00403850((float)*(int *)((int)this + 0x44) /
                             ((float)*(int *)((int)this + 0x48) * 0.0625));
        iVar5 = 0x4f - (int)lVar6;
        if (0x4e < iVar5) {
          iVar5 = 0x4e;
        }
        FUN_005078b0(this,iVar5);
        uVar1 = FUN_0047e470(this_00,0x28);
        if (CONCAT31(extraout_var,uVar1) == 0) {
          FUN_005090e0((int)this);
          FUN_0050e890(this,9);
          FUN_00507550(this,0xffff);
          return;
        }
      }
      break;
    case 3:
    case 8:
    case 0xb:
      if (*(int *)((int)this + 0x44) == 0) {
        FUN_00507550(this,0xffff);
        return;
      }
      break;
    case 5:
      if (*(int *)((int)this + 0x44) == 0) {
        FUN_00507550(this,6);
        *(short *)((int)this_00 + 0x16d2) = *(short *)((int)this_00 + 0x16d2) + 1;
        FUN_005090e0((int)this);
        FUN_00504a90(this,7);
        FUN_0050e890(this,9);
        FUN_005094a0(this,(int)this_00,0x14);
        *(undefined4 *)((int)this + *(int *)((int)this_00 + 0x30) * 4 + 0xac) = 0x14;
        iVar5 = *(int *)((int)this_00 + 0x30);
        iVar3 = FUN_00482820((int)DAT_0057c670);
        if (iVar5 == iVar3) {
          FUN_00503250(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,1);
          FUN_00503180(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,0x14);
          return;
        }
      }
      else {
        lVar6 = FUN_00403850((float)*(int *)((int)this + 0x44) /
                             ((float)*(int *)((int)this + 0x48) * 0.0625));
        iVar5 = 0x60 - (int)lVar6;
        if (0x5f < iVar5) {
          iVar5 = 0x5f;
        }
        FUN_005078b0(this,iVar5);
        uVar1 = FUN_0047e470(this_00,0xf);
        if (CONCAT31(extraout_var_00,uVar1) == 0) {
          FUN_005090e0((int)this);
          FUN_00507550(this,0xffff);
          FUN_0050e890(this,9);
          return;
        }
      }
      break;
    case 9:
      if (*(int *)((int)this + 0x44) == 0) {
        piVar2 = (int *)Game_ApplyObjectEvent((int)this);
        if ((*(int *)((int)this + 0x30) == 0xb) &&
           (iVar5 = *(int *)((int)this + 0x98), iVar3 = FUN_00489b10((int)DAT_0057c670),
           iVar3 - iVar5 < 0x18)) {
          FUN_0050e890(this,0xd);
          FUN_005090e0((int)this);
          FUN_00507550(this,2);
          FUN_00504a90(this,3);
          FUN_00509060(this,*(int *)((int)this + 0x84) + 0x10);
          return;
        }
        FUN_0050e890(this,9);
        FUN_005090e0((int)this);
        FUN_00507550(this,8);
        FUN_00504a90(this,5);
      }
      else {
        lVar6 = FUN_00403850((float)*(int *)((int)this + 0x44) /
                             ((float)*(int *)((int)this + 0x48) * 0.11111111));
        iVar5 = 9 - (int)lVar6;
        if (8 < iVar5) {
          iVar5 = 8;
        }
        piVar2 = (int *)FUN_004ee640(*(void **)((int)this + 0xc4),*(int *)((int)this + 200),
                                     *(int *)((int)this + 0x88));
        cVar4 = (char)iVar5;
        switch(*(undefined4 *)(*(int *)((int)this + 200) + 0xc)) {
        case 0x14:
          *(char *)(piVar2[2] + 0x2c) = cVar4 + '(';
          break;
        case 0x15:
          *(char *)(piVar2[2] + 0x2d) = cVar4 + '\x1e';
          break;
        case 0x16:
          *(char *)(piVar2[2] + 0x2e) = cVar4 + '\x14';
          break;
        case 0x17:
          *(char *)(piVar2[2] + 0x2f) = cVar4 + '\n';
        }
      }
      if (piVar2 != (int *)0x0) {
        UI_DrawCenteredSelectionRect(*(void **)((int)this + 0xc4),piVar2);
      }
    }
  }
  return;
}

