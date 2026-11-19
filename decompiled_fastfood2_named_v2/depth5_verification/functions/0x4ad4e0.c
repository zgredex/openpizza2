// rea decompile_all
// name: FUN_004ad4e0
// address: 0x4ad4e0
// body: available
// range: 0x4ad4e0-0x4ad97e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ad4e0(void *param_1)

{
  uint *puVar1;
  ushort uVar2;
  float fVar3;
  void *this;
  void *pvVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_EDI;
  int iVar8;
  float10 fVar9;
  longlong lVar10;
  longlong lVar11;
  int local_88;
  int local_84;
  float local_80;
  int local_7c;
  float local_78;
  int local_74;
  uint *local_70;
  void *local_6c;
  uint local_68;
  int local_64;
  uint *local_60;
  void *local_5c;
  int local_58;
  float local_54;
  float local_50;
  void *local_4c;
  int local_48;
  int *local_44;
  undefined1 local_40 [64];
  
  pvVar4 = *(void **)(DAT_0057c670 + 0x200 + *(int *)(DAT_0057c670 + 0x2ec) * 4);
  uVar2 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uVar6 = (uint)uVar2;
  pvVar5 = (void *)0x0;
  local_6c = (void *)0x0;
  local_68 = uVar6;
  local_4c = pvVar4;
  this = (void *)FUN_00531cf0(param_1,0x86b);
  local_5c = this;
  FUN_00521380((int)this);
  if (DAT_0056951c != -1) {
    pvVar5 = (void *)FUN_004017f0((void *)((int)pvVar4 + 0x148),DAT_0056951c,(int *)0x0);
    local_6c = pvVar5;
  }
  if (uVar6 == 0) {
    FUN_00521ae0(this,&local_74,&local_84);
    pvVar4 = (void *)FUN_00521b10((int)this);
    FUN_00535520(DAT_0057d638,local_74 / 2,local_84 / 2,2);
    FUN_00535500(DAT_0057d638,0);
    FUN_00535740(DAT_0057d638,pvVar4,DAT_00581444);
    FUN_0052f9b0(param_1,0x840,DAT_00582e4c);
    FUN_0052f9b0(param_1,0x841,DAT_00582e4c);
    FUN_00521b30((int)this);
    return;
  }
  if (DAT_0057d62c < 3) {
    local_78 = 1.12104e-44;
    local_64 = 0;
    local_68 = 8;
    if (DAT_0057d62c == 0) {
      local_88 = FUN_004de0d0(pvVar4,pvVar5);
    }
    else {
      if (DAT_0057d62c != 1) {
        if (DAT_0057d62c == 2) {
          local_88 = FUN_004de670(pvVar4,(int)pvVar5);
          local_7c = 4;
        }
        goto LAB_004ad6b3;
      }
      FUN_004de300((int)pvVar4,(int)pvVar5);
      lVar10 = __ftol();
      local_88 = (int)lVar10;
    }
  }
  else {
    if (uVar2 < 0x29) {
      local_64 = 0;
      local_78 = (float)uVar6;
    }
    else {
      local_64 = uVar6 - 0x28;
      local_78 = 5.60519e-44;
    }
    if (DAT_0057d62c == 3) {
      local_88 = FUN_004de120(pvVar4,(uint)pvVar5);
    }
    else {
      if (DAT_0057d62c != 4) {
        if (DAT_0057d62c == 5) {
          FUN_004de570((int)pvVar4,(int)pvVar5);
          lVar10 = __ftol();
          local_88 = (int)lVar10;
          local_7c = 7;
        }
        goto LAB_004ad6b3;
      }
      FUN_004de360((int)pvVar4,(int)pvVar5);
      lVar10 = __ftol();
      local_88 = (int)lVar10;
    }
  }
  local_7c = 9;
LAB_004ad6b3:
  fVar3 = (float)local_88;
  FUN_00521ae0(this,&local_74,&local_84);
  local_74 = local_74 + -3;
  local_84 = local_84 + -3;
  local_50 = (float)local_74 / (float)(int)local_78;
  if (fVar3 <= 0.0) {
    FUN_0054dd83(local_40,DAT_00582e4c,unaff_EDI);
  }
  else {
    FUN_0054dd83(local_40,(byte *)s__0_2f_005685f4,SUB84((double)local_88,0));
  }
  FUN_0052f9b0(param_1,0x840,local_40);
  FUN_0054dd83(local_40,(byte *)s__d__d_00568ef8,*(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1);
  FUN_0052f9b0(param_1,0x841,local_40);
  if (fVar3 <= 0.0) {
    local_78 = 0.0;
  }
  else {
    local_78 = (float)local_84 / fVar3;
  }
  local_44 = FUN_00521bc0(this,0,3);
  local_58 = 0;
  if (0 < local_7c) {
    local_60 = &DAT_005695f4;
    do {
      iVar7 = local_58;
      local_54 = 0.0;
      fVar9 = FUN_004ad2d0(local_58,pvVar5);
      if (fVar9 <= (float10)0.0) {
        fVar9 = (float10)local_84;
      }
      else {
        fVar9 = (float10)local_84 - fVar9 * (float10)local_78;
      }
      local_70 = (uint *)(float)fVar9;
      iVar8 = local_64;
      if (local_64 < (int)local_68) {
        do {
          switch(DAT_0057d62c) {
          case 0:
            iVar7 = FUN_004de1a0(pvVar4,iVar7,iVar8,pvVar5);
            fVar9 = (float10)iVar7;
            break;
          case 1:
            fVar9 = FUN_004de280((int)pvVar4,iVar7,iVar8,(int)pvVar5);
            break;
          case 2:
            iVar7 = FUN_004de600(pvVar4,iVar7,iVar8,pvVar5);
            fVar9 = (float10)iVar7;
            break;
          case 3:
            iVar7 = FUN_004de210(pvVar4,iVar7,iVar8,pvVar5);
            fVar9 = (float10)iVar7;
            break;
          case 4:
            fVar9 = FUN_004de470((int)pvVar4,iVar7,iVar8,(int)pvVar5);
            break;
          case 5:
            fVar9 = FUN_004de4f0((int)pvVar4,iVar7,iVar8,(int)pvVar5);
            break;
          default:
            fVar9 = (float10)local_80;
          }
          local_80 = (float)(fVar9 * (float10)local_78);
          lVar10 = __ftol();
          iVar7 = local_84 - (int)lVar10;
          local_48 = iVar7;
          lVar10 = __ftol();
          puVar1 = (uint *)((int)lVar10 + 1);
          lVar10 = __ftol();
          lVar11 = __ftol();
          local_70 = (uint *)((int)lVar11 + 1);
          FUN_00521740(local_5c,local_70,(int)lVar10 + 2,puVar1,iVar7 + 2,0);
          FUN_00521740(local_5c,local_70,(int)lVar10 + 1,puVar1,iVar7 + 1,*local_60);
          local_54 = local_54 + local_50;
          iVar8 = iVar8 + 1;
          local_70 = (uint *)(float)local_48;
          pvVar5 = local_6c;
          pvVar4 = local_4c;
          iVar7 = local_58;
        } while (iVar8 < (int)local_68);
      }
      local_58 = iVar7 + 1;
      local_60 = local_60 + 1;
    } while (local_58 < local_7c);
    this = local_5c;
  }
  FUN_00521b30((int)this);
  FUN_00521da0(local_44);
  return;
}

