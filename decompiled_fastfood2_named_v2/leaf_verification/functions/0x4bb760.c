// rea decompile_all
// name: FUN_004bb760
// address: 0x4bb760
// body: available
// range: 0x4bb760-0x4bbd49 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004bb760(void *param_1)

{
  char cVar1;
  void *this;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  uint uVar5;
  void *this_00;
  int iVar6;
  char *pcVar7;
  undefined4 unaff_EDI;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  undefined4 uVar11;
  int *local_88;
  int *local_84;
  char local_80 [128];
  
  iVar6 = *(int *)((int)DAT_0057c670 + 0x21c);
  this_00 = (void *)0x0;
  local_84 = (int *)0x0;
  if (*(int *)(iVar6 + 0x30) == 0x16) {
    local_88 = operator_new(8);
    local_88[1] = 0x16;
    iVar9 = 0x16;
    local_84 = local_88;
  }
  else {
    this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)(iVar6 + 0x110));
    local_88 = FUN_004e1f70(this_00,iVar6);
    iVar9 = *(int *)(iVar6 + 0x30);
  }
  FUN_005499f0(DAT_0057ba0c,iVar9,0,'\x01');
  FUN_005316f0(param_1,0x1f6f,(uint)(local_88[1] == 0x16));
  FUN_005316f0(param_1,0x1f66,(uint)(local_88[1] == 0x1e));
  FUN_005316f0(param_1,0x1f67,(uint)(local_88[1] == 0x1f));
  FUN_005316f0(param_1,0x1f65,(uint)(local_88[1] == 0x1d));
  FUN_0052fd70(param_1,0x1f41,*(undefined4 *)(iVar6 + 0xa8),0);
  if (*(int *)(iVar6 + 0xa4) != -1) {
    if (*(int *)(iVar6 + 0x74) == 0) {
      iVar9 = 0x1f68;
      do {
        FUN_00531740(param_1,iVar9);
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0x1f6e);
    }
    else {
      FUN_0052f080(param_1,0x1f6a,&DAT_005683a4,1000);
      this = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
      iVar9 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
      iVar9 = FUN_004da760(this,iVar9);
      FUN_0052f080(param_1,0x1f6b,(byte *)s__d____00568834,iVar9);
    }
    iVar9 = *(int *)(iVar6 + 0xfc);
    switch(local_88[1]) {
    case 0x16:
      iVar9 = FUN_00489820(DAT_0057c670,*(int *)(iVar9 + 8),*(int *)(iVar9 + 0x2c));
      if (*(int *)(iVar6 + 0xa4) == 2) {
        pbVar10 = DAT_00582b3c;
      }
      else {
        pbVar10 = DAT_00582b34;
      }
      FUN_0054dd83(local_80,pbVar10,iVar9 + 4);
      FUN_0052f9b0(param_1,0x1f44,local_80);
      uVar11 = DAT_00581ad4;
      break;
    default:
      goto switchD_004bb89c_caseD_17;
    case 0x1d:
      if (*(int *)(iVar9 + 4) == 0xf) {
        iVar9 = FUN_00489820(DAT_0057c670,*(int *)(iVar9 + 8),*(int *)(iVar9 + 0x2c));
        if (*(int *)(iVar6 + 0xa4) != 0x10) {
          pbVar10 = DAT_00580b50;
          goto LAB_004bba80;
        }
        FUN_0054dd83(local_80,DAT_00582f30,iVar9 + 4);
      }
      else {
        pbVar10 = DAT_005810b0;
LAB_004bba80:
        FUN_0054dd83(local_80,pbVar10,unaff_EDI);
      }
      FUN_0052f9b0(param_1,0x1f44,local_80);
      uVar11 = DAT_00582eec;
      break;
    case 0x1e:
      iVar9 = FUN_00489820(DAT_0057c670,*(int *)(iVar9 + 8),*(int *)(iVar9 + 0x2c));
      if (*(int *)(iVar6 + 0xa4) == 0xf) {
        FUN_0054dd83(local_80,DAT_00581ffc,iVar9 + 4);
      }
      else {
        FUN_0054dd83(local_80,DAT_00580f50,unaff_EDI);
      }
      FUN_0052f9b0(param_1,0x1f44,local_80);
      goto switchD_004bb89c_caseD_1e;
    case 0x1f:
      iVar2 = FUN_00489820(DAT_0057c670,*(int *)(iVar9 + 8),*(int *)(iVar9 + 0x2c));
      iVar6 = *(int *)(iVar6 + 0xa4);
      if (iVar6 == 5) {
        FUN_0054dd83(local_80,DAT_00581bb8,unaff_EDI);
      }
      else {
        if (iVar6 == 0x11) {
          if (iVar2 == 0) {
LAB_004bbaf5:
            uVar4 = 0xffffffff;
            pcVar7 = &DAT_00579aec;
            do {
              pcVar8 = pcVar7;
              if (uVar4 == 0) break;
              uVar4 = uVar4 - 1;
              pcVar8 = pcVar7 + 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar8;
            } while (cVar1 != '\0');
            uVar4 = ~uVar4;
            pcVar7 = pcVar8 + -uVar4;
            pcVar8 = local_80;
            for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
              pcVar7 = pcVar7 + 4;
              pcVar8 = pcVar8 + 4;
            }
            for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
              *pcVar8 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              pcVar8 = pcVar8 + 1;
            }
            goto LAB_004bbb61;
          }
          iVar2 = iVar2 + 4;
          pbVar10 = DAT_00581bc4;
        }
        else if (iVar6 == 0x1d) {
          iVar6 = FUN_00489850(DAT_0057c670,*(int *)(iVar9 + 8),*(int *)(iVar9 + 0x2c));
          if (iVar6 == 0) goto LAB_004bbaf5;
          iVar2 = Get_Subobject4(iVar6);
          pbVar10 = DAT_00581b98;
        }
        else {
          iVar2 = iVar2 + 4;
          pbVar10 = DAT_00581b90;
        }
        FUN_0054dd83(local_80,pbVar10,iVar2);
      }
