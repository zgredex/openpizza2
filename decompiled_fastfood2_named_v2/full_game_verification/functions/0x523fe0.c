// rea decompile_all
// name: UI_ProcessChildEvent
// address: 0x523fe0
// body: available
// range: 0x523fe0-0x5243b3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall UI_ProcessChildEvent(void *this,void *param_1)

{
  int iVar1;
  void *pvVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int local_20;
  undefined4 *local_1c;
  int local_14;
  tagRECT local_10;
  
  uVar5 = Renderer_DrawPendingSprite
                    (*(void **)((int)this + 0x8310),(int)param_1,(LPRECT)((int)this + 0x83c0));
  *(undefined4 *)((int)this + 0x83bc) = uVar5;
  local_20 = 0;
  *(undefined4 *)((int)this + 0x83d0) = 0xfffffc19;
  if ((*(int *)((int)this + 0x238) == 0) && (*(int *)((int)this + 0x83e4) == 0)) {
    iVar6 = *(int *)((int)this + 0x1a4);
    if (iVar6 != -999) {
      local_20 = 1;
      *(undefined4 *)((int)this + 0x83d0) = *(undefined4 *)((int)this + 0x1a4);
      *(undefined4 *)((int)this + 0x83d4) = *(undefined4 *)((int)this + 0x1a8);
      *(undefined4 *)((int)this + 0x83d8) = *(undefined4 *)((int)this + 0x1ac);
      *(undefined4 *)((int)this + 0x83dc) = *(undefined4 *)((int)this + 0x1b0);
      if (*(void **)((int)this + 0x1c4) != (void *)0x0) {
        iVar1 = *(int *)((int)this + 0x1a8);
        Sprite_Blit24Bit(*(void **)((int)this + 0x1c4),(int)param_1,iVar6,iVar1,
                         *(int *)((int)this + 0x1ac) - iVar6,*(int *)((int)this + 0x1b0) - iVar1,
                         iVar6,iVar1);
      }
      *(undefined4 *)((int)this + 0x1a4) = 0xfffffc19;
    }
  }
  else {
    local_20 = 2;
    *(undefined4 *)((int)this + 0x238) = 0;
    if (*(void **)((int)this + 0x1c4) == (void *)0x0) {
      if (*(int *)((int)this + 0x1b4) == 0) {
        if (*(int *)((int)this + 0x1bc) != 0) {
          Surface_Clear(*(int *)((int)this + 0x1bc));
        }
      }
      else {
        Surface_ClearRows((int)param_1);
      }
    }
    else {
      Sprite_Blit24Bit(*(void **)((int)this + 0x1c4),(int)param_1,0,0,-9999,-9999,0,0);
    }
    *(undefined4 *)((int)this + 0x234) = 0;
  }
  local_14 = 0;
  if (0 < *(int *)((int)this + 0x23c)) {
    local_1c = (undefined4 *)((int)this + 0x14);
    do {
      pvVar2 = (void *)*local_1c;
      if ((pvVar2 != (void *)0x0) && (*(int *)((int)pvVar2 + 0x4c) != 0)) {
        if ((*(int *)((int)pvVar2 + 0xe0) == 0) && (*(int *)((int)pvVar2 + 0x38) == -999)) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        bVar4 = false;
        if (local_20 == 0) {
          if (!bVar3) goto LAB_005242b4;
          local_20 = 1;
          UI_GetWindowRect(pvVar2,(LPRECT)((int)this + 0x83d0));
        }
        else if (local_20 == 1) {
          if ((!bVar3) && (*(int *)((int)this + 0x83d0) != -999)) {
            local_10.left = *(int *)((int)pvVar2 + 8);
            local_10.top = *(int *)((int)pvVar2 + 0xc);
            local_10.right = *(int *)((int)pvVar2 + 0x10);
            local_10.bottom = *(int *)((int)pvVar2 + 0x14);
            if ((*(int *)((int)this + 0x83d0) < local_10.right) &&
               (((local_10.left < *(int *)((int)this + 0x83d8) &&
                 (*(int *)((int)this + 0x83d4) < local_10.bottom)) &&
                (local_10.top < *(int *)((int)this + 0x83dc))))) {
              bVar4 = true;
            }
          }
          if ((*(int *)((int)pvVar2 + 0xe0) == 0) && (*(int *)((int)pvVar2 + 0x38) == -999)) {
            if (!bVar4) goto LAB_005242b4;
          }
          else {
            UI_GetWindowRect(pvVar2,&local_10);
            iVar6 = *(int *)((int)this + 0x83d0);
            if (iVar6 == -999) {
              *(int *)((int)this + 0x83d0) = local_10.left;
              *(LONG *)((int)this + 0x83d4) = local_10.top;
              *(LONG *)((int)this + 0x83d8) = local_10.right;
              *(LONG *)((int)this + 0x83dc) = local_10.bottom;
            }
            else {
              if (local_10.left <= iVar6) {
                iVar6 = local_10.left;
              }
              *(int *)((int)this + 0x83d0) = iVar6;
              iVar6 = *(int *)((int)this + 0x83d8);
              if (*(int *)((int)this + 0x83d8) <= local_10.right) {
                iVar6 = local_10.right;
              }
              *(int *)((int)this + 0x83d8) = iVar6;
              iVar6 = *(int *)((int)this + 0x83d4);
              if (local_10.top <= *(int *)((int)this + 0x83d4)) {
                iVar6 = local_10.top;
              }
              *(int *)((int)this + 0x83d4) = iVar6;
              iVar6 = *(int *)((int)this + 0x83dc);
              if (*(int *)((int)this + 0x83dc) <= local_10.bottom) {
                iVar6 = local_10.bottom;
              }
              *(int *)((int)this + 0x83dc) = iVar6;
            }
          }
        }
        else {
          if (local_20 != 2) goto LAB_005242b4;
          SetRect((LPRECT)((int)this + 0x83d0),0,0,*(int *)((int)this + 0x270),
                  *(int *)((int)this + 0x274));
        }
        if (*(int *)((int)this + 0x83d0) != -999) {
          UI_ClipRect((void *)*local_1c,(int *)((int)this + 0x83d0),0);
        }
        UI_ProcessWindowEvent((void *)*local_1c,param_1);
      }
LAB_005242b4:
      local_14 = local_14 + 1;
      local_1c = local_1c + 1;
    } while (local_14 < *(int *)((int)this + 0x23c));
  }
  if (*(int *)((int)this + 0x240) != 0) {
    Surface_SetBounds(param_1,0,0,DAT_00574734,DAT_00574738);
    UI_DrawChildAt(*(void **)((int)this + 0x240),param_1);
  }
  pvVar2 = *(void **)((int)this + 0x244);
  if (pvVar2 != (void *)0x0) {
    if (*(int *)((int)pvVar2 + 0x3c) != 0) {
      Window_GetRect(pvVar2,&local_10.left);
      iVar6 = *(int *)((int)this + 0x83d0);
      if (local_10.left <= *(int *)((int)this + 0x83d0)) {
        iVar6 = local_10.left;
      }
      *(int *)((int)this + 0x83d0) = iVar6;
      iVar6 = *(int *)((int)this + 0x83d8);
      if (*(int *)((int)this + 0x83d8) <= local_10.right) {
        iVar6 = local_10.right;
      }
      *(int *)((int)this + 0x83d8) = iVar6;
      iVar6 = *(int *)((int)this + 0x83d4);
      if (local_10.top <= *(int *)((int)this + 0x83d4)) {
        iVar6 = local_10.top;
      }
      *(int *)((int)this + 0x83d4) = iVar6;
      iVar6 = *(int *)((int)this + 0x83dc);
      if (*(int *)((int)this + 0x83dc) <= local_10.bottom) {
        iVar6 = local_10.bottom;
      }
      *(int *)((int)this + 0x83dc) = iVar6;
    }
    Surface_SetBounds(param_1,0,0,DAT_00574734,DAT_00574738);
    Renderer_FlushTarget(*(void **)((int)this + 0x244),(int)param_1);
  }
  Renderer_ComposeSpriteScaled(*(void **)((int)this + 0x8310),(int)param_1,-9999,-9999,(LPRECT)0x0);
  return;
}

