// rea decompile_all
// name: FUN_004be9e0
// address: 0x4be9e0
// body: available
// range: 0x4be9e0-0x4befc5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004be9e0(void *param_1)

{
  char cVar1;
  void *this;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined4 unaff_EDI;
  char *pcVar12;
  char local_80 [128];
  
  iVar4 = *(int *)((int)DAT_0057c670 + 0x21c);
  this = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  piVar2 = FUN_004e1f70(this,iVar4);
  FUN_005316f0(param_1,0x1f5e,(uint)(piVar2[1] == 0x16));
  FUN_005316f0(param_1,0x470,(uint)(piVar2[1] == 0x1e));
  FUN_005316f0(param_1,0x1f5a,(uint)(piVar2[1] == 0x1f));
  FUN_005316f0(param_1,0x46d,(uint)(piVar2[1] == 0x1d));
  FUN_0052fd70(param_1,0x1f41,*(undefined4 *)(iVar4 + 0xa8),0);
  if (*(int *)(iVar4 + 0xa4) == -1) {
    FUN_0052f080(param_1,0x1f44,&DAT_005630d0,DAT_00580b7c);
    UI_RemoveObjectByKey(param_1,0x483);
    UI_RemoveObjectByKey(param_1,0x484);
    UI_RemoveObjectByKey(param_1,0x477);
    FUN_0052f080(param_1,0x1f57,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f50,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f58,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f52,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f59,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f54,&DAT_005686f4,0);
    goto LAB_004bee3d;
  }
  FUN_005316b0(param_1,0x483);
  FUN_005316b0(param_1,0x484);
  FUN_005316b0(param_1,0x477);
  iVar5 = *(int *)(iVar4 + 0xfc);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a130(DAT_0057c670,-1,0x1f,iVar5,iVar3);
  FUN_0052f080(param_1,0x1f57,&DAT_005686f4,iVar3);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a090(DAT_0057c670,-1,0x1f,iVar5,iVar3);
  FUN_0052f080(param_1,0x1f50,&DAT_005686f4,iVar3);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a130(DAT_0057c670,-1,0x1e,iVar5,iVar3);
  FUN_0052f080(param_1,0x1f58,&DAT_005686f4,iVar3);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a090(DAT_0057c670,-1,0x1e,iVar5,iVar3);
  FUN_0052f080(param_1,0x1f52,&DAT_005686f4,iVar3);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a130(DAT_0057c670,-1,0x1d,iVar5,iVar3);
  FUN_0052f080(param_1,0x1f59,&DAT_005686f4,iVar3);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  iVar3 = FUN_0048a090(DAT_0057c670,-1,0x1d,iVar5,iVar3);
  FUN_0052f080(param_1,0x1f54,&DAT_005686f4,iVar3);
  iVar3 = piVar2[1];
  if (iVar3 == 0x1d) {
    if (*(int *)(iVar5 + 4) == 0xf) {
      iVar5 = FUN_00489820(DAT_0057c670,*(int *)(iVar5 + 8),*(int *)(iVar5 + 0x2c));
      if (*(int *)(iVar4 + 0xa4) == 0x10) {
        FUN_0054dd83(local_80,DAT_00582f30,iVar5 + 4);
        goto LAB_004bee2d;
      }
      pbVar9 = DAT_00580b50;
    }
    else {
      pbVar9 = DAT_005810b0;
    }
LAB_004bee20:
    FUN_0054dd83(local_80,pbVar9,unaff_EDI);
  }
  else if (iVar3 == 0x1e) {
    iVar5 = FUN_00489820(DAT_0057c670,*(int *)(iVar5 + 8),*(int *)(iVar5 + 0x2c));
    if (*(int *)(iVar4 + 0xa4) == 0xf) {
      FUN_0054dd83(local_80,DAT_00581ffc,iVar5 + 4);
    }
    else {
      FUN_0054dd83(local_80,DAT_00580f50,unaff_EDI);
    }
  }
  else {
    if (iVar3 != 0x1f) goto LAB_004bee3d;
    iVar3 = FUN_00489820(DAT_0057c670,*(int *)(iVar5 + 8),*(int *)(iVar5 + 0x2c));
    iVar4 = *(int *)(iVar4 + 0xa4);
    if (iVar4 == 5) {
      pbVar9 = DAT_00581bb8;
      goto LAB_004bee20;
    }
    if (iVar4 == 0x11) {
      pbVar9 = DAT_00581bc4;
    }
    else {
      if (iVar4 == 0x1d) {
        iVar4 = FUN_00489850(DAT_0057c670,*(int *)(iVar5 + 8),*(int *)(iVar5 + 0x2c));
        if (iVar4 == 0) {
          uVar7 = 0xffffffff;
          pcVar11 = &DAT_00579aec;
          do {
            pcVar12 = pcVar11;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar12 = pcVar11 + 1;
            cVar1 = *pcVar11;
            pcVar11 = pcVar12;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          pcVar11 = pcVar12 + -uVar7;
          pcVar12 = local_80;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
            pcVar11 = pcVar11 + 4;
            pcVar12 = pcVar12 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar12 = *pcVar11;
            pcVar11 = pcVar11 + 1;
            pcVar12 = pcVar12 + 1;
          }
        }
        else {
          iVar4 = FUN_00513fc0(iVar4);
          FUN_0054dd83(local_80,DAT_00581b98,iVar4);
        }
        goto LAB_004bee2d;
      }
      pbVar9 = DAT_00581b90;
    }
    FUN_0054dd83(local_80,pbVar9,iVar3 + 4);
  }
LAB_004bee2d:
  FUN_0052f9b0(param_1,0x1f44,local_80);
LAB_004bee3d:
  iVar4 = piVar2[1];
  if (iVar4 == 0x1d) {
    FUN_0052f080(param_1,0x1f4d,(byte *)s__s__d_00568964,DAT_00581044);
    puVar6 = FUN_004e25b0(this,0x1d,0);
    FUN_0052f080(param_1,0x1f47,&DAT_005686f4,puVar6);
    puVar6 = FUN_004e25b0(this,0x1d,1);
    FUN_0052f080(param_1,0x1f46,&DAT_005686f4,puVar6);
    puVar6 = FUN_004e25b0(this,0x1d,2);
    FUN_0052f080(param_1,0x1f48,&DAT_005686f4,puVar6);
    uVar10 = DAT_00582eec;
  }
  else if (iVar4 == 0x1e) {
    FUN_0052f080(param_1,0x1f4d,(byte *)s__s__d_00568964,DAT_00581044);
    puVar6 = FUN_004e25b0(this,0x1e,0);
    FUN_0052f080(param_1,0x1f47,&DAT_005686f4,puVar6);
    puVar6 = FUN_004e25b0(this,0x1e,1);
    FUN_0052f080(param_1,0x1f46,&DAT_005686f4,puVar6);
    puVar6 = FUN_004e25b0(this,0x1e,2);
    FUN_0052f080(param_1,0x1f48,&DAT_005686f4,puVar6);
    uVar10 = DAT_00582dd0;
  }
  else {
    if (iVar4 != 0x1f) {
      return;
    }
    FUN_0052f080(param_1,0x1f4d,&DAT_005686f4,1);
    FUN_0052f080(param_1,0x1f47,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f46,&DAT_005686f4,0);
    FUN_0052f080(param_1,0x1f48,&DAT_005686f4,0);
    uVar10 = DAT_00582418;
  }
  FUN_0052f9b0(param_1,0x48f,uVar10);
  return;
}