LAB_004bbb61:
      FUN_0052f9b0(param_1,0x1f44,local_80);
      uVar11 = DAT_00582418;
    }
    goto LAB_004bbb79;
  }
  FUN_0052f9b0(param_1,0x1f44,DAT_00580b7c);
  iVar6 = 0x1f68;
  do {
    FUN_00531740(param_1,iVar6);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x1f6e);
  switch(local_88[1]) {
  case 0x16:
    uVar11 = DAT_00581ad4;
    break;
  default:
    goto switchD_004bb89c_caseD_17;
  case 0x1d:
    uVar11 = DAT_00582eec;
    break;
  case 0x1e:
switchD_004bb89c_caseD_1e:
    uVar11 = DAT_00582dd0;
    break;
  case 0x1f:
    uVar11 = DAT_00582418;
  }
LAB_004bbb79:
  FUN_0052f9b0(param_1,0x48f,uVar11);
switchD_004bb89c_caseD_17:
  if (this_00 == (void *)0x0) {
    FUN_0052f9b0(param_1,0x1f5b,DAT_00582e4c);
    FUN_00531740(param_1,0x1f6e);
    FUN_00531740(param_1,0x1f5c);
    FUN_00531740(param_1,0x1f5a);
  }
  else {
    FUN_0052f9b0(param_1,0x1f5b,(int)this_00 + 8);
    FUN_004a66d0(param_1,0x1f6e,(int)this_00);
  }
  switch(local_88[1]) {
  case 0x16:
  case 0x1f:
    FUN_0052f080(param_1,0x1f61,&DAT_005686f4,1);
    FUN_0052f080(param_1,0x1f47,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f46,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f48,&DAT_005686f4,0);
  default:
    goto switchD_004bbbfb_caseD_17;
  case 0x1d:
    FUN_0052f080(param_1,0x1f61,(byte *)s__s__d_00568964,DAT_00581044);
    puVar3 = Economy_GetModifier(this_00,0x1d,0);
    FUN_0052f080(param_1,0x1f47,&DAT_005686f4,puVar3);
    puVar3 = Economy_GetModifier(this_00,0x1d,1);
    FUN_0052f080(param_1,0x1f46,&DAT_005686f4,puVar3);
    iVar6 = 0x1d;
    break;
  case 0x1e:
    FUN_0052f080(param_1,0x1f61,(byte *)s__s__d_00568964,DAT_00581044);
    puVar3 = Economy_GetModifier(this_00,0x1e,0);
    FUN_0052f080(param_1,0x1f47,&DAT_005686f4,puVar3);
    puVar3 = Economy_GetModifier(this_00,0x1e,1);
    FUN_0052f080(param_1,0x1f46,&DAT_005686f4,puVar3);
    iVar6 = 0x1e;
  }
  puVar3 = Economy_GetModifier(this_00,iVar6,2);
  FUN_0052f080(param_1,0x1f48,&DAT_005686f4,puVar3);
switchD_004bbbfb_caseD_17:
  if (local_84 != (int *)0x0) {
    FUN_0054dd78(local_84);
  }
  return;
}

