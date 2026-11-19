// rea decompile_all
// name: FUN_004ee840
// address: 0x4ee840
// body: available
// range: 0x4ee840-0x4eeee7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004ee840(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int yTop;
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  uint local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  uint local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  
  if ((DAT_00580a50 != 2) &&
     (piVar4 = *(int **)(*(int *)(param_2 + 8) + 0x20), piVar4 != (int *)0x0)) {
    do {
      FUN_00534370((void *)piVar4[0x16],*piVar4,&local_64,&local_60);
      if ((*(byte *)(piVar4 + 4) & 1) == 0) {
        if (param_1 == 0) {
          if (param_3 == 1) {
            *(undefined4 *)((int)this + 0xac) = 0xffff;
          }
          else {
            *(undefined4 *)((int)this + 0xac) = 0;
          }
          pvVar1 = (void *)piVar4[0x16];
          if (pvVar1 == *(void **)(*(int *)((int)this + 4) + 0x2c3cc)) {
            local_4c = *(int *)((int)this + 0x24);
            iVar2 = *piVar4;
            puVar5 = *(uint **)((int)this + 8);
LAB_004eec4b:
            local_4c = local_64 - local_4c;
            Record_DrawSprite48(pvVar1,puVar5,DAT_0058072c,iVar2);
          }
          else if (piVar4[0x1d] == 0) {
            if (param_3 == 0) {
              local_4c = local_64 - *(int *)((int)this + 0x24);
              Record_DrawSprite48(pvVar1,*(uint **)((int)this + 8),DAT_0058072c,*piVar4);
              pvVar1 = *(void **)(*(int *)((int)this + 4) + 0x2c180 +
                                 *(int *)(piVar4[0x1e] + 0xc) * 4);
              if (pvVar1 != (void *)0x0) {
                iVar2 = FUN_00534960((void *)piVar4[0x16],*piVar4);
                FUN_00534990(pvVar1,*(int *)(piVar4[0x1e] + 0x10),iVar2);
                local_4c = local_64 - *(int *)((int)this + 0x24);
                FUN_005346a0(pvVar1,*(int *)((int)this + 8),DAT_0058072c,
                             *(int *)(piVar4[0x1e] + 0x10));
              }
            }
          }
          else if (DAT_00580a50 == 0) {
            local_4c = local_64 - *(int *)((int)this + 0x24);
            Record_DrawSprite48(pvVar1,*(uint **)((int)this + 8),DAT_0058072c,*piVar4);
            if ((param_3 == 0) && (DAT_00580730 != (void *)0x0)) {
              Sprite_BlitOwnedRLE(DAT_00580730,*(void **)((int)this + 8),
                                  (*(int *)((int)this + 0xf8) - *(int *)((int)this + 0x24)) + -0x40
                                  + local_64,
                                  (*(int *)((int)this + 0xfc) - *(int *)((int)this + 0x28)) + -0x4d
                                  + local_60);
            }
          }
          else if ((DAT_00580a50 == 1) && (param_3 == 0)) {
            local_4c = *(int *)((int)this + 0x24);
            iVar2 = *piVar4;
            puVar5 = *(uint **)((int)this + 8);
            goto LAB_004eec4b;
          }
        }
        else {
          FUN_00534060((void *)piVar4[0x16],*piVar4,&local_48,&local_44,&local_5c,&local_58);
          FUN_005340d0((void *)piVar4[0x16],*piVar4,(int *)&local_5c,(int *)&local_58);
          local_38 = local_5c + local_64;
          local_30 = local_38 + local_48;
          local_34 = local_58 + local_60;
          local_2c = local_34 + local_44;
          if (piVar4[0x1d] == 0) {
            pvVar1 = *(void **)(*(int *)((int)this + 4) + 0x2c180 + *(int *)(piVar4[0x1e] + 0xc) * 4
                               );
            if (pvVar1 != (void *)0x0) {
              iVar2 = FUN_00534960((void *)piVar4[0x16],*piVar4);
              FUN_00534990(pvVar1,*(int *)(piVar4[0x1e] + 0x10),iVar2);
              FUN_00534060(pvVar1,*(int *)(piVar4[0x1e] + 0x10),&local_48,&local_44,&local_5c,
                           &local_58);
              FUN_005340d0(pvVar1,*(int *)(piVar4[0x1e] + 0x10),(int *)&local_5c,(int *)&local_58);
              uVar3 = local_64 + local_5c;
              iVar2 = local_58 + local_60;
              if ((int)uVar3 < (int)local_38) {
                local_38 = uVar3;
              }
              if (local_30 < (int)(local_48 + uVar3)) {
                local_30 = local_48 + uVar3;
              }
              if (iVar2 < local_34) {
                local_34 = iVar2;
              }
              if (local_2c < local_44 + iVar2) {
                local_2c = local_44 + iVar2;
              }
            }
          }
          else {
            iVar2 = (*(int *)((int)this + 0xf8) - *(int *)((int)this + 0x24)) + -7 + local_64;
            yTop = (*(int *)((int)this + 0xfc) - *(int *)((int)this + 0x28)) + -6 + local_60;
            SetRect(&local_18,iVar2,yTop,iVar2 + 0x20,yTop + 0xc);
            FUN_00534e20(DAT_0058072c,(uint *)&local_18);
          }
        }
      }
      if ((((short)piVar4[2] == -1) || ((short)piVar4[2] == 0)) ||
         ((*(byte *)(piVar4 + 4) & 1) != 0)) {
LAB_004eee19:
        uVar3 = local_38;
        if (param_1 != 0) {
          local_24 = local_34;
          local_20 = local_30;
          if (local_30 < piVar4[0x19]) {
            local_30 = piVar4[0x19];
          }
          iVar2 = local_2c;
          if (local_2c < piVar4[0x1a]) {
            iVar2 = piVar4[0x1a];
          }
          if (piVar4[0x17] < (int)local_38) {
            local_38 = piVar4[0x17];
          }
          if (piVar4[0x18] < local_34) {
            local_34 = piVar4[0x18];
          }
          local_38 = local_38 - *(int *)((int)this + 0x24);
          local_30 = local_30 - *(int *)((int)this + 0x24);
          local_34 = local_34 - *(int *)((int)this + 0x28);
          local_1c = local_2c;
          local_2c = iVar2 - *(int *)((int)this + 0x28);
          FUN_00534e20(DAT_0058072c,&local_38);
          piVar4[0x17] = uVar3;
          piVar4[0x18] = local_24;
          piVar4[0x19] = local_20;
          piVar4[0x1a] = local_1c;
        }
      }
      else {
        local_4c = local_64 - *(int *)((int)this + 0x24);
        local_54 = local_60 - *(int *)((int)this + 0x28);
        FUN_00534790((void *)piVar4[0x16],*piVar4,&local_4c,&local_54);
        pvVar1 = *(void **)(*(int *)((int)this + 4) + 0x2c3b4);
        FUN_00534990(pvVar1,piVar4[1],(int)(short)piVar4[2]);
        FUN_00533540(pvVar1,&local_40,&local_50);
        if (param_1 != 0) {
          local_64 = (local_4c - ((int)local_40 >> 2)) + *(int *)((int)this + 0x24);
          local_60 = (*(int *)((int)this + 0x28) - local_50) + -3 + local_54;
          if ((int)local_64 < (int)local_38) {
            local_38 = local_64;
          }
          if (local_30 < (int)(local_40 + local_64)) {
            local_30 = local_40 + local_64;
          }
          if (local_60 < local_34) {
            local_34 = local_60;
          }
          if (local_2c < (int)(local_50 + local_60)) {
            local_2c = local_50 + local_60;
          }
          goto LAB_004eee19;
        }
        local_3c = local_4c - ((int)local_40 >> 2);
        *(undefined4 *)((int)this + 0xac) = 0xffffff;
        Record_DrawSprite48(pvVar1,*(uint **)((int)this + 8),DAT_0058072c,piVar4[1]);
        if (*(short *)((int)piVar4 + 10) != -1) {
          FUN_00534990(pvVar1,piVar4[1],(int)*(short *)((int)piVar4 + 10));
          local_3c = local_4c - ((int)local_40 >> 2);
          Record_DrawSprite48(pvVar1,*(uint **)((int)this + 8),DAT_0058072c,piVar4[1]);
        }
      }
      piVar4 = (int *)piVar4[0x1b];
    } while (piVar4 != (int *)0x0);
    if (param_4 != 0) {
      *(undefined4 *)(*(int *)(param_2 + 8) + 0x20) = 0;
    }
  }
  return;
}

