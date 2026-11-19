// rea decompile_all
// name: FUN_004daaf0
// address: 0x4daaf0
// body: available
// range: 0x4daaf0-0x4dae23 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004daaf0(void *this,int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *this_00;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int local_10;
  
  if (param_1 == -1) {
    puVar8 = FUN_004d59c0(this,-1,0,'\x01');
    iVar1 = puVar8[5];
    do {
      piVar3 = (int *)0x0;
      uVar2 = FUN_004034d0(0,iVar1 - 1);
      pvVar4 = (void *)FUN_004017f0(puVar8,uVar2,piVar3);
      pvVar6 = (void *)FUN_004da880(this,'\x01');
      iVar5 = FUN_004d74c0(this,(int)pvVar6,(int)pvVar4,'\0');
    } while (iVar5 == 0);
    iVar1 = *(int *)(iVar5 + 0x48);
    if ((-1 < iVar1) && (iVar1 < 4)) {
      iVar1 = *(int *)(&DAT_00568188 + iVar1 * 4);
    }
    iVar7 = *(int *)((int)pvVar4 + 0x48);
    if ((-1 < iVar7) && (iVar7 < 4)) {
      iVar7 = *(int *)(&DAT_00568188 + iVar7 * 4);
    }
    FUN_004d77b0(this,pvVar4,5,-1,pvVar6,iVar7 + (*(int *)(iVar5 + 0x20) - iVar1));
    if (puVar8 != (undefined4 *)0x0) {
      (**(code **)*puVar8)(1);
    }
  }
  else {
    iVar1 = FUN_00488be0(DAT_0057c670,param_1);
    if (*(int *)(iVar1 + 0x15c) != 0) {
      uVar2 = FUN_004034d0(0,*(int *)(iVar1 + 0x15c) - 1);
      iVar1 = FUN_004017f0((void *)(iVar1 + 0x148),uVar2,(int *)0x0);
      iVar1 = FUN_004f0cc0(*(void **)((int)this + 0xfa8),1,*(int *)(*(int *)(iVar1 + 0x16f0) + 0x54)
                          );
      this_00 = FUN_004d8470(this,*(undefined4 *)((int)this + 0xfa8),-1,iVar1,0xb4,1);
      puVar8 = (undefined4 *)this_00[5];
      if (puVar8 == (undefined4 *)0x0) {
        if (this_00 != (undefined4 *)0x0) {
          (**(code **)*this_00)(1);
          return;
        }
      }
      else {
        DAT_0057dfb8 = operator_new((int)puVar8 * 4);
        piVar3 = operator_new((int)puVar8 * 4);
        iVar1 = 0;
        if (0 < (int)puVar8) {
          do {
            iVar1 = iVar1 + 1;
            *(undefined4 *)((int)DAT_0057dfb8 + iVar1 * 4 + -4) = 0;
          } while (iVar1 < (int)puVar8);
        }
        iVar1 = 0;
        if (0 < (int)puVar8) {
          piVar9 = piVar3;
          do {
            *piVar9 = iVar1;
            iVar1 = iVar1 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar1 < (int)puVar8);
        }
        local_10 = 0;
        if (0 < *(int *)((int)DAT_0057c670 + 0x50)) {
          do {
            pvVar4 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 0x3c),local_10,(int *)0x0);
            if ((*(int *)((int)pvVar4 + 0x30) < 8) && (iVar1 = 0, 0 < (int)puVar8)) {
              do {
                iVar5 = FUN_004017f0(this_00,iVar1,(int *)0x0);
                piVar9 = (int *)((int)DAT_0057dfb8 + iVar1 * 4);
                iVar5 = FUN_0050e200(pvVar4,iVar5);
                iVar1 = iVar1 + 1;
                *piVar9 = *piVar9 + iVar5;
              } while (iVar1 < (int)puVar8);
            }
            local_10 = local_10 + 1;
          } while (local_10 < *(int *)((int)DAT_0057c670 + 0x50));
        }
        if (param_2 == 0) {
          FUN_0054ea8f(piVar3,puVar8,4,&LAB_004dae30);
          pvVar4 = (void *)FUN_004017f0(this_00,*piVar3,(int *)0x0);
          iVar5 = FUN_004d74c0(this,0,0,'\0');
          iVar1 = *(int *)(iVar5 + 0x48);
          if ((-1 < iVar1) && (iVar1 < 4)) {
            iVar1 = *(int *)(&DAT_00568188 + iVar1 * 4);
          }
          iVar7 = *(int *)((int)pvVar4 + 0x48);
          if ((-1 < iVar7) && (iVar7 < 4)) {
            iVar7 = *(int *)(&DAT_00568188 + iVar7 * 4);
          }
          FUN_004d77b0(this,pvVar4,5,-1,(void *)0x0,iVar7 + (*(int *)(iVar5 + 0x20) - iVar1));
          piVar9 = (int *)((int)this + param_1 * 4 + 0xd28);
          *piVar9 = *piVar9 + 1;
        }
        else {
          FUN_0054ea8f(piVar3,puVar8,4,&LAB_004dae60);
          pvVar4 = (void *)FUN_004017f0(this_00,*piVar3,(int *)0x0);
          pvVar6 = (void *)FUN_004da880(this,'\0');
          iVar5 = FUN_004d74c0(this,(int)pvVar6,0,'\0');
          iVar1 = *(int *)(iVar5 + 0x48);
          if ((-1 < iVar1) && (iVar1 < 4)) {
            iVar1 = *(int *)(&DAT_00568188 + iVar1 * 4);
          }
          iVar7 = *(int *)((int)pvVar4 + 0x48);
          if ((-1 < iVar7) && (iVar7 < 4)) {
            iVar7 = *(int *)(&DAT_00568188 + iVar7 * 4);
          }
          FUN_004d77b0(this,pvVar4,5,-1,pvVar6,iVar7 + (*(int *)(iVar5 + 0x20) - iVar1));
          piVar9 = (int *)((int)this + param_1 * 4 + 0xd28);
          *piVar9 = *piVar9 + 1;
        }
        FUN_0054dd78(piVar3);
        FUN_0054dd78(DAT_0057dfb8);
        if (this_00 != (undefined4 *)0x0) {
          (**(code **)*this_00)(1);
          return;
        }
      }
    }
  }
  return;
}

