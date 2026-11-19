// rea decompile_all
// name: IsoMap_RenderFrame
// address: 0x4ef9e0
// body: available
// range: 0x4ef9e0-0x4f03c4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall IsoMap_RenderFrame(void *this,HWND param_1,int *param_2,uint param_3,int *param_4)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint yBottom;
  int iVar7;
  uint local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  void *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  tagRECT local_20;
  tagRECT local_10;
  
  if (0 < *(int *)((int)this + 0x154)) {
    do {
      piVar1 = (int *)IDMap_Lookup((void *)((int)this + 0x140),0,(int *)0x0);
      IsoMap_RenderViewport(this,*(void **)((int)this + 8),piVar1);
      Mem_Free(piVar1);
      IDMap_RemoveRecursive((void *)((int)this + 0x140),0);
    } while (0 < *(int *)((int)this + 0x154));
  }
  if ((*(int *)((int)this + 0x44) != 0) || (*(int *)((int)this + 0x48) != 0)) {
    *(undefined4 *)((int)this + 0xf4) = 1;
  }
  if ((*(int *)((int)this + 0x24) != *(int *)((int)this + 0xe8)) ||
     (*(int *)((int)this + 0x28) != *(int *)((int)this + 0xec))) {
    *(int *)((int)this + 0x24) = *(int *)((int)this + 0xe8);
    *(undefined4 *)((int)this + 0xf4) = 1;
    *(undefined4 *)((int)this + 0x28) = *(undefined4 *)((int)this + 0xec);
  }
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(*(int *)((int)this + 4) + 0x2f87c);
  Map_RenderVisibleObjects(this);
  piVar1 = param_2;
  if (param_2 == (int *)0x0) {
    if (param_4 == (int *)0x0) {
      GetClientRect(param_1,&local_10);
      local_2c = local_10.top;
      local_30 = local_10.left;
      local_28 = local_10.right;
      local_24 = local_10.bottom;
    }
    else {
      local_2c = param_4[1];
      local_30 = *param_4;
      local_28 = param_4[2];
      local_24 = param_4[3];
    }
  }
  else {
    if (param_3 == 0) {
      pvVar2 = Game_GetLinkedObjectExtent(this,(uint)param_2,(uint *)&param_2,&param_3);
    }
    else {
      pvVar2 = Game_GetLinkedObjectExtent
                         (this,*(int *)((int)this + 0x54) + *(int *)((int)this + 0x5c) * 0xc,
                          (uint *)&param_2,&param_3);
      piVar1 = (int *)(*(int *)((int)this + 0x54) + *(int *)((int)this + 0x5c) * 0xc);
    }
    UI_AlignSpriteToRect(this,piVar1,pvVar2,&local_38,&local_3c);
    local_30 = local_38;
    if (local_38 < 0) {
      local_30 = 0;
      param_2 = (int *)((int)param_2 - local_38);
    }
    local_2c = local_3c;
    if (local_3c < 0) {
      param_3 = param_3 - local_3c;
      local_2c = 0;
    }
    local_28 = (int)param_2 + local_30;
    local_24 = param_3 + local_2c;
  }
  iVar7 = local_2c;
  Surface_SetBounds(*(void **)((int)this + 8),local_30,local_2c,local_28,local_24);
  if (*(int *)((int)this + 0x3c) != 0) {
    local_34 = (void *)(*(int *)((int)this + 0x24) - *(int *)((int)this + 0xd8));
    iVar6 = *(int *)((int)this + 0x28) - *(int *)((int)this + 0xe0);
    param_1 = (HWND)(*(int *)((int)this + 0xdc) + *(int *)((int)this + 0x24) + DAT_00571950);
    yBottom = *(int *)((int)this + 0xe4) + *(int *)((int)this + 0x28) + DAT_00571954;
    param_3 = yBottom;
    SetRect(&local_20,(int)local_34,iVar6,(int)param_1,yBottom);
    if ((*(void **)((int)this + 0x70) != (void *)0x0) || (*(int *)((int)this + 0x74) != 0)) {
      if (*(int *)((int)this + 0xc) == 0x10) {
        puVar4 = (uint *)(((*(int *)((int)this + 0x2c) + DAT_00571960 * -0x10) - local_30) -
                         *(int *)((int)this + 0x24));
        iVar7 = ((*(int *)((int)this + 0x30) - *(int *)((int)this + 0x10) * DAT_00571964) -
                *(int *)((int)this + 0x28)) - local_2c;
        Sprite_BlitWithDefaultAlpha
                  (*(void **)((int)this + 0x74),*(uint **)((int)this + 8),DAT_0058072c,puVar4,iVar7,
                   -1);
        if (*(void **)((int)this + 0x78) != (void *)0x0) {
          Sprite_BlitWithDefaultAlpha
                    (*(void **)((int)this + 0x78),*(uint **)((int)this + 8),DAT_0058072c,puVar4,
                     iVar7,-1);
        }
        yBottom = param_3;
      }
      else {
        Sprite_Blit24BitClipped
                  (*(void **)((int)this + 0x70),*(int *)((int)this + 8),DAT_0058072c,
                   (*(int *)((int)this + 0xc) * DAT_00571960 - *(int *)((int)this + 0x2c)) +
                   local_30 + -0x100 + *(int *)((int)this + 0x24),
                   (*(int *)((int)this + 0x10) * DAT_00571964 - *(int *)((int)this + 0x30)) +
                   *(int *)((int)this + 0x28) + -0x80 + iVar7,0,0);
      }
    }
    if ((*(int *)((int)this + 0x70) == 0) && (*(int *)((int)this + 0x74) == 0)) {
      Map_ComputeVisibleTileRange
                (this,&local_20.left,&local_48,&local_4c,&local_44,&local_40,&local_50);
      piVar1 = (int *)((int)(yBottom - iVar6) / (*(int *)((int)this + 0x10) >> 1) + 3);
      param_2 = piVar1;
      if (0 < (int)piVar1) {
        iVar7 = local_44;
        iVar6 = local_48;
        do {
          iVar5 = local_4c;
          if (iVar6 <= iVar7) {
            do {
              puVar4 = (uint *)Grid_GetCell(this,iVar6,iVar5);
              iVar5 = iVar5 + -1;
              if (puVar4 != (uint *)0x0) {
                Map_DrawObject(this,3,puVar4,0);
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 <= local_44);
            iVar7 = local_44;
            iVar6 = local_48;
          }
          if (local_50 == 0) {
            iVar6 = iVar6 + 1;
            iVar7 = iVar7 + 1;
            local_48 = iVar6;
            local_44 = iVar7;
          }
          else {
            local_4c = local_4c + 1;
            local_40 = local_40 + 1;
          }
          local_50 = (uint)(local_50 == 0);
          piVar1 = (int *)((int)piVar1 + -1);
        } while (piVar1 != (int *)0x0);
      }
    }
  }
  Game_UpdateAllPlayers(DAT_0057c670,*(undefined4 *)((int)this + 8),this);
  if (*(int *)((int)this + 0x40) != 0) {
    iVar5 = *(int *)((int)this + 0x28) - *(int *)((int)this + 0xe0);
    iVar6 = *(int *)((int)this + 0x28) + DAT_00571954 + *(int *)((int)this + 0xe4);
    SetRect(&local_20,*(int *)((int)this + 0x24) - *(int *)((int)this + 0xd8),iVar5,
            *(int *)((int)this + 0xdc) + *(int *)((int)this + 0x24) + DAT_00571950,iVar6);
    Map_ComputeVisibleTileRange
              (this,&local_20.left,&local_48,&local_4c,&local_44,&local_40,&local_50);
    param_4 = (int *)0x0;
    iVar7 = *(int *)((int)this + 0x10) >> 1;
    param_2 = (int *)((iVar6 - iVar5) / iVar7 + 3 + *(int *)((int)this + 0xe4) / iVar7);
    if (0 < (int)param_2) {
      iVar7 = local_48;
      iVar6 = local_44;
      do {
        iVar5 = local_4c;
        if (iVar7 <= iVar6) {
          do {
            puVar4 = (uint *)Grid_GetCell(this,iVar7,iVar5);
            iVar5 = iVar5 + -1;
            if ((puVar4 != (uint *)0x0) && (puVar4[2] != 0)) {
              if (-1 < *(int *)(puVar4[2] + 0x10)) {
                if (*(int *)((int)this + 0xc) == 0x10) {
                  iVar6 = 3;
                }
                else {
                  iVar6 = 1;
                }
                Map_DrawObject(this,iVar6,puVar4,1);
              }
              if (*(int *)((int)this + 0xc) == 0x10) {
                Map_RenderObjectList(this,0,(int)puVar4,-1,0);
                if (*(int *)(puVar4[2] + 0x1c) != -1) {
                  Map_RenderObject(this,puVar4,0);
                }
                Map_UpdateObjectState(this,(int *)puVar4);
              }
              else {
                Map_RenderObjectList(this,0,(int)puVar4,0,0);
                Map_DrawObject(this,2,puVar4,1);
                if (0 < *(int *)(puVar4[2] + 0x1c)) {
                  Map_RenderObject(this,puVar4,0);
                }
              }
              if ((((DAT_00580a4c != 0) && (*(char *)((int)this + 0xb8) == '\0')) &&
                  (*(int *)((int)this + 0x60) != 0)) &&
                 ((*(int *)((int)this + 100) != 0 &&
                  (*(int *)puVar4[2] == **(int **)(*(int *)((int)this + 100) + 8))))) {
                if (*(char *)((int)*(void **)((int)this + 4) +
                             *(int *)((int)this + 0x68) * 0x48 + 0x24) == '\x01') {
                  pvVar2 = (void *)SparseMap_Lookup48(*(void **)((int)this + 4),
                                                      *(int *)((int)this + 0x68));
                  if (pvVar2 == (void *)0x0) {
                    return;
                  }
                  UI_DrawObjectSprite(this,puVar4,pvVar2);
                }
              }
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 <= local_44);
          iVar7 = local_48;
          iVar6 = local_44;
        }
        if (local_50 == 0) {
          iVar7 = iVar7 + 1;
          iVar6 = iVar6 + 1;
          local_48 = iVar7;
          local_44 = iVar6;
        }
        else {
          local_4c = local_4c + 1;
          local_40 = local_40 + 1;
        }
        local_50 = (uint)(local_50 == 0);
        param_4 = (int *)((int)param_4 + 1);
      } while ((int)param_4 < (int)param_2);
    }
  }
  if (*(int *)((int)this + 0xc) != 0x10) {
    Map_ComputeVisibleTileRange
              (this,&local_20.left,&local_48,&local_4c,&local_44,&local_40,&local_50);
    if (0 < (int)param_2) {
      iVar7 = local_44;
      piVar1 = param_2;
      iVar6 = local_48;
      do {
        iVar5 = local_4c;
        if (iVar6 <= iVar7) {
          do {
            iVar7 = Grid_GetCell(this,iVar6,iVar5);
            iVar5 = iVar5 + -1;
            if (iVar7 != 0) {
              Map_RenderObjectList(this,0,iVar7,1,0);
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 <= local_44);
          iVar7 = local_44;
          iVar6 = local_48;
        }
        if (local_50 == 0) {
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + 1;
          local_48 = iVar6;
          local_44 = iVar7;
        }
        else {
          local_4c = local_4c + 1;
          local_40 = local_40 + 1;
        }
        local_50 = (uint)(local_50 == 0);
        piVar1 = (int *)((int)piVar1 + -1);
      } while (piVar1 != (int *)0x0);
    }
    SetRect(&local_20,(int)local_34,param_3,(int)param_1,param_3);
    Map_ComputeVisibleTileRange
              (this,&local_20.left,&local_48,&local_4c,&local_44,&local_40,&local_50);
    local_50 = (uint)(local_50 == 0);
    if (0 < (int)param_2) {
      iVar7 = local_44;
      piVar1 = param_2;
      iVar6 = local_48;
      do {
        iVar5 = local_4c;
        if (iVar6 <= iVar7) {
          do {
            iVar7 = Grid_GetCell(this,iVar6,iVar5);
            iVar5 = iVar5 + -1;
            if (iVar7 != 0) {
              Map_RenderObjectList(this,0,iVar7,2,1);
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 <= local_44);
          iVar7 = local_44;
          iVar6 = local_48;
        }
        if (local_50 == 0) {
          iVar6 = iVar6 + -1;
          iVar7 = iVar7 + -1;
          local_48 = iVar6;
          local_44 = iVar7;
        }
        else {
          local_4c = local_4c + -1;
          local_40 = local_40 + -1;
        }
        local_50 = (uint)(local_50 == 0);
        piVar1 = (int *)((int)piVar1 + -1);
      } while (piVar1 != (int *)0x0);
    }
  }
  if (*(int *)((int)this + 0x44) != 0) {
    Map_DrawRecordLinkOverlay(this,1);
  }
  if (*(int *)((int)this + 0x48) != 0) {
    Map_DrawRecordLinkOverlay(this,0);
  }
  if (*(int *)((int)this + 0xc) == 0x40) {
    param_2 = (int *)0x224;
    pvVar2 = *(void **)(*(int *)((int)this + 4) + 0x2c3d4);
    local_34 = pvVar2;
    do {
      if (((*(int *)((int)param_2 + (int)DAT_0057c670) != 0) &&
          (iVar7 = *(int *)((int)param_2 + *(int *)((int)this + 4) + 0x2c1f8), -1 < iVar7)) &&
         ((iVar7 < *(int *)((int)pvVar2 + 0x48) &&
          ((*(char *)(*(int *)((int)pvVar2 + 0x4c) + 0x3e + iVar7 * 0x48) != '\0' &&
           (iVar6 = Game_GetPlayerBySlot
                              (DAT_0057c670,*(int *)(*(int *)((int)param_2 + (int)DAT_0057c670) + 8)
                              ), iVar6 != 0)))))) {
        Record_GetTwoFloats48(pvVar2,iVar7,&local_38,&local_3c);
        param_3 = local_38 - *(int *)((int)this + 0x24);
        Record_DrawSprite48(pvVar2,*(uint **)((int)this + 8),DAT_0058072c,iVar7);
        iVar7 = Record_GetTypeIndex48(pvVar2,iVar7);
        switch(iVar7) {
        case 0:
          iVar7 = 3;
          break;
        case 2:
          iVar7 = 0;
          break;
        case 4:
          iVar7 = 1;
          break;
        case 6:
          iVar7 = 2;
        }
        iVar5 = Player_GetFirstRecordType1(iVar6);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 4) != 0)) {
          iVar3 = Game_FindCityIndex(iVar6);
          iVar5 = *(int *)(iVar6 + 0x1e0);
          iVar6 = (int)param_2 + iVar7 + -0x224;
          pvVar2 = *(void **)(*(int *)((int)this + 4) + 0x2c3e8 + iVar7 * 4);
          param_4 = *(int **)(*(int *)((int)this + 4) + 0x2c494 + iVar6 * 4);
          Record_SetIndex48(pvVar2,(int)param_4,iVar3);
          param_3 = local_38 - *(int *)((int)this + 0x24);
          Record_DrawSprite48(pvVar2,*(uint **)((int)this + 8),DAT_0058072c,(int)param_4);
          pvVar2 = *(void **)(*(int *)((int)this + 4) + 0x2c3d8 + iVar7 * 4);
          iVar7 = *(int *)(*(int *)((int)this + 4) + 0x2c434 + iVar6 * 4);
          Record_SetIndex48(pvVar2,iVar7,iVar5);
          param_3 = local_38 - *(int *)((int)this + 0x24);
          Record_DrawSprite48(pvVar2,*(uint **)((int)this + 8),DAT_0058072c,iVar7);
          pvVar2 = local_34;
        }
      }
      param_2 = param_2 + 1;
    } while ((int)param_2 < 0x23c);
  }
  Game_BlitScaledObjectSprite(*(int *)((int)this + 4));
  *(undefined4 *)((int)this + 8) = 0;
  Surface_FillFF((int)DAT_0058072c);
  return;
}

