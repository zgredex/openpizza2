// rea decompile_all
// name: FUN_00481870
// address: 0x481870
// body: available
// range: 0x481870-0x481cf9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00481870(void *this,void *param_1,int param_2,int param_3,int *param_4)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  switch(param_3) {
  case 6:
  case 9:
    iVar4 = *(int *)((int)this + 0x290);
    *(undefined4 *)((int)this + 0x21c) = 0;
    *(undefined4 *)((int)this + 0x2da8) = 1;
    if (iVar4 == 4) {
      UI_SubtractOrigin(param_1,param_4,param_4 + 1);
      param_3 = 0;
      iVar4 = -1;
      iVar2 = Get_FieldF0((int)param_1);
      param_2 = 0;
      if (iVar2 < 1) {
        return;
      }
      do {
        iVar7 = Array_GetPair8(param_1,param_2,&local_8);
        if (local_8 != 99999) {
          FUN_00531b90(param_1,local_8,&local_4);
          iVar3 = Record_GetValue48(*(void **)((int)this + 0xa4),local_4);
          if ((iVar3 < 8) &&
             ((iVar6 = *param_4 - *(int *)(iVar7 + 0x38),
              iVar3 = param_4[1] - *(int *)(iVar7 + 0x3c), iVar3 = iVar3 * iVar3 + iVar6 * iVar6,
              iVar4 == -1 || (iVar3 < param_3)))) {
            iVar4 = *(int *)(iVar7 + 4);
            param_3 = iVar3;
          }
        }
        param_2 = param_2 + 1;
      } while (param_2 < iVar2);
      if (iVar4 == -1) {
        return;
      }
      iVar7 = IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
      iVar2 = *(int *)(iVar7 + 0xfc0);
      iVar3 = 0;
      param_4 = (int *)0xffffffff;
      if (0 < iVar2) {
        do {
          iVar6 = IDMap_Lookup((void *)(iVar7 + 0xfac),iVar3,(int *)0x0);
          if ((iVar6 != 0) && (*(int *)(iVar6 + 0x54) == iVar4)) {
            param_4 = *(int **)(iVar6 + 0x2c);
            iVar4 = *(int *)(iVar6 + 8);
            break;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar2);
      }
      if (iVar3 == iVar2) {
        return;
      }
      if (param_4 == (int *)0xffffffff) {
        return;
      }
      uVar5 = FUN_00489820(this,iVar4,(int)param_4);
      *(undefined4 *)((int)this + 0x9c) = uVar5;
      FUN_00547e70(DAT_0057ba0c);
      iVar2 = Game_GetCurrentPlayerCompanyName((int)this);
      if (iVar4 == iVar2) {
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
      }
      else {
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
      }
      *(undefined4 *)((int)this + 0x2a8) = 1;
      FUN_004850a0(this,4,0);
      return;
    }
    *(undefined4 *)((int)this + 0x2d98) = 3;
    if (((iVar4 == 5) || (iVar4 == 7)) || (iVar4 == 6)) {
      FUN_004850a0(this,1,0);
    }
    FUN_00481d30(this,0);
  case 8:
    if ((*(int *)((int)this + 0x2d98) == 3) || (param_3 == 6)) {
      local_c = *param_4;
      local_10 = param_4[1];
      iVar4 = IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
      pvVar1 = *(void **)(iVar4 + 0xfa8);
      iVar4 = *(int *)((int)pvVar1 + 0x2c);
      iVar2 = *(int *)((int)pvVar1 + 0x30);
      iVar3 = *(int *)((int)pvVar1 + 0x34) + DAT_00571950;
      iVar7 = *(int *)((int)pvVar1 + 0x38) + DAT_00571954;
      UI_SubtractOrigin(param_1,&local_c,&local_10);
      iVar7 = (iVar7 - iVar2) * local_10;
      iVar3 = (iVar3 - iVar4) * local_c;
      FUN_0048b8a0(this,pvVar1,
                   (((int)(iVar3 + (iVar3 >> 0x1f & 0x7fU)) >> 7) - (DAT_00571950 >> 1)) + iVar4,
                   (((int)(iVar7 + (iVar7 >> 0x1f & 0x7fU)) >> 7) - (DAT_00571954 >> 1)) + iVar2);
      return;
    }
    break;
  case 7:
  case 10:
    *(undefined4 *)((int)this + 0x2d98) = 0;
    FUN_00481d30(this,1);
    break;
  case 0x1b:
    iVar2 = IDMap_Lookup((void *)((int)this + 4),*(int *)((int)this + 0x2f4),(int *)0x0);
    iVar4 = *(int *)(iVar2 + 0xfc0);
    iVar7 = 0;
    if (0 < iVar4) {
      do {
        iVar3 = IDMap_Lookup((void *)(iVar2 + 0xfac),iVar7,(int *)0x0);
        if ((iVar3 != 0) && (*(int *)(iVar3 + 0x54) == param_2)) {
          iVar6 = *(int *)((int)this + 0x290);
          *(undefined4 *)((int)this + 0x21c) = 0;
          *(undefined4 *)((int)this + 0x2da8) = 1;
          if (iVar6 == 4) {
            if ((*(int *)(iVar3 + 0x2c) != -1) && (*(int *)(iVar3 + 4) == 0xf)) {
              iVar4 = FUN_00489820(this,*(int *)(iVar3 + 8),*(int *)(iVar3 + 0x2c));
              *(int *)((int)this + 0x9c) = iVar4;
              FUN_00547e70(DAT_0057ba0c);
              iVar4 = *(int *)(iVar4 + 0x30);
              iVar2 = Game_GetCurrentPlayerCompanyName((int)this);
              if (iVar4 == iVar2) {
                *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
              }
              else {
                *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
              }
              *(undefined4 *)((int)this + 0x2a8) = 1;
              FUN_004850a0(this,4,0);
              return;
            }
            *(int *)((int)this + 0x218) = iVar3;
            FUN_004d23b0(iVar3);
            if (*(int *)(iVar3 + 4) == 0x1c) {
              iVar4 = *(int *)(iVar3 + 8);
              iVar2 = Game_GetCurrentPlayerCompanyName((int)this);
              if (iVar4 == iVar2) {
                FUN_004850a0(this,2,1);
                return;
              }
            }
            else if (*(int *)(iVar3 + 4) == 0x19) {
              FUN_004850a0(this,3,1);
              return;
            }
            FUN_004850a0(this,1,1);
            return;
          }
          if (((iVar6 == 1) || (iVar6 == 2)) || (iVar6 == 3)) {
            *(undefined4 *)((int)this + 0x218) = 0;
            FUN_004a9320(iVar3,0);
            *(int *)((int)this + 0x218) = iVar3;
            FUN_004d23b0(iVar3);
          }
          else {
            *(int *)((int)this + 0x218) = iVar3;
            FUN_004d23b0(iVar3);
            FUN_004850a0(this,1,1);
          }
        }
        iVar7 = iVar7 + 1;
        if (iVar4 <= iVar7) {
          return;
        }
      } while( true );
    }
  }
  return;
}

